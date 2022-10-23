#include <iostream>
#include "SortedType.hpp"
#include "ClientType.hpp"

using namespace std;
void invalidInput();
void topLevelMenu();
void Populate(SortedType*);
void updateAccount(SortedType*);
void view(SortedType*);
void viewIndividual(SortedType*);
void viewList(SortedType*);
void deleteItem(SortedType*);


int main(int argc, char const *argv[]) {
   
   cout << "===========List===========" << endl;
   SortedType* List = new SortedType;
   bool exit = false;

   do {   
        int option;
        topLevelMenu();

        if (cin >> option) {
            switch (option) {
               case 1:
                  Populate(List);
                  break;
               case 2:
                  view(List);
                  break;

               case 3:
                  updateAccount(List);
                  break;//update
               case 4:
                  deleteItem(List);
                  break;

               case 5: //exit
               default:
                  cout << "Goodbye!\n";
                  exit = true;
                  break;

            }
        } else {
            invalidInput();
        }

        
   } while (!exit);



   return 0;
}

void Populate(SortedType* list) {
   cout << "-----List Generation-------" << endl;
   int choice = 1;
   string name;
   int id;
   float balance;
   string consume;
   while (choice == 1) {
      cin.ignore(255, '\n');
      cin.clear();
      cout << "Enter the name for the Account: " << endl;
      getline(cin, name);
      cout << "Enter ID for "<< name <<": " << endl;
      cin  >> id;

      cout << "Enter the current balance " << name << ": " << endl;
      cin  >> balance;

      ClientType* client = new ClientType(id, name, balance);
      list->PutItem(client);

      cout << "Enter 1 to add another record: ";
      cin  >> choice; 
   }
}

void view(SortedType* list) {
   int option;
   bool isValid = false;
   do {
      cout << "----Main Menu----\n"
       << "1.\tView Account\n"
       << "2.\tView Account List\n";
      if (cin >> option) {
         if (option == 1) {
            isValid = true;
            viewIndividual(list);
         }
         if (option == 2) {
            isValid = true;
            viewList(list);
         }
      } else {
         invalidInput();
      }

   } while (!isValid);
   
} 

void viewList(SortedType* list) {
   list->ResetList();
   for (int i = 0; i < list->GetLength(); i++ )
   {
      ClientType* data = list->GetNextItem();
      cout << "Name: "  << data -> getName() << "\n"
           << "ID: " << data -> getID() << "\n"
           << "Balance: " << data->getBalance() << endl;
   }
}

void viewIndividual(SortedType* list) {
   int choice = 0;
   int id;
   do {
      cout << "-------View Account -------" << endl;
      int id;
      cout << "Enter Account ID: " << endl;
      cin  >> id;

      ClientType* data = list->GetItem(id);
      cout  << "Name: "  << data -> getName() << "\n"
            << "ID: " << data -> getID() << "\n"
            << "Balance: " << data->getBalance() << endl;

      cout << "Enter 1 to view another record: ";
      cin  >> choice; 
      cin.ignore(255, '\n');
   } while (choice == 1);

}

void deleteItem(SortedType* list) {
   cout << "-------Delete Record from List -------" << endl;
   int id;
   cout << "Enter Account ID for removal: " << endl;
   cin  >> id;

   list->DeleteItem(id); 
   cout << "Account Deleted Successfully" << endl;

}

void updateAccount(SortedType* list) {
   cout << "--------Update Records-----------" << endl;
   int id;
   int choice = 0;
   string name;
   double balance;
   char isCorrect;
   do {
      cout << "Enter Account ID to Update: " << endl;
      cin >> id;
      ClientType* toUpdate = list->GetItem(id);

      if (toUpdate == NULL) {
         cout << "Account with Matching ID not found" << endl;
      } else {
         cin.ignore(256, '\n');
         cout << "---Current Information---" << endl;
         cout << "Name: "  << toUpdate-> getName() << "\n"
              << "ID: " << toUpdate-> getID() << "\n"
              << "Balance: " << toUpdate->getBalance() << endl;
      
         cout << "Enter the updated name for the Account: " << endl;
         getline(cin, name);
         
         cout << "Enter the updated balance for " << name << ": " << endl;
         cin  >> balance;

         cout << "---Current Information---" << endl;
         cout << "Name: "  << toUpdate-> getName() << "\n"
              << "ID: " << toUpdate-> getID() << "\n"
              << "Balance: " << toUpdate->getBalance() << endl;

         cout << "---Updated Information---" << endl;
         cout << "Name: "  << name << "\n"
              << "ID: " << id << "\n"
              << "Balance: " << balance << endl;

         cout << "Is this information correct? (y/n): " << endl;
         if (cin >> isCorrect) {
            if (isCorrect == 'y' || isCorrect == 'Y') {
               
               list->UpdateItem(id, balance, name);
               cout << "Record Updated." << endl;

               cout << "Enter 1 to update another record: ";
               cin  >> choice; 
               cin.ignore(255, '\n');
            }
         } 




      }

   } while (choice == 1);

   

}

void topLevelMenu() {
    cout << "----Main Menu----\n"
    << "1.\tAdd Accounts\n"
    << "2.\tView Accounts\n"
    << "3.\tUpdate Accounts\n"
    << "4.\tRemove Accounts\n"
    << "5.\tExit\n";
}

void invalidInput() {
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Please enter a valid choice\n";
}
