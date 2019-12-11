# include <iostream>
# include <cstring>
using namespace std;

class CMyString
{
    public:
        CMyString(char * pData = nullptr); // C形式字符串初始化CMyString
        CMyString(const CMyString& str); // CMyString形式字符串初始化，复制构造函数
        ~CMyString(void);

        CMyString& operator=(const CMyString& str);
    private:
        char * m_pData;
};

// // 赋值运算符重载
// CMyString& CMyString::operator=(const CMyString& str)
// {
//     // 被赋值的是同一个实例
//     if (this == &str) return *this;

//     // 清空被赋值实例内存
//     delete [] m_pData;
//     m_pData = nullptr;

//     // 赋新空间和复制字符串
//     m_pData = new char[strlen(str.m_pData) + 1];
//     strcpy(m_pData, str.m_pData);

//     return *this;
// }

// 高阶解法
CMyString& CMyString::operator=(const CMyString& str)
{
    if (this != &str)
    {
        // 使用复制构造函数新建临时实例
        CMyString strTemp(str);

        // 交换新实例数据和当前实例数据
        char * pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return * this;
}
