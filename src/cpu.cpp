#include "cpu.h"

// Responsável por executar a task por um quantum de tempo
void run(Task& task, int quantum, int& time_now) {
    // Caso seja a primeira vez que a task é executada, atualizamos o tempo de início
    if (task.start_time == -1) {
        task.start_time = time_now;
    }

    bool task_finished = task.remaining_burst <= quantum;
    if (task_finished) {
        time_now += task.remaining_burst;
        task.remaining_burst = 0;

        // Após a task terminar, calculamos os tempos.
        task.completion_time = time_now;
        task.turnaround_time = task.completion_time - task.arrival_time;
        task.waiting_time = task.turnaround_time - task.burst;
        task.response_time = task.start_time - task.arrival_time;
    } else {
        // Se a task não terminar, executamos o quantum e atualizamos o tempo
        time_now += quantum;
        task.remaining_burst -= quantum;
    }
}