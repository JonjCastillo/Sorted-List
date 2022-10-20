#ifndef CLIENTTYPE_HPP
#define CLIENTTYPE_HPP

// File ItemType.h must be provided by the user of this class.
// ItemType.h must contain the following definitions:
// MAX_ITEMS:     the maximum number of items on the list
// ItemType:      the definition of the objects on the list
// RelationType:  {LESS, GREATER, EQUAL}
// Member function ComparedTo(ItemType item) which returns
//      LESS, if self 'comes before' item
//      GREATER, if self 'comes after' item
//      EQUAL, if self and item are the same
#include <string>
#include <iostream>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

class ClientType {
   private:
      
      int id;
      string name;
      double balance;
      
   public:
      ClientType();
      ClientType(int id, string name, double balance);

      //accessors
      int getID() const;
      string getName() const;
      double getBalance() const;

      //mutators
      void setName(string name);
      void setBalance(double balance);
      RelationType ComparedTo(ClientType* item);

};

ClientType::ClientType(int id, string name, double balance) {
   this->id = id;
   this->name = name;
   this->balance = balance;
}

ClientType::ClientType() {
   this->id = 0;
   this->name = "";
   this->balance = 0.0;
}

int ClientType::getID() const{
   return id;
}

string ClientType::getName() const{
   return name;
}

double ClientType::getBalance() const{
   return balance;
}

void ClientType::setName(string name) {
   this->name = name;
}

void ClientType::setBalance(double balance) {
   this->balance = balance;
}


RelationType ClientType::ComparedTo(ClientType* item) {
   if (
      this->getID() == item->getID() &&
      this->getBalance() == item->getBalance() &&
      this->getName() == item->getName()
   ) {
      return EQUAL;
   } else if ( this->getID() > item->getID() ) {
      return GREATER;
   } 

   return LESS;
}

#endif

