#include "./vector_class.hpp"
#include "./vector_help.hpp"
#include "./vector_methods.hpp"

int main(void) {
  //   s21::vector<std::string> str;
  //   std::cout << str.size();
  s21::vector<std::string> bi = {"not", "aboba"};
  s21::vector<std::string> vi = bi;
  // s21:vector<std::string>
  for (size_t i = 0; i != vi.size(); ++i) {
    std::cout << vi[i];
  }
  return 0;
}