// Problem: Sort a LL
// https://leetcode.com/problems/sort-list/


// BFS: Vector+sort  (usually faster in practice)
// TC: O(N + N*LogN + N), we traverse the linked list, store its elements in an array, sort it, and then copy the sorted values back into the original list.
// SC: O(N)

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
    ListNode* sortList(ListNode* head) {
        vector<int> list;
        ListNode* temp = head;
        while(temp)
        {
            list.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        sort(list.begin(), list.end());
        for(int i=0; i< list.size(); i++)
        {
            temp->val = list[i];
            temp = temp->next;
        }
        return head;
    }
};


//Also BFS: A multi set can be used but not much improvement v=bcz
// TC: O(N*logN + N) traversing while inserting in multi-set and then again storing as list.
// SC: O(N)

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        multiset<int> list;
        ListNode* temp = head;
        while (temp) {
            list.insert(temp->val);
            temp = temp->next;
        }
        temp = head;
        // for (auto it = list.begin(); it != list.end(); it++) {
        //     temp->val = *it;
        //     temp = temp->next;
        // }
        for (auto val : list) {
            temp->val = val;
            temp = temp->next;
        }

        return head;
    }
};



// Optimized: Using findMidOfList and merge2SortedLists we implemented divide and conquer i.e. merge sort for sorting a linked list.
// TC: O((N + N/2)logN) => O(N*LogN), we recursively divide the linked list into two halves and then merge two sorted halves.
// SC: O(1), just recursive stack space it takes.

class Solution {
public:
    ListNode* merge2Lists(ListNode* list1, ListNode* list2)
    {
       ListNode* dummy = new ListNode();
       ListNode* curr = dummy;
       while(list1 && list2)
       {
        if(list1->val < list2->val)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
       }
       curr->next = list1 ? list1 : list2;
       return dummy->next;
    }
public:
    ListNode* findMid(ListNode* head)
    {
        ListNode* fast = head->next;  //we are keeping fast one step ahead of slow bcz for odd list it will be fine i.e. slow will point to the mid i.e. 3rd element if total is 5 so then right can start from 4th element in sortList fn but for even slow will point at the 3rd element if total 6, ie.e right can strat from mid->next ie.e 4th element, it is basically imp for the "DIVIDE" in the Divide and Conquer Algo of Merge Sort.
        ListNode* slow = head; 
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        //return slow->next; //if this then right = mid
        return slow; //if this then right = mid->next
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        return head;
        ListNode* mid = findMid(head);
        ListNode* right = mid->next;  
        mid->next = NULL;
        ListNode* left = head;
        right = sortList(right);
        left = sortList(left);

        return merge2Lists(left, right);
    }
};
