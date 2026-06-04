#include "log.h"
#include <fstream>
#include <mutex>
#include <chrono>

using namespace std;
static mutex espera;

void registrarevento(int jobId,int prioridad, string& evento)
{
    lock_guard<mutex> lock(espera);
    ofstream archivo("sistema.log", ios::app);

    auto ahora = chrono::system_clock::now();
    long long timestamp = chrono::duration_cast<chrono::seconds>(ahora.time_since_epoch()).count();

    archivo << "[" << timestamp << "] - " << jobId << " - " << prioridad << " - " << evento << endl;
    
}