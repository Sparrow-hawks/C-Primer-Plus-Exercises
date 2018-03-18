#ifndef QUEUE_H
#define QUEUE_H

class Customer {
private:
  long arrive;      // Client join time to queue
  int processtime;  // Client process time
public:
  Customer() {arrive = processtime = 0;}
  void set(long when);
  long when() const {return arrive;}
  int ptime() const {return processtime;}
};

typedef Customer Item;

class Queue {
private:
  // Class range definition
  struct Node {
    Item item;
    struct Node *next;
  };
  enum {Q_SIZE = 10};

  // Private members
  Node *front;      // Pointer to queue head
  Node *rear;       // Pointer to queue back
  int items;        // Queue size
  const int qsize;  // Maximum queue size

  // Definitions for blocking public access
  Queue(const Queue& q) : qsize(0) {}
  Queue& operator=(const Queue& q) {return *this;}

public:
  Queue(int qs = Q_SIZE);
  ~Queue();
  bool isempty() const;
  bool isfull() const;
  int queuecount() const;
  bool enqueue(const Item& item);
  bool dequeue(Item& item);
};

#endif
