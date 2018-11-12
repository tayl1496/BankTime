project(Proj_Name)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

add_executable(oneteller
  project6.cpp
  Event.cpp
  EventBuilder.cpp
  Statistics.cpp
  Simulation.cpp)
