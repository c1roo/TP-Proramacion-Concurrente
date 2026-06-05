#include "message_queue.h"
#include "log.h"
using namespace std;

bool compararJobs(const Job& job1, const Job& job2) {
    bool resultado;

    if(job1.prioridad == job2.prioridad) {
        resultado = job1.creacion > job2.creacion;
    }
    else {
        resultado = job1.prioridad < job2.prioridad;
    }

    return resultado;
}

void addJob(MessageQueue& messageQueue, Job& job) {
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lock(messageQueue.mtx);
    
    messageQueue.jobQueue.push(job);
    registrarevento(job.id, job.prioridad, "EN COLA");
}



Job getJob(MessageQueue& messageQueue) {
    vector<Job> vectorAux;

    lock_guard<mutex> lock(messageQueue.mtx);
    while (!messageQueue.jobQueue.empty()) {
        vectorAux.push_back(messageQueue.jobQueue.top());
        messageQueue.jobQueue.pop();
    }

    for (Job& j : vectorAux) {
        auto ahora = chrono::high_resolution_clock::now();
        auto tiempoDeEspera = chrono::duration_cast<chrono::milliseconds>(ahora - j.creacion);

        if (tiempoDeEspera.count() >= 5000) {
            j.prioridad = (int)(tiempoDeEspera.count() / 2500);
        }

        messageQueue.jobQueue.push(j);
    }

    Job job = messageQueue.jobQueue.top();
    messageQueue.jobQueue.pop();
    return job;
}