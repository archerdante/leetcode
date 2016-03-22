#include <iostream>
//Write a program to find the node at which the intersection of two singly linked lists begins.
using namespace std;
struct ListNode
{
	ListNode *next;
	int val;
	ListNode(int x) : val(x), next(NULL){}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL||headB == NULL) return NULL;
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        int length1 = 0, length2 = 0;
        while(p1!=NULL)
        {
            length1++;
            p1 = p1->next;
        }
        while(p2!=NULL)
        {
            length2++;
            p2 = p2->next;
        }
        ListNode* longList = headA;
        ListNode* shortList = headB;
        int diff = length1 - length2;
        if(diff < 0)
        {
            longList = headB;
            shortList = headA;
            diff = 0 - diff;
        }
        while(diff>0)
        {
            longList = longList->next;
            diff--;
        }
        while(longList!=NULL&&shortList!=NULL&&longList!=shortList)
        {
            longList = longList->next;
            shortList = shortList->next;
        }
        return longList;
    }
};
