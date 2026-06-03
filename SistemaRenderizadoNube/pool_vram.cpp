#include "pool_vram.h"
#include "log.h"
#include <thread>
#include <chrono>
using namespace std;

void init(PoolVRAM& pool, int n) {
    pool.contador = n;
}

void wait(PoolVRAM& pool) {
    unique_lock<mutex> lock(pool.mtx);
    while (pool.contador == 0) {
        pool.cv.wait(lock);
    }
    pool.contador--;
}

void signal(PoolVRAM& pool) {
    unique_lock<mutex> lock(pool.mtx);
    pool.contador++;
    pool.cv.notify_one();
}

void asignarAVRAM(PoolVRAM& pool, Job& job) {
    wait(pool);

    this_thread::sleep_for(chrono::milliseconds(450));
    string prio;
    if(job.prioridad == 1)
    {
        prio = "Premium";
    }
    else 
    {
        prio = "Free";
    }

    registrarEvento(job.id, prio, "ASIGNADO_VRAM");

}

void liberarDeVRAM(PoolVRAM& pool, Job& job) {
    this_thread::sleep_for(chrono::milliseconds(600));
    signal(pool);
    this_thread::sleep_for(chrono::milliseconds(250));

    string prio;
    if(job.prioridad == 1)
    {
        prio = "Premium";
    }
    else 
    {
        prio = "Free";
    }

    registrarEvento(job.id, prio, "FINALIZADO");

}