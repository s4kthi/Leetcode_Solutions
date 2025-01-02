# Remove Nth Node From End of List

This repository contains the solution to the LeetCode problem **"Remove Nth Node From End of List"** implemented in C++.

## Problem Description

Given the `head` of a linked list, remove the `n`-th node from the end of the list and return its head.

### Example:

**Input:**
```
head = [1, 2, 3, 4, 5], n = 2
```
**Output:**
```
[1, 2, 3, 5]
```

### Constraints:
1. The number of nodes in the linked list is `sz`.
2. \( 1 \leq sz \leq 30 \).
3. \( 0 \leq Node.val \leq 100 \).
4. \( 1 \leq n \leq sz \).

## Approach

### Intuition
To solve this problem efficiently, we use the **two-pointer technique**. The idea is to set up two pointers that maintain a gap of `n` nodes between them. This allows us to locate the node to be removed in a single traversal of the list.

### Steps
1. **Initialize two pointers:** Start both pointers (`front` and `back`) at the `head` of the list.
2. **Advance the `front` pointer:** Move the `front` pointer `n` steps ahead. This ensures that the gap between `front` and `back` is exactly `n` nodes.
3. **Check if the `front` is `null`:** If the `front` pointer becomes `null` after moving `n` steps, it means the `head` node itself is the `n`-th node from the end. In this case, update the `head` to the next node and delete the original `head`.
4. **Move both pointers:** If the `front` pointer is not `null`, move both `front` and `back` pointers one step at a time until `front` reaches the end of the list.
5. **Remove the node:** When `front` reaches the end, the `back` pointer will point to the node just before the one to be removed. Update the `back->next` pointer to skip the node to be deleted, then delete that node.

### Edge Cases
- If the list has only one node, removing it results in an empty list.
- If `n` equals the size of the list, the `head` node is removed.

## Solution

```cpp
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
```

## Detailed Explanation

1. **Initialization:**
   - `back` and `front` pointers are initialized to point at the `head` of the list.

2. **Advance the `front` pointer:**
   - In the `for` loop, we move the `front` pointer `n` steps forward. If at any point `front` becomes `null`, it indicates that the list has fewer than `n` nodes, so we return the `head` without any modifications.

3. **Handle edge case where `front` is `null`:**
   - If `front` becomes `null` after moving `n` steps, it means we need to remove the `head` node (the `n`-th node from the end). We store the current `head` in a temporary pointer, move `head` to the next node, and delete the old `head`.

4. **Traverse the list with both pointers:**
   - We continue moving `front` and `back` pointers one step at a time. When `front` reaches the last node, `back` points to the node just before the one we want to remove.

5. **Delete the target node:**
   - We update the `next` pointer of `back` to skip the target node and point to the node after it. Then, we free the memory allocated for the target node.

## Complexity Analysis

- **Time Complexity:**
  - The algorithm makes a single pass through the linked list, so the time complexity is **O(L)**, where `L` is the length of the list.

- **Space Complexity:**
  - The algorithm uses constant extra space, so the space complexity is **O(1)**.

## Usage
1. Copy the `Solution` class into your C++ environment.
2. Define the `ListNode` structure and create a linked list.
3. Call the `removeNthFromEnd` method with the linked list head and the value of `n`.

### Example Usage:
```cpp
ListNode* head = new ListNode(1);
head->next = new ListNode(2);
head->next->next = new ListNode(3);
head->next->next->next = new ListNode(4);
head->next->next->next->next = new ListNode(5);

Solution sol;
head = sol.removeNthFromEnd(head, 2);
```

Happy Coding! 🚀