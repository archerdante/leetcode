#include <iostream>
//Given a linked list, swap every two adjacent nodes and return its head.
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
using namespace std;
//Definition for singly-linked list.
struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *op = newHead;
        while(op->next != NULL && op->next->next != NULL)
        {
            ListNode *temp = op->next;
            op->next = op->next->next;
            temp->next = op->next->next;
            op->next->next = temp;
            op = temp;
        }
        head = newHead->next;
        delete newHead;
        newHead = NULL;
        return head;
    }
};
