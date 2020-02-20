/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Implementation file for a pointer-based implementation of the ADT
 *  sorted list.
 *
 *  Adapted from pages 374-377 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 3 Apr 2016
 *
 *  @version 7.0 */

// #define NDEBUG

#include <string>
#include <new>
#include <memory>

#include <cassert>

#include "PrecondViolatedExcep.h"

template <typename ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList) {

   try {
      headPtr = copyChain(aList.headPtr);

      itemCount = aList.itemCount;
   }
   catch (const std::bad_alloc&) {
      clear();
      throw;
   }
}

template <typename ItemType>
std::shared_ptr<Node<ItemType>>
LinkedSortedList<ItemType>::copyChain(const std::shared_ptr<Node<ItemType>>& origChainPtr) {

   std::shared_ptr<Node<ItemType>> copiedChainPtr;

   if (origChainPtr != nullptr) {
      // Note that std::make_shared may throw a std::bad_alloc exception:
      copiedChainPtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem() );

      copiedChainPtr->setNext(copyChain(origChainPtr->getNext()) );
   }

   return copiedChainPtr;
}

template <typename ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const {

   return itemCount == 0;
}

template <typename ItemType>
int LinkedSortedList<ItemType>::getLength() const {

   return itemCount;
}

template <typename ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry) {

   bool canInsert(true);

   try {
      auto prevPtr(getNodeBefore(newEntry) );

      if (isEmpty() || prevPtr == nullptr) {
         headPtr = std::make_shared<Node<ItemType>>(newEntry, headPtr);
      }
      else {
         auto newNodePtr(std::make_shared<Node<ItemType>>(newEntry, prevPtr->getNext()) );

         prevPtr->setNext(newNodePtr);
      }

      ++itemCount;
   }
   catch (const std::bad_alloc&) {
      canInsert = false;
   }

   return canInsert;
}

template <typename ItemType>
auto LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const {

   auto curPtr(headPtr);
   std::shared_ptr<Node<ItemType>> prevPtr;

   while (curPtr != nullptr && anEntry > curPtr->getItem() ) {
      prevPtr = curPtr;
      curPtr = curPtr->getNext();
   }

   return prevPtr;
}

template <typename ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry) {

   bool ableToRemove(false);

   if (!isEmpty() ) {
      int position(getPosition(anEntry) );

      if (position > 0) {
         auto prevPtr(getNodeBefore(anEntry) );

         auto curPtr(prevPtr->getNext() );

         prevPtr->setNext(curPtr->getNext() );

         --itemCount;

         ableToRemove = true;
      }
   }

   return ableToRemove;
}

template <typename ItemType>
bool LinkedSortedList<ItemType>::remove(const int position) {

   bool ableToRemove(position >= 1 &&
                     position <= itemCount);

   if (ableToRemove) {
      if (position == 1) {
         headPtr = headPtr->getNext();
      }
      else {
         auto prevPtr(getNodeAt(position - 1) );

         auto curPtr(prevPtr->getNext() );

         prevPtr->setNext(curPtr->getNext() );
      }

      --itemCount;
   }

   return ableToRemove;
}

template <typename ItemType>
void LinkedSortedList<ItemType>::clear() {

   headPtr = nullptr;
   itemCount = 0;
}

template <typename ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(const int position) const {

   bool ableToGet(position >= 1 &&
                  position <= itemCount);

   if (!ableToGet) {
      std::string message("LinkedSortedList::getEntry() called with an empty ");
      message += "list or an invalid position.";

      throw PrecondViolatedExcep(message);
   }

   auto nodePtr(getNodeAt(position) );

   return nodePtr->getItem();
}

template <typename ItemType>
auto LinkedSortedList<ItemType>::getNodeAt(const int position) const {

   assert(position >= 1 && position <= itemCount);

   auto curPtr(headPtr);

   for (int skip(1); skip < position; ++skip) {
      curPtr = curPtr->getNext();
   }

   return curPtr;
}

template <typename ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& anEntry) const {

   int pos(1);
   auto curPtr(headPtr);
   bool foundIt(false);

   while (!foundIt && curPtr != nullptr && anEntry >= curPtr->getItem() ) {
      if (curPtr->getItem() == anEntry) {
         foundIt = true;
      }
      else {
         curPtr = curPtr->getNext();
         ++pos;
      }
   }

   if (!foundIt) {
      pos = -pos;
   }

   return pos;
}
