#pragma once

#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H

#include <string>
#include <vector>
using namespace std;

class MedicalRecord {
private:
    int id;
    int patientId;
    vector<string> details;

public:

    static vector<MedicalRecord> medicalRecords;

    MedicalRecord(int id, int patientId);
    MedicalRecord();

    int getId();
    int getPatientId();
    vector<string> getDetails();

    void setId(int id);
    void setPatientId(int patientId);

    void updateDetails(string newDetail);
    static MedicalRecord viewMedicalRecord(int patientId) {
        for (MedicalRecord rec : MedicalRecord::medicalRecords) {
            if (rec.getPatientId() == patientId)
                return rec;
        }
        return MedicalRecord();
    }
};

#endif // MEDICALRECORD_H