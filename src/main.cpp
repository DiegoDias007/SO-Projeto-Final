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
    // Verifica se foi passado um algoritmo
    if (argc < 2) {
        cout << "\033[1;31mErro: Nenhum algoritmo especificado!\033[0m" << endl;
        cout << "\nUso: ./scheduler <algoritmo>" << endl;
        cout << "Algoritmos disponiveis: fcfs, sjf, rr, priority, priority_rr" << endl;
        return 1;
    }

    // Pega o algoritmo passado como argumento
    string algorithm = argv[1];
    string schedule_file = "schedule.txt";
    
    // Pega as tasks do arquivo de entrada
    vector<Task> tasks;
    tasks = parse_schedule(schedule_file);
    
    if (tasks.empty()) {
        cout << "Error: No tasks found in " << schedule_file << "!" << endl;
        return 1;
    }
    
    int quantum = 15;
    
    // Banner de abertura estilizado
    cout << "\n\033[1;34m========================================\033[0m" << endl;
    cout << "\033[1;34m     Simulador de Escalonamento CPU     \033[0m" << endl;
    cout << "\033[1;34m========================================\033[0m" << endl;
    cout << "Algoritmo: \033[1m" << algorithm << "\033[0m" << endl;
    cout << "Arquivo de entrada: " << schedule_file << endl;
    cout << "Tarefas: " << tasks.size() << endl;
    cout << "Quantum: " << quantum << " ms" << endl;
    cout << "\033[1;34m----------------------------------------\033[0m\n" << endl;
    
    // Executa o algoritmo passado como argumento
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
        cout << "\033[1;31mErro: Algoritmo desconhecido '" << algorithm << "'\033[0m" << endl;
        cout << "Algoritmos disponiveis: fcfs, sjf, rr, priority, priority_rr" << endl;
        return 1;
    }
    
    // Mostra as estatísticas finais
    show_avg_times(tasks);
    return 0;
}