#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>

int main() {
  int n, m;
  std::cin >> n;
  std::string input;
  std::map<std::string, int> names;
  for (int i = 0; i < n; i++) {
    std::cin >> input;
    names.insert({input, 0});
  }

  std::cin >> m >> std::ws;
  int first, second, prevFirst = 0, prevSecond = 0;
  std::string name;
  char raw_name[20];
  for (int i = 0; i < m; i++) {
    std::scanf("%d:%d %s", &first, &second, raw_name);
    name = raw_name;
    names.at(name) += std::max(first - prevFirst, second - prevSecond);
    prevFirst = first;
    prevSecond = second;
  }

  auto winner = std::max_element(names.begin(), names.end(),
                                 [](const std::pair<std::string, int>& p1,
                                    const std::pair<std::string, int>& p2) {
                                   return p1.second < p2.second;
                                 });

  std::cout << winner->first << " " << winner->second << '\n';

  return 0;
}