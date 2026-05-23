#include "productor.h"
#include "semaforo.h"
#include "global.h"
#include <iostream>
#include <queue>
#include <mutex>
#include <chrono>

const int tam = 100000;
const int cant_consumidores = 3;

void productor() {
    auto inicio = std::chrono::high_resolution_clock::now();

    int producidos = 0;
    while (producidos < tam) {
        wait(hay_espacio);
        mtx_buffer.lock();
        buffer.push(producidos);
        producidos++;
        mtx_buffer.unlock();
        signal(hay_datos);
    }

    std::cout << "Producidos: " << producidos << std::endl;

    for (int i = 0; i < cant_consumidores; i++) {
        wait(hay_espacio);
        mtx_buffer.lock();
        buffer.push(-1);
        mtx_buffer.unlock();
        signal(hay_datos);
    }
    chrono_M.lock();
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
    std::cout << "Productor termino en " << duracion << " ms" << std::endl;
    chrono_M.unlock();
}

