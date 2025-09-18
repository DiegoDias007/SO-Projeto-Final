#include <iostream>
#include <vector>
#include "task.h"
#include "driver.h"
#include "cpu.h"
#include "priority.h"
#include "rr.h"
#include "priority_rr.h"

using namespace std;

int main() {
    vector<Task> tasks;
    tasks = parse_schedule("schedule.txt");
    int quantum = 10;
    priority_rr_schedule(tasks, quantum);
    show_avg_times(tasks);
    return 0;
}