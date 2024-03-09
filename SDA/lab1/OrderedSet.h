#ifndef ORDERED_SET_H
#define ORDERED_SET_H

#include <stdio.h>                                          // needed for printf
#include <stdlib.h>                           // needed for alloc, realloc, free

/*
  IMPORTANT!

  As we stick to pure C, we cannot use templates. We will just asume
  some type T was previously defined.
*/

// -----------------------------------------------------------------------------

/*
  OrderedSet represents a set with elements of type T stored in memory
  in an ordered fashion.
*/

typedef struct OrderedSet {
  T* elements;                    // pointer to where the elements are in memory
  long size;                                // the number of elements in the set
  long capacity;                      // the current capacity (allocated memory)
} OrderedSet;

// -----------------------------------------------------------------------------

/*
  Function that creates an OrderedSet with elements of type T with a given
  initial capacity.
*/

OrderedSet* createOrderedSet(long initialCapacity) {

  OrderedSet* newSet = (OrderedSet*) malloc(sizeof(OrderedSet));

  newSet->size = 0;                        // initially, the set is empty
  newSet->capacity = initialCapacity;
  newSet->elements = (T*) malloc(initialCapacity * sizeof(T));

  return newSet;
}

// -----------------------------------------------------------------------------

/*
  Function that checks if an element exists in a given set. As the
  elements of the set are ordered in memory, this function uses binary
  search.

  Function returns 1 if the given element exists in the set, and 0
  otherwise.
*/

int contains(OrderedSet* set, const T element) {
  // TODO : Cerința 2
  int mid;
  int l = 0;
  int r = set->size - 1;
  while (l <= r) {
    mid = l + (r-l) / 2;
    if (set->elements[mid] == element) {
      return 1;
    } else if (set->elements[mid] > element) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return 0;
}

// -----------------------------------------------------------------------------

/*
  Function that adds a new element to a set. If the element was
  already in the set, nothing changes. Otherwise, the element is added
  to the set. In the end, the elements must be in ascending order.
*/

void add(OrderedSet* set, const T newElement) {
  T* temp;
  if (set->size == set->capacity) {
    temp = (T*) realloc(set, (set->capacity * 2) * sizeof(T));
    if (temp == NULL) {
      return;
    }
    set->elements = temp;
    set->capacity = set->capacity * 2;
  }
  if (contains(set, newElement) == 1) {
    return;
  }
  int i = 0;
  for (i = set->size; i > 0 ; i--) {
    if (set->elements[i] < newElement) {
      break;
    }
    set->elements[i] = set->elements[i - 1];
  }
  set->elements[i + 1] = newElement;
  // TODO : Cerința 2
}

// -----------------------------------------------------------------------------

/*
  This function takes two ordered sets with elements of type T and it
  returns the addres of a new ordered set representing the union of
  the two
*/

OrderedSet* unionOrderedSets(OrderedSet* s1, OrderedSet* s2) {
  // TODO : Cerința 3
  OrderedSet* unionSet = createOrderedSet(s1->size + s2->size);
  int i = 0, j = 0, k = 0;
  while (i < s1->size && j < s2->size) {
    if (s1->elements[i] < s2->elements[j]) {
      unionSet->elements[k++] = s1->elements[i];
    }
  }
  return unionSet;
}

// -----------------------------------------------------------------------------

/*
  This function takes two ordered sets with elements of type T and it
  returns the addres of a new ordered set representing the
  intersection of the two
*/

OrderedSet* intersectOrderedSets(OrderedSet* s1, OrderedSet* s2) {
  // TODO : Cerința 3
  

  return createOrderedSet(1);
}


// -----------------------------------------------------------------------------

#endif
