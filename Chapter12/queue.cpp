#include <cstdlib>
#include "queue.h"

// Queue class methods
Queue::Queue(int qs) : qsize(qs) {
  front = rear = nullptr;
  items = 0;
}

Queue::~Queue() {
  Node *temp;
  while (front != NULL) {   // To queue empty
    temp = front;
    front = front->next;
    delete temp;
  }
}

bool Queue::isempty() const {
  return items == 0;
}

bool Queue::isfull() const {
  return items == qsize;
}

int Queue::queuecount() const {
  return items;
}

// Queue element add
bool Queue::enqueue(const Item &item) {
  if (isfull())
    return false;
  Node *add = new Node;   // Create node
  add->item = item;
  add->next = nullptr;
  items++;
  if (front == nullptr)   // If queue is empty
    front = add;          // Put element on head
  else
    rear->next = add;     // In other case, put element on end
  rear = add;

  return true;
}

// Copy head element to argument & remove it from queue
bool Queue::dequeue(Item &item) {
  if (front == nullptr)
    return false;
  item = front->item;   // Copy first element to item
  items--;

  Node *temp = front;   // Save first element place
  front = front->next;  // Move front pointer to next element
  delete temp;          // Delete first element
  if (items == 0)
    rear = nullptr;
  return true;
}

// Customer class methods

// When client goes to queue, current system time is saved.
// Also process time is set (rand from 1 to 3).
void Customer::set(long when) {
  processtime = std::rand() % 3 + 1;
  arrive = when;
}
