// Problem: Palindrome LL
// https://leetcode.com/problems/palindrome-linked-list/


// BFS: Use stack, bcz when popped, it will give the reversed values.
// TC: O(2N), we traverse the entire linked list twice, once to push all elements into the stack, and once to compare them with the original list.
// SC: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> nodes;
        ListNode* temp = head;
        while(temp)
        {
            nodes.push(temp->val);
            temp=temp->next;
        }
        temp = head;
        while(temp != NULL)
        {
            if(temp->val != nodes.top())
            return false;
            nodes.pop();
            temp = temp->next;
        }
        return true;
    }
};


//Optimized: Reversing the Second Half of LL, fast and slow pointer used to get to the midle of LL.
// TC: O(N), we traverse the list twice, once to reverse half of it and once to compare, each taking O(N/2), which simplifies to O(N).

class Solution {
public: 
    ListNode* reverseLL(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* newHead=reverseLL(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return true;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* newHead=reverseLL(slow->next);//reversing from middle;
        ListNode* first=head;
        ListNode* second=newHead;
        while(second!=NULL)
        {
            if(first->val != second->val)
            {
                reverseLL(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
         reverseLL(newHead);
         return true;

    }
};
