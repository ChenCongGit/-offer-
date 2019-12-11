# include <iostream>
using namespace std;


struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
    ListNode(int value=0, ListNode* next=nullptr): m_nValue(value), m_pNext(next) {}
};
ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);


ListNode* ReverseList(ListNode* pHead)
{
    // 特殊输入
    if (pHead == nullptr) return nullptr;

    // 定义辅助首节点
    ListNode* pFirst = new ListNode(0, pHead);
    ListNode* pCur = pHead;

    while (pCur->m_pNext != nullptr)
    {
        ListNode* pReverse = pCur->m_pNext;
        pCur->m_pNext = pCur->m_pNext->m_pNext; // 首先取出pCur->m_pNext的节点，使pCur跳过该节点指向下一个
        pReverse->m_pNext = pFirst->m_pNext;
        pFirst->m_pNext = pReverse;
    }
    return pFirst->m_pNext;
}


ListNode* ReverseList_2(ListNode* pHead)
{
    // 特殊输入
    if (pHead == nullptr) return nullptr;

    // 定义辅助首节点
    ListNode* pFirst = new ListNode(0, pHead);
    ListNode* pCur = pHead;

    while (pCur->m_pNext != nullptr)
    {
        ListNode* pReverse = pCur->m_pNext;
        pCur->m_pNext = pReverse->m_pNext;
        pReverse->m_pNext = pFirst->m_pNext;
        pFirst->m_pNext = pReverse;
    }
    return pFirst->m_pNext;
}


// ====================测试代码====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList_2(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入空链表
void Test3()
{
    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}