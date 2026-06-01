//Problem: Reverse a Linked List
//https://leetcode.com/problems/reverse-linked-list/description/

//BFS: Using Stack. Just values reversed
// TC: O(2N) ,We traverse the linked list twice once to push all node values into the stack, and once to reassign values. Each traversal takes O(N) time, where N is the number of nodes.
// SC: O(N)

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Function to reverse a linked list using stack
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while (temp != NULL) {    // Traverse and push all node values to stack
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};


//Optimized Iterative approach => Changing the links 
TC: O(N)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};


 //RECURSIVE METHOD
// TC: O(N)Each node is visited exactly once during the recursive call, and we do constant-time work for each node (like flipping pointers).
// SC:  O(n),The recursion stack goes up to n levels deep (one for each node), which uses extra space on the call stack.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        return head;
        ListNode* newHead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newHead;
    }
};
