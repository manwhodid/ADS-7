// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCar(bool light) {
    Car* newCar = new Car;

    newCar->light = light;

    if (first == nullptr) {
        first = newCar;

        first->next = first;
        first->prev = first;
    } else {
        Car* cur = first;

        while (cur->next != first) {
            cur = cur->next;
        }

        cur->next = newCar;

        newCar->prev = cur;
        newCar->next = first;

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

    countOp += 2;

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
