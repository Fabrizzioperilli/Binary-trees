/**
 * @file ABB.h
 * @author Fabrizzio Daniell Perilli Martín alu0101138589@ull.edu.es
 * @brief This class content ABB Binary tree search is derivated class of AB
 * @version 0.1
 * @date 2023-04-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#include "AB.h"

template <class Key>
class ABB : public AB<Key>
{
private:
  void insertBranch_(NodeB<Key> *&, const Key &);
  bool searchBranch_(NodeB<Key> *, const Key &) const;

public:
  ABB();
  ~ABB();
  void insert(const Key &) override;
  virtual bool search(const Key &) const override;
};

/**
 * @brief Construct a new ABB<Key>::ABB object
 *
 * @tparam Key
 */
template <class Key>
ABB<Key>::ABB() : AB<Key>() {}

/**
 * @brief Insert a node in the branch tree
 *
 * @tparam Key
 * @param node
 * @param key
 */
template <class Key>
void ABB<Key>::insertBranch_(NodeB<Key> *&node, const Key &key)
{
  if (node == NULL)
    node = new NodeB<Key>(key);
  else if (key < node->getData())
    insertBranch_(node->getLeft(), key);
  else
    insertBranch_(node->getRight(), key);
}

/**
 * @brief Destroy the ABB<Key>::ABB object
 *
 * @tparam Key
 */
template <class Key>
ABB<Key>::~ABB() {}

template <class Key>
void ABB<Key>::insert(const Key &key)
{
  insertBranch_(this->root_, key);
}

/**
 * @brief Search a node in the branch tree
 *
 * @tparam Key
 * @param node
 * @param key
 * @return true
 * @return false
 */
template <class Key>
bool ABB<Key>::searchBranch_(NodeB<Key> *node, const Key &key) const
{
  if (node == NULL)
    return false;
  else if (key == node->getData())
    return true;
  else if (key < node->getData())
    return searchBranch_(node->getLeft(), key);
  else
    return searchBranch_(node->getRight(), key);
}

/**
 * @brief Search a node in the branch tree
 *
 * @tparam Key
 * @param key
 * @return true
 * @return false
 */
template <class Key>
bool ABB<Key>::search(const Key &key) const
{
  return searchBranch_(this->root_, key);
}