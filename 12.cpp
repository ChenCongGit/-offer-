# include <iostream>
# include <stdexcept>
# include <string>
# include <set>
using namespace std;

typedef pair<int, int> place;
typedef set<place> dot_set;
bool recursive(const char*, int, int, int, int, string, int, dot_set &);


bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
    // 特殊情况
    if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr) return false;

    // 遍历矩阵的每一个元素
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            dot_set ds;
            ds.insert(make_pair(i, j));
            if (recursive(matrix, rows, cols, i, j, str, 0, ds)) return true;
        }
    }
    return false;
}


bool recursive(const char* matrix, int rows, int cols, int x, int y, string str, int str_index, dot_set & s)
{
    int direction_x[4] = {0, 1, 0, -1};
    int direction_y[4] = {1, 0, -1, 0};

    // 如果当前字符等于当前位置的值
    if (str[str_index] == matrix[x * cols + y])
    {
        // 如果当前字符为最后一个字符，不需要再找下一个节点
        if (str_index == str.length() - 1) return true;

        // 搜索下一个节点
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + direction_x[i];
            int new_y = y + direction_y[i];

            // 判断新坐标是否越界
            if (new_x < 0 || new_y < 0 || new_x >= rows || new_y >= cols) continue;

            // 如果下一个节点没有经过，将下一节点加入集合
            if (s.count(make_pair(new_x, new_y)) == 0)
            {
                s.insert(make_pair(new_x, new_y));
                if (recursive(matrix, rows, cols, new_x, new_y, str, str_index + 1, s)) return true;
            }
        }
    }
    return false;
}






// ====================测试代码====================
void Test(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(hasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void Test1()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";

    Test("Test1", (const char*) matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
    const char* matrix = "ABCESFCSADEE";
    const char* str = "SEE";

    Test("Test2", (const char*) matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "ABFB";

    Test("Test3", (const char*) matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";

    Test("Test4", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEM";

    Test("Test5", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEEJIGOEM";

    Test("Test6", (const char*) matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEMS";

    Test("Test7", (const char*) matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAA";

    Test("Test8", (const char*) matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
    // const char* matrix = "AAAAAAAAAAAA";
    // const char* str = "AAAAAAAAAAAAA";
    const char* matrix = "AAAA";
    const char* str = "AAAAA";

    Test("Test9", (const char*) matrix, 2, 2, str, false);
}

//A

//A
void Test10()
{
    const char* matrix = "A";
    const char* str = "A";

    Test("Test10", (const char*) matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
    const char* matrix = "A";
    const char* str = "B";

    Test("Test11", (const char*) matrix, 1, 1, str, false);
}

void Test12()
{
    Test("Test12", nullptr, 0, 0, nullptr, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    return 0;
}