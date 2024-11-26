#include <iostream>

struct Node {
  int data;
  int depth = 0;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
};

void insert(Node*& root, int value);
Node* find(Node* root, int value);
void clear(Node*& root);
void print_tree(Node* root);

int main() {
  int n = 0;
  std::string action;
  Node* tree = nullptr;

  while (std::cin >> action) {
    if (action == "PRINTTREE") {
      print_tree(tree);
      continue;
    }
    std::cin >> n;
    if (action == "ADD") {
      if (find(tree, n) == nullptr) {
        insert(tree, n);
        std::cout << "DONE\n";
      } else
        std::cout << "ALREADY\n";
    }
    if (action == "SEARCH") {
      std::cout << ((find(tree, n) == nullptr) ? "NO\n" : "YES\n");
    }
  }

  clear(tree);
  return 0;
}

void insert(Node*& root, int value) {
  Node* current = root;
  Node* parent = nullptr;
  while (current != nullptr) {
    parent = current;
    if (value < parent->data) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  Node* new_node = new Node{value, parent == nullptr ? 0 : (parent->depth + 1),
                            nullptr, nullptr, parent};
  if (parent != nullptr) {
    if (value < parent->data) {
      parent->left = new_node;
    } else {
      parent->right = new_node;
    }
  } else {
    root = new_node;
  }
}

Node* find(Node* root, int value) {
  Node* current = root;
  while (current != nullptr) {
    if (value == current->data) {
      return current;
    } else {
      if (value < current->data) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
  }
  return nullptr;
}

void clear(Node*& root) {
  if (root == nullptr) return;
  clear(root->left);
  clear(root->right);
  delete root;
  root = nullptr;
}

void print_tree(Node* root) {
  if (root == nullptr) return;
  print_tree(root->left);
  for (int i = 0; i < root->depth; i++) std::cout << '.';
  std::cout << root->data << '\n';
  print_tree(root->right);
}