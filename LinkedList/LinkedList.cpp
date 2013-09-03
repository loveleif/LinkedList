#include "stdafx.h"
#include "LinkedList.h"

Node* NodeInsert(Node* node_before, Node* node_after, const T& new_data) {
  Node* new_node = new Node(new_data, node_before, node_after);

  if (node_before != NULL)
    node_before->next = new_node;
  if (node_after != NULL)
    node_after->prev = new_node;

  return new_node;
}

T NodeRemove(Node* node_pop) {
  if (node_pop->prev != NULL)
    node_pop->prev->next = node_pop->next;
  if (node_pop->next != NULL)
    node_pop->next->prev = node_pop->prev;
  
  T data = node_pop->data;
  delete node_pop;
  return data;
}

Node* Node::InsertBefore(T data) {
  return NodeInsert(this->prev, this, data);
}

Node* Node::InsertAfter(T data) {
  return NodeInsert(this, this->next, data);
}

Node* LinkedList::PushFront(T data) {
  first = NodeInsert(NULL, first, data);
  if (last == NULL)
    last = first;
  size++;
  return first;
}

Node* LinkedList::PushBack(T data) {
  if (size == 0)
    return PushFront(data);
  
  last = NodeInsert(last, NULL, data);
  size++;
  return last;
}

T LinkedList::PopFront() {
  if (size <= 0)
    return NULL;

  Node* pop = first;
  if (size == 1) {
    first = NULL;
    last = NULL;
  } else
    first = first->next;

  size--;
  return NodeRemove(pop);
}

T LinkedList::PopBack() {
  if (size <= 0)
    return NULL;

  Node* pop = last;
  if (size == 1) {
    first = NULL;
    last = NULL;
  } else
    last = last->prev;

  size--;
  return NodeRemove(pop); 
}