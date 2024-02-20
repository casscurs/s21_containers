#include "./vector.hpp"

int main(void) {
  //   s21::vector<std::string> str;
  //   std::cout << str.size();
  s21::vector<std::string> bi = {"not", "aboba"};
  s21::vector<std::string> vi;
  vi = std::move(bi);
  // s21:vector<std::string>
  for (size_t i = 0; i != vi.size(); ++i) {
    std::cout << vi[i];
  }
  std::cout << bi.front() << ' ';
  std::cout << bi.back() << " ";

  // std::vector<std::string> str1{"str"};
  // std::cout << "orig " << str1.max_size() << '\n';

  s21::vector<std::string> str2;
  std::cout << str2.max_size();
  // тест всех конструктовов
  return 0;
}