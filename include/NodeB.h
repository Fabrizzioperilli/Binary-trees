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

template <class Key>
class NodeB
{
private:
  Key data_;

protected:
  NodeB<Key> *left_;
  NodeB<Key> *right_;

public:
  NodeB(const Key&,  NodeB<Key>* = NULL, NodeB<Key>* = NULL);
  ~NodeB();
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
NodeB<Key>::NodeB(const Key& data, NodeB<Key>* left, NodeB<Key>* right) : data_(data), left_(left), right_(right) {}


/**
 * @brief Destroy the Node B< Key>:: Node B object
 * 
 * @tparam Key 
 */
template <class Key>
NodeB<Key>::~NodeB() {}
