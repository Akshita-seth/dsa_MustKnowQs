// Problem: Length of Loop 
// https://www.geeksforgeeks.org/problems/find-length-of-loop/1


//BFS: Using map and timer = 1 variable
//TC: O(N), SC: O(N)

/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* temp = head;
        unordered_map<Node*, int> nodeMap;
        int timer = 1;
        while(temp)
        {
            if(nodeMap.find(temp) != nodeMap.end())
            return timer - nodeMap[temp];
            
            nodeMap[temp] = timer;
            timer++;
            temp = temp->next;
        }
        return 0;
    }
};

//Optimized: using fast and slow pointers along with a findLength() which calculates length by finding the fast-to-slow meeting point.
// TC:  O(N), we traverse the entire linked list at least once to find the length of the loop.

class Solution {
  public: 
    int findLength(Node* fast, Node* slow)
    {
        fast = fast->next;  // This step is imp, bcz otherwise slow will be equal to fast only and will not enter the while loop
        int cnt = 1; //hence cnt starts from 1 bcz fast already on the first node of the loop
        while(slow != fast)
        {
            fast = fast->next;
            cnt++;
        }
        return cnt;
    }
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* fast = head;
        Node* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
             if(fast == slow)
             return findLength(fast, slow);
        }
        return 0;
    }
};


