#pragma once

#include <vector>
#include "task.h"

using namespace std;

Task* priority_pickNextTask(vector<Task>& tasks, int& index);
void priority_schedule(vector<Task>& tasks);
