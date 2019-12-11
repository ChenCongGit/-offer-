# include <iostream>
using namespace std;


struct ListNode
{
    int m_nValue; // 节点元素
    ListNode* m_pNext; // 指向下一个节点的指针
};

// 在某个链表的末尾添加一个值为value的节点
void AddTail(ListNode** pHead, int value)
{
    // 新建一个值为value的节点
    ListNode* newNode = new ListNode();
    newNode->m_nValue = value;
    newNode->m_pNext = nullptr;

    // 如果链表本身就为空
    if (*pHead == nullptr) *pHead = newNode;

    // 遍历到链表当前尾节点，将尾节点指针指向新节点
    ListNode* p = *pHead;
    while (p->m_pNext != nullptr)
    {
        p = p->m_pNext;
    }
    p->m_pNext = newNode;
}

// 在某个链表中删除第一个指定值value的节点
void RemoveNode_1(ListNode** pHead, int value)
{
    // 特殊情况，链表为空或者指针为空
    if (pHead == nullptr || *pHead == nullptr) return;

    // 如果删除的是头节点，则直接返回第二个节点，并删除头节点
    if ((*pHead)->m_nValue == value)
    {
        ListNode* removedNode = *pHead;
        *pHead = (*pHead)->m_pNext;
        delete removedNode; removedNode = nullptr;
    }
    else
    {
        // 遍历链表，找到该节点
        ListNode* p = *pHead;
        while (p->m_pNext != nullptr && p->m_pNext->m_nValue != value)
        {
            p = p->m_pNext;
        }
        if (p->m_pNext == nullptr) return; // 没有值为value的节点

        // 删除该节点，并将前一个结点的指针指向被删除节点的下一个节点
        ListNode* removedNode = p->m_pNext;
        p->m_pNext = p->m_pNext->m_pNext;
        delete removedNode; removedNode = nullptr;
    }
}

void RemoveNode_2(ListNode** pHead, int value)
{
    // 特殊情况
    if (pHead == nullptr) return;

    // 在原链表前加入辅助节点，可以省略特殊情况
    ListNode* helpHead = new ListNode();
    helpHead->m_pNext = *pHead;

    // 从辅助节点开始遍历链表节点
    ListNode* p = helpHead;
    while (p->m_pNext != nullptr && p->m_pNext->m_nValue != value)
    {
        p = p->m_pNext;
    }
    if (p->m_pNext == nullptr) return;

    // 删除该节点
    ListNode* r = p->m_pNext;
    p->m_pNext = p->m_pNext->m_pNext;
    delete r; r = nullptr;
}