#pragma once

#include <vector>
#include "task.h"

using namespace std;

Task* sjf_pickNextTask(vector<Task>& tasks, int& index);
void sjf_schedule(vector<Task>& tasks);