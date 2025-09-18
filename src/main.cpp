#include <iostream>
#include <vector>
#include "task.h"
#include "driver.h"

using namespace std;

int main() {
    vector<Task> tasks;
    tasks = parse_schedule("schedule.txt");
    for (Task task : tasks) {
        print_task(task);
    }
    return 0;
}