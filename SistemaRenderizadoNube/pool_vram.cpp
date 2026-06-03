#include "pool_vram.h"
#include "log.h"
#include <thread>
#include <chrono>

void init(PoolVRAM& pool, int n) {
    pool.capacidad_maxima = n;
    pool.cantidad_activos = 0;
    Job jobVacio;
    jobVacio.id = 0;
    pool.buffer_mensajes.assign(n, jobVacio);
}

void wait(PoolVRAM& pool, const Job& job) {
    std::unique_lock<std::mutex> lock(pool.mtx);
    while (pool.cantidad_activos == pool.capacidad_maxima) {
        pool.cv_espacio.wait(lock);
    }
    for (int i = 0; i < pool.capacidad_maxima; ++i) {
        if (pool.buffer_mensajes[i].id == 0) {
            pool.buffer_mensajes[i] = job;
            break;
        }
    }
    pool.cantidad_activos++;
}

void signal(PoolVRAM& pool, int jobId) {
    std::unique_lock<std::mutex> lock(pool.mtx);
    for (int i = 0; i < pool.capacidad_maxima; ++i) {
        if (pool.buffer_mensajes[i].id == jobId) {
            pool.buffer_mensajes[i].id = 0;
            break;
        }
    }
    pool.cantidad_activos--;
    lock.unlock();
    pool.cv_espacio.notify_one();
}

void asignarAVRAM(PoolVRAM& pool, Job& job) {
    wait(pool, job);
    std::this_thread::sleep_for(std::chrono::milliseconds(450)); 
    std::string prio = (job.prioridad == 1) ? "Premium" : "Free";
    registrarEvento(job.id, prio, "ASIGNADO_VRAM");
}

void liberarDeVRAM(PoolVRAM& pool, Job& job) {
    std::this_thread::sleep_for(std::chrono::milliseconds(600)); 
    signal(pool, job.id);
    std::this_thread::sleep_for(std::chrono::milliseconds(250)); 
    std::string prio = (job.prioridad == 1) ? "Premium" : "Free";
    registrarEvento(job.id, prio, "FINALIZADO");
}