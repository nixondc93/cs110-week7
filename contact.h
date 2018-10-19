#ifndef Contact_H
#define Contact_H
#include <iostream>
using namespace std;

class Contact{
  private:
    string name = "";
    string address;
    string phoneNumber;

  public:
    void setName(string n){
      name = n;
    }
    void setAddress(string ad){
      address = ad;
    }
    void setPhoneNumber(string num){
      phoneNumber = num;
    }
    string getName(){
      return name;
    }
    string getAddress(){
      return address;
    }
    string getPhoneNumber(){
      return phoneNumber;
    }
    void printContact() const;
};

#endif