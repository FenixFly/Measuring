cmake_minimum_required(VERSION 3.0)

project(MEASURING CXX)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

set(SOURCES
	src/enums.h
	src/point.h
	src/point.cpp 
	src/line.h
	src/line.cpp
	src/angle.h
	src/angle.cpp
	src/scene.h
	src/scene.cpp
	src/drawwidget.h
	src/drawwidget.cpp
	src/toolbar.h
	src/toolbar.cpp
	src/mainwindow.h
	src/mainwindow.cpp
	src/main.cpp)
	
add_executable(Measuring ${SOURCES})

target_link_libraries(Measuring Qt5::Widgets)
