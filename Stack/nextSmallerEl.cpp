// Problem: Next Smaller ELement
// https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1


//BFS: Nested loop
// TC: O(N^2) SC: O(N) for nse ans vector

vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> nse(n,-1);
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(arr[j]<arr[i])
                {
                    nse[i] = arr[j];
                    break;
                }
            }
        }
        return nse;
    }

// OS: Monotonically Increasing Stack to be used
// DON'T FORGET: Traverse array from right to left in case of NEXT (left to right in case of PREV)
// TC: O(N) SC:O(2N)

vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> nse(n,-1);
        stack<int> st;
        
        // traverse the array from right to left
        for(int i=n-1; i>=0; i--)
        {
            // monotonically INCREASING stack
            while(!st.empty() && st.top() >= arr[i])
            st.pop();
            
            if(!st.empty())
            nse[i] = st.top();
            
            st.push(arr[i]);
        }
        return nse;
    }
