#ifndef MESSAGE_QUEUE_H_INCLUDED
#define MESSAGE_QUEUE_H_INCLUDED  
#include <mutex>
#include <queue>
using namespace std;

#include <iostream>
#include <mutex>
#include <queue>
#include <vector>
#include <chrono>
#include <thread>
#include "job.h"

struct MessageQueue{
    mutex mtx; 
    spriority_queue<Job, vector<Job>, bool(*)(const Job&, const Job&)> jobQueue{compararJobs};
};

bool compararJobs(const Job& job1, const Job& job2);
void addJob(MessageQueue& messageQueue, Job& job);
Job getJob(MessageQueue& messageQueue);

#endif // MESSAGE_QUEUE_H_INCLUDED
