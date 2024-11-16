#include <iostream>

int main() {
  int x, y, x1, y1, x2, y2 = 0;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
  std::string res;
  if(x >= x1 && x <= x2){
    if(y > y2) res = "N";
    else res = "S";
  }
  else if(y >= y1 && y <= y2){
    if(x > x2) res = "E";
    else res = "W";
  }
  else {
    if(x < x1){
      if(y > y2) res = "NW";
      else if (y < y1) res = "SW";
    }
    if(x > x2){
      if(y > y2) res = "NE";
      else if(y < y1) res = "SE";
    }
  }
  std::cout << res <<"\n";
  return 0;
}