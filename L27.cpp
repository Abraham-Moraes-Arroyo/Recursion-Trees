#include<iostream> 

using namespace std;

/*
Basic structure 

      (k = root)[i]
       /         \
(left)[2*i+1]   (right)[2*i+2]

*/
/*
The heapification process is a process in which a binary tree is converted into a heap structure, in this case maximum heap, 
preseving at every stage the heap property. A heap property is the condiction where the root node's value is greater than that of its children.
*/

void heapify(int A[], int n, int i) { 
    int max = i;       // Initialize max as root, the k-th node, see below 
    int left = 2*i+1;  // these are the children of the k-th node, computed here using a fixed index formula
    int right = 2*i+2; // these are the children of the k-th node
  
    // Checking if the left child is larger than root (the k-th node, see below)
    if ((left < n) and (A[left] > A[max])) 
        max = left; 
  
    // Checking if the right child is larger than root (the k-th node)
    if ((right < n) and (A[right] > A[max])) 
        max = right; 
  
    // If maximum is not root, make it so 
    if (max != i) { 
        swap(A[i], A[max]);
        heapify(A, n, max);  // Repeat this whole process recursively by calling heapify function
    }
} 
  
void buildMaxHeap(int A[], int n) { 
    // k is the index of the farthest to the bottom-right node that is not a leaf. This is where comparing and swapping will begin
    int k = (n/2)-1;
  
    /*Starting at the k node, i.e. farthest to the bottom-right node, we compare it with its children nodes, and swapping if necessary
    in effect, we are traversing the tree bottom to top, however, we do so recursively by making a call to the heapify function. 
    */
    for (int i = k; i >= 0; i--) { 
        heapify(A, n, i); 
    } 
} 

/*Deletion of the root node is accomlished by swaping the last element in the maximal heap with the root node 
  and and then deleting the last element. 
  Note the &n argument to the function, meaning we are passing a reference to the integer n variable, 
  which we want to modify (i.e. decrease) inside the function, so we pass it the address location and 
  then change the value stored at that address, ie. n--; 
  &n = 0x7fffe75297dc, some address location 
  and n = 6, the value stored at that location;
*/

void deleteRootNode(int A[], int &n){
     /*The root node has the top priority in a heap, where the heap property is being maintained at all times.
     Because of this priority nature, priority queues are implemented by using a heap.
     */

     int last = A[n-1];
     A[0] = last;
     n--;
     heapify(A, n, 0);
}

// pop function returns the root node (with highest priority) and then deletes it from the heap.
int popRootNode(int A[], int &n){
    int root = A[0];
    deleteRootNode(A, n);
    return root;
}  
void display(int A[], int n){
     for (int i = 0; i < n; ++i)
         cout << A[i] << " ";
     cout << endl;
}

// The max heap tree is build using an array and its indices. 
// In particular, the structure is build in-place by rearranging the 
// indices of the array in the correct manner, that is, such that the 
// root node's value is greater than that of its children. This is called the heap property.
// This property must be maintained at all times.
// Steps include, building a tree using indices only, then heapifying the 
// tree, such that the heap property is satisfied everywhere.
int main() { 
    int A[] = {4,8,2,5,9,1,6}; 
    int n = sizeof(A)/sizeof(A[0]); 
  
    buildMaxHeap(A, n); 
    display(A, n);
    deleteRootNode(A, n); 
    display(A, n);
    cout << popRootNode(A, n) << endl;
    display(A, n);
    return 0; 
}

/*

Building binary tree with values {4,8,2,5,9,1,6};

            (4)

      (8)        (2)

   (5)   (9)  (1)    (6)

---------------------------------------------
Then, start hipifying to make a maximum heap:

first determine the largest value between 1,2,6 and make that the root:
so, we swap 2 and 6

           (4)

      (8)        (6)

   (5)   (9)  (1)    (2)

next determine the largest value between 5,8,9 and make that the root:
so, we swap 8 and 9

           (4)

      (9)        (6)

   (5)   (8)  (1)    (2)

next determine the largest value between 9,4,6 and make that the root:
so, we swap 4 and 9

           (9)

      (4)        (6)

   (5)   (8)  (1)    (2)

next determine the largest value between 5,4,8 and make that the root:
so, we swap 4 and 8

           (9)

      (8)        (6)

   (5)   (4)  (1)    (2)

We have built the max heap at this stage: our array looks like: [9,8,6,5,4,1,2]

*/ 
