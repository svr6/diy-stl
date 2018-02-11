#include <stdio.h>

int fib1 (int n);    //非递归生成下标为n的斐波那契数列元素
int fib2 (int n);    //递归生成下标为n的斐波那契数列元素
int mfib1(int n);
int mfib2(int n);

int main ()
{
    int n ;
    printf ("please input the index of fib:") ;
    scanf ("%d" , &n) ;
    printf ("the %d fib1 number is %d \n" , n , fib1(n)) ;
    printf ("the %d mfib1 number is %d \n" , n , mfib1(n)) ;
    printf ("the %d fib2 number is %d \n" , n , fib2(n)) ;
    printf ("the %d mfib2 number is %d \n" , n , mfib2(n)) ;
    return 0 ;
}

int mfib1(int n)
{
    int i, a, b, result;
    i = result = 0;
    a = b = 1;

    if(n<=0)
        return 0;
    if(n<=2)
        return 1;
    {
        for(i = 2; i < n; i++)
        {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
}

int fib1 (int n)
{
    int i = 0 ;
    int a = 1 ;
    int b = 1 ;
    int result = 0 ;
    if (n <= 0)
    {
        return 0 ;
    }
    else if (n <= 2)
    {
        return 1 ;
    }
    else
    {
        for (i = 3 ; i <= n ; i ++)
        {
            result = a + b ;
            a = b ;
            b = result ;
        }
        return result ;
    }
}

int fib2 (int n)
{
    if (n <= 0)
    {
        return 0 ;
    }
    else if (n <= 2)
    {
        return 1 ;    //递归终止条件
    }
    else
    {
        return fib2(n-1) + fib2(n-2) ;    //递归
    }
}

int mfib2(int n)
{
    if(n<=0)
        return 0;
    if(n<=2)
        return 1;
    {
        return mfib2(n-1) + mfib2(n-2);
    }
}
