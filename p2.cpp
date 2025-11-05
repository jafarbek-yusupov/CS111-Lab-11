#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
  int key;
  Node *left, *right;
  Node(int k): key(k), left(nullptr), right(nullptr) {}
};

// ===== Problem 2 ===== 
int height(Node* root) {
  if(root==nullptr){ return -1;}
  return 1+max(height(root->left), height(root->right));
}

int balanceFactor(Node* root){
  if(root==nullptr){ return 0;}
  return height(root->left) - height(root->right);
}
// =================== 

int main() {
  Node* root = new Node(10);
  root->left = new Node(5);
  root->right = new Node(15);
  root->left->left = new Node(3);
  cout << "Balance Factor of root: " << balanceFactor(root);
}
