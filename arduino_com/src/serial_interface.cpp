#include <arduino_com/serial_interface.hpp>

namespace serial_interface
{

    std::string send_command(std::string port_name, int bot_rate, std::string command_char)
    {

        serial::Serial my_serial(port_name, bot_rate, serial::Timeout::simpleTimeout(2000));

        if (my_serial.isOpen())
        {
            std::cout << "Port opened successfully" << std::endl;
        }
        else
        {
            std::cout << "Port failed to open" << std::endl;
            exit(1);
        }

        // Clear the input and output serial channels before beginning
        my_serial.flushOutput();
        my_serial.flushInput();

        // Write command to serial
        std::string command_string = command_char + "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        size_t bytesWritten = my_serial.write(command_string);

        // Wait for response from serial
        std::string response = "";
        do
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            response = my_serial.read(100); //May need to increase the number of characters for your application

        } while (response == "");

        my_serial.close();

        return response;
    }

}
