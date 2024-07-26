#include "Appointment.h"


int Appointment::ID = 1;
std::vector<Appointment> Appointment::appointments;
// Constructor
Appointment::Appointment(int id, const Slot& slot, int patientId, int doctorId, const std::string& description)
    : id(id), slot(slot), patientId(patientId), doctorId(doctorId), description(description) {}

// Getters
int Appointment::getId() const {
    return id;
}

Slot Appointment::getSlot() const {
    return slot;
}

int Appointment::getPatientId() const {
    return patientId;
}

int Appointment::getDoctorId() const {
    return doctorId;
}

std::string Appointment::getDescription() const {
    return description;
}

// Setters
void Appointment::setId(int id) {
    this->id = id;
}

void Appointment::setSlot(const Slot& slot) {
    this->slot = slot;
}

void Appointment::setPatientId(int patientId) {
    this->patientId = patientId;
}

void Appointment::setDoctorId(int doctorId) {
    this->doctorId = doctorId;
}

void Appointment::setDescription(const std::string& description) {
    this->description = description;
}

// Display appointment information
void Appointment::displayAppointment() const {
    std::cout << "Appointment ID: " << id << std::endl;
    slot.displaySlot();
    std::cout << "Patient ID: " << patientId << ", Doctor ID: " << doctorId << std::endl;
    std::cout << "Description: " << description << std::endl;
}