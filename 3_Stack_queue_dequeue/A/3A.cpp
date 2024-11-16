#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::pair<char, char> round = {'(', ')'};
  std::pair<char, char> square = {'[', ']'};
  std::pair<char, char> curly = {'{', '}'};
  std::string s, answer;
  std::vector<char> stack;
  int count = 0;
  std::cin >> s;

  for (char c : s) {
    if (c == round.first || c == square.first || c == curly.first) {
      stack.push_back(c);
    }
    if (c == round.second) {
      if (!stack.empty() && stack.back() == round.first)
        stack.pop_back();
      else
        count--;
    } else if (c == square.second) {
      if (!stack.empty() && stack.back() == square.first)
        stack.pop_back();
      else
        count--;
    } else if (c == curly.second) {
      if (!stack.empty() && stack.back() == curly.first)
        stack.pop_back();
      else
        count--;
    }
  }

  answer = (stack.empty() == true && count == 0) ? "yes" : "no";
  std::cout << answer << '\n';
  return 0;
}