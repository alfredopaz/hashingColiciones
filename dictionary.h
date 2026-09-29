#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP
#include <array>
#include <cstddef>

class Dictionary {
  struct Node {
    unsigned key;
    int value;
    Node* next;
  };
  static constexpr std::size_t M = 7;
  std::array<Node*, M> bucket{};
  std::size_t count = 0;
public:
  Dictionary() = default;
  Dictionary(const Dictionary&) = delete;
  Dictionary& operator=(const Dictionary&) = delete;
  ~Dictionary();

  bool get(unsigned key, int& value) const;
  bool put(unsigned key, int value);
  std::size_t size() const { return count; }
  void clear();
};
#endif
