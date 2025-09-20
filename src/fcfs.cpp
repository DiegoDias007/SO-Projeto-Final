#include <iostream>
#include <vector>
#include "task.h"
#include "cpu.h"
#include "fcfs.h"

using namespace std;

// Retorna a próxima tarefa na ordem do vetor.
Task* fcfs_pickNextTask(vector<Task>& tasks, int& index) {
    int qtd_tasks = tasks.size();
    // Se ainda há tarefas, devolve a próxima; caso contrário, nullptr
    if (index < qtd_tasks) {
        return &tasks[index++];
    }
    return nullptr;
}

void fcfs_schedule(vector<Task>& tasks) {
    int index = 0;
    int time_now = 0;
    Task* current_task = nullptr;

    // Percorre a lista na ordem e executa cada tarefa até não ter mais tarefas
    while ((current_task = fcfs_pickNextTask(tasks, index)) != nullptr) {
        run(*current_task, current_task->remaining_burst, time_now);
        print_task(*current_task);
    }
}
