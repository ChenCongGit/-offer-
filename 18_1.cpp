# include <iostream>
using namespace std;


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


// void DeleteNode(ListNode** pListNode, ListNode* pToBeDelete)
// {
//     // 特殊情况
//     if (pListNode == nullptr || pToBeDelete == nullptr) return;
    
//     // 如果当前节点是头节点
//     if (pToBeDelete == *pListNode)
//     {
//         *pListNode = pToBeDelete->m_pNext;
//         delete pToBeDelete; pToBeDelete = nullptr;
//         return;
//     }

//     // 如果删除节点是尾节点，从头到尾遍历
//     ListNode* p = *pListNode;
//     if (pToBeDelete->m_pNext == nullptr)
//     {
//         while (p->m_pNext->m_pNext != nullptr) // p到倒数第二个节点
//         {
//             p = p->m_pNext;
//         }
//         p->m_pNext = nullptr; return;
//     }

//     // 删除中间节点
//     ListNode* pNext = pToBeDelete->m_pNext;
//     pToBeDelete->m_nValue = pNext->m_nValue;
//     pToBeDelete->m_pNext = pNext->m_pNext;
//     delete pNext;
//     pNext = nullptr;
// }


void DeleteNode(ListNode** pListNode, ListNode* pToBeDelete)
{
    // 特殊情况
    if (pListNode == nullptr || pToBeDelete == nullptr) return;

    // 删除头节点
    if (*pListNode == pToBeDelete)
    {
        *pListNode = pToBeDelete->m_pNext;
        delete pToBeDelete; pToBeDelete = nullptr;
        return;
    }

    // 如果要删除的不是尾节点
    if (pToBeDelete->m_pNext != nullptr)
    {
        pToBeDelete->m_nValue = pToBeDelete->m_pNext->m_nValue;
        pToBeDelete->m_pNext = pToBeDelete->m_pNext->m_pNext;
        delete pToBeDelete->m_pNext;
        return;
    }
    else
    {
        ListNode* pNode = *pListNode;
        while (pNode->m_pNext != pToBeDelete)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = nullptr;
        delete pToBeDelete;
        return;
    }
}



// ====================测试代码====================
void Test(ListNode* &pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    PrintList(pListHead);

    printf("The node to be deleted is: \n");
    PrintListNode(pNode);

    DeleteNode(&pListHead, pNode);
    
    printf("The result list is: \n");
    PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
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

    Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2()
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

    Test(pNode1, pNode5);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test3()
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

    Test(pNode1, pNode1);

    DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1, pNode1);
}

// // 链表为空
// void Test5()
// {
//     Test(nullptr, nullptr);
// }

int main(int argc, char* argv[])
{
    // Test1();
    Test2();
    Test3();
    Test4();
    // Test5();

    return 0;
}