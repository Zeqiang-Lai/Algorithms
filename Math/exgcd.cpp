#include<stdio.h>

void gcd(int a, int b, int &d, int &x, int &y)
{
    if(!b) { d = a; x = 1; y = 0; }
    else { gcd(b, a%b, d, y, x); y -= x*(a/b); }
}

int main()
{
    int x,y,d;
    gcd(1024,729,d,x,y);
    printf("%d %d\n",x,y);
    return 0;   
}