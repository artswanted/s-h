#ifndef SIMULATOR_OPERATION_H
#define SIMULATOR_OPERATION_H

#include "iostream"
using namespace std;

#pragma once

struct POINT{
    double x;
    double y;
};

void scalpel_start (POINT& Begin, POINT& end);
void hemostat_start (POINT& Begin, POINT& end, POINT& temp);
void tweezers_start (POINT& Begin, POINT& end, POINT& temp);
void suture_start (POINT& Begin, POINT& end);

#endif //SIMULATOR_OPERATION_H
