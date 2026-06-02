#include "consumidor.h"
#include <iostream>
using namespace std;

void consumidor (MessageQueue& cola, PoolVRAM& pool, int cantidadJobs)
{
    for (int x = 0; x < cantidadJobs; x++)
    {
        Job job = getJob(cola);

        cout<< "Job: "<< job.id << "obtenido de la colka" << endl;

        asignarVRAM(pool,job);

        cout<< "Job: " << job.id << "Asignado a la VRAM" << endl;

        liberarVRAM(pool, job);

        cout<< "Job: " << job.id << "Terminado" << endl;
    }


}