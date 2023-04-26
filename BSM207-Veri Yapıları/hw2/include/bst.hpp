/**
* @file bst.hpp
* @description BST
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#ifndef BST_H
#define BST_H

class Node
{
public:
    int data, height;
    Node *left;
    Node *right;
};

// İkili Arama Ağacı (Bağıl)
class BST_r // BinarySearchTree_relative
{
public:
    Node *node = nullptr;
    int get_height(Node *root);
    int get_balance_factor(Node *root);
    void post_order(Node *root);
    void mutate(Node *root);
    Node *insert(Node *root, int new_data);
    void dinnd();
    ~BST_r();
    int *arrm;// = new int[20];
    int index;
};



#endif