#pragma once

#include <string>
#include <vector>
#include "task.h"

using namespace std;

vector<Task> parse_schedule(string filename);
Task parse_task(std::string line);