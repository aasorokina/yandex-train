#include <iostream>
#include <map>
#include <set>

void get_children(std::string grandpa,
                  std::multimap<std::string, std::string> &input,
                  std::map<std::string, std::pair<int, std::string>> &tree,
                  int i);

std::string get_lca(
    std::map<std::string, std::pair<int, std::string>> const &tree,
    std::string const &first, std::string const &second);

int main() {
  int n;
  std::cin >> n;
  std::string child, parent;
  std::map<std::string, std::pair<int, std::string>> tree;
  std::set<std::string> children;
  std::multimap<std::string, std::string> input;

  for (int i = 0; i < n - 1; i++) {
    std::cin >> child >> parent;
    input.insert({parent, child});
    children.insert(child);
  }

  auto grandpa = input.begin();
  for (; grandpa != input.end(); grandpa++) {
    if (children.count(grandpa->first) == 0) {
      break;
    }
  }

  tree.insert({grandpa->first, {0, "null"}});
  get_children(grandpa->first, input, tree, 0);

  while (std::cin >> child >> parent)
    std::cout << get_lca(tree, child, parent) << '\n';

  return 0;
}

void get_children(std::string grandpa,
                  std::multimap<std::string, std::string> &input,
                  std::map<std::string, std::pair<int, std::string>> &tree,
                  int i) {
  auto range = input.equal_range(grandpa);
  if (range.first == range.second) return;
  for (auto item = range.first; item != range.second; item++) {
    tree.insert({item->second, {i + 1, grandpa}});
    get_children(item->second, input, tree, i + 1);
  }
}

std::string get_lca(
    std::map<std::string, std::pair<int, std::string>> const &tree,
    std::string const &first, std::string const &second) {
  auto iter1 = tree.find(first);
  auto iter2 = tree.find(second);
  int h1 = iter1->second.first;
  int h2 = iter2->second.first;

  while (h1 != h2) {
    if (h1 > h2) {
      iter1 = tree.find(iter1->second.second);
      h1--;
    } else {
      iter2 = tree.find(iter2->second.second);
      h2--;
    }
  }
  while (iter1 != iter2) {
    iter1 = tree.find(iter1->second.second);
    iter2 = tree.find(iter2->second.second);
  }
  return iter1->first;
}