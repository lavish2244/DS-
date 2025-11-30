// Q(2) Design the logic to remove the duplicate elements from an Array and after the deletion the
// array should contain the unique elements.

// Step 1 —> Start
// Read the size of the array (n).
// Read n elements into the array (arr).

// Step 2 —> Remove Duplicates
// Loop i from 0 to n - 1:
// Loop j from i + 1 to n - 1:
// If arr[i] == arr[j]:
// Shift all elements from index j+1 to the left by 1 position.
// Reduce n by 1.
// Decrement j so that the new element at position j is checked again.

// Step 3 —> Print the Result
// Display the updated array which have only unique elements.

// Step 4 —> Stop