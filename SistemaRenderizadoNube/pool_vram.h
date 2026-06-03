#ifndef POOL_VRAM_H_INCLUDED
#define POOL_VRAM_H_INCLUDED

#include <mutex>
#include <condition_variable>
#include <vector>
#include "job.h"

struct PoolVRAM {
    int capacidad_maxima;
    int cantidad_activos;
    std::vector<Job> buffer_mensajes;
    std::mutex mtx;
    std::condition_variable cv_espacio;
};

void init(PoolVRAM& pool, int n);
void wait(PoolVRAM& pool, const Job& job);
void signal(PoolVRAM& pool, int jobId);
void asignarAVRAM(PoolVRAM& pool, Job& job);
void liberarDeVRAM(PoolVRAM& pool, Job& job);

#endif