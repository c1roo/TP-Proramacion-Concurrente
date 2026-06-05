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

    int cantJobs = 0;
    int cantProductores = 1;
    int cantConsumidores = 2; 

    int jobsPorProductor = cantJobs / cantProductores;       
    int restoAProducir = cantJobs % cantProductores;
    int jobsPorConsumidor = cantJobs / cantConsumidores;       
    int restoAConsumir = cantJobs % cantConsumidores;

    thread p1(productor, ref(cola), ref(hay_espacio), ref(hay_datos), jobsPorProductor + restoAProducir);
    //thread p2(productor, ref(cola), ref(hay_espacio), ref(hay_datos), jobsPorProductor);
    //thread p3(productor, ref(cola), ref(hay_espacio), ref(hay_datos), jobsPorProductor);

    thread c1(consumidor, ref(cola), ref(pool), ref(hay_espacio), ref(hay_datos), jobsPorConsumidor + restoAConsumir);
    thread c2(consumidor, ref(cola), ref(pool), ref(hay_espacio), ref(hay_datos), jobsPorConsumidor);
    //thread c3(consumidor, ref(cola), ref(pool), ref(hay_espacio), ref(hay_datos), jobsPorConsumidor);

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