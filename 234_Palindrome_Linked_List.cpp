#include <iostream>
using namespace std;
//Given a singly linked list, determine if it is a palindrome.
//Follow up:
//Could you do it in O(n) time and O(1) space?
//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        bool ret = true;
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *newHead = reverseList(slow->next);
        ListNode *p1 = newHead, *p2 = head;
        while(p1)
        {
            if(p1->val != p2->val)
            {
                ret = false;
                break;
            }
            else
            {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        reverseList(newHead);
        return ret;
    }
private:
    ListNode* reverseList(ListNode *head)
    {
        if(!head) return head;
        ListNode *p1 = NULL, *p2 = head;
        while(p2)
        {
            ListNode *temp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = temp;
        }
        return p1;
    }
};
