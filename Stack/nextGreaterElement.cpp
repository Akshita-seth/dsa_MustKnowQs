// Problem 1: Next greater element 1
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
                    break;  // Break is imp, otherwise inconsisten NGEs will be stored
                }
            }
        }
        return ans;
    }
};


// OS: Monotonis Stack
// TC: O(N1+N2), SC: O(N2+N2+N1)




