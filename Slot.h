#pragma once

#ifndef SLOT_H
#define SLOT_H

#include <string>
#include <iostream>

class Slot {
private:
    std::string date;
    std::string time;

public:
    // Constructor
    Slot(const std::string& date, const std::string& time);

    // Getters
    std::string getDate() const;
    std::string getTime() const;

    // Setters
    void setDate(const std::string& date);
    void setTime(const std::string& time);

    // Display slot information
    void displaySlot() const;
};

#endif // SLOT_H