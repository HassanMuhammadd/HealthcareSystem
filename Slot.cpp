#include "Slot.h"

// Constructor
Slot::Slot(const std::string& date, const std::string& time) : date(date), time(time) {}

// Getters
std::string Slot::getDate() const {
    return date;
}

std::string Slot::getTime() const {
    return time;
}

// Setters
void Slot::setDate(const std::string& date) {
    this->date = date;
}

void Slot::setTime(const std::string& time) {
    this->time = time;
}

// Display slot information
void Slot::displaySlot() const {
    std::cout << "Date: " << date << ", Time: " << time << std::endl;
}