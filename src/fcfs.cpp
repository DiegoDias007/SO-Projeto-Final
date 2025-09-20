#include <iostream>
#include <vector>
#include "task.h"
#include "cpu.h"
#include "fcfs.h"

using namespace std;

Task* fcfs_pickNextTask(vector<Task>& tasks, int& index) {
    int qtd_tasks = tasks.size();
    if (index < qtd_tasks) {
        return &tasks[index++];
    }
    return nullptr;
}

void fcfs_schedule(vector<Task>& tasks) {
    int index = 0;
    int time_now = 0;
    Task* current_task = nullptr;

    while ((current_task = fcfs_pickNextTask(tasks, index)) != nullptr) {
        run(*current_task, current_task->remaining_burst, time_now);
        print_task(*current_task);
    }
}
