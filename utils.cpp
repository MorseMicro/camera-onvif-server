// Copyright 2023 Morse Micro
// SPDX-License-Identifier: GPL-2.0-or-later

#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <unistd.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"


pid_t start_child_process(std::string path, std::vector<std::string> arguments) {
	const char *executable_path = path.c_str();
	std::vector<const char *> argv;
	std::transform(arguments.begin(), arguments.end(), std::back_inserter(argv),
		[] (std::string &arg) { return arg.c_str(); });
	argv.push_back(NULL);

	pid_t parent_pid = getpid();
	pid_t pid = fork();

	if (pid == -1) {
		throw new std::runtime_error("Unable to fork to start RTSP server");
	} else if (pid == 0) {
		if (-1 == prctl(PR_SET_PDEATHSIG, SIGTERM)) {
			std::cerr << "Failed to prctl(PR_SET_PDEATHSIG) for rtsp server: " << strerror(errno) << std::endl;
			exit(1);
		}
		if (getppid() != parent_pid) { // In case parent already exited...
			exit(1);
		}
		// Ok, I casted away the constness, but we're about to exec so I'm ok with that.
		if (-1 == execv(executable_path, const_cast<char *const*>(argv.data()))) {
			std::cerr << "Failed to start rtsp server at " << executable_path << ": " << strerror(errno) << std::endl;
			exit(1);
		};
	}

	return pid;
}

void stop_child_process(pid_t pid) {
	// This is ugly, but without pidfd_open I don't think there's an elegant way.
	// https://stackoverflow.com/questions/282176/waitpid-equivalent-with-timeout

	if (-1 == kill(pid, SIGTERM)) {
		if (errno == ESRCH) {
			return;
		} else {
			throw new std::runtime_error("Unable to SIGTERM RTSP server");
		}
	}
	sleep(1);
	kill(pid, SIGKILL);
	int wstatus;
	waitpid(pid, &wstatus, 0);
}