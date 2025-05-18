// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

#include <iostream>

class Train {
private:
    struct Car {
        bool light;
        Car* next;
        Car* prev;

        Car(bool l) {
            light = l;
            next = this;
            prev = this;
        }
    };

    Car* first;
    unsigned long countOp;

public:
    Train();
    ~Train();

    void addCar(bool light);

    unsigned long getLength();

    unsigned long getOpCount() const { return countOp; }
};

#endif // INCLUDE_TRAIN_H_
