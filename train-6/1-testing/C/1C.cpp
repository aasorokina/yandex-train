#include <algorithm>
#include <iostream>
#include <vector>

void del_dupl_rows(std::vector<std::string> &m);
void del_dupl_cols(std::vector<std::string> &m);
void transpose(std::vector<std::string> &m);
int count_diods(std::vector<std::string> &m);
char get_answer(std::vector<std::string> &m);

int main() {
  unsigned n;
  std::cin >> n;
  std::vector<std::string> m(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> m[i];
  }

  del_dupl_rows(m);
  transpose(m);
  del_dupl_cols(m);
  transpose(m);
  char answer = get_answer(m);
  std::cout << answer << '\n';
  return 0;
}

void del_dupl_rows(std::vector<std::string> &m) {
  std::string line(m.size(), '.');
  std::string empty(m.size(), ',');
  for (size_t i = 0; i < m.size(); i++) {
    if (line == m[i]) {
      if (line != empty) {
        m.erase(m.begin() + i);
        m.push_back(empty);
        --i;
      }
    } else
      line = m[i];
  }

  for (size_t i = 0; i < m.size(); i++) {
    if (m[i] == empty) {
      m[i] = std::string(m.size(), '.');
    }
  }
}

void del_dupl_cols(std::vector<std::string> &m) {
  std::string line(m.size(), '.');
  std::string empty(m.size(), ',');
  for (size_t i = m.size() - 1; i > 0; i--) {
    if (m[i] == line) {
      if (line != empty) {
        m.erase(m.end() - (m.size() - i));
        m.insert(m.begin(), empty);
        ++i;
      }
    } else
      line = m[i];
  }
}

void transpose(std::vector<std::string> &m) {
  std::vector<std::string> transposed(m.size(), std::string(m.size(), ' '));
  for (size_t i = 0; i < m.size(); i++) {
    for (size_t j = 0; j < m.size(); j++) {
      transposed[j][i] = m[i][j];
    }
  }
  m = transposed;
}

int count_diods(std::vector<std::string> &m) {
  int count = 0;
  for (size_t i = 0; i < m.size(); i++) {
    for (size_t j = 0; j < m.size(); j++) {
      if (m[i][j] == '#') {
        count++;
      }
    }
  }
  return count;
}

char get_answer(std::vector<std::string> &m) {
  std::vector<std::string> temp(3, std::string(3, '#'));
  temp[1][1] = '.';
  int diods = count_diods(m);
  int n = m.size();
  char answer = 'X';
  if (diods == 1) {
    answer = 'I';
  } else if (diods == 3) {
    if (m[0][n - 2] == '#' && m[1][n - 2] == '#' && m[1][n - 1] == '#') {
      answer = 'L';
    }
  } else if (diods == 5) {
    for (int i = 0; i < 3; i++) {
      temp[i][2] = '.';
    }
    answer = 'C';
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 2; j++) {
        if (m[i][n - 2 + j] != temp[i][j]) answer = 'X';
      }
    }
  } else if (diods == 7) {
    temp[1][1] = '#';
    temp[0][1] = temp[2][1] = '.';
    answer = 'H';
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (m[i][n - 3 + j] != temp[i][j]) answer = 'X';
      }
    }
  } else if (diods == 8) {
    answer = 'O';
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (m[i][n - 3 + j] != temp[i][j]) answer = 'X';
      }
    }
  } else if (diods == 9) {
    answer = 'P';
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (m[i][n - 3 + j] != temp[i][j]) answer = 'X';
      }
    }
    if(m[3][n-3] != '#') answer = 'X';
  }
  return answer;
}