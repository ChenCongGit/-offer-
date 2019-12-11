# include <iostream>
# include <queue>
using namespace std;


template<typename T>
class CStack
{
pubilc:
    CStack() {};
    ~CStack() {};

    void appendHead(const T& node);
    T deleteHead();

private:
    queue<T> queue1;
    queue<T> queue2;
};


template<typename T>
void appendHead(const T& node)
{
    
}