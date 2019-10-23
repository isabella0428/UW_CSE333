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


// this #include is not strictly necessary, but some text
// editors need it to be context-aware of definitions
#include "SkipList.h"
#include <memory>
using namespace std;

template<typename T>
SkipList<T>::SkipList(uint8_t l)
:size_(0), levels_((l > 0)? (l < 17)? l : 16 : 1)
{ clear(); }  // clear() sets up the initial state

template<typename T>
bool SkipList<T>::insert(const T &t)
{ return traverse(t, Insert); }

template<typename T>
bool SkipList<T>::contains(const T &t) const
{ return const_cast<SkipList<T>*>(this)->traverse(t, Find); }

template<typename T>
bool SkipList<T>::remove(const T &t)
{ return traverse(t, Remove); }

/* Traverses the skiplist in a canonical manner
 * Namely, "right as far as possible, then down one level, and repeat"
 * The return value is specific to the action being taken
 */
template<typename T>
bool SkipList<T>::traverse(const T &key, Action action) {
  shared_ptr<SkipListNode> curr = head_;
  shared_ptr<SkipListNode> insert_placeholder = nullptr;
  T *new_payload = nullptr;
  uint8_t go_down = levels_ - 1;
  if (action == Insert) {
    // choose a random level to start on
    for (int i = 1; i < levels_; ++i, --go_down)
      if (std::rand() % 2)
        break;
    new_payload = new T(key);
  }
  while (curr != nullptr) {
    // first, skip to the right until we find the key or reach the end
    if (curr->right != nullptr && *curr->right->payload < key) {
      curr = curr->right;
    } else {
      // What we do next depends on the desired action
      switch (action) {
        case Find:
          // if we stopped going right, we might have hit the key
          if (curr->right != nullptr && *curr->right->payload == key)
            return true;
          break;
        case Remove:
          // if we hit the key, remove it. If we're on the last level,
          // return true to indicate "we found and removed it"
          if (curr->right != nullptr && *curr->right->payload == key) {
            curr->right = curr->right->right;
            if (curr->right != nullptr)
              curr->right->left = curr;
            if (curr->down == nullptr) {
              --size_;
              return true;
            }
          }
          break;
        case Insert:
          if (go_down != 0) {
            // skip some number of rows before starting to add nodes
            --go_down;
          } else {
            // allocate a node pointing to the shared payload
            shared_ptr<SkipListNode> new_node = make_shared<SkipListNode>(new_payload);
            // stitch together the list with lots of pointer assignment
            new_node->left = curr;
            new_node->right = curr->right;
            if (curr->right != nullptr)
              curr->right->left = new_node;
            curr->right = new_node;
            if (insert_placeholder != nullptr)
              insert_placeholder->down = new_node;
            new_node->up = insert_placeholder;
            insert_placeholder = new_node;
            // if we've hit the bottom, return true to indicate success
            if (curr->down == nullptr) {
              ++size_;
              return true;
            }
          }
          break;
      }
      // we've processed this level, so go down to the next one
      curr = curr->down;
    }
  }
  // we've gone off the bottom of the list, so return "failure"
  return false;
}

template<typename T>
void SkipList<T>::clear() {
  // remove whatever was there before (if anything)
  head_ = make_shared<SkipListNode>(nullptr);
  // set up a column of "nullptr" nodes to search from
  shared_ptr<SkipListNode> np = head_;
  for (uint8_t i = 1; i < levels_; ++i) {
    np->down = make_shared<SkipListNode>(nullptr);
    np->down->up = np;
    np = np->down;
  }
}
