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

#include "NodeB.h"

template <class Key>
class AB
{
private:
  NodeB<Key> *root_;
  const int branchSize(NodeB<Key> *);
  const int heightN(NodeB<Key> *);
  const bool isBranchEquilibrium(NodeB<Key> *);

public:
  AB();
  ~AB();

  void prune(NodeB<Key> *&);
  bool isEmpty(NodeB<Key> *);
  bool isLeafNode(NodeB<Key> *);
  inline const int size();
  inline const int height();
  inline const bool isEquilibrium();

  virtual bool insert(const Key &) = 0;
  virtual bool search(const Key &) = 0;
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
  prune(root_);
}

/**
 * @brief This method remove all nodes of the tree
 *
 * @tparam Key
 * @param node
 */
template <class Key>
void AB<Key>::prune(NodeB<Key> *&node)
{
  if (node == NULL)
    return;
  prune(node->left_);
  prune(node->right_);
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
  return !node->left_ && !node->right_;
}

/**
 * @brief This method return the size of branch of tree
 *
 * @tparam Key
 * @param node
 * @return const int
 */
template <class Key>
const int AB<Key>::branchSize(NodeB<Key> *node)
{
  if (node == NULL)
    return 0;
  return (1 + branchSize(node->left_) + branchSize(node->right_));
}

/**
 * @brief This method return the size of tree
 *
 * @tparam Key
 * @return const int
 */
template <class Key>
const int AB<Key>::size()
{
  return branchSize(root_);
}

/**
 * @brief This method return the height the subtree
 *
 * @tparam Key
 * @param node
 * @return const int
 */
template <class Key>
const int AB<Key>::heightN(NodeB<Key> *node)
{
  if (node == NULL)
    return 0;
  int height_left = heightN(node->left_);
  int height_right = heightN(node->right_);

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
const int AB<Key>::height()
{
  return heightN(root_);
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
const bool AB<Key>::isBranchEquilibrium(NodeB<Key> *node)
{
  if (node == NULL)
    return true;
  const int eq = branchSize(node->left_) - branchSize(node->right_);
  switch (eq)
  {
  case -1:
  case 0:
  case 1:
    return isBranchEquilibrium(node->left_) && isBranchEquilibrium(node->right_);
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
const bool AB<Key>::isEquilibrium()
{
  return isBranchEquilibrium(root_);
}