# include <iostream>
#include <stdexcept>
using namespace std;


// void SortAges(int ages[], int length)
// {
//     if (ages == nullptr || length <= 0) return;

//     const int oldestAge = 99;
//     int timesOfAge[oldestAge + 1];

//     for (int i = 0; i < length; i++)
//     {
//         int age = ages[i];
//         if (age < 0 || age > oldestAge)
//         {
//             logic_error ex("age out of range");
//             throw new exception(ex);
//         }
//         ++timesOfAge[age];
//     }

//     int index = 0;
//     for (int i = 0; i <= oldestAge; i++)
//     {
//         for (int j = 0; j < timesOfAge[i]; j++)
//         {
//             ages[index] = i;
//             ++index;
//         }
//     }
// }


void statisicsSort(int data[], int length, int maxValue, int minValue)
{
    if (data == nullptr || length <= 0) return;

    // 统计data中元素每一个取值的个数
    int numbers[maxValue - minValue + 1] = {0};
    for (int i = 0; i < length; i++)
    {
        // data取值越界
        if (data[i] < minValue || data[i] > maxValue)
        {
            logic_error ex("value out of range.");
            throw new exception(ex);
        }
        numbers[data[i]-minValue]++;
    }

    // 根据元素出现次数排序
    int index = 0;
    for (int i = minValue; i < maxValue - minValue + 1; i++)
    {
        for (int j = 0; j < numbers[i]; j++)
        {
            data[index] = i;
            ++index;
        }
    }
}


int main()
{
    int data[11] = {1,2,6,4,7,3,1,4,6,5,2};
    statisicsSort(data, 11, 10, 0);
    for (int i = 0; i < 11; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}