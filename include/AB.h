/**
 * @file AB.h
 * @author Fabrizzio Daniell Perilli Martín alu0101138589@ull.edu.es
 * @brief This class is Binary Tree
 * @version 0.1
 * @date 2023-04-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include "NodeB.h"
#include <iostream>
#include <queue>

template <class Key>
class AB
{
private:
  int branchSize_(NodeB<Key> *) const; 
  int heightN_(NodeB<Key> *) const; 
  bool isBranchEquilibrium_(NodeB<Key> *) const; 
  void prune_(NodeB<Key> *&);

protected:
  NodeB<Key> *root_;

public:
  AB();
  virtual ~AB();

  bool isEmpty(NodeB<Key> *);
  bool isLeafNode(NodeB<Key> *);
  inline int size() const;
  inline int height() const;
  inline bool isEquilibrium() const;

  virtual void insert(const Key &) = 0;
  // virtual bool search(const Key &) = 0;
  //void inorden() const;
  template <class T>
  friend std::ostream &operator<<(std::ostream &, const AB<T> &);
};


/**
 * @brief Construct a new AB<Key>::AB object
 *
 * @tparam Key
 */
template <class Key>
AB<Key>::AB() : root_(NULL) {}

/**
 * @brief Destroy the AB<Key>::AB object
 *
 * @tparam Key
 */
template <class Key>
AB<Key>::~AB()
{
  prune_(root_);
}

/**
 * @brief This method remove all nodes of the tree
 *
 * @tparam Key
 * @param node
 */
template <class Key>
void AB<Key>::prune_(NodeB<Key> *&node)
{
  if (node == NULL)
    return;
  prune_(node->getLeft());
  prune_(node->getRight());
  delete node;
  node = NULL;
}

/**
 * @brief Check if node is empty or not
 *
 * @tparam Key
 * @param node
 * @return true
 * @return false
 */
template <class Key>
bool AB<Key>::isEmpty(NodeB<Key> *node)
{
  return node == NULL;
}

/**
 * @brief Check if node is leaf
 *
 * @tparam Key
 * @param node
 * @return true
 * @return false
 */
template <class Key>
bool AB<Key>::isLeafNode(NodeB<Key> *node)
{
  return !node->getLeft() && !node->getRight();
}

/**
 * @brief This method return the size of branch of tree
 *
 * @tparam Key
 * @param node
 * @return const int
 */
template <class Key>
int AB<Key>::branchSize_(NodeB<Key> *node) const
{
  if (node == NULL)
    return 0;
  return (1 + branchSize_(node->getLeft) + branchSize_(node->getRight()));
}

/**
 * @brief This method return the size of tree
 *
 * @tparam Key
 * @return const int
 */
template <class Key>
int AB<Key>::size() const
{
  return branchSize_(root_);
}

/**
 * @brief This method return the height the subtree
 *
 * @tparam Key
 * @param node
 * @return const int
 */
template <class Key>
int AB<Key>::heightN_(NodeB<Key> *node) const
{
  if (node == NULL)
    return 0;
  int height_left = heightN_(node->getLeft());
  int height_right = heightN_(node->getRight());

  if (height_right > height_left)
    return ++height_right;
  else
    return ++height_left;
}

/**
 * @brief Return the height tree
 *
 * @tparam Key
 * @return const int
 */
template <class Key>
int AB<Key>::height() const
{
  return heightN_(root_);
}

/**
 * @brief This method check if the branch is equilibirum
 *
 * @tparam Key
 * @param node
 * @return true
 * @return false
 */
template <class Key>
bool AB<Key>::isBranchEquilibrium_(NodeB<Key> *node) const
{
  if (node == NULL)
    return true;
  const int eq = branchSize_(node->getLeft()) - branchSize_(node->getRight());
  switch (eq)
  {
  case -1:
  case 0:
  case 1:
    return isBranchEquilibrium_(node->getLeft()) && isBranchEquilibrium_(node->getRight());
  default:
    return false;
  }
}

/**
 * @brief This method check if the tree is equilibrium
 *
 * @tparam Key
 * @return true
 * @return false
 */
template <class Key>
bool AB<Key>::isEquilibrium() const
{
  return isBranchEquilibrium_(root_);
}

/**
 * @brief This method print the tree
 *
 * @tparam Key
 * @param os
 * @param ab_tree
 * @return std::ostream&
 */
template <class Key>
std::ostream& operator<<(std::ostream& os, const AB<Key>& ab_tree) {
  std::queue<std::pair<NodeB<Key>*, int>> queue;
  queue.push(std::make_pair(ab_tree.root_, 0));
  int current_level = 0;
  
  std::cout << "Level " << current_level << ": ";
  while (!queue.empty()) {
    std::pair<NodeB<Key>*, int> node_current = queue.front();
    queue.pop();

    if (node_current.second > current_level) {
      current_level++;
      os << "\nLevel " << current_level << ": ";
    }

    if (node_current.first != NULL) {
      os << "[" << *node_current.first << "] ";
      queue.push(std::make_pair(node_current.first->getLeft(), current_level + 1));
      queue.push(std::make_pair(node_current.first->getRight(), current_level + 1));
    } else {
      os << "[.] ";
    }
  }

  return os;
}
