/*
    Arquivo responsável pela lógica de ler o arquivo de entrada
    e guardar um vector de tasks.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "task.h"
#include "parser.h"
#include <sstream>

using namespace std;

// Função responsável por parsear o arquivo e criar o vector de tasks
vector<Task> parse_schedule(string filename) {
    ifstream file(filename);
    vector<Task> tasks;
    
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return tasks;
    }
    
    string line;
    while (getline(file, line)) {
        tasks.push_back(parse_task(line));
    }
    return tasks;
}

// Função responsável por parsear a linha e criar a task
Task parse_task(string line) {
    Task task;
    stringstream ss(line);
    string token;
    getline(ss, token, ',');
    task.id = stoi(token.substr(1));
    getline(ss, token, ',');
    task.priority = stoi(token);
    getline(ss, token, ',');
    task.burst = stoi(token);
    task.remaining_burst = task.burst;
    return task;
}