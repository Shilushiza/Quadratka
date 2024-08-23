#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <cmath>
//---------------------------------------------------------------------------------------------------------------------------------------

enum NUM_ROOTS {ZeroRoots = 0,
                OneRoot = 1,
                TwoRoots = 2,
                InfinityRoots = 3};
enum USER_MODE {
    SOLVE,
    TEST
};
static const double epsilon = 1e-8;

NUM_ROOTS SolveEquatoin2 (double a, double b, double c, double* x1, double* x2);
void SortingCasesSE2(NUM_ROOTS QuantityRoots, double x1, double x2);
int ComparsionWith0(double s);
void Input (double* a, double* b, double* c);
void SolvesCheckerSE2();
USER_MODE Intro();


//---------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    //SolvesCheckerSE2(); // �������� ������� ������ ���������� ��� �������
    double a=0, b=0, c=0, x1=0, x2=0;
    USER_MODE Mode = Intro();
    printf("here");
    if (Mode == SOLVE)
    {
        printf ("������� �������� ������������� ����������� ��������� ���� ax^2+bx+c=0 � ��������� �������: a, b, c\n");

        Input(&a, &b, &c);

        NUM_ROOTS QuantityRoots = SolveEquatoin2(a, b, c, &x1, &x2);
        SortingCasesSE2(QuantityRoots, x1, x2);
     }
     return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------
void Input (double* a, double* b, double* c)
{
    int NumInput = 0;
    NumInput = scanf ("%lf %lf %lf", a, b, c);
    while ((getchar()) != '\n');
    while (NumInput != 3)
    {
        printf("�������� ��� ���\n");
        NumInput = scanf ("%lf %lf %lf", a, b, c);
        while ((getchar()) != '\n');
    }
}

//-----------------------------------------------------------------------------------------------------------------------------




NUM_ROOTS SolveEquatoin2 (double a, double b, double c, double* x1, double* x2)
{

    assert(std::isfinite(a));//�������� ���� ������� ��� ���������� isfinite
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    int A = ComparsionWith0(a);
    int B = ComparsionWith0(b);
    int C = ComparsionWith0(c);

    if (A == 0)
    {
        if (B == 0)
        {
            return (C == 0)?InfinityRoots : ZeroRoots;
        }
        else
        {
            *x1 = -c/b;
            return OneRoot;
        }
    }
    else
    {
        double d = b*b - 4*a*c;
        int D = ComparsionWith0(d);
        if (D == 0)
        {
            *x1 = *x2=-b/(2*a);
            return OneRoot;
        }
        if (d>0)
        {
            double sqrt_d = sqrt(d);
            *x1 = (-b-sqrt_d)/(2*a);
            *x2 = (-b+sqrt_d)/(2*a);
            return TwoRoots;
        }
        else
        {
            return ZeroRoots;
        }
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
        printf("��� ������");
        break;
      case OneRoot:
        printf("x = %lg\n", x1);
        break;
      case TwoRoots:
        printf("x1 = %lg, x2 = %lg\n", x1, x2);
        break;
      case InfinityRoots:
        printf("���������� ������");
        break;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------

int ComparsionWith0(double s)
{
    return (((s < epsilon)&&(s > -epsilon))?0:1);
}

//-----------------------------------------------------------------------------------------------------------------

void SolvesCheckerSE2()
{
    double x1 = 0, x2 = 0;
    NUM_ROOTS QuantityRoots = SolveEquatoin2(1, 0, -4, &x1, &x2);
    if (QuantityRoots != 2 || x1 != -2 || x2 != 2)
    {
        printf ("������ ����� 1: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, QuantityRoots = %lg\n"
                "��������� �����: x1 = %lg, x2 = %lg, QuantityRoots = %lg\n",
                1, 0, -4, x1, x2, QuantityRoots,
                -2, 2, 2);
    }else
    {
        printf ("���� 1 �������\n");
    }

}

//--------------------------------------------------------------------------------------------------------------------

USER_MODE Intro()
{
    printf ("����������� ������� ���������� ���������\n");

    printf ("�������� �����:\n"
            "������� �������� TEST, ����� ����������� �����������, ��� �������� SOLVE, ����� ������ ���������\n");
    char command[6] = "";
    scanf ("%s", command);
    if (!strcmp(command,"SOLVE")) //command == solve
    {
        printf("here1");
        return SOLVE;
    }
    if (!strcmp(command,"TEST"))
    {
         return TEST;
    }
}
