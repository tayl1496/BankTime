
#include <string>
#include <iostream>

#include "EventType.h"
#include "Statistics.h"
#include "Time.h"
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

Event EventBuilder::createArrivalEvent(int number) {
 Event aEvent;
 Time aTime, lengthTime;
 

if (inputFile >> aTime >> lengthTime) {

aEvent.setTime(aTime);
aEvent.setDuration(lengthTime);
aEvent.setNumber(number);

} else {

aEvent.setNumber(0);

}

 if (inputFile.eof()) {
aEvent.setEventType(EventType::NONE);
 } else {
  aEvent.setEventType(EventType::ARRIVAL);
 }

  return aEvent;
}

Event EventBuilder::createDepartureEvent(const Time& currentEventTime,
					 const Time& transactionLength,
					 int number)
{
  Event aEvent;

aEvent.setEventType(EventType::DEPARTURE);
aEvent.setTime(currentEventTime + transactionLength);
aEvent.setNumber(number);

  return aEvent;
}
