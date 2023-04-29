/**
 * @file NodeB.h
 * @author Fabrizzio Daniell Perilli Martín alu0101138589@ull.edu.es
 * @brief This class contains the node of binary tree
 * @version 0.1
 * @date 2023-04-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include <iostream>

template <class Key>
class NodeB
{
private:
  Key data_;

protected:
  NodeB<Key> *left_;
  NodeB<Key> *right_;

public:
  NodeB(const Key &, NodeB<Key> * = NULL, NodeB<Key> * = NULL);
  virtual ~NodeB();

  inline Key getData() const;

  inline NodeB<Key> *getLeft() const;
  inline NodeB<Key> *&getLeft();

  inline NodeB<Key> *getRight() const;
  inline NodeB<Key> *&getRight();

  template <class T>
  friend std::ostream &operator<<(std::ostream &, const NodeB<T> &);
};

/**
 * @brief Construct a new Node B< Key>:: Node B object
 *
 * @tparam Key
 * @param data
 * @param left
 * @param right
 */
template <class Key>
NodeB<Key>::NodeB(const Key &data, NodeB<Key> *left, NodeB<Key> *right) : data_(data), left_(left), right_(right) {}

/**
 * @brief Destroy the Node B< Key>:: Node B object
 *
 * @tparam Key
 */
template <class Key>
NodeB<Key>::~NodeB() {}

/**
 * @brief Return the dato of node
 *
 * @tparam Key
 * @return Key
 */
template <class Key>
Key NodeB<Key>::getData() const
{
  return data_;
}

/**
 * @brief Return the left node
 *
 * @tparam Key
 * @return NodeB<Key>*
 */
template <class Key>
NodeB<Key> *NodeB<Key>::getLeft() const
{
  return left_;
}

/**
 * @brief Return the left node
 *
 * @tparam Key
 * @return NodeB<Key>*&
 */
template <class Key>
NodeB<Key> *&NodeB<Key>::getLeft()
{
  return left_;
}

/**
 * @brief Return the right node
 *
 * @tparam Key
 * @return NodeB<Key>*
 */
template <class Key>
NodeB<Key> *NodeB<Key>::getRight() const
{
  return right_;
}

/**
 * @brief Return the right node
 *
 * @tparam Key
 * @return NodeB<Key>*&
 */
template <class Key>
NodeB<Key> *&NodeB<Key>::getRight()
{
  return right_;
}

template <class Key>
std::ostream &operator<<(std::ostream &os, const NodeB<Key> &node)
{
  os << node.data_;
  return os;
}