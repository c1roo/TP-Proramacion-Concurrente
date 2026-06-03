#include "productor.h"
#include<iostream>
#include "job.h"
#include <chrono>
#include "message_queue.h"
#include "log.h"
using namespace std;

void productor(MessageQueue& cola,int cantidadJobs)
{
    for(int i = 1; i <= cantidadJobs; i++)
    {
        Job nuevoJob;

        nuevoJob.id = i;
        nuevoJob.prioridad = rand() % 2; // prioridad aleatoria
        nuevoJob.creacion = chrono::high_resolution_clock::now(); // tiempo en que se creo el job
        addJob(cola,nuevoJob);
        string prio;
        if(nuevoJob.prioridad == 1)
        {
            prio = "Premium";
        }
        else
        {
            prio = "Free";
        }
        registrarEvento(nuevoJob.id, prio, "EN_COLA");
        cout << "Job creado: " << nuevoJob.id<< " Prioridad: "<<nuevoJob.prioridad <<endl;
    }
}
