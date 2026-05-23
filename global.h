#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <queue>
#include <vector>
#include <mutex>
#include "semaforo.h"
#include "job.h" 


// BUFFER 1 Message Queue 

extern std::queue<Job> message_queue; 
extern std::mutex mtx_mq;            
extern Semaforo mq_hay_espacio;       
extern Semaforo mq_hay_datos;         


// BUFFER 2 Pool de VRAM 


extern std::vector<Job> pool_vram;    
extern std::mutex mtx_vram;           
extern Semaforo vram_slots_libres;  


// RECURSOS COMPARTIDOS ADICIONALES

extern int jobs_finalizados;         
extern std::mutex mtx_contador;       
extern std::mutex mtx_log;            

#endif // GLOBAL_H_INCLUDED