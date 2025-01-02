# Remove Nth Node From End of List

This repository contains the solution to the LeetCode problem **"Remove Nth Node From End of List"** implemented in Python.

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
2. **Advance the `front` pointer:** Move the `front` pointer `n` steps forward. This ensures that the gap between `front` and `back` is exactly `n` nodes.
3. **Check if the `front` is `None`:** If the `front` pointer becomes `None` after moving `n` steps, it means the `head` node itself is the `n`-th node from the end. In this case, return the `head.next` as the new head.
4. **Move both pointers:** If the `front` pointer is not `None`, move both `front` and `back` pointers one step at a time until `front.next` is `None`.
5. **Remove the node:** When `front.next` is `None`, the `back` pointer will point to the node just before the one to be removed. Update the `back.next` pointer to skip the node to be deleted.

### Edge Cases
- If the list has only one node, removing it results in an empty list.
- If `n` equals the size of the list, the `head` node is removed.

## Solution

```python
def removeNthFromEnd(head, n):
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
```

## Detailed Explanation

1. **Initialization:**
   - `front` and `back` pointers are initialized to point at the `head` of the list.

2. **Advance the `front` pointer:**
   - In the `for` loop, we move the `front` pointer `n` steps forward.

3. **Handle edge case where `front` is `None`:**
   - If `front` becomes `None` after moving `n` steps, it means we need to remove the `head` node (the `n`-th node from the end). Return `head.next` as the new head.

4. **Traverse the list with both pointers:**
   - Continue moving `front` and `back` pointers one step at a time. When `front.next` becomes `None`, `back` points to the node just before the one we want to remove.

5. **Delete the target node:**
   - Update the `next` pointer of `back` to skip the target node.

## Complexity Analysis

- **Time Complexity:**
  - The algorithm makes a single pass through the linked list, so the time complexity is **O(L)**, where `L` is the length of the list.

- **Space Complexity:**
  - The algorithm uses constant extra space, so the space complexity is **O(1)**.

## Usage
1. Copy the `removeNthFromEnd` function into your Python environment.
2. Define the `ListNode` class and create a linked list.
3. Call the `removeNthFromEnd` function with the linked list head and the value of `n`.

### Example Usage:
```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))

# Remove the 2nd node from the end
n = 2
head = removeNthFromEnd(head, n)

# Print the modified linked list
current = head
while current:
    print(current.val, end=" -> ")
    current = current.next
```

Happy Coding! 🚀
