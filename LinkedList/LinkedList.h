#pragma once

#include "stdafx.h"

/*
 * Represents one node in a double linked list.
 */
template <class T>
class Node {
public:
  Node<T>* prev;
  Node<T>* next;
  T data;

  /* Constructors */
  Node(T data): data(T), prev(nullptr), next(nullptr) { }
  Node(T data, Node* prev, Node* next) : data(data), prev(prev), next(next) { }
  
  /* Creates a new Node and inserts is after this node. */
  const Node<T>* InsertAfter(T data);
  
  /* Creates a new Node and inserts is before this node. */
  const Node<T>* InsertBefore(T data);
};

/*
 * Double linked list.
 */
template <class T>
class LinkedList {
private:
  Node<T>* last;
  Node<T>* first;
  int size;
public:
  /* Constructor */
  LinkedList(): last(nullptr), first(nullptr), size(0) { }
  
  /* Destructor */
  ~LinkedList();

  /* Adds a new item to the front of the list. Returns pointer to the newly 
   * created Node.
   */
  const Node<T>* PushFront(T data);
  
  /* Adds a new item to the back of the list. Returns pointer to the newly 
   * created Node.
   */
  const Node<T>* PushBack(T data);

  /* Removes the first item of the list and returns its value. */
  T PopFront();

  /* Removes the last item of the list and returns its value. */
  T PopBack();

  /* Returns a pointer to the first Node of the list. */
  const Node<T>* First() { return first; }
  
  /* Returns a pointer to the last Node of the list. */
  const Node<T>* Last() { return last; }
  
  /* Returns the number of items currently in the list. */
  int Size() { return size; }
};

template <class T>
Node<T>* NodeInsert(Node<T>* node_before, Node<T>* node_after, const T& new_data) {
  Node<T>* new_node = new Node<T>(new_data, node_before, node_after);

  if (node_before != nullptr)
    node_before->next = new_node;
  if (node_after != nullptr)
    node_after->prev = new_node;

  return new_node;
}

template <class T>
T NodeRemove(Node<T>* node_pop) {
  if (node_pop->prev != nullptr)
    node_pop->prev->next = node_pop->next;
  if (node_pop->next != nullptr)
    node_pop->next->prev = node_pop->prev;
  
  T data = node_pop->data;
  delete node_pop;
  return data;
}

template <class T>
const Node<T>* Node<T>::InsertBefore(T data) {
  return NodeInsert(this->prev, this, data);
}

template <class T>
const Node<T>* Node<T>::InsertAfter(T data) {
  return NodeInsert(this, this->next, data);
}

template <class T>
LinkedList<T>::~LinkedList() {
  auto tmp = first;
  while (first != nullptr) {
    tmp = first;
    first = first->next;
    delete tmp;
  }
}

template <class T>
const Node<T>* LinkedList<T>::PushFront(T data) {
  first = NodeInsert<T>(nullptr, first, data);
  if (last == nullptr)
    last = first;
  size++;
  return first;
}

template <class T>
const Node<T>* LinkedList<T>::PushBack(T data) {
  if (size == 0)
    return PushFront(data);
  
  last = NodeInsert<int>(last, nullptr, data);
  size++;
  return last;
}

template <class T>
T LinkedList<T>::PopFront() {
  if (size <= 0)
    return NULL;

  Node<T>* pop = first;
  if (size == 1) {
    first = nullptr;
    last = nullptr;
  } else
    first = first->next;

  size--;
  return NodeRemove(pop);
}

template <class T>
T LinkedList<T>::PopBack() {
  if (size <= 0)
    return NULL;

  Node<T>* pop = last;
  if (size == 1) {
    first = nullptr;
    last = nullptr;
  } else
    last = last->prev;

  size--;
  return NodeRemove(pop); 
}