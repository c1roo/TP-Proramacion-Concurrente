#ifndef POOL_VRAM_H_INCLUDED
#define POOL_VRAM_H_INCLUDED

#include <mutex>
#include <condition_variable>
#include "job.h"

struct PoolVRAM {
    std::mutex mtx;                          
    std::condition_variable cv_disponible;   
    int slots_ocupados = 0;
    const int MAX_SLOTS = 5;                 
};

void asignarAVRAM(PoolVRAM& pool, Job& job);
void liberarDeVRAM(PoolVRAM& pool, Job& job);

#endif // POOL_VRAM_H_INCLUDED