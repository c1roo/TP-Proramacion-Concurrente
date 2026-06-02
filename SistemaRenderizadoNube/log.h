#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

#include <fstream>
#include <iostream>
#include <mutex>

using namespace std;

static mutex espera;

void registrarevento(int jobId, string prioridad, string evento, string timestamp()){
        lock_guard<mutex> lock(espera);

        ofstream archivo("Sistema.log", ios::app);

        archivo << "[" << timestamp << "] - "<< jobId << " - " << prioridad << " - " << evento << endl;
}

#endif 
