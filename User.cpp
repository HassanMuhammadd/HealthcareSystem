#include "User.h"

int User::IdCounter = 1;
vector<pair<User, bool>> User::SystemUsers = vector<pair<User,bool>>();

User::User() {
    this->Id = IdCounter++;
}

User::User(string Name, string Password, string Email, string Type) {
    this->Name = Name;
    this->Password = Password;
    this->Email = Email;
    this->Type = Type;
    // When a new user is created, he takes the value of the last unassigned id from the variable IdCounter
    // then IdCounter is increased by 1
    this->Id = IdCounter++;
}

string User::getName() {
    return Name;
}

void User::setName(string Name) {
    this->Name = Name;
}

int User::getId() {
    return Id;
}

void User::setId(int Id) {
    this->Id = Id;
}

string User::getPassword() {
    return Password;
}

void User::setPassword(string Password) {
    this->Password = Password;
}

string User::getEmail() {
    return Email;
}

void User::setEmail(string Email) {
    this->Email = Email;
}

string User::getType() {
    return Type;
}

void User::setType(string Type) {
    this->Type = Type;
}



