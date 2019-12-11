# include <iostream>
using namespace std;


long long Fibonacci(int n)
{
    long long f0 = 0;
    long long f1 = 1;
    long long f2;

    if (n == 0) return f0;
    if (n == 1) return f1;

    for (int i = 1; i < n; i++)
    {
        f2 = f0 + f1;
        f0 = f1; f1 = f2;
    }
    return f2;
}



// ====================测试代码====================
void Test(int n, int expected)
{
    if(Fibonacci(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);
}

int main(int argc, char* argv[])
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);

    return 0;
}