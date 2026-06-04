#include "log.h"
#include <fstream>
#include <mutex>
#include <chrono>

extern chrono::high_resolution_clock::time_point inicio;

using namespace std;
static mutex espera;

void registrarevento(int jobId,int prioridad, string evento)
{
    lock_guard<mutex> lock(espera);
    ofstream archivo("sistema.log", ios::app);

    auto ahora = chrono::high_resolution_clock::now();
    long long timestamp = chrono::duration_cast<chrono::milliseconds>(ahora - inicio).count();
    archivo << "[" << timestamp << "] - " << jobId << " - " << prioridad << " - " << evento << endl;
   cout << "[" << timestamp << "] - " << jobId << " - " << prioridad << " - " << evento << endl;
}