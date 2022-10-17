#ifndef STUDENTTYPE_HPP
#define STUDENTTYPE_HPP

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

class StudentType {
   private:
      
      int student_id;
      string name;
      double gpa;
      string status;
      
   public:
      StudentType();
      StudentType(int id, string name, double gpa, string status);
      int getID() const;
      string getName() const;
      double getGPA() const;
      string getStatus() const;
      RelationType ComparedTo(StudentType* item);

      // Does this need setter methods?
};

StudentType::StudentType(int id, string name, double gpa, string status) {
   this->student_id = id;
   this->name = name;
   this->gpa = gpa;
   this->status = status;
}

StudentType::StudentType() {
   this->student_id = 0;
   this->name = "";
   this->gpa = 0.0;
   this->status = "";
}

int StudentType::getID() const{
   return student_id;
}

string StudentType::getName() const{
   return name;
}

double StudentType::getGPA() const{
   return gpa;
}

string StudentType::getStatus() const{
   return status;
}

RelationType StudentType::ComparedTo(StudentType* item) {
   if (
      this->getID() == item->getID() &&
      this->getGPA() == item->getGPA() &&
      this->getStatus() == item->getStatus() &&
      this->getName() == item->getName()
   ) {
      return EQUAL;
   } else if ( this->getID() > item->getID() ) {
      return GREATER;
   } 

   return LESS;
}

#endif

