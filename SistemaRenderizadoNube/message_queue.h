#ifndef MESSAGE_QUEUE_H_INCLUDED
#define MESSAGE_QUEUE_H_INCLUDED  

#include <iostream>
#include <mutex>
#include <queue>
#include <vector>
#include <chrono>
#include <thread>
#include "job.h"
using namespace std;

bool compararJobs(const Job& job1, const Job& job2);

struct MessageQueue{
    mutex mtx; 
    priority_queue<Job, vector<Job>, bool(*)(const Job&, const Job&)> jobQueue{compararJobs};
};

void addJob(MessageQueue& messageQueue, Job& job);
Job getJob(MessageQueue& messageQueue);

#endif // MESSAGE_QUEUE_H_INCLUDED


