#ifndef JOB_H_INCLUDED
#define JOB_H_INCLUDED
#include <chrono>
using namespace std;

struct Job
{
    int id;
    int prioridad;
    chrono::high_resolution_clock::time_point creacion;
    
};
<<<<<<< HEAD
=======

  //-agregar el tiempo en el que se crea como atributo de nombre "creacion"


>>>>>>> origin/Rama_TP_Concurrente_Ricarte_2026
#endif // JOB_H_INCLUDED
