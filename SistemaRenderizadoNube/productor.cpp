#include "productor.h"
#include<iostream>
#include "job.h"
#include "log.h"
using namespace std;

void productor(int cantidadJobs)
{
    for(int i = 1; i <= cantidadJobs; i++)
    {
        Job nuevoJob;

        nuevoJob.id = i;
        nuevoJob.prioridad = rand() % 2;

        cout << "Job creado: " << nuevoJob.id<< "Prioridad: "<<nuevoJob.prioridad <<endl;
    }
    registrarevento(nuevoJob.id, nuevoJob.prioridad, "CREADO");

}