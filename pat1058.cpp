#include<iostream>
using namespace std;

int main()
{
   int a1,b1,c1;
   int a2,b2,c2;
   scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
   int cc = 0;
   int c = (c1+c2+cc)%29;
   cc=(c1+c2+cc)/29;
   int b = (b1+b2+cc)%17;
   cc=(b1+b2+cc)/17;
   int a = a1+a2+cc;
   printf("%d.%d.%d\n",a,b,c);
}