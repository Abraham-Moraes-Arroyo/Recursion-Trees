/*
Operations on a binary search tree.
This code implements the binary search tree creation 
and additional class member functions node_count(),
leaf_count(), node_sum(), node_exists, find().
Functions with an _h appended are the helper functions,
which do most of the computational work.
*/

#include<iostream>
#include<vector>

using namespace std;

struct Node {
       int data;
       Node *left;
       Node *right;
};

class BSTree {
      private:
        Node *root;
        void insert_h(int,  Node * );
        Node *find_h(int, Node *);
        int node_count_h(Node *);
        int leaf_count_h(Node *);
        int node_sum_h(Node *);

      public:
        void insert(int);
        void generateBST(vector<int>);
        Node *find(int);
        bool node_exists(int);
        int node_count();
        int leaf_count();
        int node_sum();
        

      BSTree() {
         root = NULL;
      }
};

/*Node Insertion Functions*/
void BSTree::insert_h(int value, Node *leaf) {
           if(value <= leaf->data) {
              if(leaf->left != NULL)
                insert_h(value, leaf->left);
              else {
                leaf->left=new Node;
                leaf->left->data=value;
                leaf->left->left = NULL;    
                leaf->left->right = NULL;   
              }  
           }
           else if(value >leaf->data) {
                if(leaf->right != NULL)
                   insert_h(value, leaf->right);
                else {
                   leaf->right = new Node;
                   leaf->right->data = value;
                   leaf->right->left = NULL;  
                   leaf->right->right= NULL;
              }
          }
}

void BSTree::insert(int value){
           if(root==NULL){
              root=new Node;
              root->data=value;
              root->left=NULL;
              root->right=NULL;
           }
           else
             insert_h(value, root); 
}

void BSTree::generateBST(vector<int> v){
           for (auto x = v.begin(); x != v.end(); ++ x)
                insert(*x); // placing elements of the vector into the BSTree
}

/*Node Finder Functions*/

Node * BSTree::find_h(int value, Node *leaf) {
           if(leaf != NULL) {
              if(value == leaf->data)
                 return leaf;
              if(value < leaf->data)
                 return find_h(value, leaf->left);
              else
                 return find_h(value, leaf->right);
           }
           else 
             return NULL;
}

Node * BSTree::find(int value) {
       return find_h(value, root);
} 

bool BSTree::node_exists(int value){
     if (find(value) == NULL)
        return false;
     else
        return true;
}

/*Tree Operation Functions*/

int BSTree::node_count_h(Node *current){
            static int cnt = 0; 
            if (current != NULL) {
               cnt += 1;
               node_count_h(current->left);
               node_count_h(current->right);
             }
            return cnt;
}

int BSTree::node_count(){
    return node_count_h(root);

}

int BSTree::leaf_count_h(Node *current){
            static int cnt = 0; 
            if (current != NULL) {
               if ((current->left == NULL) and (current->right == NULL))
               cnt += 1;
               leaf_count_h(current->left);
               leaf_count_h(current->right);
             }
            return cnt;
}

int BSTree::leaf_count(){
    return leaf_count_h(root);

}

int BSTree::node_sum_h(Node *current){
    static int sum = 0; 
    if (current != NULL) {
       sum += current->data;
       node_sum_h(current->left);
       node_sum_h(current->right);
    }
    return sum;
}

int BSTree::node_sum(){
    return node_sum_h(root);
}


int main(){
    vector<int> v = {3,6,2,8,1,2,9,7};
    BSTree T;
    T.generateBST(v);
    cout << "---------" << endl;
    cout << "Node exists: " << T.node_exists(6) << endl;
    cout << "---------" << endl;
    cout << "Node count = " << T.node_count() << endl;
    cout << "---------" << endl;
    cout << "Leaf count = " << T.leaf_count() << endl;
    cout << "---------" << endl;
    cout << "Sum of all nodes = " << T.node_sum() << endl;
    return 0;
}

/*
BSTree for v = {3,6,2,8,1,2,9,7}
          (3)
         /   \
       (2)    (6)
      /  \    /  \
    (1)  (N) (N) (8)
    / \        /   \
   (N)(2)    (7)   (9)
      / \    / \   / \
    (N) (N)(N) (N)(N) (N)
N = NULL
*/
