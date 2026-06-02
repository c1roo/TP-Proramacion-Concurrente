#ifndef POOL_VRAM_H_INCLUDED
#define POOL_VRAM_H_INCLUDED

#include <mutex>
#include <condition_variable>
#include "job.h"

struct PoolVRAM {
    int contador;
    std::mutex mtx;
    std::condition_variable cv;
};

void init(PoolVRAM& pool, int n);
void wait(PoolVRAM& pool);
void signal(PoolVRAM& pool);

void asignarAVRAM(PoolVRAM& pool, Job& job);
void liberarDeVRAM(PoolVRAM& pool, Job& job);

#endif