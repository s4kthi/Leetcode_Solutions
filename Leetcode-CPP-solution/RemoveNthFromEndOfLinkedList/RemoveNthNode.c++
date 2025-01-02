class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* back = head;
        ListNode* front = head;

        // Move the front pointer n steps ahead
        for (int i = 0; i < n; i++) {
            if (front == nullptr) return head; // Safety check
            front = front->next;
        }

        // If front is null, we need to remove the head
        if (front == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Move both pointers until front reaches the last node
        while (front->next != nullptr) {
            front = front->next;
            back = back->next;
        }

        // Remove the nth node from the end
        ListNode* temp = back->next;
        back->next = back->next->next;
        delete temp;

        return head;

    }
};