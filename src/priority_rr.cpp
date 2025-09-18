#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "task.h"
#include "cpu.h"
#include "priority_rr.h"

using namespace std;

Task* priority_rr_pickNextTask(map<int, queue<Task*>>& priority_queues) {
    // Procura pela fila de maior prioridade (menor número) que tenha tasks
    for (auto& priority_pair : priority_queues) {
        queue<Task*>& ready_queue = priority_pair.second;
        
        if (!ready_queue.empty()) {
            Task* current_task = ready_queue.front();
            ready_queue.pop();
            return current_task;
        }
    }
    
    return nullptr;
}

void priority_rr_schedule(vector<Task>& tasks, int quantum) {
    int time_now = 0;
    map<int, queue<Task*>> priority_queues;
    Task* current_task = nullptr;
    
    // Inicializa as filas de prioridade com todas as tasks
    for (Task& task : tasks) {
        priority_queues[task.priority].push(&task);
    }
    
    // Executa em priority round-robin até todas as filas ficarem vazias
    while ((current_task = priority_rr_pickNextTask(priority_queues)) != nullptr) {
        // Executa a task pelo quantum ou pelo seu remaining_burst (o que for menor)
        int time_to_run = min(quantum, current_task->remaining_burst);
        run(*current_task, time_to_run, time_now);
        
        // Se a task não terminou, coloca ela de volta no final da sua fila de prioridade
        if (current_task->remaining_burst > 0) {
            priority_queues[current_task->priority].push(current_task);
        } else {
            // Se a task terminou, imprime informações
            print_task(*current_task);
        }
    }
}
