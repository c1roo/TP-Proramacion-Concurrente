#include "global.h"

int proximoID = 0;
int jobFinalizados = 0;
mutex contador;

int generarID()
{
    lock_guard<mutex> lock (contador);
    proximoID++;
    return proximoID;
}

void incrementarContador() {
    lock_guard<mutex> lock(contador);
    jobFinalizados++;
}

void mostrarContador() {
    lock_guard<mutex> lock(contador);
    cout << "Jobs finalizados: " << jobFinalizados << endl;
}