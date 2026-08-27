// https://www.youtube.com/watch?v=NKJnHewiGdc&t=563s

// 👉 Rule of thumb:
// If the heap stores pointers, comparator takes them as plain pointers (T*).
// If the heap stores objects (like pair, int, string), comparator takes them as const T&.

// 1. Insertion: O(logN)
// 2. Deletion: O(logN)
// 3. Heapify (puts just one node to the correct position): O(logN) 
// 4. Building a heap from an array(all nodes, using heapify): O(N) and not O(N*logN) 
//    -> To build a heap, you call heapify on all non‑leaf nodes:
// cpp
// for(int i = n/2 - 1; i >= 0; i--) {
//     heapify(arr, n, i);
// }
//    -> That’s about n/2 calls. Naively, you’d think: n/2 * O(log n) = O(n log n). But the actual complexity is O(n). Why?
//    -> Because not all nodes take O(log n) time:
//    -> Nodes near the bottom have very small subtrees → their heapify runs in constant time.
//    -> Only the top nodes (few in number) can take O(log n) time.
// 6. Heap Sort: O(NlogN)


// HEAPIFY (Downward Fix)
// Purpose: Used when a node might violate the heap property because its value is too large compared to its children.
// Direction: Pushes the node downward until it finds the correct position.
// Use case:
// 1. Building a heap from an array (bottom-up).
// 2. After deleting the root (replace root with last element, then fix down).


// Bubble-Up (Upward Fix) 
while (i != 0 && arr[parent(i)] > arr[i]) {
    swap(&arr[parent(i)], &arr[i]);
    i = parent(i);
}
// Purpose: Used when a node might violate the heap property because its value is too small compared to its parent.
// Direction: Moves the node upward until it finds the correct position.
// Use case: Insertion (new element added at the end, then bubbled up).



#include<bits/stdc++.h>
using namespace std;

class heap{  //MAX HEAP
    public:
       int arr[100];
       int size;
    heap()
    {
        size=0;
    }
    void insert(int val)
    {
        arr[size]=val;
        int i=size;
        size++;
        while(i>0)
        {
            int parent=(i-1)/2;
            if(arr[parent]<arr[i])
            {
               swap(arr[parent],arr[i]);
               i=parent;
            }
            else
             break;
        } 
        return;
    }

    void deleteRoot()  //More robust and general approach
    {
        if(size==0)
        {
            cout<<"Heap is empty"<<endl;
            return;
        }
        arr[0]=arr[size-1]; // put last node in root's place
        size--; //remove the last node
        
        int i=0;
        while(true)
        {
            int left = 2*i+1;
            int right = 2*i+2;
            int largest = i;

            if(left<size && arr[left]>arr[largest]) 
            largest = left;
        
            if(right<size && arr[right]>arr[largest])
            largest = right;
            if(largest != i)
            {
                swap(arr[i],arr[largest]);
                i=largest;
            }
            else
            break; //heap property restored;
        
        }
    }

    void deleteRootSimpler() 
   {     //it’s slightly less general because it doesn’t compare both children before deciding — it prioritizes left if both are valid.
    if(size == 0) {
        cout << "Heap is empty" << endl;
        return;
    }

    // Replace root with last element
    arr[0] = arr[size - 1];
    size--;

    // Heapify down
    int i = 0;
    while(i < size) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && arr[i] < arr[left]) {
            swap(arr[i], arr[left]);
            i = left;
        }
        else if(right < size && arr[i] < arr[right]) {
            swap(arr[i], arr[right]);
            i = right;
        }
        else {
            break; // heap property restored
        }
    }
}


    void print()
    {
        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

};

void heapify(int arr[], int n, int i)
{
    int largest  = i; // Initialize largest as root
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[left]>arr[largest])
    largest = left;
    if(right < n && arr[right]>arr[largest])
    largest = right;
    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr,n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        // step 1
        swap(arr[size-1], arr[0]);
        size--;
        // step 2
        heapify(arr, size, 0);
    }
}

int main()
{
    heap h;
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    //h.print();
    h.deleteRoot();
    // h.insert(55);
    // h.insert(70);
    //h.print();

    int n=6;
    int arr[n] = {10,20,80,30,40,70};

    // Building the heap
    for(int i=n/2-1; i>=0; i--)
    {
        heapify(arr, n, i);
    }

    cout<< "Heap array is: "<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";


    // Heap sort
    heapSort(arr, n);

    cout<< "Sorted array is: "<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    // Using priority Queue
    priority_queue<int> pq; // max heap by default

    priority_queue<int, vector<int>, greater<int>> min_pq; // min heap
    return 0;
}
