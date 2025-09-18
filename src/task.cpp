#include <iostream>
#include <vector>
#include "task.h"

using namespace std;

void print_task(Task& task) {
    cout << "--------------------------------" << endl;
    cout << "ID da Tarefa: " << task.id << endl;
    cout << "Prioridade: " << task.priority << endl;
    cout << "Burst: " << task.burst << endl;
    cout << "Burst Restante: " << task.remaining_burst << endl;
    cout << "Tempo de Chegada: " << task.arrival_time << endl;
    cout << "Tempo de Inicio: " << task.start_time << endl;
    cout << "Tempo de Conclusao: " << task.completion_time << endl;
    cout << "Tempo de Retorno: " << task.turnaround_time << endl;
    cout << "Tempo de Espera: " << task.waiting_time << endl;
    cout << "Tempo de Resposta: " << task.response_time << endl;
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
    cout << "Tempo Medio de Retorno: " << avg_turnaround << endl;
    cout << "Tempo Medio de Espera: " << avg_waiting << endl;
    cout << "Tempo Medio de Resposta: " << avg_response << endl;
    cout << "--------------------------------" << endl;
}