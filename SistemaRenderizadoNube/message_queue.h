#ifndef MESSAGE_QUEUE_H_INCLUDED
#define MESSAGE_QUEUE_H_INCLUDED  

#include <iostream>
#include <mutex>
#include <queue>
#include <vector>
#include <chrono>
#include <thread>
#include "job.h"

bool compararJobs(const Job& job1, const Job& job2);

struct MessageQueue{
    std::mutex mtx; 
    std::priority_queue<Job, std::vector<Job>, bool(*)(const Job&, const Job&)> jobQueue{compararJobs};
};

void addJob(MessageQueue& messageQueue, Job& job);
Job getJob(MessageQueue& messageQueue);

#endif // MESSAGE_QUEUE_H_INCLUDED


