// response_time = start_time - arrival_time
// turnaround_time = completion_time - arrival_time
// waiting_time = turnaround_time - burst

#pragma once

struct Task {
    int id;
    int priority;
    int burst;
    int remaining_burst;
    
    
    int arrival_time = 0; // Sempre será 0, adicionado para facilitar legibilidade
    int start_time = -1;
    int completion_time = -1;
    
    // response_time = start_time - arrival_time
    // turnaround_time = completion_time - arrival_time
    // waiting_time = turnaround_time - burst
    int response_time = -1;
    int turnaround_time = -1;
    int waiting_time = -1;
};

void print_task(Task task);