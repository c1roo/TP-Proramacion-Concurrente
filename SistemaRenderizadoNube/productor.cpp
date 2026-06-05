#include "productor.h"
#include <chrono>
#include "message_queue.h"
#include "semaforo.h"
#include "log.h"
#include "global.h"
using namespace std;

void productor(MessageQueue& cola, Semaforo& hay_espacio, Semaforo& hay_datos, int cantidadJobs) {
    for (int i = 1; i <= cantidadJobs; i++) {
        Job nuevoJob;
        nuevoJob.id = generarID();
        nuevoJob.prioridad = rand() % 2;
        nuevoJob.creacion = chrono::high_resolution_clock::now();

        registrarevento(nuevoJob.id, nuevoJob.prioridad, "CREADO");

        wait(hay_espacio);      
        addJob(cola, nuevoJob);
        signal(hay_datos);    
    }
}