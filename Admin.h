/*#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include "Patient.h"
#include "Doctor.h"
#include "User.h"

using namespace std;

class Admin : public User {
public:
    Admin();

    Admin(string name, string password, string email, string type);

    static vector<pair<Admin, bool>> systemAdmins;

    static User* addUser() {
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

        User* user;
        if (type == "doctor") {
            cout << "Enter the user's specialization: ";
            string specialization;
            cin >> specialization;
            Doctor* d1 = new Doctor(username, password, email, type, specialization);
            Doctor::systemDoctors.emplace_back(*d1, false);
            User::SystemUsers.emplace_back(*user, false);
            return user;

        }
        else if (type == "patient") {
            Patient* p1 = new Patient(username, password, email, type);
            Patient::systemPatients.emplace_back(*p1, false);
            User::SystemUsers.emplace_back(*user, false);
            return user;

        }
        else if (type == "admin") {
            Admin* ad1 = new Admin(username, password, email, type);
            systemAdmins.emplace_back(*ad1, false);
            User::SystemUsers.emplace_back(*user, false);
            return user;

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

#endif //ADMIN_H*/