# Two Sum - Beginner Friendly Explanation

## Problem Description

The **Two Sum** problem is a common algorithmic challenge that asks:

> Given an array of integers `nums` and an integer `target`, return **indices** of the two numbers such that they add up to the `target`.

- You may assume that each input would have exactly one solution.
- You cannot use the same element twice.
- Return the indices in any order.

---

## Example

### Input:
```plaintext
nums = [2, 7, 11, 15], target = 9
```

### Output:
```plaintext
[0, 1]
```

### Explanation:
The numbers `2` and `7` add up to `9`. Their indices are `0` and `1`, respectively.

---

## Solution Explanation

Here’s a step-by-step breakdown of the solution using C++:

### Explanation:
1. **Initialization**:
   - Use a `map` to store the value of elements as the key and their indices as the value.
   
2. **Iterate Through Array**:
   - For each element in the array, calculate the difference between the `target` and the current number (`x = target - nums[i]`).
   - Check if this difference (`x`) already exists in the `map`.

3. **Check for Match**:
   - If `x` exists in the `map`, we’ve found the two numbers. Return their indices.

4. **Update the Map**:
   - If `x` doesn’t exist, store the current number and its index in the `map` for future reference.

5. **Return Default**:
   - If no pair is found (though the problem guarantees a solution), return `{-1, -1}`.

---

## Key Concepts

1. **Map for Quick Lookup**:
   - A `map` allows constant-time complexity to check for the existence of an element.

2. **Efficient Approach**:
   - This solution avoids nested loops by using the `map`, making it faster with a time complexity of **O(n)**.

---

## Example Walkthrough

### Input:
```plaintext
nums = [2, 7, 11, 15], target = 9
```

### Step-by-Step Execution:
1. **Iteration 1**:
   - `i = 0, nums[i] = 2, target = 9`
   - `x = 9 - 2 = 7`
   - `7` is not in the map, so add `{2: 0}` to the map.

2. **Iteration 2**:
   - `i = 1, nums[i] = 7, target = 9`
   - `x = 9 - 7 = 2`
   - `2` exists in the map at index `0`.
   - Return `[1, 0]`.

### Output:
```plaintext
[1, 0]
```

---

## How to Run the Code

1. **Environment**:
   - Ensure you have a C++ compiler installed (e.g., g++, Visual Studio, or an online IDE).

2. **Input Format**:
   - Provide an array `nums` and an integer `target` as input.

3. **Run the Function**:
   - Use the `twoSum` function from the `Solution` class with your input.

---

## Common Questions

1. **Why use a map?**
   - The map helps us find if the complement of the current number exists in constant time, reducing the time complexity.

2. **What if there are multiple solutions?**
   - The problem guarantees one unique solution, so we don't handle multiple pairs.

3. **Can the same number be used twice?**
   - No, the indices must be distinct.

---

## Practice
Try running the code with these inputs:

1. `nums = [3, 2, 4], target = 6`  
   **Output**: `[1, 2]`

2. `nums = [3, 3], target = 6`  
   **Output**: `[0, 1]`

---

Happy Coding! 🚀

