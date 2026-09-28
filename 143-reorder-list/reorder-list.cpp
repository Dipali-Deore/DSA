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
private:
    ListNode* rev(ListNode* head)
    {
        ListNode* prev=nullptr;
        ListNode* curr=head;

        while(curr!=nullptr)
        {
            ListNode* forr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forr;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* trave=rev(slow->next);
        slow->next=nullptr;
        slow=head;

        while(slow!=nullptr && trave!=nullptr)
        {
            ListNode* t1=slow->next;
            ListNode* t2=trave->next;

            slow->next=trave;
            trave->next=t1;

            slow=t1;
            trave=t2;
        }
    }
};