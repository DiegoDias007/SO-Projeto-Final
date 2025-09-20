#include <iostream>
#include <vector>
#include <iomanip>
#include "task.h"

using namespace std;

void print_task(Task& task) {
    cout << "--------------------------------" << endl;
    cout << "Task ID: " << task.id << endl;
    cout << "Priority: " << task.priority << endl;
    cout << "Burst: " << task.burst << " ms" << endl;
    cout << "Remaining Burst: " << task.remaining_burst << " ms" << endl;
    cout << "Arrival Time: " << task.arrival_time << " ms" << endl;
    cout << "Start Time: " << task.start_time << " ms" << endl;
    cout << "Completion Time: " << task.completion_time << " ms" << endl;
    cout << "Turnaround Time: " << task.turnaround_time << " ms" << endl;
    cout << "Waiting Time: " << task.waiting_time << " ms" << endl;
    cout << "Response Time: " << task.response_time << " ms" << endl;
    cout << "--------------------------------" << endl;
}

void show_avg_times(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Error: No tasks to calculate statistics!" << endl;
        return;
    }
    
    double avg_turnaround = 0;
    double avg_waiting = 0;
    double avg_response = 0;
    
    for (Task& task : tasks) {
        avg_turnaround += task.turnaround_time;
        avg_waiting += task.waiting_time;
        avg_response += task.response_time;
    }

    avg_turnaround /= tasks.size();
    avg_waiting /= tasks.size();
    avg_response /= tasks.size();

    cout << "\n========================================" << endl;
    cout << "          FINAL STATISTICS" << endl;
    cout << "========================================" << endl;
    cout << fixed << setprecision(2);
    cout << "Average Turnaround Time: " << avg_turnaround << " ms" << endl;
    cout << "Average Waiting Time: " << avg_waiting << " ms" << endl;
    cout << "Average Response Time: " << avg_response << " ms" << endl;
    cout << "========================================" << endl;
}