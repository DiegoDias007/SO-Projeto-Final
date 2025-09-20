#include <iostream>
#include <vector>
#include "task.h"
#include "cpu.h"
#include "priority.h"
#include <algorithm>

using namespace std;

// Retorna a próxima tarefa na ordem do vetor.
Task* priority_pickNextTask(vector<Task>& tasks, int& index) {
    int qtd_tasks = tasks.size();
    // Se ainda há tarefas, devolve a próxima; caso contrário, nullptr
    if (index < qtd_tasks) {
        return &tasks[index++];
    }
    return nullptr;
}

void priority_schedule(vector<Task>& tasks) {
    int index = 0;
    int time_now = 0;
    Task* current_task = nullptr;

    // Ordena as tasks pela sua prioridade
    // Tasks com menor número de prioridade são executadas primeiro
    // OBS: Também seria possível ordenar por maior número de prioridade
    sort(tasks.begin(), tasks.end(), [](Task& a, Task& b) {
        return a.priority < b.priority;
    });

    // Percorre a lista na ordem e executa cada tarefa até não ter mais tarefas
    while ((current_task = priority_pickNextTask(tasks, index)) != nullptr) {
        run(*current_task, current_task->remaining_burst, time_now);
        print_task(*current_task);
    }
}
