/*#pragma once

#ifndef HEALTHCARE_SYSTEM_DOCTOR_H
#define HEALTHCARE_SYSTEM_DOCTOR_H

#include<vector>
#include <string>
#include "User.h"
#include "Slot.h"

using namespace std;

class Doctor : public User {
    string specialization;
    vector<Slot> Schedule;

public:
    static vector<pair<Doctor, bool>> systemDoctors;

    Doctor(string Name, string Password, string Email, string Type, string specialization);


    void setSpecialization(string specialization);

    string getSpecialization();
    vector<Slot> getSchedule();

    void viewAppointments();
    void updateMedicalRecord(int patientID, string newDetail);
    void viewPatientDetails(int patientID);
    void updateSchedule(Slot newAppointment);


};

#endif //HEALTHCARE_SYSTEM_DOCTOR_H*/