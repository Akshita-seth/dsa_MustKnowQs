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


// OS: Three pointers and sort backwards
// TC: O(M+N) SC: O(1)


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1;  // end of nums1’s valid elements
        int p2 = n-1;  // end of nums2
        int p = m+n-1;   // end of nums1’s allocated space

        while(p1 >= 0 && p2 >= 0)
        {
            if(nums1[p1] > nums2[p2])
            nums1[p--] = nums1[p1--];
            else
            nums1[p--] = nums2[p2--];
        }
        // Remaining nums1 elements are already in place.
        // Remaining nums2 elements must be inserted
        while(p2 >= 0)    
        nums1[p--] = nums2[p2--];
        
    }
};


// There’s also a gap method or using extra arrays, but the in-place three-pointer approach is the most efficient and clean.
//just for knowledge

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // First, copy nums2 into nums1’s extra space
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        int len = m + n;
        int gap = (len / 2) + (len % 2); // ceil(len/2)

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
                if (nums1[left] > nums1[right]) {
                    swap(nums1[left], nums1[right]);
                }
                left++;
                right++;
            }
            // You’d end up comparing the same index with itself, which is meaningless.
            if (gap == 1) break;  //  ensures the algorithm stops cleanly after the last useful pass.
            gap = (gap / 2) + (gap % 2); // shrink gap
        }
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
// TC: O(logbase2(m+n) * (m+n)) SC: O(1)



class Solution {
  public:
    void swapIfGreater(vector<int>& a, vector<int>& b, int i, int j)
    {
        if(a[i] > b[j])
        swap(a[i], b[j]);
    }
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int m = a.size();
        int n = b.size();
        
        int len = (m+n);
        int gap = len/2 + len%2;  // to get ceil value
        
        while(gap > 0)
        {
            int left = 0;
            int right = left + gap;
            
            while(right < len)
            {
                // Case 1: left in a, right in b
                if(left < m && right >= m )
                {
                    swapIfGreater(a,b,left, right-m);
                }
                
                // Case 2: left in b, right in b
                else if(left >= m)
                {
                    swapIfGreater(b,b,left-m,right-m);
                }
                
                // Case 3: left in a, right in a
                else
                {
                    swapIfGreater(a,a,left,right);
                }
                left++, right++;
            }
            
            if(gap == 1) break;
            gap = gap/2 + gap%2; // ceil value
        }
        
        
    }
};
