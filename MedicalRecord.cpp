#include "MedicalRecord.h"
#include <iostream>
using namespace std;

vector<MedicalRecord> MedicalRecord::medicalRecords;

MedicalRecord::MedicalRecord(int id, int patientId) {
    this->id = id;
    this->patientId = patientId;
    this->details = vector<string>();
}

MedicalRecord::MedicalRecord() {
    this->id = -1;
};

int MedicalRecord::getId() {
    return id;
}

int MedicalRecord::getPatientId() {
    return patientId;
}

vector<string> MedicalRecord::getDetails() {
    return details;
}

void MedicalRecord::setId(int id) {
    this->id = id;
}

void MedicalRecord::setPatientId(int patientId) {
    this->patientId = patientId;
}

void MedicalRecord::updateDetails(string newDetail) {
    details.push_back(newDetail);
}