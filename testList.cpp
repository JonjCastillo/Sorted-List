#include <iostream>
#include "SortedType.hpp"
#include "ClientType.hpp"

using namespace std;
void Populate(SortedType*);
void PopulateUnsorted(SortedType*);
void view(SortedType*);
void deleteItem(SortedType*);


int main(int argc, char const *argv[]) {
   
   cout << "===========Sorted List===========" << endl;
   SortedType* List = new SortedType;
  



   cout << "-----List Generation-------" << endl;
   Populate(List);

   cout << "-------Current List---------" << endl;
   view(List);

   cout << "-------Delete Record from List -------" << endl;
   deleteItem(List);

   cout << "-------Current List----------" << endl;
   view(List);

   return 0;
}

void Populate(SortedType* list) {
   int choice = 1;
   string name;
   int id;
   float balance;
   string consume;
   while (choice == 1) {

      cout << "Enter the name of the Student: " << endl;
      getline(cin, name);
      cout << "Enter Student ID for "<< name <<": " << endl;
      cin  >> id;

      cout << "Enter the current GPA for " << name << ": " << endl;
      cin  >> balance;

      ClientType* student = new ClientType(id, name, balance);
      list->PutItem(student);
      cout << "Enter 1 to add another record: ";
      cin  >> choice; 
      cin.ignore(255, '\n');
   }
}

void view(SortedType* list) {
   list->ResetList();
   for (int i = 0; i < list->GetLength(); i++ )
   {
      ClientType* data = list->GetNextItem();
      cout << "Name: "  << data -> getName() << "\n"
           << "ID: " << data -> getID() << "\n"
           << "Balance: " << data->getBalance() << endl;
   }
}

void deleteItem(SortedType* list) {

   int id;
      cout << "Enter Student ID for removal: " << endl;
      cin  >> id;

      list->DeleteItem(id); 
      cout << "Student Deleted Successfully" << endl;

}
