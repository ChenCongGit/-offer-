# include <iostream>
# include <stack>
#include <stdexcept>
using namespace std;


template<typename T>
class CQueue
{
    public:
        CQueue(void) {};
        ~CQueue(void) {};

        void appendTail(const T& node);
        T deleteHead();

    private:
        stack<T> stack1; // 入栈队列
        stack<T> stack2; // 出栈队列
};


template<typename T>
void CQueue<T>::appendTail(const T& node)
{
    // stack1
    stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
    // 如果出栈队列为空，将所有入栈队列中的元素全部压入出栈队列
    if (stack2.empty())
    {
        // 两个栈都为空，无法出栈
        if (stack1.empty())
        {
            logic_error ex("queue is empty");
            throw new exception(ex);
        }
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        T element = stack2.top(); stack2.pop();
        return element;
    }
    else
    {
        T element = stack2.top(); stack2.pop();
        return element;
    }
}


// ====================测试代码====================
void Test(char actual, char expected)
{
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    CQueue<char> queue;

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    Test(head, 'a');

    head = queue.deleteHead();
    Test(head, 'b');

    queue.appendTail('d');
    head = queue.deleteHead();
    Test(head, 'c');

    queue.appendTail('e');
    head = queue.deleteHead();
    Test(head, 'd');

    head = queue.deleteHead();
    Test(head, 'e');

    return 0;
}
