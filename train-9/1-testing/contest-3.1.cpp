#include <algorithm>
#include <cctype>
#include <iostream>

int count_apostrophes(int pos, std::string& str) {
  int count = 0, end = str.size();
  while (str[pos] == '\'' && pos < end) {
    count++;
    pos++;
  }
  return count;
}

int main() {
  std::string input;
  std::getline(std::cin, input);

  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '\'' && (i == 0 || std::isspace(input[i - 1]))) {
      int count = count_apostrophes(i, input);
      input.erase(i, count * 2);
    } else if (input[i] == '\'' && std::islower(input[i - 1])) {
      int count = count_apostrophes(i, input);
      input.erase(i - count, count * 2);
      i -= count;
    }
  }

  input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
  std::cout << input << '\n';

  return 0;
}
