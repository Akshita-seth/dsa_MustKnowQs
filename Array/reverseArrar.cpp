// Problem: Reverse an array
// 

// With Built-in Fn:
void reverseArray(vector<int> &arr) {
     reverse(arr.begin(), arr.end());
}

// Without built-in:

//BFS: TC: O(n), SC: O(n)
// Using a temporary array

void reverseArray(vector<int> &arr) {
    int n = arr.size();
    
    // Temporary array to store elements 
    // in reversed order
    vector<int> temp(n);
  
    // Copy elements from original array 
    // to temp in reverse order
    for(int i = 0; i < n; i++)
        temp[i] = arr[n - i - 1];
  
    // Copy elements back to original array
    for(int i = 0; i < n; i++)
        arr[i] = temp[i];
}

// OS 1: Two Pointer
// TC: O(n), SC: O(1)

void reverseArray(vector<int> &arr) {
        int n = arr.size();
        int left = 0, right = n-1;
        while(left < right)
        {
            swap(arr[left], arr[right]);
            left++, right--;
        }
    }

// OS 2: Using One-Pointer
// The idea is to iterate over the first half of the array and swap each element with its corresponding element from the end. 
// So, while iterating over the first half, any element at index i is swapped with the element at index (n - i - 1).
// TC: O(n), SC: O(1)

void reverseArray(vector<int> &arr) {
        // code here
        // reverse(arr.begin(), arr.end());
        int n = arr.size();
        int left = 0;
        while(left < n/2)
        {
            swap(arr[left], arr[n-left-1]);
            left++;
        }
    }
