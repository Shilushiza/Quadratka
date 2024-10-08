#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <cmath>
//---------------------------------------------------------------------------------------------------------------------------------------

const int BeskonechnoKorney = 999;
static const double epsilon = 0.00000000001;
int KolichestvoKorney (double a, double b, double c, double* x1, double* x2);// ������� ���� ���
void KakayaToFunc(int Peremennaya, double x1, double x2);// ������� ���� ���
int check(double s);

//---------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    printf ("#����������� ������� ���������� ���������\n");
    printf ("#������� �������� ������������� ����������� ��������� ���� ax^2+bx+c=0 � ��������� �������: a, b, c\n");

    double a=0, b=0, c=0;
    scanf ("%lf %lf %lf", &a, &b, &c);
    printf("a - %lf b - %lf c - %lf /n", a, b, c);

    double x1=0, x2=0;
    printf ("here1");
    int Peremennaya = KolichestvoKorney(a, b, c, &x1, &x2);
    KakayaToFunc(Peremennaya, x1, x2);
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int KolichestvoKorney (double a, double b, double c, double* x1, double* x2)     // ������� ���� ���
{

    assert(std::isfinite(a));//�������� ���� ������� ��� ���������� isfinite
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    int A = check(a);
    int B = check(b);
    int C = check(c);

    if (A == 0)
    {
        if (B == 0)
        {
            return (C == 0)?BeskonechnoKorney : 0;
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
        int D = check(d);
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
            printf("hahahaha");
            return 0;
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------

void KakayaToFunc(int Peremennaya, double x1, double x2)// ������� ���� ���
{
    assert(x1 != NAN);
    assert(x2 != NAN);
//    assert(x1 != x2)
    printf("x1 - %lf, x2 - %lf", x1, x2);

    switch(Peremennaya)
    {
      case 0:
        printf("��� ������");
        break;
      case 1:
        printf("x = %lf\n", x1);
        break;
      case 2:
        printf("x1 = %lf, x2 = %lf\n", x1, x2);
        break;
      case BeskonechnoKorney:
        printf("���������� ������");
        break;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------

int check(double s)
{
    return (((s < epsilon)&&(s > -epsilon))?0:1);
}
