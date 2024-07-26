#pragma once
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Slot.h"
#include <string>
#include <vector>

class Appointment {
private:
    int id;
    Slot slot;
    int patientId;
    int doctorId;
    std::string description;
public:
    static std::vector<Appointment> appointments;
    static int ID;
    // Constructor
    Appointment(int id, const Slot& slot, int patientId, int doctorId, const std::string& description);

    // Getters
    int getId() const;
    Slot getSlot() const;
    int getPatientId() const;
    int getDoctorId() const;
    std::string getDescription() const;

    // Setters
    void setId(int id);
    void setSlot(const Slot& slot);
    void setPatientId(int patientId);
    void setDoctorId(int doctorId);
    void setDescription(const std::string& description);

    // Display appointment information
    void displayAppointment() const;
};

#endif // APPOINTMENT_H