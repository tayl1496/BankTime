
#include <iostream>
#include <string>

#include "Time.h"
#include "EventType.h"
#include "Event.h"
#include "EventBuilder.h"

EventBuilder::EventBuilder(){
  std::string s = "";

  do {
    std::cout<<"Enter File Name: ";
    std::cin>>s;

    inputFile.open(s.c_str() );

    if (!inputFile){
      std::cerr<<"ERROR: File Not Found" <<std::endl;
    }

  } while (!inputFile);
}

Event EventBuilder::createArrivalEvent(const int number, const int LineNum){
Event aEvent;
 aEvent.setType(EventType::ARRIVAL);
 
Time aTime, lengthTime;

if (inputFile >> aTime >> lengthTime) {
  aEvent.setTime(aTime);
  aEvent.setDuration(lengthTime);
  aEvent.setNumber(number);
  aEvent.setLine(LineNum);
} else {
  aEvent.setNumber(0);
}

if (inputFile.eof()) {
  aEvent.setType(EventType::NONE);
}
return aEvent;
}

Event EventBuilder::createDepartureEvent(const Time& currentEventTime,
					 const Time& transactionLength,
					 const int number,
					 const int LineNum)
{
  Event aEvent;

 aEvent.setType(EventType::DEPARTURE);
 aEvent.setTime(currentEventTime + transactionLength);
 aEvent.setNumber(number);
 aEvent.setLine(LineNum);

 return aEvent;
}
