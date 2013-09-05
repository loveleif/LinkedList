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

  Node(): data(NULL), prev(NULL), next(NULL) { }
  Node(T data, Node* prev, Node* next) : data(data), prev(prev), next(next) { }
  Node<T>* InsertAfter(T data);
  Node<T>* InsertBefore(T data);
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
  LinkedList(): last(NULL), first(NULL), size(0) { }
  ~LinkedList();
  Node<T>* PushFront(T data);
  Node<T>* PushBack(T data);
  T PopFront();
  T PopBack();
  Node<T>* First() { return first; }
  Node<T>* Last() { return last; }
  int Size() { return size; }
};

template <class T>
Node<T>* NodeInsert(Node<T>* node_before, Node<T>* node_after, const T& new_data) {
  Node<T>* new_node = new Node<T>(new_data, node_before, node_after);

  if (node_before != NULL)
    node_before->next = new_node;
  if (node_after != NULL)
    node_after->prev = new_node;

  return new_node;
}

template <class T>
T NodeRemove(Node<T>* node_pop) {
  if (node_pop->prev != NULL)
    node_pop->prev->next = node_pop->next;
  if (node_pop->next != NULL)
    node_pop->next->prev = node_pop->prev;
  
  T data = node_pop->data;
  delete node_pop;
  return data;
}

template <class T>
Node<T>* Node<T>::InsertBefore(T data) {
  return NodeInsert(this->prev, this, data);
}

template <class T>
Node<T>* Node<T>::InsertAfter(T data) {
  return NodeInsert(this, this->next, data);
}

template <class T>
LinkedList<T>::~LinkedList() {
  auto tmp = first;
  while (first != NULL) {
    tmp = first;
    first = first->next;
    delete tmp;
  }
}

template <class T>
Node<T>* LinkedList<T>::PushFront(T data) {
  first = NodeInsert<T>(NULL, first, data);
  if (last == NULL)
    last = first;
  size++;
  return first;
}

template <class T>
Node<T>* LinkedList<T>::PushBack(T data) {
  if (size == 0)
    return PushFront(data);
  
  last = NodeInsert<int>(last, NULL, data);
  size++;
  return last;
}

template <class T>
T LinkedList<T>::PopFront() {
  if (size <= 0)
    return NULL;

  Node<T>* pop = first;
  if (size == 1) {
    first = NULL;
    last = NULL;
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
    first = NULL;
    last = NULL;
  } else
    last = last->prev;

  size--;
  return NodeRemove(pop); 
}