#pragma once

#include <vector>
#include "task.h"

using namespace std;

Task* fcfs_pickNextTask(vector<Task>& tasks, int& index);
void fcfs_schedule(vector<Task>& tasks);