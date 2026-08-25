// Problem: Previous Smaller Element
// https://www.geeksforgeeks.org/problems/previous-smaller-element/1


// BFS: TC: O(N^2) SC: O(N) ans vector
// Trversing right to left

class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> pse(n,-1);
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j = i-1; j>=0; j--)
            {
                if(arr[j] < arr[i])
                {
                    pse[i] = arr[j];
                    break;
                }
            }
        }
        return pse;
    }
};

// OS: TC: O(N) SC: O(2N) 
// Previous -> Left to right traversal
// Smaller -> Monotonically Increasing Stack

class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> pse(n,-1);
        stack<int> st;
        
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && st.top() >= arr[i])
            st.pop();
            
            if(!st.empty())
            pse[i] = st.top();
            
            st.push(arr[i]);
        }
        return pse;
    }
};
