#include "contact.h"
#include <iostream>
using namespace std;

void Contact::printContact() const {
  cout << "Name: " << name << endl;
  cout << "Address: " << address << endl;
  cout << "Phone number: " << phoneNumber << endl;
  cout << endl;
}