//
// Created by Zachary Kurmas on 2019-08-17.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Vector.h"

TEST_CASE("Resize changes size if plenty of capacity") {
  Vector<int> v1(10);

  // This isn't necessary for Vector to operate correctly,
  // but, if Vector changes how it handles SPARE_CAPACITY,
  // we want a quick failure so we know what's going on.
  REQUIRE(12 == v1.capacity());

  v1.resize(12);
  REQUIRE(v1.size() == 12);
}

TEST_CASE("Resize does not change capacity if not necessary.") {
  Vector<int> v1(10);
  v1.resize(12);
  REQUIRE(v1.capacity() == 12);
}

TEST_CASE("Reserve does not loose data") {
  Vector<int> v1(5);
  v1[0] = 6;
  v1[1] = 9;
  v1[2] = 14;
  v1[3] = 22;
  v1[4] = 43;
  v1.reserve(8);
  REQUIRE(v1.capacity() == 8);
  REQUIRE(6 == v1[0]);
  REQUIRE(9 == v1[1]);
  REQUIRE(14 == v1[2]);
  REQUIRE(22 == v1[3]);
  REQUIRE(43 == v1[4]);
}

TEST_CASE("insert inserts at beginning") {
  Vector<int> v1(5);
  auto orig_begin = v1.begin();

  v1[0] = 6;
  v1[1] = 9;
  v1[2] = 14;
  v1[3] = 22;
  v1[4] = 43;

  v1.insert(v1.begin()+1, 29);
  REQUIRE(v1.size() == 6);
  REQUIRE(v1.capacity() >= 6);
  REQUIRE(29 == v1[0]);
  REQUIRE(6 == v1[1]);
  REQUIRE(9 == v1[2]);
  REQUIRE(14 == v1[3]);
  REQUIRE(22 == v1[4]);
  REQUIRE(43 == v1[5]);

  // Should not have resized.
  REQUIRE(v1.begin() == orig_begin);
}


TEST_CASE("erases beginning") {
  Vector<int> v1(7);
  v1[0] = 0;
  v1[1] = 10;
  v1[2] = 20;
  v1[3] = 30;
  v1[4] = 40;
  v1[5] = 50;
  v1[6] = 60;

  int orig_capacity = v1.capacity();
  auto orig_begin = v1.begin();

  auto from = v1.begin();
  auto to = v1.begin();
  ++to;
  ++to;

  v1.erase(from, to);
  REQUIRE(5 == v1.size());

  // No resason to change capacity.
  REQUIRE(orig_capacity == v1.capacity());
  REQUIRE(orig_begin == v1.begin());

  REQUIRE(20 == v1[0]);
  REQUIRE(30 == v1[1]);
  REQUIRE(40 == v1[2]);
  REQUIRE(50 == v1[3]);
  REQUIRE(60 == v1[4]);

  REQUIRE(20 == *v1.begin());
  REQUIRE(60 == *(v1.end()-1));
}
