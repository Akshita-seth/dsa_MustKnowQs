// Problem: Implement Min Stack
// https://leetcode.com/problems/min-stack/
// https://www.youtube.com/watch?si=4_Jbsq5trFvfSdUY&v=NdDIaH91P0g&feature=youtu.be


// BFS: TC: O(1), SC: O(2N) => : O(N) extra (since every element carries its own min).


#include <stack>
#include <utility> // for pair
using namespace std;

class MinStack {
public:
    stack<pair<int,int>> st;  // each element: {value, currentMin}

    MinStack() {}

    void push(int value) {
        if(st.empty()) {
            st.push({value, value});
        } else {
            int currentMin = min(value, st.top().second);
            st.push({value, currentMin});
        }
    }

    void pop() {
        if(!st.empty()) {
            st.pop();
        }
    }

    int top() {
        if(st.empty()) return -1;
        return st.top().first;
    }

    int getMin() {
        if(st.empty()) return -1;
        return st.top().second;
    }
};





// OS: TC: O(1) SC:O(N) only for teh stack used already

class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int value) {
        if(st.empty())
        {
            st.push(value);
            mini = value;
            return;
        }
        if(value >= mini)
        st.push(value);
        else
        {
            st.push(2LL * value - mini);
            mini = value;
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long popped = st.top();
        st.pop();

        if(popped < mini)
        mini = 2LL*mini - popped; 
    }
    
    int top() {
        if(st.empty()) 
        return -1;

        long long topVal = st.top();
        
        return (topVal < mini) ? (int)mini : (int)topVal;
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
