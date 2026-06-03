#include <iostream>
#include <thread>
#include "productor.h"
#include "consumidor.h"
#include "message_queue.h"
#include "pool_vram.h"
#include "global.h"

using namespace std;


int main()
{
    MessageQueue cola;
    PoolVRAM pool;
    init(pool,5);
    
    int cantJobs = 10;

    thread p1(productor, ref(cola), cantJobs);

    thread c1(consumidor, ref(cola), ref(pool), cantJobs / 2);
    thread c2(consumidor, ref(cola), ref(pool), cantJobs / 2);

    p1.join();
    c1.join();
    c2.join();

    mostrarContador();

    return 0;
}
