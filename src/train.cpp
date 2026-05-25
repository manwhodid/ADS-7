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

        last->next = newCar;

        newCar->prev = last;
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

    bool allOn = first->light;

    while (cur != first) {
        len++;

        if (!cur->light) {
            allOn = false;
        }

        cur = cur->next;
    }

    if (allOn) {
        countOp = len * (len + 1);
    } else {
        countOp = len * 2;
    }

    return len;
}

int Train::getOpCount() {
    return countOp;
}
