# include <iostream>
using namespace std;


bool match(const char* str, const char* pattern)
{
    // 输入参数
    if (str == nullptr || pattern == nullptr) return false;

    if (*str == '\0' && *pattern == '\0') return true;
    if (*str != '\0' && *pattern == '\0') return false;

    // 第二个字符是否为'*'
    if (*(pattern+1) == '*')
    {
        // 如果str[0]和pattern[0]*可以匹配
        if (*pattern == *str || (*pattern == '.' && *str != '\0'))
            // 正常匹配下一个字符，|| 下一个字符仍然匹配当前模式， || 当前模式忽略(*为0)
            return match(str+1, pattern+2) || match(str+1, pattern) || match(str, pattern+2);
        else return match(str, pattern+2); // 无法匹配当前字符，只能查找下个模式
    }
    else
    {
        if (*str == *pattern || (*pattern == '.' && *str != '\0'))
            return match(str+1, pattern+1);
    }
    return false;
    
}


// ====================测试代码====================
void Test(const char* testName, const char* string, const char* pattern, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(match(string, pattern) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    Test("Test01", "", "", true);
    Test("Test02", "", ".*", true);
    Test("Test03", "", ".", false);
    Test("Test04", "", "c*", true);
    Test("Test05", "a", ".*", true);
    Test("Test06", "a", "a.", false);
    Test("Test07", "a", "", false);
    Test("Test08", "a", ".", true);
    Test("Test09", "a", "ab*", true);
    Test("Test10", "a", "ab*a", false);
    Test("Test11", "aa", "aa", true);
    Test("Test12", "aa", "a*", true);
    Test("Test13", "aa", ".*", true);
    Test("Test14", "aa", ".", false);
    Test("Test15", "ab", ".*", true);
    Test("Test16", "ab", ".*", true);
    Test("Test17", "aaa", "aa*", true);
    Test("Test18", "aaa", "aa.a", false);
    Test("Test19", "aaa", "a.a", true);
    Test("Test20", "aaa", ".a", false);
    Test("Test21", "aaa", "a*a", true);
    Test("Test22", "aaa", "ab*a", false);
    Test("Test23", "aaa", "ab*ac*a", true);
    Test("Test24", "aaa", "ab*a*c*a", true);
    Test("Test25", "aaa", ".*", true);
    Test("Test26", "aab", "c*a*b", true);
    Test("Test27", "aaca", "ab*a*c*a", true);
    Test("Test28", "aaba", "ab*a*c*a", false);
    Test("Test29", "bbbba", ".*a*a", true);
    Test("Test30", "bcbbabab", ".*a*a", false);

    return 0;
}
