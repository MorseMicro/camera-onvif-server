/*
 * Copyright 2023 Morse Micro
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#include <unistd.h>

extern pid_t spawn_wsdd_server(const char *listen_ip, const char *service_uri);
