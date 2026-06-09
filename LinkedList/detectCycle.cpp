// Problem: Detect Cycle
// https://leetcode.com/problems/linked-list-cycle/description/


// BFS: TC: O(N*1) best and avg case, (N*N) worst case for unordered map and O(N*logN) if ordered map used, we traverse the entire linked list once so N TC and store and retrieve nodes from the hash map. Map operations since unordered map used hence 1 or N, if ordered map used them TC: O(logN) for all best, avg and worst. 
// SC: O(N)
// Approach: Using MAP to store visited nodes and finding if an already visited node is encountered or not

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // if(head == NULL || head->next == NULL)
        // return false;
        ListNode* temp = head;
        unordered_map<ListNode*, int> nodeMap;
        while(temp)
        {
            if(nodeMap.find(temp) != nodeMap.end())
            return true;
            nodeMap[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};



//Optimized: Fast and Slow Pointer
// TC: O(N), we traverse the entire linked list once. The fast pointer either reaches the end of the list or meets the slow pointer in linear time.

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
          fast=fast->next->next;
          slow=slow->next;
          if(fast==slow)
          return true;
        }
        return false;
    }
};

