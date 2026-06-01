// Problem: Detect Cycle
// https://leetcode.com/problems/linked-list-cycle/description/


// BFS: TC: O(N*LogN), we traverse the entire linked list once and store and retrieve nodes from the hash map. Map operations have a worst time space complexiy of O(LogN).
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

