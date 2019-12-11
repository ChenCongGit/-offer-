# include <iostream>
# include <stdexcept>
using namespace std;

bool g_InvalidInput = false;
bool equal(double num1, double num2);

double Power_1(double base, int exponent)
{
    // 特殊情况
    // 0^0和0的负数次幂
    if (equal(base, 0.0) && exponent < 0)
    {
        // logic_error ex("Zero invalid.");
        // throw new exception(ex);
        g_InvalidInput = true;
        return 0.0;
    }
    if (equal(base, 0.0) && exponent == 0)
    {
        g_InvalidInput = false;
        return 1.0;
    }

    double result = 1.0;

    // 负指数
    if (exponent < 0)
    {
        for (int i = 1; i <= -exponent; i++)
        {
            result *= base;
        }
        return 1.0 / result;
    }
    // 正指数
    else
    {
        for (int i = 1; i <= exponent; i++)
        {
            result *= base;
        }
        return result;
    }
}


double Power_2(double base, unsigned int exponent)
{
    if (exponent == 0) return 1;
    if (exponent == 1) return base;

    double result = Power_2(base, exponent >> 1);
    result *= result;
    if (exponent & 0x1 == 1) result *= base;
    return result;
}


// ====================测试代码====================
bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}


void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power_2(base, exponent);
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char* argv[])
{
    // 底数、指数都为正数
    Test("Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    Test("Test2", -2, 3, -8, false);

    // 指数为负数
    Test("Test3", 2, -3, 0.125, false);

    // 指数为0
    Test("Test4", 2, 0, 1, false);

    // 底数、指数都为0
    Test("Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    Test("Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    Test("Test7", 0, -4, 0, true);

    return 0;
}