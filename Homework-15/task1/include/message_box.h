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
    WELCOME,
    SCALPEL_FIRST,
    SCALPEL_SECOND,
    SCALPEL_CUT_1,
    SCALPEL_CUT_2,
    HEMOSTAT_START,
    HEMOSTAT_ERROR
};

void print_message(int iType);
void print_message_advance(int iType, double x, double y);


#endif //SIMULATOR_MESSAGE_BOX_H
