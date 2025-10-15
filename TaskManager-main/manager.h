#ifndef TASKMENAGER_MANAGER_H
#define TASKMENAGER_MANAGER_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
#include "process.h"
#include <mutex>


class Manager {
public:
    Manager();
    void addProcess( const std::string& name, int type);
    void stopProcess(int id);
    void stopAll();
    void listProcesses() const;

private:
    std::vector<std::shared_ptr<Process>> processes;
    mutable std::mutex managerMutex;
    int nextProcessID;
};


#endif //TASKMENAGER_MANAGER_H
