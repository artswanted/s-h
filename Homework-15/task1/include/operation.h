#include "iostream"
#pragma once

#ifndef SIMULATOR_OPERATION_H
#define SIMULATOR_OPERATION_H

struct POINT{
    double x;
    double y;
};

void scalpel_start (POINT& Begin, POINT& end);
void hemostat_start (POINT& Begin, POINT& end, POINT& temp);

#endif //SIMULATOR_OPERATION_H
