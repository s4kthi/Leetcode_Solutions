class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        front = head
        back = head
        
        # Move the front pointer `n` steps ahead
        for _ in range(n):
            front = front.next
        
        # If `front` is None, the head itself needs to be removed
        if not front:
            return head.next
        
        # Move both pointers until `front.next` is None
        while front.next:
            front = front.next
            back = back.next
        
        # Remove the nth node from the end
        back.next = back.next.next
        
        return head
