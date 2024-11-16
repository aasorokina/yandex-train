#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long int;

int main() {
  int n;
  std::cin >> n;
  std::vector<ll> vec(n);
  std::vector<ll> answer;

  for (int i = 0; i < n; i++) {
    std::cin >> vec[i];
  }

  std::sort(vec.begin(), vec.end());
  int count = n;
  ll mediana;

  while (count > 0) {
    if (count % 2 != 0) {
      mediana = count / 2;
    } else {
      mediana = (vec[(count / 2) - 1] < vec[count / 2]) ? ((count / 2) - 1) : (count / 2);
    }
    answer.push_back(vec[mediana]);
    auto iter = (vec.begin() + mediana);
    vec.erase(iter);
    count--;
  }

   for (int i = 0; i < n; i++) {
     std::cout << answer[i] << " ";
   }
   std::cout << '\n';
  return 0;
}