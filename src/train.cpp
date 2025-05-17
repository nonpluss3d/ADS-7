// Copyright 2021 NNTU-CS
#include "train.h"

#include <random>

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car *newCar = new Car;
  countOp++;
  newCar->light = light;
  countOp++;

  if (first == nullptr) {
    first = newCar;
    countOp++;
    newCar->next = newCar;
    countOp++;
    newCar->prev = newCar;
    countOp++;
  } else {
    Car *last = first->prev;
    countOp++;
    
    last->next = newCar;
    countOp++;
    newCar->prev = last;
    countOp++;
    newCar->next = first;
    countOp++;
    first->prev = newCar;
    countOp++;
  }
}

int Train::getLength() {
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
