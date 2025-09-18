#include <iostream>
#include <vector>
#include <string>
#include "task.h"
#include "driver.h"
#include "cpu.h"
#include "priority.h"
#include "rr.h"
#include "priority_rr.h"
#include "fcfs.h"
#include "sjf.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Erro: Nenhum algoritmo informado!" << endl;
        cout << "Uso: ./programa <algoritmo>" << endl;
        cout << "Algoritmos disponiveis: fcfs, sjf, rr, priority, priority_rr" << endl;
        return 1;
    }

    string algorithm = argv[1];
    string schedule_file = "schedule.txt";
    
    vector<Task> tasks;
    tasks = parse_schedule(schedule_file);
    
    if (tasks.empty()) {
        cout << "Erro: Nenhuma tarefa encontrada em schedule.txt!" << endl;
        return 1;
    }
    
    int quantum = 10;
    
    cout << "Executando algoritmo " << algorithm << " com schedule.txt" << endl;
    cout << "========================================" << endl;
    
    if (algorithm == "fcfs") {
        fcfs_schedule(tasks);
    } else if (algorithm == "sjf") {
        sjf_schedule(tasks);
    } else if (algorithm == "rr") {
        rr_schedule(tasks, quantum);
    } else if (algorithm == "priority") {
        priority_schedule(tasks);
    } else if (algorithm == "priority_rr") {
        priority_rr_schedule(tasks, quantum);
    } else {
        cout << "Erro: Algoritmo desconhecido '" << algorithm << "'" << endl;
        cout << "Algoritmos disponiveis: fcfs, sjf, rr, priority, priority_rr" << endl;
        return 1;
    }
    
    cout << "========================================" << endl;
    show_avg_times(tasks);
    return 0;
}