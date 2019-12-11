# include <iostream>
using namespace std;


// 将n逐位右移，当n为负数时，右移左边将会填充1，将会无限循环
int NumberOf1(int n)
{
    int num = 0;
    while (n != 0)
    {
        if (n & 1 == 1) num++;
        n >> 1;
    }
    return num;
}

// 将1左移，直到越界，即1变为0
int NumberOf2(int n)
{
    int num = 0;
    unsigned int flag = 1;
    while (flag) // 无符号整型4个字节32位，当左移32次时，全部变为0
    {
        if (n & flag) num++;
        flag = flag << 1;
    }
    return num;
}

// n与n-1做位与运算，将n的最右边的1变成0
int NumberOf3(int n)
{
    int num = 0;
    while (n)
    {
        num++;
        n = (n-1)&n;
    }
    return num;
}


// ====================测试代码====================
void Test(int number, unsigned int expected)
{
    // int actual = NumberOf1(number);
    // if (actual == expected)
    //     printf("Solution1: Test for %p passed.\n", number);
    // else
    //     printf("Solution1: Test for %p failed.\n", number);

    int actual = NumberOf2(number);
    if (actual == expected)
        printf("Solution2: Test for %p passed.\n", number);
    else
        printf("Solution2: Test for %p failed.\n", number);

    actual = NumberOf3(number);
    if (actual == expected)
        printf("Solution3: Test for %p passed.\n", number);
    else
        printf("Solution3: Test for %p failed.\n", number);

    printf("\n");
}

int main(int argc, char* argv[])
{
    // 输入0，期待的输出是0
    Test(0, 0);

    // 输入1，期待的输出是1
    Test(1, 1);

    // 输入10，期待的输出是2
    Test(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    Test(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test(0xFFFFFFFF, 32);

    // 输入0x80000000（负数），期待的输出是1
    Test(0x80000000, 1);

    return 0;
}