#include "Admin.h"
#include "User.h"
#include <string>
using namespace std;

vector<pair<Admin, bool>> Admin::systemAdmins;


Admin::Admin() {}

Admin::Admin(string name, string password, string email, string type) : User(name, password, email, type) {}



