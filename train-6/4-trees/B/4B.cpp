#include <iostream>
#include <map>
#include <set>

int get_children(std::string grandpa,
                 std::multimap<std::string, std::string> &input,
                 std::map<std::string, int> &tree);

int main() {
  int n;
  std::cin >> n;
  std::string child, parent;
  std::map<std::string, int> tree;
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

  int res = get_children(grandpa->first, input, tree);
  tree.insert({grandpa->first, res});
  for (auto item : tree) std::cout << item.first << ' ' << item.second << '\n';

  return 0;
}

int get_children(std::string grandpa,
                 std::multimap<std::string, std::string> &input,
                 std::map<std::string, int> &tree) {
  auto range = input.equal_range(grandpa);
  if (range.first == range.second) {
    tree.insert({grandpa, 0});
    return 1;
  }
  int res = 0;
  for (auto item = range.first; item != range.second; item++) {
    res += get_children(item->second, input, tree);
  }
  tree.insert({grandpa, res});
  return res + 1;
}