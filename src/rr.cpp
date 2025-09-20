#include <iostream>
#include <vector>
#include <queue>
#include "task.h"
#include "cpu.h"
#include "rr.h"

using namespace std;

Task* rr_pickNextTask(queue<Task*>& ready_queue) {
    // Se a fila de prontos está vazia, retorna nullptr
    if (ready_queue.empty()) {
        return nullptr;
    }
    
    // Retorna a tarefa no topo da fila de prontos
    Task* current_task = ready_queue.front();
    ready_queue.pop();
    return current_task;
}

void rr_schedule(vector<Task>& tasks, int quantum) {
    int time_now = 0;
    queue<Task*> ready_queue;
    Task* current_task = nullptr;
    
    // Inicializa a fila de prontos com todas as tasks
    for (Task& task : tasks) {
        ready_queue.push(&task);
    }
    
    // Executa em round robin até a fila ficar vazia
    while ((current_task = rr_pickNextTask(ready_queue)) != nullptr) {
        // Executa a task pelo quantum ou pelo seu remaining_burst (o que for menor)
        int time_to_run = min(quantum, current_task->remaining_burst);
        run(*current_task, time_to_run, time_now);
        
        // Se a task não terminou, coloca ela de volta no final da fila
        if (current_task->remaining_burst > 0) {
            ready_queue.push(current_task);
        } else {
            // Se a task terminou, imprime informações
            print_task(*current_task);
        }
    }
}
