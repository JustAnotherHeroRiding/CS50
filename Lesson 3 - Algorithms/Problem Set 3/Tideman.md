Sure, let's assume we have three candidates: Alice (0), Bob (1), and Charlie (2). And we have two voters who rank the candidates as follows:

- Voter 1: Alice > Bob > Charlie (represented as [0, 1, 2])
- Voter 2: Alice > Charlie > Bob (represented as [0, 2, 1])

Given these votes, let's see how the `preferences` array would be populated.

1. **For Voter 1:**
    - Alice (0) is preferred over Bob (1) and Charlie (2). Therefore, `preferences[0][1]` and `preferences[0][2]` should each be incremented by 1.
    - Bob (1) is preferred over Charlie (2). Therefore, `preferences[1][2]` should be incremented by 1.

2. **For Voter 2:**
    - Alice (0) is preferred over Charlie (2) and Bob (1). Therefore, `preferences[0][2]` and `preferences[0][1]` should each be incremented by 1.
    - Charlie (2) is preferred over Bob (1). Therefore, `preferences[2][1]` should be incremented by 1.

So, after processing these votes, your `preferences` array should look like this:

`preferences = {   {0, 2, 2},  // Alice is preferred over Bob and Charlie by 2 voters   {0, 0, 1},  // Bob is preferred over Charlie by 1 voter   {0, 1, 0}   // Charlie is preferred over Bob by 1 voter }`

This shows that Alice is the most preferred candidate, Bob is the least preferred candidate, and Charlie is in the middle. This is the expected result given the votes from the two voters.

To achieve this, you would need a nested loop in your `record_preferences` function, where for each rank `i`, you consider all following ranks `j` (where `j>i`) and increment `preferences[ranks[i]][ranks[j]]`.


## Lock pairs

Charlie beats both alice and bob
alice beats bob
