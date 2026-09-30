// Problem: Merge 2 Sorted Arrays without extra space
// Leetcode version: https://leetcode.com/problems/merge-sorted-array/
// input 2 arrays, output 1 array [arr1]

// BFS: Concatenation & Sort
// TC: O((M+N)log(M+N) + O(N))

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++)
        nums1[m+i] = nums2[i];

        sort(nums1.begin(), nums1.end());
    }
};



// GFG Version: https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
// 2Input 2 arrays, output 2 arrays

// BFS: put all nums in 3rd array -> sort -> then store in both the arrays
// TC: O((M+N)log(M+N)) SC: O(M+N)


// Better:  Two-pointer merge but with extra space
// TC: O((M+N)) SC: O(M+N)

void merge(long long arr1[], long long arr2[], int n, int m) {
    long long arr3[n + m];
    int left = 0, right = 0, index = 0;

    // Merge until one array is exhausted
    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            arr3[index++] = arr1[left++];
        } else {
            arr3[index++] = arr2[right++];
        }
    }

    // Copy remaining elements of arr1
    while (left < n) {
        arr3[index++] = arr1[left++];
    }

    // Copy remaining elements of arr2
    while (right < m) {
        arr3[index++] = arr2[right++];
    }

    // Distribute merged array back into arr1 and arr2
    for (int i = 0; i < n + m; i++) {
        if (i < n) arr1[i] = arr3[i];
        else arr2[i - n] = arr3[i];
    }
}

// OS: two pointer merge without extra space
// TC: O(min(m,n) + nlogn + mlogm) SC: O(1) 

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int m = a.size();
        int n = b.size();
        
        int left = m-1, right = 0;
        
        while(left >= 0 && right < n)
        {
            if(a[left] > b[right])
            {
                swap(a[left], b[right]);
                left--, right++;
            }
            else
            break;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};

// OS 2: Gap MEthod based on Shell Sort
