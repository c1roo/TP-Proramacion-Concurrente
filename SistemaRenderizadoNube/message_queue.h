#ifndef MESSAGE_QUEUE_H_INCLUDED
#define MESSAGE_QUEUE_H_INCLUDED  
#include <mutex>
#include <queue>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <condition_variable>
#include "job.h"
using namespace std;

bool compararJobs(const Job& job1, const Job& job2);

struct MessageQueue{
    mutex mtx;
    condition_variable cv; 
    priority_queue<Job, vector<Job>, bool(*)(const Job&, const Job&)> jobQueue{compararJobs};
};

void addJob(MessageQueue& messageQueue, Job& job);
Job getJob(MessageQueue& messageQueue);

#endif // MESSAGE_QUEUE_H_INCLUDED
