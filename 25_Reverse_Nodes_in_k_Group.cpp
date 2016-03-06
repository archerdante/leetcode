#include <iostream>
#include <vector>
/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
*
*If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
*
*You may not alter the values in the nodes, only nodes itself may be changed.
*
*Only constant memory is allowed.
*
*For example,
*Given this linked list: 1->2->3->4->5
*
*For k = 2, you should return: 2->1->4->3->5
*
*For k = 3, you should return: 3->2->1->4->5
*/
using namespace std;
//Definition for singly-linked list.
struct ListNode {
		int val;
  		ListNode *next;
     	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	public:
	ListNode* reverseKGroup(ListNode* head, int k) {
            if(head == NULL) return NULL;
            ListNode* tempHead = head;
            ListNode* tempTail = NULL;
            ListNode* newHead = head;
            ListNode* lastTail = NULL;
            ListNode* tempNewHead = NULL;
            ListNode* op = head;
            bool isFirstTime = true;
            int i = 1;
            int j = 0;
            while(op != NULL) 
            {   
                if(i == k)
                {   
                    tempTail = op; 
                    ListNode* temp = op->next;
                    tempNewHead = reverseList(tempHead,tempTail);
                    if(isFirstTime) 
                    {   
                        newHead = tempNewHead;
                        lastTail = tempHead;
                        isFirstTime = false;
                    }
                    else
                    {
                        lastTail->next = tempNewHead;
                        lastTail = tempHead;
                    }
                    tempHead = temp;
                    op = tempHead;
                    i = 0;
                }
                else
                {
                    op = op->next;
                }
                i++;
                j++;
            }
            if(j < k) return head;
            if(i <= k)
            {
                lastTail->next = tempHead;
            }
            return newHead;
    }
    private:
    ListNode* reverseList(ListNode* tempHead, ListNode* tempTail)
    {
        if(tempHead == NULL) return NULL;
        ListNode* p = NULL;
        ListNode* q = tempHead;
        ListNode* end = tempTail->next;
        while(q != end)
        {
            ListNode* temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        return p;
    }
};
int main()
{
	vector<ListNode*> v;
	v.push_back(new ListNode(1));
	v.push_back(new ListNode(2));
	v.push_back(new ListNode(3));
	v.push_back(new ListNode(4));
	v.push_back(new ListNode(5));
	v.push_back(new ListNode(6));
	for(vector<ListNode*>::iterator it = v.begin();it != v.end() - 1;it++)
	{
		(*it)->next = *(it+1);	
	}
	ListNode* head = v[0];
	ListNode* op = head;
	cout << "old " << endl;
	while(op != NULL)
	{
		cout << op->val << endl;
		op = op->next;
	}
	Solution s;
	op = s.reverseKGroup(head,4);
	cout << "new " << endl;
	while(op != NULL)
	{
		cout << op->val << endl;
		op = op->next;
	}
}
