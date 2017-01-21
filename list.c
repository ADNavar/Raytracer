/* List functions */

#include "list.h"

/** newList -- create a new list object **/
list_t *newList() {
    list_t *newList;
    newList = (list_t *)malloc(sizeof(list_t));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}


/** l_add -- add an object to the linked list **/
void l_add(list_t *list, void *objPtr) {
   node_t *newNode;
   /* Create new node */
   newNode = (node_t *)malloc(sizeof(node_t));
   newNode->objPtr = objPtr;
   newNode->next = NULL;

   /* Link new node onto end of list */
   if (list->tail != NULL) {
      /* Point node currently at end of list to this new node */
      list->tail->next = newNode;
   }
   else {
      /* List currently empty -- need to point head to new node */
      list->head = newNode;
   }
   /* Always point tail to new node */
   list->tail = newNode;
}

/** newIterator -- create a new iterator and associate it with the
                   specified list
**/
iterator_t *newIterator(list_t *list) {
   iterator_t *newIter;
   newIter = (iterator_t *)malloc(sizeof(iterator_t));
   newIter->list = list;
   newIter->position = list->head;
   return(newIter);
}

/** l_next -- return the object pointed to by the node pointed to by
            position, and then advance position to the next node in 
            the list.
**/
void *l_next(iterator_t *iter) {
    node_t *nodePtr = iter->position;
    if (nodePtr == NULL) {
       return NULL;
    }

    /* Advance to next node in list */
    iter->position = iter->position->next;
    return (nodePtr->objPtr);
}

/** l_begin -- reset position to point to first node of list **/
void l_begin(iterator_t *iter) {
    iter->position = iter->list->head;
}

/** l_hasnext -- test for end of list **/
int l_hasnext(iterator_t *iter) {
   if (iter->position != NULL) {
      return(1);
   }
   else {
      return(0);
   }
}

