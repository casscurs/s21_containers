// #include "./vector.hpp"

// int main(void) {
//   //   s21::vector<std::string> str;
//   //   std::cout << str.size();
//   s21::vector<std::string> bi = {"not", "aboba"};
//   s21::vector<std::string> vi = {"swap", "swap"};
//   std::cout << "size:" << bi.size() << "capacity:" << bi.capacity() << '\n';
//   bi.reserve(20);
//   std::cout << "after reserve "
//             << "size:" << bi.size() << " capacity:" << bi.capacity() << '\n';

//   for (size_t i = 0; i != bi.size(); ++i) {
//     std::cout << bi[i];
//   }
//   std::cout << '\n';

//   // bi.push_back(" boba");

//   // bi.insert(bi.begin(), "biba");
//   bi.erase(bi.begin());
//   std::cout << "after clear "
//             << "size:" << bi.size() << " capacity:" << bi.capacity() << '\n';

//   for (size_t i = 0; i != bi.size(); ++i) {
//     std::cout << bi[i];
//   }

//   // std::cout << *(bi.begin());
//   // std::cout << '\n';
//   // for (size_t i = 0; i != vi.size(); ++i) {
//   //   std::cout << vi[i];
//   // }

//   return 0;
// }