SmartTaskManager
- The project is currently in the planning phase, so its goals and features may (90%) change. This is a preliminary version of the README.
- Intelligent Task Manager in C++ with Anomaly Detection

Project Description:
SmartTaskManager is a console-based application written in C++20 that simulates the behavior of an operating system task manager. Each process runs as a separate thread, generating artificial CPU and RAM load. The system analyzes this data in real time and detects anomalies in process behavior.

The project aims to practice:
* Concurrent programming (**threads, synchronization**)
* Memory management (**pointers, smart pointers**)
* Real-time data processing
* Basic artificial intelligence (**heuristics, outlier detection**)

Technologies to Be Used:
* C++20
* Multithreading: `std::thread`, `std::jthread`, `std::mutex`, `std::condition_variable`
* Smart Pointers: `std::unique_ptr`, `std::shared_ptr`
* Anomaly Detection: simple heuristic or rule-based system (with the possibility to extend using AI)
* Optional: Python (for ML model integration)
* Compiler: `g++` / `clang++` / `MSVC`
* Build System: CMake

Features:
* Simulation of multiple processes as independent threads
* Dynamic CPU and RAM usage simulation
* Logging of per-process metrics (rolling window)
* Anomaly detection (e.g., sudden CPU spikes, excessive RAM consumption)
* Automatic response to anomalies (e.g., mark or terminate process)
* Integration with machine learning for anomaly detection
* Simple terminal-based user interface

👨‍💻 Author
Project developed by Nalagatla Sathish
For personal learning and development purposes 🎓

