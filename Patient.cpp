
#include <vector>

#include "Appointment.h"
#include "Patient.h"
#include "Doctor.h"
#include "User.h"

using namespace std;

vector<pair<Patient, bool>> Patient::systemPatients;


void Patient::addAppointment() {

    cout << "Available appointments in the system: " << endl;
    for (int j = 0; j < Doctor::systemDoctors.size(); j++) {

        Doctor doctor = Doctor::systemDoctors[j].first;
        cout << j + 1 << "Doctor " << doctor.getName() << endl << endl;
        if (doctor.getSchedule().empty()) {
            cout << "Doctor " << doctor.getName() << " has no appointments at the moment" << endl << endl;
            continue;
        }
        cout << "Available appointments for doctor. " << doctor.getName() << endl << endl;
        for (int i = 0; i < doctor.getSchedule().size(); i++) {
            cout << i + 1 << ": " << "Date: " << doctor.getSchedule()[i].getDate() << ", Time: " << doctor.getSchedule()[i].getTime() << endl << endl;
        }
    }

    // Represents the Doctor and the appointment index that the patient will choose.
    int doctorIndex, appointmentIndex;
    cout << "Enter the number of the Doctor that you want to choose or 0 to exit: ";
    cin >> doctorIndex;
    if (doctorIndex == 0) {
        return;
    }
    cout << "Enter the number of the appointment that you want to choose or 0 to exit: ";
    cin >> appointmentIndex;
    if (appointmentIndex == 0) {
        return;
    }
    // Cast the user object to a doctor object and choose the add the selected doctor index and appointment to the patient's appointments
    // and then erases it from the doctor's appointments.
    Doctor doctor = Doctor::systemDoctors[doctorIndex - 1].first;
    //Appointment(int id, const Slot & slot, int patientId, int doctorId, const std::string & description);
    Appointment appointment(Appointment::ID++, doctor.getSchedule()[appointmentIndex - 1], this->getId(), doctor.getId(), "Test");
    Appointment::appointments.push_back(appointment);
}

void Patient::viewAppointments() {
    for (const Appointment& i : Appointment::appointments) {
        if (i.getPatientId() == this->getId()) {
            cout << "Appointment ID: " << i.getId() << "\n";
            cout << "Appointment Slot: " << i.getSlot().getDate() << " - " << i.getSlot().getTime() << "\n";
            cout << "Patient ID: " << i.getPatientId() << "\n";
            cout << "Doctor ID: " << i.getDoctorId() << "\n";
            cout << "Description: " << i.getDescription() << "\n";
            cout << "=====================\n";
        }
    }
}