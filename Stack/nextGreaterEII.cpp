// Problem: Next Greater Element II (Circular Array)
// https://leetcode.com/problems/next-greater-element-ii/description/

// BFS:  TC: O(N^2), SC: O(1)

// 1st version:
vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n,-1);

        for(int i=0; i<n; i++)
        {
            // Double the array hypothetically
            for(int j=i+1; j< i+n; j++)
            {
                int idx = j%n;
                if(nums[idx] > nums[i])
                {
                    nge[i] = nums[idx];
                    break;
                }
            }
        }
        return nge;
    }

// 2nd Version (Just loop part)
for(int i=0; i<n; i++)
        {
            
            for(int j=1; j< n; j++)
            {
                // Getting the hypothetical index
                int idx = (i+j)%n;
                if(nums[idx] > nums[i])
                {
                    nge[i] = nums[idx];
                    break;
                }
            }
        }


// OS: Monotonic stack, Hypothetically doibled the array
// TC: O(2N), SC: O(2N) for stack (worst) + O(N) for ans


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n,-1);
        stack<int> st;

        // Double the array hypothetically
        for(int i=2*n-1; i>=0; i--)
        {
            int idx = i%n;
            while(!st.empty() && st.top() <= nums[idx])
            st.pop();
            if(i < n)
            {
                nge[i] = st.empty()?-1 : st.top();
            }
            st.push(nums[idx]);
        }
        return nge;
    }
};
