#ifndef EVENT_H
#define EVENT_H

#include "Time.h"
#include "EventType.h"

class Event {

private:
  
  EventType type;
  Time time;
  Time duration;
  int number;
  int line;

public:
  
  void setType(const EventType&);
  void setTime(const Time&);
  void setDuration(const Time&);
  void setNumber(const int&);
  void setLine(const int&);
  
  EventType getType() const;
  Time getTime() const;
  Time getDuration() const;
  int getNumber() const;
  int getLine() const;
  
  bool operator> (const Event& rhs) const;
  bool operator< (const Event& rhs) const;
  bool operator<=(const Event& rhs) const;
  bool operator>=(const Event& rhs) const;
  bool operator==(const Event& rhs) const;
  bool operator!=(const Event& rhs) const;
  
};

#endif
