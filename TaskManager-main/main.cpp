#include <iostream>
#include <memory>
#include <thread>
#include "process.h"
#include "manager.h"



int main() {
    Manager manager;

    std::cout << "=== SmartTaskManager ===" << std::endl;

    // Dodajemy kilka procesów
    manager.addProcess("NormalProcess1", 1);     // zwykły proces
    manager.addProcess("NormalProcess2", 1);     // drugi zwykły
    manager.addProcess("AnomalyProcess", 2);     // anomalia (na razie puste)

    // Czekamy 5 sekund – niech procesy coś „pożyją”
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Listujemy procesy i ich aktualne zużycie
    manager.listProcesses();

    // Czekamy jeszcze trochę
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Zatrzymujemy wszystkie procesy
    manager.stopAll();

    std::cout << "=== All processes stopped ===" << std::endl;
    return 0;
}

