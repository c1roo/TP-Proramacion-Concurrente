#include "consumidor.h"
#include "semaforo.h"
#include "global.h"
#include "log.h"
using namespace std;

void consumidor(MessageQueue& cola, PoolVRAM& pool, Semaforo& hay_espacio, Semaforo& hay_datos, int cantidadJobs) {
    for (int x = 0; x < cantidadJobs; x++) {
        wait(hay_datos);  
        Job job = getJob(cola);
        signal(hay_espacio);   

        asignarAVRAM(pool, job);
        liberarDeVRAM(pool, job);
        incrementarContador();
    }
    
}