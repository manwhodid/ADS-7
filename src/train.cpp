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
  if (first == nullptr) {
    return 0;
  }

  int len = 1;

  Car* cur = first->next;

  countOp = 0;

  while (cur != first) {
    len++;
    countOp += 2;
    cur = cur->next;
  }

  return len;
}

int Train::getOpCount() {
  return countOp;
}
