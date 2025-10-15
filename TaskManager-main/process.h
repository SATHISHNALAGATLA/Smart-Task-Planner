#ifndef TASKMENAGER_PROCESS_H
#define TASKMENAGER_PROCESS_H

#include <utility>
#include <random>
#include <iostream>
#include <string>
#include <atomic>
#include <thread>
#include <mutex>

class Process {

public:
    Process(int id, std::string  name, int type);
    ~Process();

    void start();
    void stop();
    void run();
    void join();


    double getCpuUsage() const;
    double getRamUsage() const;
    int getId() const;
    std::string getName() const;

private:
    int id;
    int type;
    std::string name;
    std::atomic<bool> running;
    std::thread worker;
    double cpuUsage;
    double ramUsage;
    std::chrono::time_point<std::chrono::steady_clock> startTime;

};


#endif //TASKMENAGER_PROCESS_H
