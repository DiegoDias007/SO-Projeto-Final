#include <iostream>
#include <vector>
#include <string>
#include "task.h"
#include "driver.h"
#include "cpu.h"
#include "priority.h"
#include "rr.h"
#include "priority_rr.h"
#include "fcfs.h"
#include "sjf.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Error: No algorithm specified!" << endl;
        cout << "Usage: ./scheduler <algorithm>" << endl;
        cout << "Available algorithms: fcfs, sjf, rr, priority, priority_rr" << endl;
        return 1;
    }

    string algorithm = argv[1];
    string schedule_file = "schedule.txt";
    
    vector<Task> tasks;
    tasks = parse_schedule(schedule_file);
    
    if (tasks.empty()) {
        cout << "Error: No tasks found in " << schedule_file << "!" << endl;
        return 1;
    }
    
    int quantum = 15;
    
    cout << "========================================" << endl;
    cout << "Executing " << algorithm << " algorithm" << endl;
    cout << "Input file: " << schedule_file << endl;
    cout << "Number of tasks: " << tasks.size() << endl;
    cout << "Time quantum: " << quantum << " ms" << endl;
    cout << "========================================" << endl;
    
    if (algorithm == "fcfs") {
        fcfs_schedule(tasks);
    } else if (algorithm == "sjf") {
        sjf_schedule(tasks);
    } else if (algorithm == "rr") {
        rr_schedule(tasks, quantum);
    } else if (algorithm == "priority") {
        priority_schedule(tasks);
    } else if (algorithm == "priority_rr") {
        priority_rr_schedule(tasks, quantum);
    } else {
        cout << "Error: Unknown algorithm '" << algorithm << "'" << endl;
        cout << "Available algorithms: fcfs, sjf, rr, priority, priority_rr" << endl;
        return 1;
    }
    
    show_avg_times(tasks);
    return 0;
}