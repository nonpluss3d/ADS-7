// Copyright 2021 NNTU-CS
#include <random>

#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car *newCar = new Car;
  newCar->light = light;

  if (first == nullptr) {
    first = newCar;
    newCar->next = newCar;
    newCar->prev = newCar;

    countOp += 3;
  } else {
    Car *last = first->prev;
    countOp++;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;

    countOp += 6;
  }
}

int Train::getLength() {
  countOp = 0;

  if (!first) return 0;

  int length = 0;
  const Car *current = first;
  do {
    length++;
    countOp += 2;
    current = current->next;
  } while (current != first);

  return length;
}

int Train::getOpCount() { return countOp; }
