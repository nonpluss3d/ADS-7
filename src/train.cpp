// Copyright 2021 NNTU-CS
#include "train.h"

#include <random>

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car *newCar = new Car;
  newCar->light = light;

  if (first == nullptr) {
    first = newCar;
    newCar->next = newCar;
    newCar->prev = newCar;
  } else {
    Car *last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (first == nullptr) return 0;

  int length = 0;
  const Car *current = first;
  do {
    length++;
    current = current->next;
    countOp++; // Count the move
  } while (current != first);

  return length;
}

int Train::getOpCount() { return countOp; }
