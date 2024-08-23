#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <cmath>
//---------------------------------------------------------------------------------------------------------------------------------------

const int InfinityRoots = 999;
static const double epsilon = 0.00000000001;
int SolveEquatoin2 (double a, double b, double c, double* x1, double* x2);
void SortingCasesSE2(int QuantityRoots, double x1, double x2);
int ComparsionWith0(double s);

//---------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    printf ("#����������� ������� ���������� ���������\n");
    printf ("#������� �������� ������������� ����������� ��������� ���� ax^2+bx+c=0 � ��������� �������: a, b, c\n");

    double a=0, b=0, c=0;
    int NumInput = 0;
    while (NumInput != 3)
    {
        printf("�������� ��� ���\n");
        NumInput = scanf ("%lf %lf %lf", &a, &b, &c);
    }
    printf("a - %lf b - %lf c - %lf /n", a, b, c);// ������������ ������ ����� ������ �� ���������� ������

    double x1=0, x2=0;
    int QuantityRoots = SolveEquatoin2(a, b, c, &x1, &x2);
    SortingCasesSE2(QuantityRoots, x1, x2);
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------------


// enum ��� ���������� ������



int SolveEquatoin2 (double a, double b, double c, double* x1, double* x2)
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
            return (C == 0)?InfinityRoots : 0;
        }
        else
        {
            *x1 = -c/b;
            return 1;
        }
    }
    else
    {
        double d = b*b - 4*a*c;
        int D = ComparsionWith0(d);
        if (D == 0)
        {
            *x1 = *x2=-b/(2*a);
            return 1;
        }
        if (d>0)
        {
            double sqrt_d = sqrt(d);
            *x1 = (-b-sqrt_d)/(2*a);
            *x2 = (-b+sqrt_d)/(2*a);
            return 2;
        }
        else
        {
            return 0;
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------

void SortingCasesSE2(int QuantityRoots, double x1, double x2)
{
    assert(x1 != NAN);
    assert(x2 != NAN);

    switch(QuantityRoots)
    {
      case 0:
        printf("��� ������");       // enum
        break;
      case 1:
        printf("x = %lf\n", x1);
        break;
      case 2:
        printf("x1 = %lf, x2 = %lf\n", x1, x2);
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
