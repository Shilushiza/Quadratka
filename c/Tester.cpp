#include "Tester.h"
#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Enum.h"
#include "Solver.h"

static void SolvesCheckerSE2(double NumTest, double k1, double k2, double k3, double x1Correct, double x2Correct, NUM_ROOTS QuantityRootsCorrect,
                      double* x1, double* x2);
static double const EpsilonForTests = 1e-3;

//---------------------------------------------------------------------------------------------------------------------------------------

bool Comparison (double k, double l)
{
    return ((EpsilonForTests > (k-l)) && ((k-l) > -EpsilonForTests));
}

//-----------------------------------------------------------------------------------------------------------------------------------------------


void SolvesCheckerSE2(double NumTest, double k1, double k2, double k3, double x1Correct, double x2Correct, NUM_ROOTS QuantityRootsCorrect,
                      double* x1, double* x2)
{
    *x1 = NAN;
    *x2 = NAN;
    NUM_ROOTS QuantityRoots = SolveEquatoin2(k1, k2, k3, x1, x2);


    if (QuantityRoots == TwoRoots)
    {
        if (QuantityRoots != QuantityRootsCorrect || !Comparison(*x1, x1Correct) || !Comparison(*x2, x2Correct))
        {
            printf ("������ ����� %lg: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, QuantityRoots = %d\n"
                    "��������� �����: x1 = %lg, x2 = %lg, QuantityRoots = %d\n",
                    NumTest, k1, k2, k3, *x1, *x2, QuantityRoots,
                    x1Correct, x2Correct, QuantityRootsCorrect);
        }
        else
        {
            printf ("���� %lg �������: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, QuantityRoots = %d\n",
                    NumTest, k1, k2, k3, *x1, *x2, QuantityRoots);
        }
    }


    else if (QuantityRoots == OneRoot)
    {
        if (QuantityRoots != QuantityRootsCorrect || !Comparison(*x1, x1Correct))
        {
            printf ("������ ����� %lg: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, QuantityRoots = %d\n"
                    "��������� �����: x = %lg, QuantityRoots = %d\n",
                    NumTest, k1, k2, k3, *x1, *x2, QuantityRoots,
                    x1Correct, QuantityRootsCorrect);
        }
        else
        {
            printf ("���� %lg �������: a = %lg, b = %lg, c = %lg, x = %lg, QuantityRoots = %d\n",
                    NumTest, k1, k2, k3, *x1, QuantityRoots);
        }
    }


    else if (QuantityRoots == ZeroRoots)
    {
        if (QuantityRoots != QuantityRootsCorrect)
        {
            printf ("������ ����� %lg: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, QuantityRoots = %d\n"
                    "��������� �����: QuantityRoots = %d\n",
                    NumTest, k1, k2, k3, *x1, *x2, QuantityRoots,
                    QuantityRootsCorrect);
        }
        else
        {
            printf ("���� %lg �������: a = %lg, b = %lg, c = %lg, QuantityRoots = %d\n",
                    NumTest, k1, k2, k3, QuantityRoots);
        }
    }


    else if (QuantityRoots == InfinityRoots)
    {
        if (QuantityRoots != QuantityRootsCorrect)
        {
            printf ("������ ����� %lg: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, QuantityRoots = %d\n"
                    "��������� �����: QuantityRoots = InfinityRoots",
                    NumTest, k1, k2, k3,*x1, *x2, QuantityRoots);
        }else
        {
            printf ("���� %lg �������: a = %lg, b = %lg, c = %lg, QuantityRoots = InfinityRoots",
                    NumTest, k1, k2, k3);
        }
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------

void BiblioChecker(double* x1, double* x2)
{
    SolvesCheckerSE2(1, 1, 0, -4, -2, 2, TwoRoots, x1, x2);
    SolvesCheckerSE2(2, 0.6, 5.3, -12.2, -10.7285, 1.8952, TwoRoots, x1, x2);
    SolvesCheckerSE2(3, 1, 5.3, -12.2, -7.0343, 1.7343, TwoRoots, x1, x2);
    SolvesCheckerSE2(4, 5959, 5.89, -0.2, -0.0063, 0.0053, TwoRoots, x1, x2);
    SolvesCheckerSE2(5, 1, 7, 853, NAN, NAN, ZeroRoots, x1, x2);
    SolvesCheckerSE2(6, 1, 2, 1, -1, NAN, OneRoot, x1, x2);
    SolvesCheckerSE2(7, 0, 0, 0, NAN, NAN, InfinityRoots, x1, x2);
}

