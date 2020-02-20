
#include <string>

#include "EventType.h"
#include "EventBuilder.h"

void Event::setEventType(const EventType& type){
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

int Event::getTellerNum() const {
  return tellerNum;
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
