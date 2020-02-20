
#include "Event.h"
#include "EventBuilder.h"
#include "LinkedQueue.h"
#include "PriorityQueue.h"
#include "Statistics.h"

#include "Simulation.h"

// Event currentEvent;
// EventBuilder eventBuilder;
// LinkedQueue<Event> line;
// PriorityQueue<Event> events;
// Statistics stats;
// Just to remeber what the data names are

Simulation::Simulation()
{  
}

void Simulation::processArrival(){

  if(line.isEmpty()) {
    events.enqueue(eventBuilder.createDepartureEvent
		   (currentEvent.getTime(),
		    currentEvent.getDuration(),
		    currentEvent.getNumber()) );
  }

  line.enqueue(currentEvent);
  events.dequeue();
  
  Event newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber() + 1);

  if (newEvent.getType() == EventType::ARRIVAL) {
    events.enqueue(newEvent);
  }
  
}

void Simulation::processDeparture(){
  Event aEvent = line.peekFront();
  line.dequeue();
  events.dequeue();

  if (!line.isEmpty() ) {
    Event DEvent = eventBuilder.createDepartureEvent(currentEvent.getTime(),
						     aEvent.getDuration(),
						     currentEvent.getNumber() + 1);
    events.enqueue(DEvent);
  }
}

void Simulation::simulate(){
  Event initialArrival = eventBuilder.createArrivalEvent(1);

  if (initialArrival.getType() == EventType::ARRIVAL) {
    events.enqueue(initialArrival);
  }
  while (!events.isEmpty()) {
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
