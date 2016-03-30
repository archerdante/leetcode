#include <iostream>
#include <vector>
//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//Return a deep copy of the list.
using namespace std;
//Definition for singly-linked list with a random pointer.
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode *op = head;
        while(op != NULL)
        {
            RandomListNode *temp = op->next;
            op->next = new RandomListNode(op->label);
            op->next->next = temp;
            op = temp;
        }
        op = head;
        while(op != NULL)
        {
            if(op->random != NULL) op->next->random = op->random->next;
            op = op->next->next;
        }
        op = head;
        RandomListNode *newHead = op->next;
        while(op->next->next != NULL)
        {
            RandomListNode *temp = op->next->next;
            op->next->next = temp->next;
            op->next = temp;
            op = temp;
        }
        op->next = NULL;
        return newHead;
    }
};
