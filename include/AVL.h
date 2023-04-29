/**
 * @file AVL.h
 * @author Fabrizzio Daniell Perilli Martín alu0101138589@ull.edu.es
 * @brief This class content AVL Binary tree search is derivated class of ABB
 * @version 0.1
 * @date 2023-04-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "ABB.h"
#include "NodeAVL.h"

template <class Key>
class AVL : public ABB<Key>
{
private:
  void rotationLL_(NodeAVL<Key> *&);
  void rotationRR_(NodeAVL<Key> *&);
  void rotationLR_(NodeAVL<Key> *&);
  void rotationRL_(NodeAVL<Key> *&);

  void insertBalanceRight_(NodeAVL<Key> *&, bool &);
  void insertBalanceLeft_(NodeAVL<Key> *&, bool &);
  void insertBalance_(NodeAVL<Key> *&, NodeAVL<Key> *, bool &);

public:
  AVL();
  ~AVL();
  inline NodeAVL<Key> *getRootAVL() const;
  inline NodeAVL<Key> *&getRootAVL();

  void insert(const Key &k) override;
};

/**
 * @brief Construct a new AVL<Key>::AVL object
 *
 * @tparam Key
 */
template <class Key>
AVL<Key>::AVL() : ABB<Key>() {}

/**
 * @brief Destroy the AVL<Key>::AVL object
 *
 * @tparam Key
 */
template <class Key>
AVL<Key>::~AVL() {}

/**
 * @brief Return the root of the branch tree
 *
 * @tparam Key
 * @return NodeAVL<Key>*
 */
template <class Key>
NodeAVL<Key> *AVL<Key>::getRootAVL() const
{
  return reinterpret_cast<NodeAVL<Key> *>(this->root_);
}

/**
 * @brief Return the root of the branch tree
 *
 * @tparam Key
 * @return NodeAVL<Key>*
 */
template <class Key>
NodeAVL<Key> *&AVL<Key>::getRootAVL()
{
  return reinterpret_cast<NodeAVL<Key> *&>(this->root_);
}

/**
 * @brief Insert a node in the branch tree
 *
 * @tparam Key
 * @param node
 * @param key
 */
template <class Key>
void AVL<Key>::insert(const Key &key)
{

  bool grow = false;
  insertBalance_(getRootAVL(), new NodeAVL<Key>(key), grow);
}

/**
 * @brief Simple rotation to the left
 *
 * @tparam Key
 * @param node
 */
template <class Key>
void AVL<Key>::rotationLL_(NodeAVL<Key> *&node)
{
  NodeAVL<Key> *node1 = node->getLeftAVL();
  node->getLeftAVL() = node1->getRightAVL();
  node1->getRightAVL() = node;

  if (node1->getBalanceFactor() == 1)
  {
    node->getBalanceFactor() = 0;
    node1->getBalanceFactor() = 0;
  }
  else
  {
    node->getBalanceFactor() = 1;
    node1->getBalanceFactor() = -1;
  }
  node = node1;
}

/**
 * @brief Simple rotation to the right
 *
 * @tparam Key
 * @param node
 */
template <class Key>
void AVL<Key>::rotationRR_(NodeAVL<Key> *&node)
{
  NodeAVL<Key> *node1 = node->getRightAVL();
  node->getRightAVL() = node1->getLeftAVL();
  node1->getLeftAVL() = node;

  if (node1->getBalanceFactor() == -1)
  {
    node->getBalanceFactor() = 0;
    node1->getBalanceFactor() = 0;
  }
  else
  {
    node->getBalanceFactor() = -1;
    node1->getBalanceFactor() = 1;
  }
  node = node1;
}

/**
 * @brief Double rotation to the right
 *
 * @tparam Key
 * @param node
 */
template <class Key>
void AVL<Key>::rotationLR_(NodeAVL<Key> *&node)
{
  NodeAVL<Key> *node1 = node->getLeftAVL();
  NodeAVL<Key> *node2 = node1->getRightAVL();
  node->getLeftAVL() = node2->getRightAVL();
  node2->getRightAVL() = node;
  node1->getRightAVL() = node2->getLeftAVL();
  node2->getLeftAVL() = node1;

  if (node2->getBalanceFactor() == -1)
  {
    node1->getBalanceFactor() = 1;
  }
  else
  {
    node1->getBalanceFactor() = 0;
  }
  if (node2->getBalanceFactor() == 1)
  {
    node->getBalanceFactor() = -1;
  }
  else
  {
    node->getBalanceFactor() = 0;
  }
  node2->getBalanceFactor() = 0;
  node = node2;
}

/**
 * @brief Double rotation to the left
 *
 * @tparam Key
 * @param node
 */
template <class Key>
void AVL<Key>::rotationRL_(NodeAVL<Key> *&node)
{
  NodeAVL<Key> *node1 = node->getRightAVL();
  NodeAVL<Key> *node2 = node1->getLeftAVL();
  node->getRightAVL() = node2->getLeftAVL();
  node2->getLeftAVL() = node;
  node1->getLeftAVL() = node2->getRightAVL();
  node2->getRightAVL() = node1;

  if (node2->getBalanceFactor() == 1)
  {
    node1->getBalanceFactor() = -1;
  }
  else
  {
    node1->getBalanceFactor() = 0;
  }
  if (node2->getBalanceFactor() == -1)
  {
    node->getBalanceFactor() = 1;
  }
  else
  {
    node->getBalanceFactor() = 0;
  }
  node2->getBalanceFactor() = 0;
  node = node2;
}

/**
 * @brief Insert a new node in the tree balancing it left
 *
 * @tparam Key
 * @param node
 * @param grow
 */
template <class Key>
void AVL<Key>::insertBalanceLeft_(NodeAVL<Key> *&node, bool &grow)
{
  switch (node->getBalanceFactor())
  {
  case -1:
    node->getBalanceFactor() = 0;
    grow = false;
    break;
  case 0:
    node->getBalanceFactor() = 1;
    break;
  case 1:
    NodeAVL<Key> *node1 = node->getLeftAVL();
    if (node1->getBalanceFactor() == 1)
      rotationLL_(node);
    else
      rotationLR_(node);
    grow = false;
    break;
  }
}

/**
 * @brief Insert a new node in the tree balancing it right
 *
 * @tparam Key
 * @param node
 * @param grow
 */
template <class Key>
void AVL<Key>::insertBalanceRight_(NodeAVL<Key> *&node, bool &grow)
{
  switch (node->getBalanceFactor())
  {
  case 1:
    node->getBalanceFactor() = 0;
    grow = false;
    break;
  case 0:
    node->getBalanceFactor() = -1;
    break;
  case -1:
    NodeAVL<Key> *node1 = node->getRightAVL();
    if (node1->getBalanceFactor() == -1)
      rotationRR_(node);
    else
      rotationRL_(node);
    grow = false;
    break;
  }
}

/**
 * @brief Insert a new node in the tree balancing it
 *
 * @tparam Key
 * @param node
 * @param newNode
 * @param grow
 */
template <class Key>
void AVL<Key>::insertBalance_(NodeAVL<Key> *&node, NodeAVL<Key> *newNode, bool &grow)
{
  if (node == NULL)
  {
    node = newNode;
    grow = true;
  }
  if (node->getData() == newNode->getData())
    return;

  if (node->getData() > newNode->getData())
  {
    insertBalance_(node->getLeftAVL(), newNode, grow);
    if (grow)
      insertBalanceLeft_(node, grow);
  }
  else
  {
    insertBalance_(node->getRightAVL(), newNode, grow);
    if (grow)
      insertBalanceRight_(node, grow);
  }
}