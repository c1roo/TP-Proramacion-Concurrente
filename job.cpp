#include "job.h"
#include <thread>
#include <chrono>

// Constructor por defecto (necesario si creas un array tipo "Job mi_buffer[5];")
Job::Job() : id(-1), prioridad(0) {
    tiempo_creacion = std::chrono::steady_clock::now();
}

// Constructor parametrizado (para cuando el Productor crea la tarea)
Job::Job(int id_asignado, int prioridad_asignada) : id(id_asignado), prioridad(prioridad_asignada) {
    tiempo_creacion = std::chrono::steady_clock::now();
}

// Simula el procesamiento del trabajo en el Worker Node
void Job::procesar() {
    // Un Job debe permanecer en el Pool de VRAM un mínimo de 600ms[cite: 10].
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
}

// Comprueba si un trabajo de baja prioridad está sufriendo inanición
bool Job::estaEnInanicion() const {
    if (prioridad == 1) {
        return false; // Los Premium no sufren inanición en este contexto
    }
    
    auto ahora = std::chrono::steady_clock::now();
    auto tiempo_espera = std::chrono::duration_cast<std::chrono::milliseconds>(ahora - tiempo_creacion).count();
    
    // Los jobs de baja prioridad (Free) deben ser procesados tras un periodo de 5000ms[cite: 10].
    return tiempo_espera >= 5000;
}

// Getters para leer los valores desde afuera
int Job::getId() const {
    return id;
}

int Job::getPrioridad() const {
    return prioridad;
}