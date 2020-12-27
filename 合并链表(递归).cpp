/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/
//注意：升序，链表的存储形式。

#include<iostream>
using namespace std;

//链表节点:
class Node
{
    public:
        int date;
        Node* next;
};
Node* mergeTwoList(Node* l1 , Node* l2);
void PrintLinkedList(Node* n);
int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    Node* head1 = NULL;
    Node* second1 = NULL;
    Node* third1 = NULL;
    //在heap中申请3个空间：
    head = new Node();
    second = new Node();
    third = new Node();

    head1 = new Node();
    second1 = new Node();
    third1 = new Node();
    //对每个表赋值，并讲它们链接在一起
    head->date = 1;
    head->next = second;
    second->date = 2;
    second->next = third;
    third->date = 4;
    third->next = NULL;

    head1->date = 1;
    head1->next = second1;
    second1->date = 3;
    second1->next = third1;
    third1->date = 4;
    third1->next = NULL;

    Node* new_head = NULL;
    new_head = new Node();
    //合并链表
    new_head = mergeTwoList(head,head1);
    //打印链表
    PrintLinkedList(new_head);
    
    return 0;
}
//合并链表：
Node* mergeTwoList(Node* l1,Node* l2)
{
    if(l1 == nullptr)
    {
        return l2;
    }
    if(l2 == nullptr)
    {
        return l1;
    }
    if(l1->date <= l2->date)
    {
        l1->next = mergeTwoList(l1->next,l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoList(l1,l2->next);
        return l2;
    }
}

void PrintLinkedList(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->date<<endl;
        n = n->next;
    }
}
