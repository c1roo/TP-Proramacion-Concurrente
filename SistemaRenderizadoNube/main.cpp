#include <iostream>
#include "productor.h"
#include "pool_vram.h"


using namespace std;

PoolVRAM pool;


int main()
{
    init(pool,5);
    
    productor(10);
    return 0;
}
