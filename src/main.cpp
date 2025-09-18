#include <iostream>
#include <vector>
#include "task.h"
#include "driver.h"
#include "cpu.h"
#include "fcfs.h"
#include "task.h"

using namespace std;

int main() {
    vector<Task> tasks;
    tasks = parse_schedule("schedule.txt");
    schedule(tasks);
    show_avg_times(tasks);
    return 0;
}