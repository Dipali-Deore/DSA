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
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode *dummy=new ListNode(0);
        ListNode* temp=dummy;

        ListNode* t1=l1;
        ListNode* t2=l2;

        while(t1!=nullptr && t2!=nullptr)
        {
            if(t1->val <t2->val)
            {
                temp->next=new ListNode(t1->val);
                t1=t1->next;
                temp=temp->next;
            }
            else{
                temp->next=new ListNode(t2->val);
                t2=t2->next;
                temp=temp->next;
            }

        }

        if(t1)
        {
            temp->next=t1;
        }
        else{
            temp->next=t2;
        }
        return dummy->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(lists.empty())
        {
            return nullptr;
        }

        while(n>1)
        {
            int index=0;

            for(int i=0;i<n;i+=2)
            {
                if(i+1<n)
                {
                    lists[index++]=merge(lists[i],lists[i+1]);
                }
                else{
                    lists[index++]=lists[i];
                }
            }
            n=index;
        }

        return lists[0];
    }
};