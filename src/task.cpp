#include <iostream>
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