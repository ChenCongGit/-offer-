# include <iostream>
# include <stdexcept>
# include <set>
using namespace std;

typedef set<pair<int, int>> dot_set;
int recursive(int, int, int, int, int, dot_set &);
int numberSum(int);


int movingCount(int threshold, int rows, int cols)
{
    // 特殊情况
    if (rows <= 0 || cols <= 0 || threshold < 0) return 0;

    dot_set ds;
    ds.insert(make_pair(0, 0));
    return recursive(threshold, rows, cols, 0, 0, ds);
}


int recursive(int threshold, int rows, int cols, int x, int y, dot_set& s)
{
    // 当前坐标数位之和
    int sum = numberSum(x) + numberSum(y);

    // 当前数位之和大于阈值
    if (sum > threshold) return 0;

    // 当前坐标越界
    if (x < 0 || y < 0 || x >= rows || y >= cols) return 0;

    int direction_x[4] = {1,0,-1,0};
    int direction_y[4] = {0,1,0,-1};

    int numbers = 0;
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + direction_x[i];
        int new_y = y + direction_y[i];

        // 当前坐标不在集合中
        if (s.count(make_pair(new_x, new_y)) == 0)
        {
            s.insert(make_pair(new_x, new_y));
            numbers += recursive(threshold, rows, cols, new_x, new_y, s);
        }
    }
    return numbers + 1;
}


int numberSum(int x)
{
    int numbers = 0;
    while (x > 0)
    {
        numbers += x % 10;
        x = x / 10;
    }
    return numbers;
}


// ====================测试代码====================
void test(char* testName, int threshold, int rows, int cols, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int sum = movingCount(threshold, rows, cols);
    if(sum == expected)
        {cout << sum << " " << expected << endl; printf("Passed.\n");}
    else
        {cout << sum << " " << expected << endl; printf("FAILED.\n");}
}

// 方格多行多列
void test1()
{
    test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3()
{
    test("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void test9()
{
    test("Test9", -10, 10, 10, 0);
}

int main(int agrc, char* argv[])
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

    return 0;
}