#pragma once

#include <sys/types.h>

#include <vector>
#include <string>


extern pid_t start_child_process(std::string path, std::vector<std::string> arguments);

extern void stop_child_process(pid_t pid);