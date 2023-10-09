
## Important Links
- [Lesson Timestamp](https://youtu.be/9rT9vYlYVos?t=8308)
- [Section](https://cs50.harvard.edu/x/2023/sections/3/)
- [Practice Problems](https://cs50.harvard.edu/x/2023/problems/3/)
- [Lab 3](https://cs50.harvard.edu/x/2023/labs/3/)
- [Problem Set 3](https://cs50.harvard.edu/x/2023/psets/3/)

## Algorithms Class Notes
- Linear search is when go start searching the array of elements one by one, left to right or right to left
- Binary search will start from the middle, and if the number is not found, we will discard one half of the array where our target is not contained
- Big O notation calculates the worst case scenario for a possible algorithms
1. **O(1) - Constant Time**:
    
    - Description: The algorithm's runtime is constant, meaning it takes the same amount of time to execute regardless of the input size.
2. **O(log n) - Logarithmic Time**:
    
    - Description: The algorithm's runtime grows logarithmically with the input size. As the input size increases, the time taken increases, but not as drastically as linear or quadratic time.
3. **O(n) - Linear Time**:
    
    - Description: The algorithm's runtime is directly proportional to the input size. As the input size increases, the time taken also increases linearly.
4. **O(n log n) - Linearithmic Time**:
    
    - Description: The algorithm's runtime is slightly worse than linear, but better than quadratic. It's often seen in efficient sorting algorithms like merge sort and quicksort.
5. **O(n^2) - Quadratic Time**:
    
    - Description: The algorithm's runtime is proportional to the square of the input size. As the input size increases, the time taken grows much faster.
6. **O(n^3) - Cubic Time**:
    
    - Description: The algorithm's runtime is proportional to the cube of the input size. It's common in algorithms with three nested loops.
7. **O(2^n) - Exponential Time**:
    
    - Description: The algorithm's runtime doubles with each additional element in the input. It's often seen in algorithms with recursive branching.
8. **O(n!) - Factorial Time**:
    
    - Description: The algorithm's runtime grows very rapidly with the input size and is generally considered highly inefficient. It's often seen in brute-force algorithms that generate all permutations or combinations.
9. **O(n^k) - Polynomial Time** (where k is a constant):
    
    - Description: The algorithm's runtime is a polynomial function of the input size with a fixed exponent k. The specific exponent determines how the algorithm scales with input size.
10. **O(2^(n/2)) - Square Root Time**:
    
    - Description: Often seen in algorithms that divide the input in half at each step, such as binary search. It's better than linear but not as good as logarithmic.

These are some of the most commonly used Big O notations to describe the time complexity of algorithms. It's important to analyze and understand the time complexity of algorithms to make informed decisions about their efficiency when working on software development projects.


## Sorting Algorithms

### Selection Sort

- Selection sort will compare each element and save the smallest element
- After checking the entire array, it will place the smallest element at index 0 and then start from index
- It will then place the 2nd smallest element at index 1 until the entire array is sorted
- This takes O(n^2) as it will always run a loop for each element, and then loop over again to check the element

### Bubble sort

- Bubble Sort will take the current element and compare it to the next one, if the next one is smaller, it will swap them
- This will push the biggest elements to the top
- Here we compare up until n - 2 so that we do not go out of bounds and since we will access the last element when we check n -2 and it's next element which is n - 1
- However this is still running in O(n^2)
- The formula for this is n^2 - 2n + 1, however 2n and +1 are very small and can be discarded in the big picture
- If there are no swaps in one loop, we can conclude that it is sorted


### Recursion


### Merge Sort


### Sorting Algorithms
