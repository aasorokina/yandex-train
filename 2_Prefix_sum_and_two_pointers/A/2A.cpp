#include <iostream>
#include <vector>

using ll = long long int;

int main() {
  int n;
  std::cin >> n;
  std::vector<int> vec(n);
  std::vector<ll> prefix(n + 1, 0);
 
  for (int i = 0; i < n; i++) {
    std::cin >> vec[i];
    prefix[i + 1] = prefix[i] + vec[i];
    std::cout << prefix[i + 1] << " ";
  }
  std::cout << "\n";
  return 0;
}