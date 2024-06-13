#include <rclcpp/rclcpp.hpp>
#include <arduino_com/serial_interface.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    while (rclcpp::ok())
    {
        std::cout << "Enter Arduino command: " << std::endl;
        std::string command;
        std::cin >> command;
        if (command == "end")
        {
            rclcpp::shutdown();
            break;
        }

        std::string response;
        response = serial_interface::send_command("/dev/ttyACM0", 2400, command);
        std::cout << "Arduino response: " << response << std::endl;
    }

    rclcpp::shutdown();
    return 0;
}