#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED
#include <string>
#include <iostream>
#include <mutex>
using namespace std;

extern mutex mtxlog;

void registrarEvento(int jobId, string prioridad, string evento);

#endif