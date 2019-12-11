# include <iostream>
# include <stack>
using namespace std;


// list.cpp
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);


// 从尾到头打印链表节点的值
void PrintListReversingly(ListNode* pHead)
{
    // 链表为空
    if (pHead == nullptr)
    {
        cout << "" << endl;
        return;
    }

    // 使用一个栈保存每个节点的值
    stack<int> s;
    ListNode* p = pHead;
    while (p != nullptr)
    {
        s.push(p->m_nValue);
        p = p->m_pNext;
    }
    while (!s.empty())
    {
        cout << s.top() << '\t';
        s.pop();
    }
    cout << endl;
}


// ====================测试代码====================
void Test(ListNode* pHead)
{
    PrintList(pHead);
    PrintListReversingly(pHead);
    printf("\n");
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
    printf("\nTest2 begins.\n");

    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1);

    DestroyList(pNode1);
}

// 空链表
void Test3()
{
    printf("\nTest3 begins.\n");

    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
