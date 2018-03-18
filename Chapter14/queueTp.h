#ifndef _QUEUETP_H_
#define _QUEUETP_H_

#include <iostream>

template<typename T>
class QueueTp {
private:
  enum {MAX = 20};

  size_t m_Size;
  T m_Data[MAX];
  size_t m_Head;
  size_t m_Tail;
  size_t m_Next;

  void inline inc(size_t& element) {element = element + 1 % MAX;}

public:
  QueueTp();
  ~QueueTp();

  T& first();
  T& back();

  const T& first() const;
  const T& back() const;

  bool empty() const {return m_Size == 0;}
  size_t size() const {return m_Size;}

  void push(const T& element);
  void pop();
};

template<typename T>
QueueTp<T>::QueueTp() : m_Size (0), m_Head (0), m_Tail(0), m_Next(0) {

}

template<typename T>
QueueTp<T>::~QueueTp() {

}

template<typename T>
T& QueueTp<T>::first() {
  return m_Data[m_Head];
}

template<typename T>
T& QueueTp<T>::back() {
  return m_Data[m_Tail];
}

template<typename T>
const T& QueueTp<T>::first() const {
  return m_Data[m_Head];
}

template<typename T>
const T& QueueTp<T>::back() const {
  return m_Data[m_Tail];
}

template<typename T>
void QueueTp<T>::push(const T& element) {
  if (m_Size < MAX) {
    m_Data[m_Next] = element;
    m_Tail = m_Next;
    inc(m_Next);

    ++m_Size;
  }
}

template<typename T>
void QueueTp<T>::pop() {
  if (m_Size != 0) {
    inc(m_Head);
    if (m_Size == 1)
      inc(m_Tail);

    --m_Size;
  }
}

#endif
