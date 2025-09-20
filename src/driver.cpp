#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <atomic>
#include "task.h"
#include "driver.h"
#include <sstream>

using namespace std;

// Variável atômica para geração de TIDs
atomic<int> next_tid(1);

// Função responsável por parsear o arquivo e criar o vector de tasks
vector<Task> parse_schedule(string filename) {
    ifstream file(filename);
    vector<Task> tasks;
    
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return tasks;
    }
    
    // Lê cada linha do arquivo e cria uma task para cada linha
    string line;
    while (getline(file, line)) {
        tasks.push_back(parse_task(line));
    }
    
    file.close();
    return tasks;
}

// Função responsável por parsear a linha e criar a task
Task parse_task(string line) {
    Task task;
    stringstream ss(line);
    string token;

    // ID atômico (ignorar o T1, T2, etc. do arquivo)
    task.id = next_tid.fetch_add(1, memory_order_relaxed);
    getline(ss, token, ',');  // Ignora o T1, T2, etc.

    // Prioridade
    getline(ss, token, ',');
    task.priority = stoi(token);

    // Burst
    getline(ss, token, ',');
    task.burst = stoi(token);
    task.remaining_burst = task.burst;

    // Arrival time explícito (todas chegam no tempo 0)
    task.arrival_time = 0;

    // Inicializar outros campos
    task.start_time = -1;
    task.completion_time = -1;
    task.response_time = -1;
    task.turnaround_time = -1;
    task.waiting_time = -1;

    return task;
}