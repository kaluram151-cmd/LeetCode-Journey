/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
        {
            return NULL;
        }
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int length1 = 0;
        int length2 = 0;
        while(temp1)
        {
            length1 = length1+1;
            temp1 = temp1->next;
        }
        while(temp2)
        {
            length2 = length2+1;
            temp2 = temp2->next;
        }
        temp1 = headA;
        temp2 = headB;
        if(length2>length1)
        {
            int k = length2-length1;
                while(k>0)
            {
                temp2 = temp2->next;
                k--;
            }
                 while(temp1 && temp2)
            {
                if(temp1==temp2)
            {
                return temp1;
            }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        else
        {
            int k = length1-length2;
            while(k>0)
            {
                temp1 = temp1->next;
                k--;
            }
             while(temp1 && temp2)
            {
                if(temp1==temp2)
                {
                    return temp1;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return NULL;
    }
};