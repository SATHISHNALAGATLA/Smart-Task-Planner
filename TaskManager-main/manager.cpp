#include "manager.h"

Manager::Manager() : nextProcessID(1) {}


void Manager::addProcess(const std::string& name, int type) {
    std::lock_guard<std::mutex> lock(managerMutex);
    std::shared_ptr<Process> process = std::shared_ptr<Process>(new Process(nextProcessID++, name, type));
    process->start();
    processes.push_back(process);
    std::cout << "Started process: " << name << " [ID: " << process->getId() << "]\n";
}

void Manager::stopProcess(int id) {
    std::lock_guard<std::mutex> lock(managerMutex);
    auto it = std::find_if(processes.begin(), processes.end(), [id](const auto& p) {
        return p->getId() == id;
    });
    if (it != processes.end()) {
        (*it)->stop();
        (*it)->join();
        std::cout << "Stopped process with ID: " << id << "\n";
    } else {
        std::cout << "Process with ID " << id << " not found.\n";
    }
}

void Manager::stopAll() {
    std::lock_guard<std::mutex> lock(managerMutex);
    for (auto& process : processes) {
        process->stop();
        process->join();
    }
    std::cout << "All processes stopped.\n";
}

void Manager::listProcesses() const {
    std::lock_guard<std::mutex> lock(managerMutex);
    std::cout << "\nActive Processes:\n";
    std::cout << "ID\tName\t\tCPU%\tRAM(MB)\n";
    for (const auto& process : processes) {
        std::cout << process->getId() << "\t" << process->getName()
                  << "\t" << process->getCpuUsage() << "\t" << process->getRamUsage() << "\n";
    }
    std::cout << std::endl;
}