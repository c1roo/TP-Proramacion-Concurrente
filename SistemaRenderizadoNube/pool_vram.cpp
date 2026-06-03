#include "pool_vram.h"
#include "log.h"
#include <thread>
#include <chrono>

void init(PoolVRAM& pool, int n) {
    pool.contador = n;
}

void wait(PoolVRAM& pool) {
    std::unique_lock<std::mutex> lock(pool.mtx);
    while (pool.contador == 0) {
        pool.cv.wait(lock);
    }
    pool.contador--;
}

void signal(PoolVRAM& pool) {
    std::unique_lock<std::mutex> lock(pool.mtx);
    pool.contador++;
    pool.cv.notify_one();
}

void asignarAVRAM(PoolVRAM& pool, Job& job) {
    wait(pool);

    std::this_thread::sleep_for(std::chrono::milliseconds(450));

    registrarevento(job.id, job.prioridad, "ASIGNADO_A_VRAM");

}

void liberarDeVRAM(PoolVRAM& pool, Job& job) {
    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    signal(pool);

    std::this_thread::sleep_for(std::chrono::milliseconds(250));

    registrarevento(job.id, job.prioridad, "FINALIZADO");
    {
        lock_guard<mutex> lock(contador);
        jobFinalizados++;
    }

}