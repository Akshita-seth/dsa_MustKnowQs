// Problem: Sort a LL of 0s, 1s, 2s
// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1


// Soln 1: Counting Method (Simplest)
// Traverse the list once and count the number of 0s, 1s, and 2s.
// Then traverse again and overwrite node values in order: first all 0s, then 1s, then 2s.
// TC: O(n), SC: O(1)


class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head) return head;

        // Step 1: Count 0s, 1s, and 2s
        int count0 = 0, count1 = 0, count2 = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data == 0) count0++;
            else if (temp->data == 1) count1++;
            else count2++;
            temp = temp->next;
        }

        // Step 2: Rewrite values in order
        temp = head;
        while (count0--) {
            temp->data = 0;
            temp = temp->next;
        }
        while (count1--) {
            temp->data = 1;
            temp = temp->next;
        }
        while (count2--) {
            temp->data = 2;
            temp = temp->next;
        }

        return head;
    }
};


// Soln 2:  Partition the linked list into three dummy sublists (0s, 1s, 2s) while traversing, then stitch them together in order, carefully skipping empty lists so the final head points to the first non‑empty sublist.
// TC: O(N), SC: O(1)


/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* dummy0 = new Node(0);
        Node* dummy1 = new Node(0);
        Node* dummy2 = new Node(0);
        Node* curr0 = dummy0;
        Node* curr1 = dummy1;
        Node* curr2 = dummy2;
        Node* temp = head;
        
        while(temp)
        {
            if(temp->data == 0)
            {
                curr0->next = temp;
                curr0 = curr0->next;
            }
            else if(temp->data == 1)
            {
                curr1->next = temp;
                curr1 = curr1->next;
            }
            else
            {
                curr2->next = temp;
                curr2 = curr2->next;
            }
            temp = temp->next;
        }
        curr0->next = dummy1->next ? dummy1->next : dummy2->next;
        curr1->next = dummy2->next;
        curr2->next = NULL;
        
        return dummy0->next ? dummy0->next : (dummy1->next ? dummy1->next : dummy2->next);;
    }
};
