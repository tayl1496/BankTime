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
 *  @date 24 Oct 2018
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
std::shared_ptr<Node<ItemType>>se {
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
ItemType LinkedSortedList<ItemType>::getEntry(int position) const {

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
auto LinkedSortedList<ItemType>::getNodeAt(int position) const {

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

  while (!foundIt && curPtr && anEntry >= curPtr->getItem() ) {
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
