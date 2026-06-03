#include "global.h"

int jobsFinalizados = 0;
mutex mtxContador;

void incrementarContador() {
    lock_guard<mutex> lock(mtxContador);
    jobsFinalizados++;
}

void mostrarContador() {
    lock_guard<mutex> lock(mtxContador);
    cout << "Jobs finalizados: " << jobsFinalizados << endl;
}