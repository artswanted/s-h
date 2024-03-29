//
// Created by dmytro on 22.10.2021.
//
#ifndef SIMULATOR_MESSAGE_BOX_H
#define SIMULATOR_MESSAGE_BOX_H

#include "operation.h"

enum MESSAGE{
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
    HEMOSTAT_ERROR,
    HEMOSTAT_CUT,
    TWEEZERS_START,
    TWEEZERS_ERROR,
    TWEEZERS_CUT,
    SUTURE_FINISH,
    SUTURE_LINE_1,
    SUTURE_LINE_2
};

void print_message(int iType);
void print_message_advance(int iType, double x, double y);


#endif //SIMULATOR_MESSAGE_BOX_H
