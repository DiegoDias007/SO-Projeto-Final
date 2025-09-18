#pragma once

#include <vector>
#include <queue>
#include "task.h"

using namespace std;

Task* rr_pickNextTask(queue<Task*>& ready_queue);
void rr_schedule(vector<Task>& tasks, int quantum);