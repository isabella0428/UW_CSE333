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

#ifndef _SKIPLIST_H_
#define _SKIPLIST_H_

#include <stdint.h>
#include <cstdlib>
#include <memory>
using namespace std;

/* A canonical implementation of a skip list
 * (Functions as a multi-set container of sorts)
 *
 * Note: this is a probabilistic data structure that uses std::rand(),
 * so it is a good idea for the caller to seed with std::srand(time(0))
 */
template<typename T>
class SkipList {
  class SkipListNode;
 public:
  /* The SkipList constructor accepts a "max height" for the list
   * between 1 and 16 (inclusive). Numbers out of this range will
   * be mapped to the nearest value.
   */
  explicit SkipList(uint8_t);
  SkipList(const SkipList &) = delete;
  ~SkipList() = default;

  /* Insert an item into the list. Multiple copies of an item can
   * be stored, but no guarantee on their ordering is given.
   * Return: true  --> success (added item)
   *         false --> failure (should never happen)
   */
  bool insert(const T &);
  /* Does the list contain any copies [at least one] of this item? */
  bool contains(const T &) const;
  /* Try to remove [one copy of] an item from the list.
   * Return: true  --> success (removed item)
   *         false --> list did not contain item
   */
  bool remove(const T &);
  /* Remove all items and reset to default state */
  void clear();
  /* How many elements are in the list currently? */
  size_t size() const { return size_; }
  /* How tall was this list again? */
  size_t levels() const { return levels_; }

 private:
  /* helper function for functions that traverse the list */
  enum Action { Insert, Find, Remove };
  bool traverse(const T &, Action);

  /* private state member variables */
  size_t size_;
  uint8_t levels_;
  shared_ptr<SkipListNode> head_;

  /* "Visual Documentation"
   *
   *  head_
   *    |
   *    v
   *  +---+                      +---+                           --+
   *  | 0 |<-------------------->| C |                             |
   *  +---+                      +---+                             |
   *    ^                          ^                               |
   *    |                          |                               |
   *    v                          v                               |
   *  +---+             +---+    +---+             +---+           |
   *  | 0 |<----------->| B |<-->| C |<----------->| E |           | levels_ = 3
   *  +---+             +---+    +---+             +---+           |
   *    ^                 ^        ^                 ^             |
   *    |                 |        |                 |             |
   *    v                 v        v                 v             |
   *  +---+    +---+    +---+    +---+    +---+    +---+    +---+  |
   *  | 0 |<-->| A |<-->| B |<-->| C |<-->| D |<-->| E |<-->| F |  |
   *  +---+    +---+    +---+    +---+    +---+    +---+    +---+--+
   *           |                                                |
   *           +------------------------------------------------+ 
   *                                 size_ = 6
   *
   * - "0" = nullptr (the left column is only to track the initial pointers)
   * - A-F are each pointers to some heap-allocated "T"
   * - all pointers not explicitly drawn are nullptr
   */

  class SkipListNode {
   public:
    explicit SkipListNode(T *p): payload(p) { }

    T *payload;
    shared_ptr<SkipListNode>left  = nullptr;
    shared_ptr<SkipListNode> right = nullptr;
    shared_ptr<SkipListNode> up = nullptr;
    shared_ptr<SkipListNode> down = nullptr;
  };
};
#include "SkipList.cc"
#endif  // _SKIPLIST_H_
