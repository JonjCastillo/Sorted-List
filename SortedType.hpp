#ifndef SORTEDTYPE_HPP
#define SORTEDTYPE_HPP

#include "StudentType.hpp"
#include <iostream>
using namespace std;
// Header file for Sorted List ADT.
struct NodeType;

struct NodeType {
    StudentType* info;
    NodeType* next;
};

class SortedType {

public:
  SortedType();     // Class constructor
  ~SortedType();    // Class destructor

  bool IsFull() const;
  int  GetLength() const;
  void MakeEmpty();
  StudentType* GetItem(StudentType* item, bool& found);
  void PutItem(StudentType* item);
  void PutItemUnsorted(StudentType* item);
  void DeleteItem(int key);
  void ResetList();
  StudentType* GetNextItem();
  NodeType* sortList(NodeType* head);
  NodeType* getHead();

private:
   NodeType* listData;
   int length;
   NodeType* currentPos;

   NodeType* mergeList(NodeType* l1, NodeType* l2);
};


SortedType::SortedType() {  // Class constructor
  length = 0;
  listData = NULL;
}

bool SortedType::IsFull() const {
   NodeType* location;
   try {
      location = new NodeType;
      delete location;
      return false;
   }
   catch (bad_alloc exception) {
      return true;
   }
}

int SortedType::GetLength() const {
   return length;
}

void SortedType::MakeEmpty() {
  NodeType* tempPtr;

  while (listData != NULL) {
    tempPtr = listData;

    listData = listData->next;
    delete tempPtr;
  }
  length = 0;
}

// Set location to listData
// Set found to false
// Set moreToSearch to (location != NULL)
// while moreToSearch AND NOT found
//      switch (item.ComparedTo(location->info))
//          case GREATER  :        Set location to location->next
//                                 Set moreToSearch to (location != NULL)
//          case EQUAL    :        Set found to true
//                                 Set item to location->info
//          case LESS     :        Set moreToSearch to false
// return item
StudentType* SortedType::GetItem(StudentType* item, bool& found) {
   bool moreToSearch;
   NodeType* location;

   location = listData;
   found = false;
   moreToSearch = (location != NULL);

   while (moreToSearch && !found) {

      switch ( item->ComparedTo( location->info ) ) {
      case GREATER: 
         location = location->next;
         moreToSearch = (location != NULL);
         break;
      case EQUAL:   
         found = true;
         item = location->info;
         break;
      case LESS:    
         moreToSearch = false;
         break;
      }
   }

   return item;
}

// Set location to listData
// Set predLoc to NULL
// Set moreToSearch to (location != NULL)
// while moreToSearch
//     switch (item.ComparedTo(location->info))
//         case GREATER   :       Set predLoc to location
//                                Set location to location->next
//                                Set moreToSearch to (location != NULL)
//         case LESS      : Set moreToSearch to false
// Set newNode to the address of a newly allocated node
// Set newNode->info to item
// Set newNode->next to location
// Set predLoc->next to newNode
// Increment length

void SortedType::PutItem(StudentType* item)
{
  NodeType* newNode;  // pointer to node being inserted
  NodeType* predLoc;  // trailing pointer
  NodeType* location; // traveling pointer
  bool moreToSearch;

  location = listData;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  // Find insertion point.
  while (moreToSearch)
  {
    switch( item->ComparedTo(location->info ) )
    {
      case GREATER:
        predLoc = location;
        location = location->next;
        moreToSearch = (location != NULL);
        break;
      case LESS:
        moreToSearch = false;
        break;
     }
  }
  // Prepare node for insertion.
  newNode = new NodeType;
  newNode->info = item;

  // Insert node into list.
  if (predLoc == NULL)         // Insert as first.
  {
    newNode->next = listData;
    listData = newNode;
  }
  else
  {
     newNode->next = location;
     predLoc->next = newNode;
  }
  length++;
}

//method to place an unsorted list

void SortedType::PutItemUnsorted(StudentType* item) {

  NodeType* newNode;
  newNode = new NodeType;
  newNode->info = item;
  /* listData = newNode; */
  newNode->next = listData;
  listData = newNode; 
  length++;
}


// Initialize location to position of first item
// Set found to false
// while NOT found
//     switch (item.ComparedTo(Info(location)))
//         case GREATER   :   Set location to Next(location)
//         case LESS      :   // Cannot happen because list is sorted.
//         case EQUAL     :   Set found to true
// for index going from location + 1 TO length – 1
//      Set Info(index – 1) to Info(index)
// Decrement length
void SortedType::DeleteItem(int key)
{
  NodeType* location = listData;
  NodeType* tempLocation;

  // Locate node to be deleted.
  if ( key == listData->info->getID() ) {
    tempLocation = location;
    listData = listData->next;    // Delete first node.
  }
  else {
    while (key != location->next->info->getID()) {
      location = location->next;
    }

    // Delete node at location->next
    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;
  length--;
}

void SortedType::ResetList()
{
  currentPos = NULL;
}

StudentType* SortedType::GetNextItem()
{
  StudentType* item;
  if (currentPos == NULL) {
    currentPos = listData;
  }
  item = currentPos->info;
  currentPos = currentPos->next;
  return item;
}

SortedType::~SortedType()
{
  NodeType* tempPtr;

  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
}

NodeType* SortedType::getHead() {
  return listData;
}

NodeType* SortedType::sortList(NodeType* head) {
    //If List Contain a Single or 0 Node
    if(head == NULL || head ->next == NULL) {
      return head;
    }
    
    
    NodeType *temp = NULL;
    NodeType *slow = head;
    NodeType *fast = head;
    
    // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
    while(fast !=  NULL && fast -> next != NULL)
    {
        temp = slow;
        slow = slow->next;          //slow increment by 1
        fast = fast ->next ->next;  //fast incremented by 2
        
    }   
    temp -> next = NULL;            //end of first left half
    
    NodeType* l1 = sortList(head);    //left half recursive call
    NodeType* l2 = sortList(slow);    //right half recursive call
    
    return mergeList(l1, l2);         //mergeList Function call
        
}
    
    //MergeSort Function O(n*logn)
NodeType* SortedType::mergeList(NodeType *l1, NodeType *l2) {
    NodeType *ptr = new NodeType;
    NodeType *curr = ptr;
    
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->info->getID() <= l2->info->getID())
        {
            curr -> next = l1;
            l1 = l1 -> next;
        }
        else
        {
            curr -> next = l2;
            l2 = l2 -> next;
        }
    
    curr = curr ->next;
    }
    
    //for unequal length linked list
    if(l1 != NULL)
    {
        curr -> next = l1;
        l1 = l1->next;
    }
    
    if(l2 != NULL)
    {
        curr -> next = l2;
        l2 = l2 ->next;
    }
    
    return ptr->next;
}

#endif