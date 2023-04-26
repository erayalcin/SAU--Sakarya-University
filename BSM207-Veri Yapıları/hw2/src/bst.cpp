/**
* @file bst.cpp
* @description BST
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "bst.hpp"

using namespace std;

int BST_r::get_height(Node *root)
{
    if (root == NULL)
        return -1;
    return (root->height);
}

int BST_r::get_balance_factor(Node *root)
{
    if (root == NULL)
        return 0;
    return (get_height(root->left) - get_height(root->right));
}

void BST_r::post_order(Node *root)
{
    if (root == NULL)
        return;
    post_order(root->left);
    post_order(root->right);
    printf(" %d ", root->data);
}

void BST_r::mutate(Node *root)
{
    if (root == NULL)
        return;
    mutate(root->left);
    mutate(root->right);
    if (root->left != NULL && root->right != NULL)
        if (root->left->data == root->right->data)
        {
            root->data = root->data / 2;
        }
    arrm[index++] = root->data;
}

void BST_r::dinnd()
{
    cout << "i=" << index << "\t";
    for (int d = 0; d < index; d++)
    {
        cout << arrm[d] << " ";
    }
    cout << endl;
}

Node *BST_r::insert(Node *root, int new_data)
{
    if (root == NULL)
    {
        root = new Node;
        root->data = new_data;
        root->left = NULL;
        root->right = NULL;
        root->height = 0;
        return root;
    }
    if (root->data < new_data)
        root->right = insert(root->right, new_data);
    else
        root->left = insert(root->left, new_data);

    root->height = max(get_height(root->left), get_height(root->right)) + 1;
}

BST_r::~BST_r()
{
    delete[] node;
}