#ifndef EVENT_H
#define EVENT_H

#include <iostream>

#include "Time.h"
#include "EventType.h"

class Event {

 private:
  
  EventType type;
  Time time;
  Time duration;
  int number;
  int teller;

 public:
  
  void setEventType(const EventType&);
  void setTime(const Time&);
  void setDuration(const Time&);
  void setNumber(const int&);
  void setTellerNum(const int&);
  
  EventType getEventType() const;
  Time getTime() const;
  Time getDuration() const;
  int getNumber() const;
  int getTellerNum() const;
  
  bool operator< (const Event& rhs) const;
  bool operator<=(const Event& rhs) const;
  bool operator>=(const Event& rhs) const;
  bool operator==(const Event& rhs) const;
  bool operator!=(const Event& rhs) const;
  
}

#endif
