#include <iostream>
#include "User.h"
#include "Doctor.h"

int main()
{
    User::SystemUsers.emplace_back(User("khaled", "pass", "mail", "patient"), false);
    User* u = User::login("mail", "1234");
    if (u != nullptr) {
        cout << u->getEmail() << endl;
    }
    User::updateProfile("mail", "u->getEmail()", "newpass", "newname");
    if (User::logout("u->getEmail()")) {
        cout << "yes" << endl;
    }

    Admin* a1 = new Admin("hassan", "1234", "hm.mail.com", "admin");
    a1->login("hm.mail.com", "1234");
    string type = Admin::addUser();
    Doctor* d1 = nullptr;
    if (type == "doctor")
        d1 = &Doctor::systemDoctors.back().first;

    Slot* s1 = new Slot("12/24", "23:00");
    d1->updateSchedule(*s1);

    type = Admin::addUser();
    Patient* p1 = nullptr;
    if (type == "patient")
        p1 = &Patient::systemPatients.back().first;

    p1->addAppointment();
}
