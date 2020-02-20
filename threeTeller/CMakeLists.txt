project(Three-Teller)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

add_executable(threeTeller
  project6.cpp
  Simulation.cpp
  Event.cpp
  Statistics.cpp
  PrecondViolatedExcep.cpp
  EventBuilder.cpp)
