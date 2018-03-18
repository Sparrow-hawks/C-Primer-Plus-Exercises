#include <iostream>
#include "list.h"

List::List() : m_First {nullptr}, m_Last {nullptr}, m_Size {0} {

}

List::~List() {
  for (Node *pNode = m_First; pNode != nullptr; ) {
    Node *pCurrent = pNode;

    pNode = pNode->next;

    delete pCurrent;
  }
}

size_t List::size() const {
  return m_Size;
}

bool List::isEmpty() const {
  return m_Size == 0;
}

bool List::isFull() const {
  return m_Size == MAX;
}

void List::push(const Item& item) {
  // Check is enough space in List
  if (!isFull()) {
    Node *pNode = new Node ({nullptr, item});

    // If list was empty, m_First shell be update too
    if (isEmpty())
      m_First = m_Last = pNode;

    m_Last = m_Last->next = pNode;

    ++m_Size;
  } else {
    std::cerr << "[ERROR]: Not enough space!" << std::endl;
  }
}

Item List::pop() {
  Item item {};
  // Check list if is empty
  if (isEmpty()) {
    std::cerr << "[ERROR]: List is empty!" << std::endl;
  } else {
    item = m_Last->item;

    Node *pNode = m_First;
    if (size() == 1) {
      delete m_Last;

      m_First = m_Last = nullptr;
    } else {
      for (pNode = m_First; pNode->next != m_Last; pNode = pNode->next)
        ;
      pNode->next = nullptr;

      delete m_Last;

      m_Last = pNode;
    }
    --m_Size;
  }
  return item;
}

void List::visit(void (*pf)(Item &)) {
  if (!isEmpty()) {
    for (Node *pNode = m_First; pNode != m_Last; pNode = pNode->next) {
      (*pf)(pNode->item);
    }
  } else {
    std::cerr << "[ERROR]: List is empty!" << std::endl;
  }
}
