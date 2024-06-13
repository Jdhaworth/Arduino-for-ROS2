# Arduino Communication
 ROS 2 package for communicating directly with arduino over serial. This work is based on https://github.com/Christian-Prather/youtube-serail-tutorial
 
 **Requirements:**
 - Ubuntu 20.04, Ubuntu 22.04
 - ROS2 Galactic, ROS2 Humble
 - Arduino IDE
 ## Instructions
 ### Setup

 Create your workspace and clone the repository into it:
 
 ```mkdir -p <workspace_dir>/src```
 
 ```cd <workspace_dir>/src```
 
 ```git clone git@github.com:MRE-Lab-UMD/arduino_com.git```

 Open your Arduino IDE.

 Open your Arduino script. Use the provided example script as a template. The script must be reading for a character serial input, and return a string when finished. 

 Load the script onto the Arduino board.

 In the Arduino IDE, note the port for the Arduino board. Example: The Arduino port might be: "/dev/ttyACM0"

 Build the repository:

 ```colcon build```

 Source the workspace:

 ```source install/setup.bash```

 Note: You may need to change the delay when sending commands over serial. This is likely due to the length of the cable you are using to connect to the Arduino. To address this, increase the delay on line 27 of serial_interface.cpp
 ```std::this_thread::sleep_for(std::chrono::milliseconds(1000));```

 ### Sending commands to arduino from your node
 To send commands to the Arduino from another node/package, first make sure the "arduino_com" is listed as a dependecy in your package.xml.

 ```<depend>arduino_com</depend>```
 
 Then make sure "arduino_com" is listed as a dependecy in your and CMakeLists.txt files.

 ```find_package(arduino_com REQUIRED)```
 ```ament_target_dependencies( example_node arduino_com)```
 
 In your cpp file add the line:
 
 ```#include <arduino_com/serial_interface.hpp>``` 
 
 Then wherever you would like to send commands to Arduino, use the function:
 
 ```std::string serial_interface::send_command(std::string port_name, int bot_rate, std::string command_char);```

 Where port_name is the port identified in your Arduino IDE, bot_rate is your bot rate, and command_char is the character you are sending to the Arduion over serial. 
