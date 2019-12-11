# include <iostream>
using namespace std;

bool scanInt(const char* &str); // 扫描整数
bool scanUnInt(const char* &str); // 扫描无符号整数


bool isNumeric(const char* str)
{
    if (str == nullptr) return false;

    bool numeric = scanInt(str);

    // 如果去掉整数部分后有'.'
    if (*str == '.')
    {
        ++str; // 去掉小数点
        // 小数点前或后有数字时可以表示数值
        numeric = scanUnInt(str) || numeric;
    }
    // 如果去掉小数部分后面有'e'或者'E'
    if (*str == 'e' || *str == 'E')
    {
        ++str; // 去掉e和E
        // e和E前后都有数值时才可以表示数值
        numeric = numeric && scanInt(str);
    }

    return numeric && *str == '\0';
}


bool scanInt(const char* &str)
{
    if (*str == '+' || *str == '-') ++str;
    return scanUnInt(str);
}

bool scanUnInt(const char* &str)
{
    const char* before = str;
    while (*str != '\0' && *str >= '0' && *str <= '9') ++str;
    return str > before;
}



// ====================测试代码====================
void Test(const char* testName, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "e1", false);
    Test("Test19", "+.", false);
    Test("Test20", "", false);
    Test("Test21", nullptr, false);

    return 0;
}