#include <iostream>
#include <map>
#include <set>

void get_children(std::string grandpa,
                  std::multimap<std::string, std::string> &input,
                  std::map<std::string, int> &tree, int i);

int main() {
  int n;
  std::cin >> n;
  std::string child, parent;
  std::map<std::string, int> tree;
  std::set<std::string> children;
  std::multimap<std::string, std::string> input;

  for (int i = 0; i < n; i++) {
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

  tree.insert({grandpa->first, 0});
  get_children(grandpa->first, input, tree, 0);
  for (auto item : tree) std::cout << item.first << ' ' << item.second << '\n';

  return 0;
}

void get_children(std::string grandpa,
                  std::multimap<std::string, std::string> &input,
                  std::map<std::string, int> &tree, int i) {
  auto range = input.equal_range(grandpa);
  if (range.first == range.second) return;
  for (auto item = range.first; item != range.second; item++) {
    tree.insert({item->second, i + 1});
    get_children(item->second, input, tree, i + 1);
  }
}