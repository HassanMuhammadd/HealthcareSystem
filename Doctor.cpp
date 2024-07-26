#include "Doctor.h"
#include "Appointment.h"
#include "MedicalRecord.h"
#include "Patient.h"
#include "User.h"
#include <iostream>
#include <vector>

using namespace std;

vector<pair<Doctor, bool>> Doctor::systemDoctors;

Doctor::Doctor(string name, string password, string email, string type, string specialization)
    : User(name, password, email, type) {
    this->specialization = specialization;
    vector<Slot> vec1;
    this->Schedule = vec1;
}

void Doctor::setSpecialization(string specialization) {
    this->specialization = specialization;
}

string Doctor::getSpecialization() {
    return specialization;
}

vector<Slot> Doctor::getSchedule() {
    return Schedule;
}

void Doctor::viewAppointments() {
    for (const Appointment& i : Appointment::appointments) {
        if (i.getDoctorId() == this->getId()) {
            cout << "Appointment ID: " << i.getId() << "\n";
            cout << "Appointment Slot: " << i.getSlot().getDate() << " - " << i.getSlot().getTime() << "\n";
            cout << "Patient ID: " << i.getPatientId() << "\n";
            cout << "Doctor ID: " << i.getDoctorId() << "\n";
            cout << "Description: " << i.getDescription() << "\n";
            cout << "=====================\n";
        }
    }
}

void Doctor::updateMedicalRecord(int patientID, string newDetail) {
    MedicalRecord record = MedicalRecord::viewMedicalRecord(patientID);

    if (record.getId() != -1) { // there exists a record for this Patient
        record.updateDetails(newDetail);
    }
    else {
        cout << "No Medical record was found for this Patient's ID. \n";
    }
}

void Doctor::viewPatientDetails(int patientID) {
    for (pair<Patient, bool> user : Patient::systemPatients) {
        if (user.first.getId() == patientID) {
            Patient patient = user.first;
            cout << "Patient Data: \n";
            cout << "Name: " << patient.getName() << "\n";
            cout << "ID: " << patient.getId() << "\n";
            cout << "Email: " << patient.getEmail() << "\n";
            return;
        }
    }
    // if this line is reached, then no patient was found with that ID
    cout << "No patient with this ID\n";
}

void Doctor::updateSchedule(Slot newSlot) {
    Schedule.push_back(newSlot);
}