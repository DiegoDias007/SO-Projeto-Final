#include <iostream>
#include <vector>
#include "task.h"
#include "driver.h"
#include "cpu.h"

using namespace std;

int main() {
    vector<Task> tasks;
    tasks = parse_schedule("schedule.txt");
    for (Task task : tasks) {
        print_task(task);
    }

    Task exemplo = tasks[0];
    print_task(exemplo);
    int time_now = 0;
    run(exemplo, 30, time_now);
    print_task(exemplo);
    return 0;
}