# include <iostream>
using namespace std;


void ReorderOddEven_1(int* &pData, unsigned int length)
{
    // 特殊输入
    if (pData == nullptr || length <= 0) return;

    // 从前到后交换
    int swap_index = 0;
    int search_index = 0;
    while (search_index < length)
    {
        // 当前值为奇数，交换下一个元素
        if (pData[swap_index] & 1 == 1)
        {
            ++swap_index;
            search_index = swap_index;
        }
        // 当前值为偶数，查找当前节点之后最近的奇数
        else
        {
            // 当之后的所有数都为偶数时，跳出循环
            // 当之后的最后一个数之前存在奇数时，交换两个数
            while (search_index < length && ((pData[search_index] & 1) == 0))
            {
                ++search_index;
            }
            if (search_index == length) break;
            else swap(pData[search_index], pData[swap_index]);
            ++swap_index;
            ++search_index;
        }
    }
}


// ====================测试代码====================
void PrintArray(int numbers[], int length)
{
    if(length < 0)
        return;

    for(int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void Test(char* testName, int numbers[], int length)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
    {
        copy[i] = numbers[i];
    }

    printf("Test for solution 1:\n");
    PrintArray(numbers, length);
    ReorderOddEven_1(numbers, length);
    PrintArray(numbers, length);

    // printf("Test for solution 2:\n");
    // PrintArray(copy, length);
    // ReorderOddEven_2(copy, length);
    // PrintArray(copy, length);

    delete[] copy;
}

void Test1()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int));
}

void Test2()
{
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int));
}

void Test3()
{
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int));
}

void Test4()
{
    int numbers[] = {1};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int));
}

void Test5()
{
    int numbers[] = {2};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int));
}

void Test6()
{
    Test("Test6", nullptr, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}