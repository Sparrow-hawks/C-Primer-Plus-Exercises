#include <cstring>
#include "stack.h"

// Constructor, create empty stack
Stack::Stack(int n) {
  pitems = new Item[n];
  size = n;
  top = 0;
}

Stack::Stack(const Stack& st) {
  pitems = new Item[st.size];
  size = st.size;
  top = st.top;

  memcpy(pitems, st.pitems, st.size);
}

Stack::~Stack() {
  delete [] pitems;
}

bool Stack::isempty() const {
  return top == 0;
}

bool Stack::isfull() const {
  return top == MAX;
}

bool Stack::push(const Item& item) {
  if (top < MAX) {
    pitems[top++] = item;
    return true;
  } else
    return false;
}

bool Stack::pop(Item& item) {
  if (top > 0) {
    item = pitems[--top];
    return true;
  } else
    return false;
}

Stack& Stack::operator=(const Stack& st) {
  if (this != &st) {
    delete pitems;

    pitems = new Item [st.size];
    size = st.size;
    top = st.top;

    memcpy(pitems, st.pitems, st.size);
  }

  return *this;
}
