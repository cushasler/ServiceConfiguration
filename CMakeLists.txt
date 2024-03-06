cmake_minimum_required(VERSION 3.10)

# Set some basic project attributes
project (ServiceTool
	VERSION 0.2
	DESCRIPTION "A Service Tool Project")

# This project will output an executable file
add_executable(${PROJECT_NAME} ServiceTool.cpp Configuration.cpp 
                               Configuration_impl.cpp BuildTeloc.cpp 
                               Compare.cpp Util.cpp Debug.cpp)

# Create a simple configuration header
configure_file(config.h.in config.h)

# Include the configuration header in the build
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")
include_directories(/home/kali/libxl-4.2.0/include_cpp/)
include_directories(/home/kali/eclipse-workspace/ServiceTool/include/)
target_link_libraries(ServiceTool /home/kali/libxl-4.2.0/lib64/libxl.so)
set(CMAKE_BUILD_TYPE Debug)
