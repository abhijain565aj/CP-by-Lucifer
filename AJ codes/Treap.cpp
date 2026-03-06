
#include <bits/stdc++.h>
using namespace std;

struct Treap {
 public:
  struct Node {
    Node *left, *right;
    char key;
    int prior;
    int size;
    Node() : left(nullptr), right(nullptr), prior(rand()), size(0) {};
    Node(char key) : left(nullptr), right(nullptr), key(key), prior(rand()), size(1) {}
  };
  Node* root;
  Treap() : root(nullptr) {}
  void insert(char key) {
    if (root == nullptr) {
      root = new Node(key);
      return;
    } else {
      Node* n = new Node(key);
      merge(root, root, n);
    }
  }
  pair<Node*, Node*> split(Node* nd, int size) {
    Node *l, *r;
    split(nd, size, l, r);
    return {l, r};
  }
  void merge(Node* l, Node* r) {
    merge(root, l, r);
  }
  Node* getRoot() {
    return root;
  }
  string to_string(Node* t) {
    if (!t) return "";
    return to_string(t->left) + t->key + to_string(t->right);
  }

 private:
  int getSize(Node* t) {
    return t ? t->size : 0;
  }
  void split(Node* t, int size, Node*& l, Node*& r) {
    if (size == 0) {
      l = nullptr;
      r = t;
      return;
    }
    if (getSize(t->left) < size) {
      split(t->right, size - getSize(t->left) - 1, l, r);
      t->right = l;
      l = t;
    } else if (getSize(t->left) > size) {
      split(t->left, size, l, r);
      t->left = r;
      r = t;
    } else {
      l = t->left;
      t->left = nullptr;
      r = t;
    }
    t->size = 1 + getSize(t->left) + getSize(t->right);
  }
  void merge(Node*& t, Node* l, Node* r) {
    if (!l || !r) {
      t = l ? l : r;
      return;
    }
    if (l->prior > r->prior) {
      l->size += r->size;
      merge(l->right, l->right, r);
      t = l;
    } else {
      r->size += l->size;
      merge(r->left, l, r->left);
      t = r;
    }
    t->size = 1 + getSize(t->left) + getSize(t->right);
  }
};