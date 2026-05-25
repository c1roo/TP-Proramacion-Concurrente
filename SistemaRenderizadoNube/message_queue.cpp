#include "message_queue.h"

bool compararJobs(const Job& job1, const Job& job2) {
    return job1.prioridad < job2.prioridad; 
}

void addJob(MessageQueue& messageQueue, Job& job) {
    std::lock_guard<std::mutex> lock(messageQueue.mtx);
    messageQueue.jobQueue.push(job);
}


Job getJob(MessageQueue& messageQueue) {
    std::vector<Job> vectorAux;

    std::lock_guard<std::mutex> lock(messageQueue.mtx);
    while (!messageQueue.jobQueue.empty()) {
        vectorAux.push_back(messageQueue.jobQueue.top());
        messageQueue.jobQueue.pop();
    }

    for (Job& j : vectorAux) {
        auto ahora = std::chrono::high_resolution_clock::now();
        auto tiempoDeEspera = std::chrono::duration_cast<std::chrono::milliseconds>(ahora - j.creacion);

        if (tiempoDeEspera.count() >= 5000) {
            j.prioridad = 2;
        }

        messageQueue.jobQueue.push(j);
    }

    Job job = messageQueue.jobQueue.top();
    messageQueue.jobQueue.pop();
    return job;
}