#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_
#include <stdlib.h>
#include <stdio.h>

typedef char Item;
/*
  IMPORTANT!

  As we stick to pure C, we cannot use templates. We will just asume
  some type T was previously defined.
*/

// -----------------------------------------------------------------------------
/**
 *  Linked list representation -- R2 Curs2 (Slide 8)
 */
typedef struct ListNode{
	Item elem; // Stored node value
	struct ListNode* next; // link to next node
	struct ListNode* prev; // link to prev node
} ListNode;

/**
 *  Double linked list representation -- desen Curs 3 (Slide 19)
 */
typedef struct List{
	ListNode* first; // link to the first node
	ListNode* last; // link to the last node
}List;
// -----------------------------------------------------------------------------

/**
 * Create a new node
 *  [input]: Item
 *  [output]: List*
 */
ListNode *createNode(Item elem) {
	// TODO: Cerinta 1a
	ListNode* node = (ListNode*) malloc(sizeof(ListNode));
	node->elem = elem;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

/**
 * Create a new (empty)  list  -- Silde-urile 13/14 Curs 2
 *  [input]: None
 *  [output]: List*
 */
List* createList(void){
	// TODO: Cerinta 1a
	List* list = (List*) malloc(sizeof(List));
	list->first = list->last = NULL;
	return list;
}
// -----------------------------------------------------------------------------


/**
 * Determines if the list is empty
 *  [input]: List*
 *  [output]: 1 - empty/ 0 - not empty
 */
int isEmpty(List *list){
	// TODO: Cerinta 1b
	return list == NULL || list->first == NULL;
}
// -----------------------------------------------------------------------------


/**
 * Determines if a list contains a specified element
 *  [input]: List*, Item
 *  [output]: int (1 - contains/ 0 - not contains)
 */
int contains(List *list, Item elem){
	// TDOO: Cerinta 1c
	if (isEmpty(list))
		return 0;
	ListNode* itr = list->first;
	while (itr != NULL) {
		if (itr->elem == elem)
			return 1;
		itr = itr->next;
	}
	return 0;
}
// -----------------------------------------------------------------------------
/**
 * Compute list length
 *  [input]: List*
 *  [output]: int
 */
int length(List *list){
	// Guard against young player errors
	if(list == NULL) return 0;
	if(list->first == NULL) return 0;
	ListNode *itr = list->first;
	int count = 0;
	while (itr != NULL) {
		itr = itr->next;
		count++;
	}
	// TODO: Cerinta 1f
	return count;
}
// -----------------------------------------------------------------------------


/**
 * Insert a new element in the list at the specified position.
 * Note: Position numbering starts with the position at index zero
 *  [input]: List*, Item, int
 *  [output]: void
 */

void insertAt(List* list, Item elem, int pos){

	// Guard against young player errors
	int size = length(list);
	if (pos < 0 || pos > size) {
		return;
	}
	ListNode *node = createNode(elem);
	if (list == NULL) {
		return;
	}
	if (list->first == NULL) {
		list->first = list->last = node;
		return;
	}
	ListNode *itr = list->first;
	if (pos == 0) {
		node->next = itr;
		node->prev = NULL;
		itr->prev = node;
		list->first = node;
		return;
	}
	if (pos == size) {
		node->next = NULL;
		node->prev = list->last;
		list->last->next = node;
		list->last = node;
		return;
	}
	while (pos) {
		itr = itr->next;
		pos--;
	}
	node->next = itr;
	node->prev = itr->prev;
	itr->prev->next = node;
	itr->prev = node;
	// TODO: Cerinta 1d
}


// -----------------------------------------------------------------------------


/**
 * Delete the first element instance form a list.
 *  [input]: List*, Item
 *  [output]: void
 */
void deleteOnce(List *list, Item elem){
	// Guard against young player errors
	if(list == NULL) return;
	if (list->first == NULL) return;

	ListNode* itr = list->first;
	while (itr->elem != elem && itr != NULL) {
		itr = itr->next;
	}
	if (itr == NULL) {
		printf("Elementul nu a fost gasit!");
		return;
	}
	if (itr == list->first) {
		ListNode* tmp = itr;
		list->first = list->first->next;
		if (list->first != NULL) {
			list->first->prev = NULL;
		} else {
			list->last == NULL;
		}
		free(tmp);
		return;
	}
	if (itr == list->last) {
		ListNode* tmp = itr;
		list->last = list->last->prev;
		if (list->last != NULL)
			list->last->next = NULL;
		else
			list->first = NULL;
		free(tmp);
		return;
	}
	ListNode* tmp = itr;
	itr->prev->next = itr->next;
	itr->next->prev = itr->prev;
	free(tmp);
	//TODO: Cerinta 1e
}
// -----------------------------------------------------------------------------





/**
 * Destroy a list.
 *  [input]: List*
 *  [output]: void
 */
List* destroyList(List* list){
	// Guard against young player errors
	if(list == NULL) return NULL;
	ListNode *itr = list->first;
	while (itr != NULL) {
		ListNode *temp = itr;
		itr = itr->next;
		free(temp);
	}
	free(list);
	//TODO: Cerinta 1g
	return NULL;
}
// -----------------------------------------------------------------------------


#endif //_DOUBLE_LINKED_LIST_H_
