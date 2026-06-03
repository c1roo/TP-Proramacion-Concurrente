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

#endif // JOB_H_INCLUDED
