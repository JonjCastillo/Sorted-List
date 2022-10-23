#ifndef SORTEDTYPE_HPP
#define SORTEDTYPE_HPP

#include "ClientType.hpp"
#include <iostream>
using namespace std;
// Header file for Sorted List ADT.
struct NodeType;

struct NodeType {
    ClientType* info;
    NodeType* next;
};

class SortedType {

public:
  SortedType();     // Class constructor
  ~SortedType();    // Class destructor

  bool IsFull() const;
  int  GetLength() const;
  void MakeEmpty();
  ClientType* GetItem(int key);
  void PutItem(ClientType* item);
  void PutItemUnsorted(ClientType* item);
  void DeleteItem(int key);
  void ResetList();
  void UpdateItem(int key, double balance, string name);
  ClientType* GetNextItem();
  NodeType* getHead();

private:
   NodeType* listData;
   int length;
   NodeType* currentPos;


};


SortedType::SortedType() {  // Class constructor
  length = 0;
  listData = NULL;
}

//checks to see if there is enough memory to add another 
//node to the list.
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

//return the length of the list
int SortedType::GetLength() const {
   return length;
}

//method empties out the list
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
/**
 * @brief this method returns the account found by its ID
 * it searches through the list until it finds the node.
 * 
 * @param key the id of the list
 * @return ClientType* the account that correlated to the ID
 */
ClientType* SortedType::GetItem(int key) {
  bool moreToSearch;
  NodeType* location;
  NodeType* tempLocation;
  ClientType* item;

  location = listData;
  moreToSearch = (location != NULL);
  if ( key == location->info->getID() ) {
    item = location->info;
    return item;
  }
  else {
    while (key != location->next->info->getID()) {
      location = location->next;
      item = NULL;
    }

    item = location->next->info;
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
/**
 * @brief this method adds an item to the list sorted by its ID
 * the method will first compare to see where the node must be inserted, 
 * then will proceed to insert the node at that point and increment the total length of the list
 * 
 * @param item the account that is being added.
 */
void SortedType::PutItem(ClientType* item)
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
/**
 * @brief this method finds the specified account by its ID
 * and then deletes it by removing the node and setting the pointer of the previous node 
 * to the following node of the list.
 * 
 * @param key this is the ID of the account
 */
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

/**
 * @brief returns the next item in the list
 * 
 * @return ClientType* the client that followed in the list
 */
ClientType* SortedType::GetNextItem()
{
  ClientType* item;
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

/**
 * @brief this method will search similar to GetItem() and then update the found
 * node with the given parameters
 * 
 * @param key the account ID for the node
 * @param balance the updated balance for the account
 * @param name the updated name for the account
 */
void SortedType::UpdateItem(int key, double balance, string name) {
  bool moreToSearch;
  NodeType* location;
  NodeType* tempLocation;

  location = listData;
  moreToSearch = (location->next != NULL);

  if ( key == location->info->getID() ) {
    location->info->setBalance(balance);
    location->info->setName(name); 
  }
  else {
    while (key != location->next->info->getID()) {
      location = location->next;
    }

    location->next->info->setBalance(balance);
    location->next->info->setName(name);
  }
  
}

// returns the head of the list
NodeType* SortedType::getHead() {
  return listData;
}


#endif