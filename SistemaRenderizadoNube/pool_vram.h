#ifndef POOL_VRAM_H_INCLUDED
#define POOL_VRAM_H_INCLUDED

<<<<<<< HEAD
registrarevento(int jobId, string prioridad, string evento, string timestamp());




registrarevento(int jobId, string prioridad, string evento, string timestamp());
=======
#include <mutex>
#include <condition_variable>
#include "job.h"
>>>>>>> origin/Rama_TP_Concurrente_Ricarte_2026

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