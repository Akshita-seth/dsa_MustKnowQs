// Problem: Largest Rectangle in Histogram
//https://leetcode.com/problems/largest-rectangle-in-histogram/
// https://www.youtube.com/watch?v=Bzat9vgD0fs


// BFS:  TC: O(N^2), SC: O(1)


// 1st version: using curr 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;

        // Consider every bar one by one
        for(int i=0; i<n; i++)
        {
            int curr = heights[i];
            int width = 1;

            // expanding towards left
            // Traverse left while we have a greater height bar
            for(int j=i-1; j>=0 && heights[j] >= heights[i]; j--)
            curr += heights[i];
            // expanding right
            // Traverse right while we have a greater height bar
            for(int j=i+1; j<n && heights[j] >= heights[i]; j++)
            curr += heights[i];

            ans = max(ans,curr);
        }
        return ans;
    }
};

// 2nd version: using width and h
int getMaxArea(vector<int> &arr){
    int n = arr.size();
    int res = 0;

    for(int i = 0; i < n; i++){
        int h = arr[i];
        int width = 1;

        // expand left
        for(int j = i-1; j >= 0 && arr[j] >= h; j--) width++;

        // expand right
        for(int j = i+1; j < n && arr[j] >= h; j++) width++;

        res = max(res, h * width);
    }
    return res;
}



// OS: TWO PASS SOLN:
// Key difference
// Left → right NSE: assign to the popped index (nse[st.top()] = i).
// Right → left NSE: assign to the current index (nse[i] = st.top()).

// left→right PSE: updates(assigns to) current index (pse[i] = st.top();)
// right→left PSE: updates popped indices. (pse[st.top()] = i)

// One-liner intuition
// NSE:
// L→R: future smaller resolves past bars
// R→L: current bar finds its smaller ahead
// PSE:
// L→R: current bar looks back
// R→L: future smaller resolves waiting bars

// for helper fns:
// At first glance, it looks like nested work — but here’s the trick:
// Each index is pushed once and popped once.
// So across the whole run, total pushes = N, total pops = N.
// That makes the inner while loops amortized O(N).
// Therefore, each function is O(2N) overall.

// TC: O(2N) + O(2N) + O(N) = O(5N) -> O(N)
// SC: O(2N) + O(2N) = O(4N)

class Solution {
public:
    vector<int> nextSmaller(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> nse(n,n);
        stack<int> st;
        //Traverse right to left
        for(int i=n-1; i>=0; i--)
        {
            
            while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

            if(!st.empty())
            nse[i] = st.top(); // Updates current idx
            // if traversal was left to right=> updates popped index
            st.push(i);
        } 
        return nse;
    }
    vector<int> prevSmaller(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> pse(n,-1);
        stack<int> st;

        // Trverses left to right
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
            if(!st.empty())
            pse[i] = st.top();  // Updates current idx
            // if traversal was right to left => updates popped index
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = nextSmaller(heights); // TC: => O(2N), SC: O(2N) -> stack in helper fn + nse 
        vector<int> pse = prevSmaller(heights);  // TC: O(2N), SC: O(2N) -> stack in helper fn + nse 

        int maxi = 0;

        for(int i=0; i<heights.size(); i++)  // TC: O(N)
        {
            int area = heights[i] * (nse[i] - pse[i] - 1);
            maxi = max(area, maxi);
        }
        return maxi;
    }
};


// OS: One stack solution
// TC: O(N) for traversal + O(N) for every every index altogether once
// SC: O(N) just the stack

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxi=0;
        stack<int> st;
        int nse, pse;

        // FORMULA: heights[i] * (nse - pse - 1)
        for(int i=0;i<n; i++)
        {
             while(!st.empty() && heights[st.top()] > heights[i])
             {
                int element = st.top(); // top before popping is the element to be touched i.e. computed
                st.pop();

                //nse computation is done while coming back, i.e. while popping since the right of taht indec has been seen, found smaller hence being popped
                nse = i; // Current index is NSE [OFC bcz of that only entered the while loop]
                pse = st.empty()? -1: st.top(); // after popping get PSE
                maxi = max(maxi, heights[element] * (nse-pse-1));
             }
            st.push(i);
        }
        // If elements still left in stack => those els do not hv pse/nse
        // Hence they are not touched yet
        
        while(!st.empty())
        {
            nse = n;
            int element = st.top();
            st.pop();
            pse = st.empty()? -1 : st.top();
            maxi = max(maxi, heights[element] * (nse-pse-1));
        }
        return maxi;
    }
};
