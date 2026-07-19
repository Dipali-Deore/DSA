class Solution {
public:
    void reorderList(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
            return;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Split the list
        ListNode* second = slow->next;
        slow->next = nullptr;

        // Step 3: Reverse second half
        ListNode* prev = nullptr;

        while(second)
        {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // Step 4: Merge two halves
        ListNode* first = head;
        second = prev;

        while(second)
        {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};