#include <iostream>
#include <vector>
#include <iomanip>
#include "task.h"

using namespace std;

// Bordas e cores para a tabela de tasks
static const char* TASK_ROW_BORDER = "+----+------------+-------+--------+-----------+------------+---------+----------+";
static const char* COLOR_HEADER    = "\033[1;33m"; // Amarelo forte
static const char* COLOR_RESET     = "\033[0m";

void print_task(Task& task) {
    static bool header_printed = false;
    if (!header_printed) {
        cout << "\n" << COLOR_HEADER << TASK_ROW_BORDER << COLOR_RESET << endl;
        cout << COLOR_HEADER
             << "| ID | Prioridade | Burst | Inicio | Termino   | Retorno    | Espera  | Resposta |"
             << COLOR_RESET << endl;
        cout << COLOR_HEADER << TASK_ROW_BORDER << COLOR_RESET << endl;
        header_printed = true;
    }

    cout << "| " << setw(2) << right << task.id
         << " | " << setw(10) << right << task.priority
         << " | " << setw(5) << right << task.burst
         << " | " << setw(6) << right << task.start_time
         << " | " << setw(9) << right << task.completion_time
         << " | " << setw(10) << right << task.turnaround_time
         << " | " << setw(7) << right << task.waiting_time
         << " | " << setw(8) << right << task.response_time
         << " |" << endl;
}

void show_avg_times(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\033[1;31mErro: Nenhuma task para calcular estatisticas!\033[0m" << endl;
        return;
    }

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

    // Separador da tabela de tasks antes do resumo
    cout << TASK_ROW_BORDER << endl;

    // Tabela de estatísticas finais
    static const char* STATS_BORDER = "+---------------------------+---------------+";
    cout << "\n\033[1;36mResumo de Desempenho\033[0m" << endl;
    cout << STATS_BORDER << endl;
    cout << "| Metrica                   | Media (ms)    |" << endl;
    cout << STATS_BORDER << endl;
    cout << fixed << setprecision(2);
    cout << "| Tempo de Retorno          | " << setw(13) << right << avg_turnaround << " |" << endl;
    cout << "| Tempo de Espera           | " << setw(13) << right << avg_waiting << " |" << endl;
    cout << "| Tempo de Resposta         | " << setw(13) << right << avg_response << " |" << endl;
    cout << STATS_BORDER << endl;
}