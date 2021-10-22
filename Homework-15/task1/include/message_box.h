//
// Created by dmytro on 22.10.2021.
//
#ifndef SIMULATOR_MESSAGE_BOX_H
#define SIMULATOR_MESSAGE_BOX_H

#include "operation.h"

enum ERROR{
    ALREADY_STARTED = 1,
    WRONG_INPUT,
    WRONG_START,
    NEXT_STEP,
    WELCOME
};

void print_message(int iType);


#endif //SIMULATOR_MESSAGE_BOX_H
