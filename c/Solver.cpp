#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Solver.h"
#include "Enum.h"

static const double epsilon = 1e-8;

//------------------------------------------------------------------------------------------------------------------------------------------

NUM_ROOTS SolveEquatoin2 (double a, double b, double c, double* x1, double* x2)
{
    if (IsNull(a))  // IsZero
    {
        if (IsNull(b))
        {
            return IsNull(c) ? InfinityRoots : ZeroRoots;  // вынеси линейный и квалратный случаи в отдельные функции
        }
        else
        {
            *x1 = -c/b;
            return OneRoot;
        }
    }
    else
    {
        double d = b * b - 4 * a * c;

        if (IsNull(d))
        {
            *x1 = *x2=-b / (2 * a);
            return OneRoot;
        }

        if (d > 0)
        {
            double sqrt_d = sqrt(d);
            *x1 = (-b - sqrt_d)/(2 * a);
            *x2 = (-b + sqrt_d)/(2 * a);
            return TwoRoots;
        }

        return ZeroRoots;
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------

void SortingCasesSE2(NUM_ROOTS QuantityRoots, double x1, double x2)
{
    assert(x1 != NAN);
    assert(x2 != NAN);

    switch(QuantityRoots)
    {
      case ZeroRoots:
        printf("Нет корней");
        break;
      case OneRoot:
        printf("x = %lg\n", x1);
        break;
      case TwoRoots:
        printf("x1 = %lg, x2 = %lg\n", x1, x2);
        break;
      case InfinityRoots:
        printf("Бесконечно корней");
        break;

        default:
            printf("Сам с этим развлекайся, я хлебушеко\n");
    }
}


//--------------------------------------------------------------------------------------------------------------------------------------------

int IsNull(double s)
{
    return (-epsilon < s) && (s < epsilon);
}


