
#include "Event.h"
#include "EventType.h"

void Event::setType(const EventType& type){
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

void Event::setLine(const int& line){
  this->line = line;
}

EventType Event::getType() const {
  return type;
}

Time Event::getTime() const {
  return time;
}

Time Event::getDuration() const {
  return duration;
}

int Event::getNumber() const {
  return number;
}

int Event::getLine() const {
  return line;
}

bool Event::operator> (const Event& rhs) const {
  return time < rhs.time;
}

bool Event::operator< (const Event& rhs) const {
  return time < rhs.time;
}

bool Event::operator<=(const Event& rhs) const {
  return time <= rhs.time;
}

bool Event::operator>=(const Event& rhs) const {
  return time >= rhs.time;
}

bool Event::operator==(const Event& rhs) const {
  return time == rhs.time;
}

bool Event::operator!=(const Event& rhs) const {
  return time != rhs.time;
}
