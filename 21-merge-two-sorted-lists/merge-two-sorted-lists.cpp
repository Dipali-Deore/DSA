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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *neww=new ListNode(0);
        ListNode* dummy=neww;


        ListNode* d1=list1;
        ListNode* d2=list2;

        while(d1!=NULL && d2!=NULL)
        {
            if(d1->val < d2->val)
            {
                dummy->next=d1;
                d1=d1->next;
            }
            else{
                dummy->next=d2;
                d2=d2->next;
            }
            dummy=dummy->next;
        }

        while(d1!=nullptr)
        {
            dummy->next=d1;
            d1=d1->next;
            dummy=dummy->next;
        }

        while(d2!=nullptr)
        {
            dummy->next=d2;
            d2=d2->next;
            dummy=dummy->next;
        }

        return neww->next;
    }
};