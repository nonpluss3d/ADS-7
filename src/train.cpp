// Copyright 2021 NNTU-CS
#include <cstdlib>

#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};

  if (!first) {
    first = newCar;
    newCar->next = newCar;
    newCar->prev = newCar;
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

  if (!first) return 0;

  Car* current = first;

  current->light = true;
  countOp++;

  int steps = 1;
  current = current->next;
  countOp++;

  while (!current->light) {
    current = current->next;
    countOp++;
    steps++;
  }

  return steps;
}

int Train::getOpCount() { return countOp; }
