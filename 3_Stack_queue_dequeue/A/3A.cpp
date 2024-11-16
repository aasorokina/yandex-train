#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::string s, answer;
  std::vector<char> stack;
  int count = 0;
  std::cin >> s;

  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') {
      stack.push_back(c);
    }
    if (c == ')') {
      if (!stack.empty() && stack.back() == '(')
        stack.pop_back();
      else
        count--;
    } else if (c == ']') {
      if (!stack.empty() && stack.back() == '[')
        stack.pop_back();
      else
        count--;
    } else if (c == '}') {
      if (!stack.empty() && stack.back() == '{')
        stack.pop_back();
      else
        count--;
    }
  }

  answer = (stack.empty() == true && count == 0) ? "yes" : "no";
  std::cout << answer << '\n';
  return 0;
}