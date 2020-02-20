
#include <iostream>

#include "Simulation.h"
#include "Statistics.h"
#include "EventBuilder.h"
#include "Event.h"
#include "PriorityQueue.h"
#include "Time.h"
#include "EventType.h"

Simulation::Simulation() {}

void Simulation::processArrival() {

  int leg1 = line1.getLength();
  int leg2 = line2.getLength();
  int leg3 = line3.getLength();
  int min;

  if (leg1 < leg2 && leg1 < leg3)
    min = leg1;
  else if (leg2 < leg3)
    min = leg2;
  else
    min = leg3;
  
  if (min == leg1) {
    currentEvent.setLine(1);
  } else if (min == leg2) {
    currentEvent.setLine(2);
  } else {
    currentEvent.setLine(3);
  }
  
  if (currentEvent.getLine() == 1) {
    events.dequeue();
   if(line1.isEmpty()) {
    events.enqueue(eventBuilder.createDepartureEvent
		   (currentEvent.getTime(),
		    currentEvent.getDuration(),
		    currentEvent.getNumber(), 1));
   }
   line1.enqueue(currentEvent);
   events.dequeue();
  } else if (currentEvent.getLine() == 2) {
    events.dequeue();
     if(line2.isEmpty()) {
    events.enqueue(eventBuilder.createDepartureEvent
		   (currentEvent.getTime(),
		    currentEvent.getDuration(),
		    currentEvent.getNumber(), 2));
  }
  line2.enqueue(currentEvent);
  } else {
    events.dequeue();
     if(line3.isEmpty()) {
    events.enqueue(eventBuilder.createDepartureEvent
		   (currentEvent.getTime(),
		    currentEvent.getDuration(),
		    currentEvent.getNumber(), 3));
  }
     line3.enqueue(currentEvent);
  }

  Event newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber() + 1, currentEvent.getLine());

  if (newEvent.getType() == EventType::ARRIVAL) {
    events.enqueue(newEvent);
  } 
}

void Simulation::processDeparture() {
  Event aEvent = events.peekFront();
  events.dequeue();
  
  switch ( (int)aEvent.getLine() ) {
  case 1:
    
    line1.dequeue();
    if (!line1.isEmpty() ) {
    Event DEvent1 = eventBuilder.createDepartureEvent(currentEvent.getTime(),
						     aEvent.getDuration(),
						      currentEvent.getNumber() + 1, 1);
    events.enqueue(DEvent1);
    }
    break;
  case 2:
    line2.dequeue();
    if (!line2.isEmpty() ) {
      Event DEvent2 = eventBuilder.createDepartureEvent(currentEvent.getTime(),
							aEvent.getDuration(),
							currentEvent.getNumber() + 1,
							2);
    events.enqueue(DEvent2);
    }
    break;
  case 3:
    line3.dequeue();
    if (!line3.isEmpty() ) {
      Event DEvent3 = eventBuilder.createDepartureEvent(currentEvent.getTime(),
							aEvent.getDuration(),
							currentEvent.getNumber() + 1,
							3);
    events.enqueue(DEvent3);
    }
    break;
  default:
    std::cout<<"This Line doesn't EXIST!!";
    break;
  }	     
}

void Simulation::simulate() {
  Event initialArrival = eventBuilder.createArrivalEvent(1,1);

  if (initialArrival.getType() == EventType::ARRIVAL) {
    events.enqueue(initialArrival);
  }
  while (!events.isEmpty() ) {
    currentEvent = events.peekFront();
    if (currentEvent.getType() == EventType::ARRIVAL) {
      processArrival();
    } else {
      processDeparture();
    }
    stats.addEvent(currentEvent);
  }
  stats.reportStats();
}
