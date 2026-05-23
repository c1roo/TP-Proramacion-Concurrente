
#include <consumidor.h>
#include "global.h"
#include <semaforo.h>
#include <iostream>
#include <queue>
#include <mutex>
#include <chrono>





void consumidor(int id) {
    auto inicio = std::chrono::high_resolution_clock::now();

    while (true) {
        wait(hay_datos);
        mtx_buffer.lock();
        if (buffer.empty()) {
            mtx_buffer.unlock();
            break; // salir si ya no hay nada
        }
        int val = buffer.front();
        buffer.pop();
        mtx_buffer.unlock();
        signal(hay_espacio);

        if (val == -1) {

            break; // sale por ser ultimo
        }
    }
chrono_M.lock();
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
    std::cout << "Consumidor "<<id<<"termino en " << duracion << " ms" << std::endl;
    chrono_M.unlock();
}