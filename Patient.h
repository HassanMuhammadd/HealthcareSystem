/*#pragma once

#ifndef HEALTHCARE_SYSTEM_PATIENT_H
#define HEALTHCARE_SYSTEM_PATIENT_H

#include <iostream>
#include <string>
#include <vector>

#include "Appointment.h"
#include "User.h"

using namespace std;

class Patient : public User {
public:
    static vector<pair<Patient, bool>> systemPatients;

    Patient(string name, string password, string email, string type) : User(name, password, email, type) {};
    void addAppointment();
    void viewAppointments();
};
#endif //HEALTHCARE_SYSTEM_PATIENT_H*/