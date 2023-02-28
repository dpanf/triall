#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double solver1(double (*f)(double),double c,double d, double eps, double* delta, int* n){
    double m=(c+d)/2;
    *delta=d-c;
    if(abs(f(m))<eps){
        return m;
    }
    if(f(c)*f(m)<0){
        d=m;
        (*n)++;
        return solver1(f,c,d,1e-5,delta,n);
    }
    if(f(d)*f(m)<0){
        c=m;
        (*n)++;
        return solver1(f,c,d,1e-5,delta,n);
    }
}

int main()
{
    int n=0;
    double delta, eps, a, b, x;
    scanf("%lf %lf", &a,&b);
    scanf("%lf", &eps);
    if((f(a)==0)||(f(b)==0)){
        n=0; delta=b-a;
        if(f(a)==0) x=a;
        else x=b;
    }
    else x=solver1(f,a,b,1e-5,&delta,&n);
    return 0;
}