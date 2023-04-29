/**
 * @file NodeAVL.h
 * @author Fabrizzio Daniell Perilli Martín alu0101138589@ull.edu.es
 * @brief This class content Node AVL Binary tree search is derivated class of NodeB
 * @version 0.1
 * @date 2023-04-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "NodeB.h"

template <class Key>
class NodeAVL : public NodeB<Key>
{
private:
  int balance_factor_;

public:
  NodeAVL(const Key &, NodeAVL<Key> * = NULL, NodeAVL<Key> * = NULL);
  ~NodeAVL();

  inline int getBalanceFactor() const;
  inline int &getBalanceFactor();

  inline NodeAVL<Key> *getLeftAVL() const;
  inline NodeAVL<Key> *&getLeftAVL();
  inline NodeAVL<Key> *getRightAVL() const;
  inline NodeAVL<Key> *&getRightAVL();
};

/**
 * @brief Construct a new Node AVL< Key>:: Node AVL object
 *
 * @tparam Key
 * @param data
 * @param left
 * @param right
 */
template <class Key>
NodeAVL<Key>::NodeAVL(const Key &data, NodeAVL<Key> *left, NodeAVL<Key> *right) : NodeB<Key>(data, left, right), balance_factor_(0) {}

/**
 * @brief Destroy the Node AVL< Key>:: Node AVL object
 *
 * @tparam Key
 */
template <class Key>
NodeAVL<Key>::~NodeAVL() {}

/**
 * @brief Return the balance factor of node
 *
 * @tparam Key
 * @return int
 */
template <class Key>
int NodeAVL<Key>::getBalanceFactor() const
{
  return balance_factor_;
}

/**
 * @brief Return the balance factor of node
 *
 * @tparam Key
 * @return int
 */
template <class Key>
int &NodeAVL<Key>::getBalanceFactor()
{
  return balance_factor_;
}

/**
 * @brief Return the left node
 *
 * @tparam Key
 * @return NodeAVL<Key>*
 */
template <class Key>
NodeAVL<Key> *NodeAVL<Key>::getLeftAVL() const
{
  return reinterpret_cast<NodeAVL<Key> *>(this->left_);
}

/**
 * @brief Return the left node
 *
 * @tparam Key
 * @return NodeAVL<Key>*
 */
template <class Key>
NodeAVL<Key> *&NodeAVL<Key>::getLeftAVL()
{
  return reinterpret_cast<NodeAVL<Key> *&>(this->left_);
}

/**
 * @brief Return the right node
 *
 * @tparam Key
 * @return NodeAVL<Key>*
 */
template <class Key>
NodeAVL<Key> *NodeAVL<Key>::getRightAVL() const
{
  return reinterpret_cast<NodeAVL<Key> *>(this->right_);
}

/**
 * @brief Return the right node
 *
 * @tparam Key
 * @return NodeAVL<Key>*
 */
template <class Key>
NodeAVL<Key> *&NodeAVL<Key>::getRightAVL()
{
  return reinterpret_cast<NodeAVL<Key> *&>(this->right_);
}