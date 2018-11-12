
#include <string>

#include "EventType.h"
#include "EventBuilder.h"

Event::Event()
  : time(-1), type(0), duration(0), number(-1), teller(1)
{ }

void Event::setEventType(const EventType type){
  this->type = type;
}

void Event::setTime(const Time& time){
  this->time = time;
}

void Event::setDuration(const Time& duration){
  this->duration = duration;
}

void Event::setNumber(const int& number){
  this->number = number;
}

void Event::setTellerNum(const int& tellerNum){
  this->tellerNum = tellerNum;
}

EventType Event::getEventType() const {
  return type;
}

Time Event::getTime() const {
  return time;
}

Time Event::getDuration() const {
  return duration;
}

int Event::getCustNumber() const {
  return number;
}

int Event::getTellerNum() const {
  return teller;
}
