#ifndef PRODUCTOR_H_INCLUDED
#define PRODUCTOR_H_INCLUDED
#include "message_queue.h"
#include "semaforo.h"

void productor(MessageQueue& cola, Semaforo& hay_espacio, Semaforo& hay_datos, int cantidadJobs);

#endif