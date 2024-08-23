#ifndef ENUM_H
#define ENUM_H

#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
enum NUM_ROOTS {ZeroRoots = 0,
                OneRoot = 1,
                TwoRoots = 2,
                InfinityRoots = 3};

enum USER_MODE {
    SOLVE,
    TEST
};

#endif //ENUM_H
