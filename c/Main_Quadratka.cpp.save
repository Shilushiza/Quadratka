#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Tester.h"
#include "Enum.h"
#include "Solver.h"
#include "Input.h"

//---------------------------------------------------------------------------------------------------------------------------------------

USER_MODE Intro();

//------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    double a=0, b=0, c=0, x1=0, x2=0;

    USER_MODE Mode = Intro();

    if (Mode == SOLVE)
    {
        printf ("Введите значения коэффициентов квадратного уравнения вида ax^2+bx+c=0 в следующем порядке: a, b, c\n");

        if(!Input(&a, &b, &c)) return 0;

        NUM_ROOTS QuantityRoots = SolveEquatoin2(a, b, c, &x1, &x2);

        SortingCasesSE2(QuantityRoots, x1, x2);
     }

     if (Mode == TEST)
     {
        BiblioChecker(&x1, &x2);
     }

     return 0;
}


//-------------------------------------------------------------------------------------------------------------------------------------

USER_MODE Intro()
{
    printf ("Калькулятор решения квадратных уравнений\n");

    printf ("Выберите режим:\n"
            "Введите комманду TEST, чтобы тестировать калькулятор, или комманду SOLVE, чтобы решить уравнение\n");
    char command[6] = "";
    scanf ("%s", command);
    // fgets
    if (!strcmp(command,"SOLVE")) //command == solve
    {
        return SOLVE;
    }
    if (!strcmp(command,"TEST"))
    {
         return TEST;
    }
    else
    {
         printf("Ты не умеешь писать, я обидевся. Пака");
         return SOLVE;
    }
}
