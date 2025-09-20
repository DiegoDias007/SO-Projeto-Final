#include <iostream>
#include <vector>
#include "task.h"
#include "cpu.h"
#include "sjf.h"
#include <algorithm>

using namespace std;

// Retorna a próxima tarefa na ordem do vetor.
Task* sjf_pickNextTask(vector<Task>& tasks, int& index) {
    int qtd_tasks = tasks.size();
    // Se ainda há tarefas, devolve a próxima; caso contrário, nullptr
    if (index < qtd_tasks) {
        return &tasks[index++];
    }
    return nullptr;
}

void sjf_schedule(vector<Task>& tasks) {
    int index = 0;
    int time_now = 0;
    Task* current_task = nullptr;

    // Ordena as tasks pelo seu burst
    // Tasks com menor burst são executadas primeiro
    sort(tasks.begin(), tasks.end(), [](Task& a, Task& b) {
        return a.burst < b.burst;
    });

    // Percorre a lista na ordem e executa cada tarefa até não ter mais tarefas
    while ((current_task = sjf_pickNextTask(tasks, index)) != nullptr) {
        run(*current_task, current_task->remaining_burst, time_now);
        print_task(*current_task);
    }
}