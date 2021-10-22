#ifndef SIMULATOR_OPERATION_H
#define SIMULATOR_OPERATION_H

#include "iostream"
#include "message_box.h"
using namespace std;

#pragma once

struct POINT{
    double x;
    double y;
};

void scalpel_start (POINT& begin, POINT& end);
void hemostat_start (POINT& begin, POINT& end, POINT& temp);
void tweezers_start (POINT& begin, POINT& end, POINT& temp);
void suture_start (POINT& begin, POINT& end);

#endif //SIMULATOR_OPERATION_H
