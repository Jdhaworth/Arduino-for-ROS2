# Arduino for ROS2
 ROS 2 package for communicating directly with arduino over serial. This work is based on https://github.com/Christian-Prather/youtube-serail-tutorial
 
 **Requirements:**
 - Ubuntu 20.04 or Ubuntu 22.04
 - ROS2 Galactic or ROS2 Humble
 - Arduino IDE
 - Arduino MEGA2560 or Arduino UNO (other Arduinos have not been tested)
 ## Instructions
 ### Setup

 Create your workspace and clone the repository into it:
 
 ```mkdir -p <workspace_dir>/src```
 
 ```cd <workspace_dir>/src```
 
 ```git@github.com:Jdhaworth/Arduino-for-ROS2.git```

 Open your Arduino IDE.

 Open your Arduino script. Use the provided example script as a template. The script must be reading for a character serial input, and print a string when finished. 

 Load the script onto the Arduino board.

 In the Arduino IDE, note the port for the Arduino board. Example: The Arduino port might be: "/dev/ttyACM0"

 Build the repository:

 ```colcon build```

 Source the workspace:

 ```source install/setup.bash```

 Note: You may need to change the delay when sending commands over serial. This is likely due to the length of the cable you are using to connect to the Arduino. To address this, increase the delay on line 27 of serial_interface.cpp
 ```std::this_thread::sleep_for(std::chrono::milliseconds(1000));```

 ### Sending commands to Arduino from your node
 See test_node as an example.
 To send commands to the Arduino from another node/package, first make sure the "arduino_com" is listed as a dependecy in your package.xml.

 ```<depend>arduino_com</depend>```
 
 Then make sure "arduino_com" is listed as a dependecy in your and CMakeLists.txt files.

 ```find_package(arduino_com REQUIRED)```
 ```ament_target_dependencies( example_node arduino_com)```
 
 In your cpp file add the line:
 
 ```#include <arduino_com/serial_interface.hpp>``` 
 
 Then wherever you would like to send commands to Arduino, use the function:
 
 ```std::string serial_interface::send_command(std::string port_name, int bot_rate, std::string command_char);```

 Where port_name is the port identified in your Arduino IDE, bot_rate is the bot ratte you set in the arduino script, and command_char is the character you are sending to the Arduino over serial. The Arduino script should be set to print a string when it is finished. This string will then be returned by the send_command function. 

To run the test node, use the command:
```ros2 run test_node test_node```

You can then use the command 'a' to turn on the onboard LED and 'b' to turn it off. All other commands should return "Invalid Command".
