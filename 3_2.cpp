# include <iostream>
using namespace std;

int getDuplication_1(const int* numbers, int length);
int getDuplication_2(const int* numbers, int length);
int countRange(const int* numbers, int length, int start, int end);

// 再不修改原数组的前提下找出一个重复元素

// 1.哈希表
int getDuplication_1(const int* numbers, int length)
{
    // 异常情况
    if (numbers == nullptr || length <= 0) return -1;
    for (int i = 0 ; i < length; i++)
    {
        if (numbers[i] < 1 || numbers[i] >= length)
            return -1;
    }

    // 使用哈希表根据下标保存数组元素
    int hash[length] = {}; // 下标范围是0-n，值范围是1-n
    for (int i = 0; i < length; i++)
    {
        if (hash[numbers[i]] == 1) return numbers[i];
        hash[numbers[i]] = 1;
    }
    return -1;
}

// // 2.采用二分查找，时间复杂度O(nlogn)，空间复杂度O(1)
int getDuplication_2(const int* numbers, int length)
{
    // 异常情况
    if (numbers == nullptr || length <= 0) return -1;
    for (int i = 0; i < length; i++)
        if (numbers[i] < 1 || numbers[i] > length-1) return -1;

    // 二分法查找重复元素
    int start = 1; // 1
    int end = length - 1; // n
    while (start <= end)
    {
        int middle = (start + end) >> 1;
        int count = countRange(numbers, length, start, middle); // 值为start到middle的元素的个数
        // 二分结束
        if (start == end)
        {
            if (count > 1) return start;
            else break;
        }
        if (count > (middle - start + 1)) end = middle; // 二分
        else start = middle + 1;
    }
    return -1;
}

int countRange(const int* numbers, int length, int start, int end)
{
    // 统计numbers数组中值在start到end的区间内的元素个数
    if (numbers == nullptr) return 0;
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] >= start && numbers[i] <= end) ++count;
    }
    return count;
}


// ====================测试代码====================
void test(const char* testName, int* numbers, int length, int* duplications, int dupLength)
{
    int result = getDuplication_2(numbers, length);
    for(int i = 0; i < dupLength; ++i)
    {
        if(result == duplications[i])
        {
            std::cout << testName << " passed." << std::endl;
            return;
        }
    }
    std::cout << testName << " FAILED." << std::endl;
}

// 多个重复的数字
void test1()
{
    int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
    int duplications[] = { 2, 3 };
    test("test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 一个重复的数字
void test2()
{
    int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
    int duplications[] = { 4 };
    test("test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字是数组中最小的数字
void test3()
{
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
    int duplications[] = { 1 };
    test("test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字是数组中最大的数字
void test4()
{
    int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
    int duplications[] = { 8 };
    test("test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 数组中只有两个数字
void test5()
{
    int numbers[] = { 1, 1 };
    int duplications[] = { 1 };
    test("test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字位于数组当中
void test6()
{
    int numbers[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
    int duplications[] = { 3 };
    test("test6", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 多个重复的数字
void test7()
{
    int numbers[] = { 1, 2, 2, 6, 4, 5, 6 };
    int duplications[] = { 2, 6 };
    test("test7", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 一个数字重复三次
void test8()
{
    int numbers[] = { 1, 2, 2, 6, 4, 5, 2 };
    int duplications[] = { 2 };
    test("test8", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 没有重复的数字
void test9()
{
    int numbers[] = { 1, 2, 6, 4, 5, 3 };
    int duplications[] = { -1 };
    test("test9", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 无效的输入
void test10()
{
    int* numbers = nullptr;
    int duplications[] = { -1 };
    test("test10", numbers, 0, duplications, sizeof(duplications) / sizeof(int));
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    return 0;
}