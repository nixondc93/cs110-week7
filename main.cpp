#include <iostream>
using namespace std;
#include "contact.h"


int linearSearch(Contact arr[], string value){
  int pos=0;
  int size = 100;
  bool isFound = false;



  while(!isFound && pos < size)
  {
    if(arr[pos].getName() == value){
      isFound= true;
    }
    pos++;
  }

  if(isFound){
    return pos - 1;
  }

  return -1;
}



void swap(int &x, int &y){
  x = x + y;
  y = x - y;
  x = x - y;
}

void sortContacts(Contact arr[]){
  for(int i = 0; i < 100 - 1; ++i){
    int minValue = i;
    for(int j = i + 1; j < 100; ++j){
      if(arr[j].getName() > arr[minValue].getName()){
        minValue = j;
      }
    }
    swap(arr[i], arr[minValue]);
  }
}

void searchContacts(Contact arr[]){
  string value;
  cout << "Who do you want to search for?" << endl;
  cout << "Enter their name: ";
  cin >> value;

  int result = linearSearch(arr, value);

  if(result == -1){
    cout << "Contact not found";
  } else {
    arr[result].printContact();
  }
}

void addContact(Contact arr[]){
  string name;
  string address;
  string phoneNumber;

  cout << "Enter Name" << endl;
  cin >> name;

  cout << "Enter Address" << endl;
  cin >> address;

  cout << "Enter Phone Number" << endl;
  cin >> phoneNumber;

  Contact a;
  a.setName(name);
  a.setAddress(address);
  a.setPhoneNumber(phoneNumber);


  for(int i = 0; i <= 100; i++){
    if(arr[i].getName() == ""){
      arr[i] = a;
      break;
    }
  }
  sortContacts(arr);
}

void updateContact(Contact arr[]){
  string name;
  cout << "Which Contact would you like to update." << endl;
  cout << "Enter their name: ";
  cin >> name;

  int result = linearSearch(arr, name);

  if(result == -1){
    cout << "Contact not found";
  }else{
    string name, address, phone;
    cout << "Enter new info for this contact";
    cout << "Name: ";
    cin >> name;
    cout << "Address: ";
    cin >> address;
    cout << "Phone number: ";
    cin >> phone;
    arr[result].setName(name);
    arr[result].setAddress(address);
    arr[result].setPhoneNumber(phone);
  }
}

void listAllContacts(Contact arr[]){

  for(int i = 0; i < 100; i++){
    if(arr[i].getName() == ""){
      break;
    }
    arr[i].printContact();
  }
}

void deleteContact(Contact arr[]){
  string contactName;
  cout << "Which contact would you like to delete? Enter their name." << endl;
  cin >> contactName;

  for(int i = 0; i < 100; i++){
    if(arr[i].getName() == contactName){
      Contact a;
      arr[i] = a;
    }
  }

}

void menu(Contact contactList[]){
  int userChoice;
  cout << endl;
  cout << "Welcome to your contact list" << endl;
  cout << "What would you like to do?" << endl;
  cout << "Add a contact? (1)" << endl;
  cout << "Update a contact (2)" << endl;
  cout << "Delete Contact (3)" << endl;
  cout << "List all contacts (4)" << endl;
  cout << "Search contacts (5)" << endl;
  cout << "Quit Contact List (6)" << endl;
  cout << "Enter an option to continue" << endl;
  cin >> userChoice;
  cout << endl;

  switch(userChoice){
    case 1:
      addContact(contactList);
      sortContacts(contactList);
      menu(contactList);
      break;
    case 2:
      updateContact(contactList);
      sortContacts(contactList);
      menu(contactList);
      break;
    case 3:
      deleteContact(contactList);
      sortContacts(contactList);
      menu(contactList);
      break;
    case 4:
      listAllContacts(contactList);
      sortContacts(contactList);
      menu(contactList);
      break;
    case 5:
      searchContacts(contactList);
      sortContacts(contactList);
      menu(contactList);
      break;
    case 6:
      exit(0);
      break;
    default:
      cout << "Invalid Option. Enter a number 1 through 6." << endl;
      menu(contactList);
      break;
  }
}

int main() {
	Contact contactList[100];

  menu(contactList);
  return 0;
}
