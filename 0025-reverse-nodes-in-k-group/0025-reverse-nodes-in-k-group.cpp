/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp)
        {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        ListNode* newNode = temp;
        int group = 0;
        while(temp)
        {
            int count = 1;
            ListNode* KthNode = temp;
            while(count!=k && KthNode->next!=NULL)
            {
                KthNode = KthNode->next;
                count++;
            }
            if(count!=k)
            {
                if(prevNode!=NULL) prevNode->next = temp;
                break;
            }
            newNode = KthNode->next;
            group++;
            KthNode->next = nullptr;
            ListNode* newHead = reverse(temp);
            if(group==1)
            {
                head = newHead;
            }
            if(prevNode!=NULL)
            {
                prevNode->next = newHead;
            }
            prevNode = temp;
            temp = newNode;
        }
        return head;
    }
};