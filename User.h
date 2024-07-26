#pragma once
#ifndef HEALTHCARE_SYSTEM_USER_H
#define HEALTHCARE_SYSTEM_USER_H

#include <iostream>
#include <string>
#include <vector>
#include "Admin.h"
#include "Slot.h"

using namespace std;

class User {
    string Name;
    int Id;
    string Password;
    string Email;
    string Type;

public:

    static int IdCounter; // gives a unique id for the user and increases automatically

    static vector<pair<User, bool>> SystemUsers;

    User();
    User(string Name, string Password, string Email, string Type);

    string getName();
    void setName(string Name);

    int getId();
    void setId(int Id);

    string getPassword();
    void setPassword(string Password);

    string getEmail();
    void setEmail(string Email);

    string getType();
    void setType(string Type);

    static User* login(string email, string password) {
        for (pair<User, bool>user : SystemUsers) {
            if (user.first.Email == email && user.first.Password == password) {
                user.second = true;
                return &user.first;
            }
        }
        return nullptr;
    }
    static bool logout(string email) {
        for (pair<User, bool>user : SystemUsers) {
            if (user.first.Email == email) {
                user.second = false;
                return true;
            }
        }
        return false;
    }
    static bool updateProfile(string email, string newEmail, string newPassword, string newName) {
        for (pair<User, bool>user : SystemUsers) {
            if (user.first.Email == email) {
                user.first.Password = newPassword;
                user.first.Email = newEmail;
                user.first.Name = newName;
                return true;
            }
        }
        return false;
    }
};

class Patient : public User {
public:
    static vector<pair<Patient, bool>> systemPatients;

    Patient(string name, string password, string email, string type) : User(name, password, email, type) {};
    void addAppointment();
    void viewAppointments();
};

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


class Admin : public User {
public:
    Admin();

    Admin(string name, string password, string email, string type);

    static vector<pair<Admin, bool>> systemAdmins;

    static string addUser() {
        cout << "Enter the user's name: ";
        string username;
        cin >> username;
        cout << "Enter the user's password: ";
        string password;
        cin >> password;
        cout << "Enter the user's email: ";
        string email;
        cin >> email;
        cout << "Enter the user's type: ";
        string type;
        cin >> type;

        User* user = nullptr;
        if (type == "doctor") {
            cout << "Enter the user's specialization: ";
            string specialization;
            cin >> specialization;
            Doctor d1(username, password, email, type, specialization);
            Doctor::systemDoctors.emplace_back(d1, false);
            //User::SystemUsers.emplace_back(*user, false);
            return "doctor";

        }
        else if (type == "patient") {
            Patient p1(username, password, email, type);
            Patient::systemPatients.emplace_back(p1, false);
           // User::SystemUsers.emplace_back(*user, false);
            return "patient";

        }
        else if (type == "admin") {
            Admin ad1(username, password, email, type);
            systemAdmins.emplace_back(ad1, false);
            //User::SystemUsers.emplace_back(*user, false);
            return "admin";

        }
        else {
            cout << "Invalid user type" << endl;
            return nullptr;
        }
    }

    static void deleteUser(string email) {
        for (int i = 0; i < User::SystemUsers.size(); ++i) {
            if (User::SystemUsers[i].first.getEmail() == email) {
                User::SystemUsers.erase(User::SystemUsers.begin() + i);
                cout << "User of email: " << email << " has been deleted successfully" << endl;
                return;
            }
        }
    }

    static bool updateUser(string email, string newEmail = "", string newUsername = "", string newPassword = "") {
        for (int i = 0; i < User::SystemUsers.size(); ++i) {
            if (User::SystemUsers[i].first.getEmail() == email) {
                User& user = User::SystemUsers[i].first;
                if (!newUsername.empty()) user.setName(newUsername);
                if (!newEmail.empty()) user.setEmail(newEmail);
                if (!newPassword.empty()) user.setPassword(newPassword);
                cout << "User of email: " << email << " has been updated successfully" << endl;
                return true;
            }
        }
        return false;
    }

    static vector<pair<User, bool>> viewUsers() {
        for (int i = 0; i < User::SystemUsers.size(); ++i) {
            cout << User::SystemUsers[i].first.getName() << endl;
            cout << User::SystemUsers[i].first.getType() << endl;
        }
        return User::SystemUsers;
    }
};



#endif //HEALTHCARE_SYSTEM_USER_H

