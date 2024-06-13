cmake_minimum_required(VERSION 3.8)
project(arduino_com LANGUAGES CXX)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#Stuff for serial
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

include_directories( include )
include_directories( serial_com/include )

set(serial_SRCS serial_com/src/serial.cc serial_com/include/serial/serial.h 
    serial_com/include/serial/v8stdint.h serial_com/src/impl/list_ports/list_ports_linux.cc)
list(APPEND serial_SRCS serial_com/src/impl/unix.cc)

add_library( arduino_com src/serial_interface.cpp ${serial_SRCS})
target_link_libraries( arduino_com rt)
ament_target_dependencies( arduino_com rclcpp )

install( DIRECTORY include/ serial_com/include/ DESTINATION include)

install(
  TARGETS arduino_com
  EXPORT export_arduino_com
  LIBRARY DESTINATION lib 
  ARCHIVE DESTINATION lib 
  RUNTIME DESTINATION bin 
  INCLUDES DESTINATION include 
)

ament_export_include_directories(include serial_com/include)
ament_export_targets(export_arduino_com HAS_LIBRARY_TARGET)
ament_export_libraries(arduino_com)
ament_export_dependencies(rclcpp rclcpp_action)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()