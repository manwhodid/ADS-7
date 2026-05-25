// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCar(bool light) {
    Car* newCar = new Car;

    newCar->light = light;
    newCar->next = nullptr;
    newCar->prev = nullptr;

    if (first == nullptr) {
        first = newCar;

        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;

        newCar->next = first;
        newCar->prev = last;

        last->next = newCar;
        first->prev = newCar;
    }
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
        cur = cur->next;
    }

    countOp = len * 2 + 2;

    return len;
}

int Train::getOpCount() {
  return countOp;
}
