#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H
#include "serial_com/include/serial/serial.h"
#include <iostream>
#include "thread"

namespace serial_interface{

    std::string send_command(std::string port_name, int bot_rate, std::string command_char);

}

#endif