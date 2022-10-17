#include <iostream>
#include "SortedType.hpp"
#include "StudentType.hpp"

using namespace std;
void Populate(SortedType*);
void PopulateUnsorted(SortedType*);
void view(SortedType*);
void deleteItem(SortedType*);


int main(int argc, char const *argv[]) {
   
   cout << "===========Sorted List===========" << endl;
   SortedType* sortedList = new SortedType;
   SortedType* unsortedList = new SortedType;



   cout << "-----List Generation-------" << endl;
   Populate(sortedList);

   cout << "-------Current List---------" << endl;
   view(sortedList);

   cout << "-------Delete Record from List -------" << endl;
   deleteItem(sortedList);

   cout << "-------Current List----------" << endl;
   view(sortedList);

   cout << "============Unsorted List============" << endl;
   cout << "-----List Generation-------" << endl;
   PopulateUnsorted(unsortedList);

   cout << "-------Current List---------" << endl;
   view(unsortedList);

   cout << "--------Beginning Sort------" << endl;
   unsortedList->sortList(unsortedList->getHead());

   cout << "-------Current List---------" << endl;
   view(unsortedList);


   return 0;
}

void Populate(SortedType* list) {
   int choice = 1;
   string name;
   int id;
   string status;
   float gpa;
   string consume;
   while (choice == 1) {

      cout << "Enter the name of the Student: " << endl;
      // cin  >> name;
      // cin  >> consume;
      getline(cin, name);
      cout << "Enter Student ID for "<< name <<": " << endl;
      cin  >> id;
      cout << "Enter the current status for " << name << ": " << endl;
      // ignore the newline character
      cin.ignore(255, '\n');
      getline(cin, status);
      cout << "Enter the current GPA for " << name << ": " << endl;
      cin  >> gpa;

      StudentType* student = new StudentType(id, name, gpa, status);
      list->PutItem(student);
      cout << "Enter 1 to add another record: ";
      cin  >> choice; 
      cin.ignore(255, '\n');
   }
}

void PopulateUnsorted(SortedType* list) {
   int choice = 1;
   string name;
   int id;
   string status;
   float gpa;
   string consume;
   while (choice == 1) {

      cout << "Enter the name of the Student: " << endl;
      // cin  >> name;
      // cin  >> consume;
      getline(cin, name);
      cout << "Enter Student ID for "<< name <<": " << endl;
      cin  >> id;
      cout << "Enter the current status for " << name << ": " << endl;
      // ignore the newline character
      cin.ignore(255, '\n');
      getline(cin, status);
      cout << "Enter the current GPA for " << name << ": " << endl;
      cin  >> gpa;

      StudentType* student = new StudentType(id, name, gpa, status);
      list->PutItemUnsorted(student);
      cout << "Enter 1 to add another record: ";
      cin  >> choice; 
      cin.ignore(255, '\n');
   }
}

void view(SortedType* list) {
   list->ResetList();
   for (int i = 0; i < list->GetLength(); i++ )
   {
      StudentType* data = list->GetNextItem();
      cout << "Name: "  << data -> getName() << "\n"
           << "ID: " << data -> getID() << "\n"
           << "Status: " << data->getStatus() << "\n"
           << "GPA: " << data->getGPA() << endl;
   }
}

void deleteItem(SortedType* list) {
   // int choice = 1;
   // string name;
   int id;
   // string status;
   // float gpa;
   // string consume;
   // while (choice == 1) 
      cout << "Enter Student ID for removal: " << endl;
      cin  >> id;

      list->DeleteItem(id); 
      cout << "Student Deleted Successfully" << endl;

}
