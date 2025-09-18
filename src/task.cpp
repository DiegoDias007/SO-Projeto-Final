#include <iostream>
#include <vector>
#include "task.h"

using namespace std;

void print_task(Task task) {
    cout << "--------------------------------" << endl;
    cout << "Task ID: " << task.id << endl;
    cout << "Priority: " << task.priority << endl;
    cout << "Burst: " << task.burst << endl;
    cout << "Remaining Burst: " << task.remaining_burst << endl;
    cout << "Arrival Time: " << task.arrival_time << endl;
    cout << "Start Time: " << task.start_time << endl;
    cout << "Completion Time: " << task.completion_time << endl;
    cout << "Response Time: " << task.response_time << endl;
    cout << "Turnaround Time: " << task.turnaround_time << endl;
    cout << "Waiting Time: " << task.waiting_time << endl;
    cout << "--------------------------------" << endl;
}

void show_avg_times(vector<Task>& tasks) {
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

    cout << "--------------------------------" << endl;
    cout << "Average Turnaround Time: " << avg_turnaround << endl;
    cout << "Average Waiting Time: " << avg_waiting << endl;
    cout << "Average Response Time: " << avg_response << endl;
    cout << "--------------------------------" << endl;
}