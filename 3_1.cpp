# include <iostream>
using namespace std;

// 找出数组中的重复数字

// 1.哈希表，时间复杂度O(n)，空间复杂度O(n)
bool duplicate_1(int numbers[], int length, int * duplication)
{
    // 异常情况
    if (numbers == nullptr || length < 0) return false;
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] < 0 || numbers[i] > length-1)
            return false;
    }

    int hash[length] = {}; // 初始化哈希数组为0
    for (int i = 0; i < length; i++)
    {
        if (hash[numbers[i]] == 1)
        {
            *duplication = numbers[i];
            return true;
        }
        hash[numbers[i]] = 1;
    }
    return false;
}

// 2.哈希表原地算法，时间复杂度O(n)，空间复杂度O(1)
bool duplicate_2(int numbers[], int length, int * duplication)
{
    // 异常情况
    if (numbers == nullptr || length < 0) return false;
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] < 0 || numbers[i] > length-1)
            return false;
    }

    // 逐元素交换至正确位置，至多需要n次交换，时间复杂度为O(n)
    for (int i = 0; i < length; i++)
    {
        while (numbers[i] != i)
        {
            if (numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }
            swap(numbers[i], numbers[numbers[i]]);
        }
    }
    return false;
}


// ====================测试代码====================
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}

void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate_1(numbers, lengthNumbers, &duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications[] = { 4 };
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
    int* numbers = nullptr;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}