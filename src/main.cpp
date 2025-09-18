#include <iostream>
#include <vector>
#include "task.h"
#include "driver.h"
#include "cpu.h"
#include "sjf.h"

using namespace std;

int main() {
    vector<Task> tasks;
    tasks = parse_schedule("schedule.txt");
    sjf_schedule(tasks);
    show_avg_times(tasks);
    return 0;
}