#include "log.h"

mutex mtxlog;

void registrarEvento(int jobId, string prioridad, string evento)
{
    lock_guard<mutex> lock(mtxlog);
    cout<< "Job: "<<jobId<<"-"<< prioridad << "-" << evento <<endl; 
}