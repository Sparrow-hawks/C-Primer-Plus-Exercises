#ifndef _LIST_H
#define _LIST_H

#include <iostream>

typedef double Item;

class List {
public:
  List();
  ~List();

  void push(const Item& item);
  Item pop(void);

  void visit(void (*pf)(Item&));

  bool isEmpty() const;
  bool isFull() const;

  size_t size() const;
private:
  enum {MAX = 10};

  struct Node {
    Node *next;
    Item item;
  };

  Node* m_First;
  Node* m_Last;

  size_t m_Size;
};

#endif
