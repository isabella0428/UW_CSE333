/*
 * Copyright ©2019 Aaron Johnston.  All rights reserved.  Permission is
 * hereby granted to students registered for University of Washington
 * CSE 333 for use solely during Summer Quarter 2019 for purposes of
 * the course.  No other use, copying, distribution, or modification
 * is permitted without prior written consent. Copyrights for
 * third-party components of this work must be honored.  Instructors
 * interested in reusing these course materials should contact the
 * author.
 */

#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <set>
#include <map>

#include "SkipList.h"

#define NTESTS 1000
#define NS_PER_S 1000000000.0

using namespace std;

void test(string name, bool (*t)()) {
  cout << "  " << name << ": " << (t()? "PASS" : "FAIL") << endl;
}

bool test_basic();
bool test_insert();
bool test_find();
bool test_remove();
bool test_1level();

int main() {
  std::srand(time(0));
  cout << "========================" << endl <<
          " Running SkipList Tests"  << endl <<
          "========================" << endl;
  test("basic", &test_basic);
  test("insert", &test_insert);
  test("find", &test_find);
  test("remove", &test_remove);
  test("linked list", &test_1level);
}

// Can we create an empty list?
bool test_basic() {
  SkipList<int32_t> list(5);
  return list.levels() == 5 && list.size() == 0;
}

// Can we insert a whole bunch of elements?
bool test_insert() {
  SkipList<int32_t> list(5);
  for (int32_t i = 0; i < NTESTS; ++i)
    if (!list.insert(rand() & NTESTS))
      return false;
  return list.size() == NTESTS;
}

// Can we find the elements we inserted?
bool test_find() {
  set<int32_t> values;
  SkipList<int32_t> list(5);
  for (int32_t i = 0; i < NTESTS; ++i) {
    int32_t test = rand() % NTESTS;
    if (list.contains(test) != (values.count(test) > 0))
      return false;
    values.insert(test);
    list.insert(test);
    if (!list.contains(test))
      return false;
  }
  return true;
}

// Can we remove each element exactly the right number of times?
bool test_remove() {
  map<int32_t, int32_t> counts;
  SkipList<int32_t> list(5);
  for (int32_t i = 0; i < NTESTS; ++i) {
    int32_t test = rand() % NTESTS;
    counts[test]++;
    list.insert(test);
  }
  for (auto it : counts) {
    for (int32_t i = 0; i < it.second; ++i)
      if (!list.remove(it.first))
        return false;
    if (list.remove(it.first))
      return false;
  }
  return true;
}

// Does the skiplist work as a linked list? (when levels_ == 1)
bool test_1level() {
  map<int32_t, int32_t> counts;
  SkipList<int32_t> list(0);
  for (int32_t i = 0; i < NTESTS; ++i) {
    int32_t test = rand() % NTESTS;
    counts[test]++;
    list.insert(test);
  }
  for (auto it : counts) {
    for (int32_t i = 0; i < it.second; ++i)
      if (!list.remove(it.first))
        return false;
    if (list.remove(it.first))
      return false;
  }
  return true;
}
