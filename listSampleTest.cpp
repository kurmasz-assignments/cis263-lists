//
// Created by Zachary Kurmas on 2019-08-17.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "List.h"
#include <vector>

template<typename T>
void verifyList(const List<T> &l1, std::vector<T> expected) {
  REQUIRE(expected.size() == l1.size());

  auto iter = l1.begin();
  for (int i = 0; i < expected.size(); i++) {
    REQUIRE(expected[i] == *iter);
    ++iter;
  }
  REQUIRE(iter == l1.end());

  iter = l1.end();
  for (int i = expected.size() - 1; i >= 0; --i) {
    --iter;
    REQUIRE(expected[i] == *iter);
  }
  REQUIRE(iter == l1.begin());
}

TEST_CASE("raw_front works for list with one item") {
  List<int> l1;
  l1.push_back(17);

  REQUIRE(17 == l1.raw_front());
}


TEST_CASE("raw_push_front inserts into empty list") {
  List<int> l1;
  l1.raw_push_front(43);
  verifyList(l1, {43});
}

TEST_CASE("raw_push_front inserts multiple items into empty list") {
  List<int> l1;
  l1.raw_push_front(43);
  l1.raw_push_front(81);
  l1.raw_push_front(19);

  verifyList(l1, {19, 81, 43});
}


TEST_CASE("push_front then push_back") {
  List<int> l1;
  l1.raw_push_front(43);
  l1.raw_push_back(22);

  verifyList(l1, {43, 22});
}

TEST_CASE("raw_insert_in_order front of one item list") {
  List<int> l1;
  l1.push_front(15);
  l1.raw_insert_in_order(6);
  verifyList(l1, {6, 15});
}

TEST_CASE("splice into middle") {
  List<int> l1;
  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(3);
  l1.push_back(4);

  List<int> l2;
  l2.push_back(5);
  l2.push_back(6);
  l2.push_back(7);
  l2.push_back(8);

  auto iter = l1.begin();
  ++iter;
  ++iter;

  l1.splice(iter, l2);

  verifyList(l1, {1, 2, 5, 6, 7, 8, 3, 4});
  REQUIRE(l2.empty());
  verifyList(l2, {});
}
