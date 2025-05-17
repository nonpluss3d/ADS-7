// Copyright 2021 NNTU-CS
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
  if (!first) return 0;

  countOp = 0;
  Car* current = first;

  bool initialLight = current->light;
  current->light = !initialLight;
  countOp++;

  int stepsForward = 1;
  current = current->next;
  countOp++;

  while (current->light != !initialLight) {
    current = current->next;
    countOp++;
    stepsForward++;
  }

  int stepsBackward = 0;
  while (current != first) {
    current = current->prev;
    countOp++;
    stepsBackward++;
  }

  first->light = initialLight;
  countOp++;

  return stepsForward;
}

int Train::getOpCount() { return countOp; }
