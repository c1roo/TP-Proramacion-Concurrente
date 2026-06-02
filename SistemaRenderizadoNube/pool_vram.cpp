#include "pool_vram.h"
#include "log.h"
#include <thread>
#include <chrono>

void asignarAVRAM(PoolVRAM& pool, Job& job) {
    std::unique_lock<std::mutex> lock(pool.mtx);

    while (pool.slots_ocupados >= pool.MAX_SLOTS) {
        pool.cv_disponible.wait(lock);
    }

    pool.slots_ocupados++;
    lock.unlock(); 

    std::this_thread::sleep_for(std::chrono::milliseconds(450));

    // falta del log algo como registrarEvento(job, "ASIGNADO_VRAM");
}

void liberarDeVRAM(PoolVRAM& pool, Job& job) {
    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    std::unique_lock<std::mutex> lock(pool.mtx);
    pool.slots_ocupados--;
    lock.unlock(); 

    std::this_thread::sleep_for(std::chrono::milliseconds(250));

    // falta del log algo como registrarEvento(job, "FINALIZADFO");

    pool.cv_disponible.notify_one();
}