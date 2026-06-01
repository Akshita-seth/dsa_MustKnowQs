//Problem: Reverse a Linked List
//https://leetcode.com/problems/reverse-linked-list/description/

//BFS: Using Stack jjst values reversed

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
