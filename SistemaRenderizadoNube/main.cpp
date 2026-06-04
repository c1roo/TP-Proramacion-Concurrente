#include <iostream>
#include <thread>
#include <chrono>
#include "productor.h"
#include "consumidor.h"
#include "message_queue.h"
#include "pool_vram.h"
#include "semaforo.h"
#include "global.h"
using namespace std;

chrono::high_resolution_clock::time_point inicio = chrono::high_resolution_clock::now();

int main() {
    MessageQueue cola;
    PoolVRAM pool;
    init(pool, 5);

    Semaforo hay_espacio;
    Semaforo hay_datos;
    init(hay_espacio, 10);
    init(hay_datos, 0);    

    int cantJobs = 10;

    thread p1(productor, ref(cola), ref(hay_espacio), ref(hay_datos), cantJobs);

    thread c1(consumidor, ref(cola), ref(pool), ref(hay_espacio), ref(hay_datos), cantJobs / 2);
    thread c2(consumidor, ref(cola), ref(pool), ref(hay_espacio), ref(hay_datos), cantJobs / 2);

    p1.join();
    c1.join();
    c2.join();

    mostrarContador();
    return 0;
}