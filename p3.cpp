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
  if(n==nullptr){ return 0;}
  return height(n->left) - height(n->right);
}

// --- Rotations ---
Node* rightRotate(Node* y){
  Node* x = y->left;
  Node* r = x->right;
  x->right = y;
  y->left = r;
  return x;
}

Node* leftRotate(Node* y){
  Node* x = y->right;
  Node* r = x->left;
  x->left = y;
  y->right = r;
  return x;
}

// --- Insertion with balancing ---
Node* insert(Node* node, int key){
  if(node == nullptr){ return new Node(key);}
  if(key < node->key){ node->left = insert(node->left, key);}
  else if(key > node->key){ node->right = insert(node->right, key);}
  else{ return node; }

  int balance = getBalance(node);

  // ====== balancing tree ====== //
  
  // LL
  if(balance>1 && key < node->left->key){ return rightRotate(node);}

  // RR
  if(balance<-1 && key > node->right->key){ return leftRotate(node);}

  // LR
  if(balance>1 && key > node->left->key){
      node->left = leftRotate(node->left);
      return rightRotate(node);
  }

  // RL
  if (balance<-1 && key < node->right->key){
      node->right = rightRotate(node->right);
      return leftRotate(node);
  }
  
  return node;
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
