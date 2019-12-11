# include <iostream>
# include <stdexcept>
using namespace std;

int Partition(int data[], int length, int start, int end);


void QuickSort(int data[], int length, int start, int end)
{
    if (start == end) return;

    int index = Partition(data, length, start, end);
    if (index > start) QuickSort(data, length, start, index - 1);
    if (index < end) QuickSort(data, length, index + 1, end);
}


int Partition(int data[], int length, int start, int end)
{
    // 特殊情况
    if (data == nullptr || length  <= 0 || start < 0 || end > length)
    {
        logic_error ex("Invalid Parameters");
        throw new exception(ex);
    }

    // 取end位置元素为参考值
    int small = start - 1;
    for (int index = start; index < end; index++)
    {
        if (data[index] < data[end])
        {
            ++small;
        }
    }
}