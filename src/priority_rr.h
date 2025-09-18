#pragma once

#include <vector>
#include <map>
#include <queue>
#include "task.h"

using namespace std;

Task* priority_rr_pickNextTask(map<int, queue<Task*>>& priority_queues);
void priority_rr_schedule(vector<Task>& tasks, int quantum);
