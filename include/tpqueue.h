// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* mas;
    int f, l, cnt;

 public:
    TPQueue() : f(0), l(0), cnt(0) {
        mas = new T[size];
    }
    bool isEmpty() const {
        return 0 == cnt;
    }
    bool isFull() const {
        return cnt == size;
    }
    void push(const T& val) {
        if (isFull()) {
            throw std::string("is Full");
        } else {
            int a = l;
            mas[l % size] = val;
            T temp = mas[a % size];
            while (mas[(a - 1) % size].prior < mas[a % size].prior \
            && f < a) {
                temp = mas[a % size];
                mas[a % size] = mas[(a - 1) % size];
                mas[(a - 1) % size] = temp;
                a--;
            }
            cnt++;
            l++;
        }
    }
    const T& pop() {
        if (isEmpty()) {
            throw std::string("is Empty");
        } else {
            cnt--;
            return mas[f++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
