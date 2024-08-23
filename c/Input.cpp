#include "Input.h"
#include "Tester.h"
#include "Solver.h"

#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

static bool ClearingInput ();

static int IsFinite (double n);

static bool IsNAN (double n);

static bool IsInf (double n);


//------------------------------------------------------------------------------------------------------------------------------------------

bool Input (double* a, double* b, double* c)
{
    int NumInput = 0;

    while (((NumInput = scanf ("%lg %lg %lg", a, b, c)) != 3) || (IsFinite(*a) != 1) || (IsFinite(*b) != 1) || (IsFinite(*c) != 1))
    {
        if(!ClearingInput ())
        {
            return 0;
        }
        printf("Попробуй ещё раз\n");
    }
    return 1;
}

//----------------------------------------------------------------------------------------------------

bool ClearingInput ()
{
     int str = 0;
     while ((str = getchar()) != '\n')
    {
        if (str == EOF)
        {
            return 0;
        }
    }
    return 1;
}

//------------------------------------------------------------------------------------------------------------------------------------

int IsFinite (double n)
{
    return !(IsInf(n) || IsNAN(n));
}

//-------------------------------------------------------------------------------------------------------------------------------------

bool IsNAN (double n)
{
    return (!Comparison(n, n));
}

//-------------------------------------------------------------------------------------------------------------------------------------

bool IsInf (double n)
{
    return (!IsNull(n * 0));
}

