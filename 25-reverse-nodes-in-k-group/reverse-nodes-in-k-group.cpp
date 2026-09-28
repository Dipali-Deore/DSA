class Solution {
private:
    ListNode* rev(ListNode* l1, ListNode* stop)
    {
        ListNode* prev = stop;
        ListNode* curr = l1;

        while(curr != stop)
        {
            ListNode* forr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forr;
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* ans = dummy;

        while(true)
        {
            // Find kth node
            ListNode* trave = ans;

            for(int i = 0; i < k; i++)
            {
                trave = trave->next;

                // Fewer than k nodes remaining
                if(trave == nullptr)
                {
                    return dummy->next;
                }
            }

            // Start of current group
            ListNode* temp = ans->next;

            // Node after current group
            ListNode* nextGroup = trave->next;

            // Reverse exactly k nodes
            ListNode* newHead = rev(temp, nextGroup);

            // Connect previous group to reversed group
            ans->next = newHead;

            // temp is now the LAST node of reversed group
            ans = temp;
        }
    }
};