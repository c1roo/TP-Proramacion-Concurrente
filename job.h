#ifndef JOB_H
#define JOB_H

#include <chrono>

class Job {
private:
    int id;
    int prioridad; // 1 para Premium, 0 para Free
    std::chrono::time_point<std::chrono::steady_clock> tiempo_creacion;

public:
    // Constructores
    Job(); // Constructor por defecto
    Job(int id_asignado, int prioridad_asignada);

    // Métodos de comportamiento
    void procesar();
    bool estaEnInanicion() const;

    // Getters (para acceder a los datos privados desde los buffers o el log)
    int getId() const;
    int getPrioridad() const;
};

#endif