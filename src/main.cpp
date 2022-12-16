/*
 *  Project:    moba-shutdown
 *
 *  Version:    2.0.0
 *
 *  Copyright (C) 2016 Stefan Paproth <pappi-@gmx.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/agpl.txt>.
 *
 */

#include <unistd.h>
#include <cstdlib>
#include <getopt.h>
#include <config.h>
#include <iostream>
#include <moba-common/helper.h>

#include <wiringPi.h>

namespace {
    moba::AppData appData = {
        PACKAGE_NAME,
        moba::Version{PACKAGE_VERSION},
        __DATE__,
        __TIME__,
        "",
        0
    };

    static const int SHUTDOWN_PORT = 23;
}

void printHelp() {
    std::cout << std::endl;
    std::cout << "-p, --port      default: " << SHUTDOWN_PORT << std::endl;
    std::cout << "-r, --reboot    reboot" << std::endl;
    std::cout << "-h, --help      shows this help" << std::endl;
    std::cout << "-v, --version   shows version-info" << std::endl;
}

int main(int argc, char** argv) {
    static struct option longOptions[] = {
        {"port",      required_argument, 0, 'p'},
        {"reboot",    no_argument,       0, 'r'},
        {"help",      no_argument,       0, 'h'},
        {"version",   no_argument,       0, 'v'},
        {NULL,      0, NULL, 0}
    };

    int optionIndex = 0;
    int port = SHUTDOWN_PORT;

    while (true) {
        int c = getopt_long(argc, argv, "rhv", longOptions, &optionIndex);
        if(c == -1) {
            break;
        }

        switch (c) {
            case 'p':
                port = atoi(optarg);
                break;

            case 'r':
                execl("/sbin/shutdown", "shutdown", "-r", "now", NULL);
                return EXIT_SUCCESS;

            case 'h':
                printHelp();
                return EXIT_SUCCESS;

            case 'v':
                moba::printAppData(appData);
                return EXIT_SUCCESS;
        }
    }
    wiringPiSetup();
    pinMode(port, OUTPUT);

    digitalWrite(port, HIGH);
    sleep(2);
    digitalWrite(port, LOW);
    execl("/sbin/shutdown", "shutdown", "-h", "now", NULL);
}
