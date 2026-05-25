// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCar(bool light) {
  Car* n = new Car;

  n->light = light;

  if (first == nullptr) {
    first = n;
    n->next = n;
    n->prev = n;
    return;
  }

  Car* last = first->prev;

  n->next = first;
  n->prev = last;

  last->next = n;
  first->prev = n;
}

int Train::getLength() {
    countOp = 0;

    if (first == nullptr) {
        return 0;
    }

    int len = 1;

    const Car* cur = first->next;

    while (cur != first) {
        len++;
        countOp += 2;
        cur = cur->next;
    }

    countOp += 2;

    return len;
}

int Train::getOpCount() {
  return countOp;
}
