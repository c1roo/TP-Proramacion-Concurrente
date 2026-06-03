#ifndef CONSUMIDOR_H_INCLUDED
#define CONSUMIDOR_H_INCLUDED
#include "message_queue.h"
#include "pool_vram.h"
#include "semaforo.h"

void consumidor(MessageQueue& cola, PoolVRAM& pool, Semaforo& hay_espacio, Semaforo& hay_datos, int cantidadJobs);

#endif