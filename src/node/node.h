//
// Created by Nana Daughterless on 11/15/22.
//

#ifndef CPPCONTAINERS_NODE_H
#define CPPCONTAINERS_NODE_H

#include <initializer_list>
#include <stdexcept>

namespace s21 {

template <class T>
struct Node {
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using TNode = Node<value_type>;

  TNode* head;
  TNode* tail;
  value_type data;

  explicit Node(TNode* head = nullptr, TNode* tail = nullptr)
      : head((head) ? head : this), tail((tail) ? tail : this), data() {}
  explicit Node(const_reference value, TNode* head = nullptr,
                TNode* tail = nullptr)
      : data(value), head((head) ? head : this), tail((tail) ? tail : this){};
};

template <class T>
class NodeIterator {
 public:
  using value_type = T;
  using TNode = Node<T>;

 private:
  // TODO(think) Может быть не очень удачным решением сделать её публичным
  TNode* head_node_;

 public:
  // Head -> end node (когда делается вставка, обнавляется последний элемент)
  // Tail -> first element
  NodeIterator() = default;
  explicit NodeIterator(TNode* head_node) noexcept : head_node_(head_node) {}
  TNode* GetNode() { return head_node_; };
  NodeIterator<value_type>& operator++() noexcept {
    head_node_ = head_node_->tail;
    return *this;
  }
  NodeIterator<value_type>& operator--() noexcept {
    head_node_ = head_node_->head;
    return *this;
  }
  bool operator==(const NodeIterator<value_type>& other) const noexcept {
    return head_node_ == other.head_node_;
  }
  bool operator!=(const NodeIterator<value_type>& other) const noexcept {
    return head_node_ != other.head_node_;
  }
  value_type operator*() const noexcept { return head_node_->data; }
};

}  // namespace s21

#endif  // CPPCONTAINERS_NODE_H
