#include <iostream>
/*Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
*
*You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
*
*Example:
*Given 1->2->3->4->5->NULL,
*return 1->3->5->2->4->NULL.
*
*Note:
*The relative order inside both the even and odd groups should remain as it was in the input. 
*The first node is considered odd, the second node even and so on ...
*/
using namespace std;
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution 
{
	public:
    ListNode* oddEvenList(ListNode* head) 
	{
 		if(head == NULL || head->next == NULL) return head;
        ListNode* evenHead = head;
        ListNode* oddHead = head->next;
        ListNode* evenList = head;  
        ListNode* oddList = head->next;
        ListNode* op = head->next->next;
        while(op != NULL)
        {   
			//add to even list
            evenList->next = op; 
            evenList = op; 
            op = op->next;  
			//add to odd list
            if(op == NULL)
            {   
                oddList->next = NULL; //important !!!, without this line will have circle(ex:1,2,3)
                break;
            }   
            else
            {   
                oddList->next = op; 
                oddList = op; 
                op = op->next;  
            }   
        }   
        evenList->next = oddHead;
        return evenHead;       
    }
};
