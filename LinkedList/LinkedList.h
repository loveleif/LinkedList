#pragma once

#include "stdafx.h"

typedef int T;

class Node {
public:
  Node* prev;
  Node* next;
  T data;

  Node(): data(NULL), prev(NULL), next(NULL) { }
  Node(T data, Node* prev, Node* next) : data(data), prev(prev), next(next) { }
  Node* InsertAfter(T data);
  Node* InsertBefore(T data);
};

class LinkedList {
private:
  Node* last;
  Node* first;
  int size;
public:
  LinkedList(): last(NULL), first(NULL), size(0) { }
  Node* PushFront(T data);
  Node* PushBack(T data);
  T PopFront();
  T PopBack();
  Node* First() { return first; }
  Node* Last() { return last; }
  int Size() { return size; }
};