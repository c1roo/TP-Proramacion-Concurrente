#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#include <mutex>
#include <iostream>
using namespace std;

extern int jobFinalizados;
extern mutex contador;

void incrementarContador();
void mostrarContador();


#endif // GLOBAL_H_INCLUDED
