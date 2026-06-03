#include <iostream>
#include "productor.h"
#include "pool_vram.h"
#include "global.h"


using namespace std;

PoolVRAM pool;


int main()
{
    init(pool,5);
    
    productor(10);

    cout << "Jobs finalizados: " << jobFinalizados << endl;
    return 0;
}
