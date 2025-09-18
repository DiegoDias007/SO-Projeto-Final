#pragma once

#include <vector>
#include "task.h"

using namespace std;

Task* pickNextTask(vector<Task>& tasks, int& index);
void schedule(vector<Task>& tasks);