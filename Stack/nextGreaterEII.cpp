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


// OS:
