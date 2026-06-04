#include "global.h"

int jobFinalizados = 0;
mutex contador;

void incrementarContador() {
    lock_guard<mutex> lock(contador);
    jobFinalizados++;
}

void mostrarContador() {
    lock_guard<mutex> lock(contador);
    cout << "Jobs finalizados: " << jobFinalizados << endl;
}