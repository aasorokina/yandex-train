#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

bool can_insert(char c, int &count, int &count_round, int &count_square,
                std::deque<char> &answer);

void insert(char c, int &count, int &count_round, int &count_square,
            std::deque<char> &answer);

int main() {
  int n;
  std::cin >> n;
  getchar();
  std::string w;
  std::vector<char> symbols(4, '0');
  std::getline(std::cin, w);
  for (int i = 0; i < 4; i++) {
    symbols[i] = w[i];
  }

  std::string s;
  std::getline(std::cin, s);
  std::deque<char> temp;
  std::deque<char> answer;
  int count_round = 0;
  int count_square = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '[') {
      count_square++;
      temp.push_back(s[i]);
    }
    if (s[i] == '(') {
      count_round++;
      temp.push_back(s[i]);
    }
    if (s[i] == ')') {
      count_round--;
      if (!temp.empty() && temp.back() == '(') temp.pop_back();
    }
    if (s[i] == ']') {
      count_square--;
      if (!temp.empty() && temp.back() == '[') temp.pop_back();
    }
    answer.push_back(s[i]);
  }

  int count = n - answer.size();
  bool inserted = false;
  while (count > 0) {
    for (int i = 0; i < 4 && inserted == false; i++) {
      if (can_insert(symbols[i], count, count_round, count_square, temp)) {
        insert(symbols[i], count, count_round, count_square, temp);
        answer.push_back(symbols[i]);
        inserted = true;
      }
    }
    inserted = false;
  }

  for (char i : answer) {
    std::cout << i;
  }
  std::cout << '\n';

  return 0;
}

bool can_insert(char c, int &count, int &count_round, int &count_square,
                std::deque<char> &temp) {
  if (c == '(' || c == '[') {
    if (count - 2 >= 0 && count > (count_round + count_square)) return true;
  }
  if (c == ')') {
    if (!temp.empty() && temp.back() != '[' && count_round > 0) return true;
  }
  if (c == ']') {
    if (!temp.empty() && temp.back() != '(' && count_square > 0)
      return true;
  }
  return false;
}

void insert(char c, int &count, int &count_round, int &count_square,
            std::deque<char> &temp) {
  if (c == '(') {
    count_round++;
    temp.push_back(c);
  }
  if (c == '[') {
    count_square++;
    temp.push_back(c);
  }
  if (c == ')') {
    if (temp.back() == '(') temp.pop_back();
    count_round--;
  }
  if (c == ']') {
    if (temp.back() == '[') temp.pop_back();
    count_square--;
  }
  count--;
}