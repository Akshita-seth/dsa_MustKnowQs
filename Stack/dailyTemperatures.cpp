// Problem: Daily Temperatures
//


// BFS: TC: O(N^2) SC: O(1)
// Like NGE: 1st Imp: Initialize array size, 2nd Imp: Brak is imp

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            int days = 0;
            for(int j=i+1; j<n; j++)
            {
                days++;
                if(temperatures[j] > temperatures[i])
                {
                    ans[i] = days;
                    break;
                }
            }
        }
        return ans;
    }
};


// OS: TC: O(N), SC: O(N)


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;   // store indices
        vector<int> ans(n,0);

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && temperatures[st.top()] < temperatures[i]) // remeber not <= bcz here strictly decreasing stack
            {
                int prev = st.top();
                st.pop();
                ans[prev] = i - prev; // days until warmer
            }
            st.push(i);
        }
        return ans;
    }
};
