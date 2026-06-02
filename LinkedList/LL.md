struct Node { 
    int data;
    Node* next;
    Node(int d, Node* n=nullptr) : data(d), next(n) {}
};
int main(){
Node x = Node(2, nullptr);
Node* y= new Node(2, nullptr);
cout << y; 
cout << y->data;
cout << y->next;
cout << x;
cout << x->data;
cout << x->next;
}


1. This will be a problem=> Node x = new Node(2, nullptr);
Problem: new Node(…) returns a pointer, but you’re trying to assign it to a plain Node object (x).

This won’t compile. If you meant to store the pointer, it should be:

cpp
Node* x = new Node(2, nullptr);
Otherwise, if you want a stack object:

cpp
Node x(2, nullptr);

2. Node* y = new Node(2, nullptr);
✅ This is correct. y is a pointer to a dynamically allocated Node.

3. cout << y;
Prints the address stored in y (something like 0x7ffee3a2b8).

Because y is a pointer, cout shows its memory location.

4. cout << y->data;
Prints the integer value inside the node.

Output: 2.

5. cout << y->next;
Prints the address stored in next.

Since you passed nullptr, it prints 0 or (nil) depending on your compiler.

6. cout << x;
If x is declared as Node* x = new Node(…):
→ Prints the address of the allocated node (same behavior as cout << y;).

If x is declared as Node x(…):
→ This won’t compile, because cout << x; doesn’t know how to print a Node object unless you overload operator<<.

7. cout << x->data;
If x is a pointer (Node*): prints 2.

If x is a stack object (Node), this won’t compile — you’d need x.data.

8. cout << x->next;
If x is a pointer: prints nullptr (same as y->next).

If x is a stack object: again, won’t compile — you’d need x.next.
