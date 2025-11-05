#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
  int key;
  Node *left, *right;
  Node(int k): key(k), left(nullptr), right(nullptr) {}
};

int height(Node* n) {
  if(n==nullptr){ return -1;}
  return 1+max(height(n->left), height(n->right));
}

int getBalance(Node* n){
  if(root==nullptr){ return 0;}
  return height(root->left) - height(root->right);
}

// --- Rotations ---
Node* rightRotate(Node* y){
  
}

Node* leftRotate(Node* x){
  
}

// --- Insertion with balancing ---
Node* insert(Node* node, int key) {
// TODO: perform normal BST insertion
// TODO: update height
// TODO: get balance factor
// TODO: apply rotations for 4 imbalance cases
// LL, RR, LR, RL
// TODO: return node
}

void preorder(Node* root){
  if (root != nullptr){
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

int main(){
  Node* root = nullptr;
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 10);
  root = insert(root, 25);
  cout << "Preorder traversal of AVL tree:\n";
  preorder(root);
}
