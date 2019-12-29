// 一元二次方程
//                    ax²+bx+c=0   (a≠0)
//                     
//     其求根依据判定式△的取值为三种   ( △=b²-4ac )
//     
//         1. △>0，方程有两个不相等的实数根；
//         
//             x1=[-b+√(△)]/2a;   //( △=b²-4ac )
//             x2=[-b-√(△)]/2a;
//         
//         2. △=0，方程有两个相等的实数根；
//             x1=x2=[-b+√(△)]/2a= -b/2a ;
//         
//         3. △<0，方程无实数根，但有2个共轭复根。
//             x1=[-b+√(△)*i]/2a;   //( △=b²-4ac )
//             x2=[-b-√(△)*i]/2a;
#include<iostream>
#include<cmath>
#include<cstdio>

void fun1(double a, double b, double c){     //△ > 0
    double x1 = (-b + sqrt(b*b - 4*a*c)) / 2*a;
    double x2 = (-b - sqrt(b*b - 4*a*c)) / 2*a;
    printf("x1 = %.3lf, x2 = %.3lf", x1, x2);
}

void fun2(double a, double b, double c){     //△ = 0
    double x1, x2;
    x1 = x2 = (-b) / 2 * a;
    printf("x1 = %.3lf, x2 = %.3lf", x1, x2);
}

void fun3(double a, double b, double c){    //△ < 0
    double x1 = (-b + sqrt(b*b - 4*a*c)) / 2*a;
}

int main(void)
{
    
    
    system("pause");
    return 0;
}