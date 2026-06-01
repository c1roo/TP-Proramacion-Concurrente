#include "pool_vram.h"
#include "log.h"
#include <thread>
#include <chrono>

void asignarAVRAM(PoolVRAM& pool, Job& job) {
    static std::mutex mtx_entrada_secuencial;
    std::unique_lock<std::mutex> lock_entrada(mtx_entrada_secuencial);

    std::unique_lock<std::mutex> lock(pool.mtx);

    while (pool.slots_ocupados >= pool.MAX_SLOTS) {
        pool.cv_disponible.wait(lock);
    }

    pool.slots_ocupados++;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(450));

    // llamada al log asignado de vram
    registrarEvento(job, "ASIGNADO_VRAM");
}

void liberarDeVRAM(PoolVRAM& pool, Job& job) {
    static std::mutex mtx_salida_secuencial;
    std::unique_lock<std::mutex> lock_salida(mtx_salida_secuencial);

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    std::unique_lock<std::mutex> lock(pool.mtx);

    pool.slots_ocupados--;

    std::this_thread::sleep_for(std::chrono::milliseconds(250));

    // llamada al log finalizado
    registrarEvento(job, "FINALIZADO");

    pool.cv_disponible.notify_one();