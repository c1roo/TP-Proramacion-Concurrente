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

    int cantJobs = 100;

    thread p1(productor, ref(cola), ref(hay_espacio), ref(hay_datos), cantJobs);
    //thread p2(productor, ref(cola), ref(hay_espacio), ref(hay_datos), cantJobs);
    //thread p3(productor, ref(cola), ref(hay_espacio), ref(hay_datos), cantJobs);

    thread c1(consumidor, ref(cola), ref(pool), ref(hay_espacio), ref(hay_datos), cantJobs);
    thread c2(consumidor, ref(cola), ref(pool), ref(hay_espacio), ref(hay_datos), cantJobs);
    //thread c3(consumidor, ref(cola), ref(pool), ref(hay_espacio), ref(hay_datos), cantJobs);

    p1.join();
   // p2.join();
   // p3.join();
    c1.join();
    c2.join();
   // c3.join();

    mostrarContador();
    return 0;
}
/*

cd SistemaRenderizadoNube
g++ -std=c++20 *.cpp -o programa.exe
./programa.exe

 */