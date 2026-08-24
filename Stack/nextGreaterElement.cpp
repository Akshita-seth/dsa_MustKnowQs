//Problem 1: Next Greater Element I
// https://www.geeksforgeeks.org/dsa/next-greater-element/

// BFS: TC: O(N^2)

class Solution {
	public:
	vector<int> nextLargerElement(vector<int>& arr) {
		// code here
		int n = arr.size();
		vector<int> ans(n, -1); // Initialising is imp
		
		for (int i = 0; i<n; i++)
			{
			for (int j = i + 1; j<n; j++)
				{
				if (arr[j] > arr[i]) {
					ans[i] = arr[j];
					break;  // Break is imp
				}
			}
			
		}
		return ans;
	}
};


// OS: Monotonic Stack
// TC: O(N), SC: O(N)
// For optimization, one thing is sure: you must start tarversal from right bcz only then u would have already seen the elements next i.e. right of the given index


class Solution {
	public:
	vector<int> nextLargerElement(vector<int>& arr) {
		// code here
		int n = arr.size();
		vector<int> nge(n);  // initialisng the size of array is imp
		stack<int> st;
		
		for (int i = n - 1; i >= 0; i--)
			{
			while (!st.empty() && arr[i] >= st.top())
				st.pop();
			if (st.empty())
				nge[i] = -1;
			else
				nge[i] = st.top();
			st.push(arr[i]);
			
		}
		return nge;
	}
};



// Problem 2: Next greater element of subarray n1 and array n2
// https://leetcode.com/problems/next-greater-element-i/


// BFS: 
// TC: O(N1*N2) or O(N^2)

class Solution {
public:
    int checkGreater(vector<int>& nums2, int j, int n2) {
        int greater = -1;
        if (j != n2 - 1) {
            for (int i = j + 1; i < n2; i++) {
                if (nums2[i] > nums2[j])
                    return nums2[i];
            }
        }
        return greater;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> ans(n1);  // Don't Forget to initialise the size, bcz below directly accessing indices

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (nums2[j] == nums1[i]) {
                    int greater = checkGreater(nums2, j, n2);
                    ans[i] = greater;
                    break;  // Break is imp, otherwise inconsistent NGEs will be stored
                }
            }
        }
        return ans;
    }
};


// OS: Monotonic Stack
// TC: O(N1+N2)  (linear scan of both arrays, each element pushed/popped once), SC: O(N2 + N2) for stack + hashmap
// For optimization, one thing is sure, u musy start tarversal from right bcz only then u would have already seen the elements next i.e. right of the given index
// Store this mapping in a hashmap: {element → nextGreater}
// For each element in nums1, just look up the precomputed hashmap


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nge;  // {val -> next greater}
        stack<int> st;

        // Precompute next greater for nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            nge[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        // Build answer for nums1
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(nge[x]);
        }
        return ans;
    }
};




