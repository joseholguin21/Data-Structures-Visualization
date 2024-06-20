//
// Created by Jose Holguin on 6/5/24.
//

#include "AVL.h"

void AVL::rotateLeft(Node *&n) {
    if (!n || !n->right) {
        return;
    }
    else {
        Node *temp = n;
        n = n->right;
        temp->right = n->left;
        n->left = temp;
    }
}

void AVL::rotateRight(Node *&n) {
    if (!n || !n->left) {
        return;
    }
    else {
        Node *temp = n;
        n = n->left;
        temp->left = n->right;
        n->right = temp;
    }
}

void AVL::balance(Node *&node) {
    if (node) {
        balance(node->left);
        balance(node->right);
        validate(node);
        root->circle.setPosition(position);
    }
}

int AVL::getBalanceFactor(Node *node) {
    if (node->height == 1)
        return 0;
    else if (node->right == nullptr)
        return node->left->height;
    else if (node->left == nullptr)
        return -(node->right->height);
    else
        return node->left->height - node->right->height;
}

void AVL::updateHeight(Node *&node) {
    if (isLeaf(node)) {
        node->height = 1;
    }
    else if (hasOneChild(node)) {
        Node*& child = returnOneChild(node);
        node->height = 1 + child->height;
    }
    else if (hasTwoChild(node))
    {
        node->height = 1 + max(node->left->height, node->right->height);
    }
}

void AVL::validate(Node *&node) {
    if (node) {
        updateHeight(node);
        if (getBalanceFactor(node) < -1) {
            if (getBalanceFactor(node->right) > 0)
                rotateRight(node->right);
            rotateLeft(node);
        }
        else if (getBalanceFactor(node) > 1)
        {
            if (getBalanceFactor(node->left) < 0)
                rotateLeft(node->left);
            rotateRight(node);
        }
    }
}

int AVL::max(int lh, int rh) {
    if (lh > rh)
        return lh;
    else
        return rh;
}

void AVL::copy(Node *node) {

}

void AVL::push(const int &data) {
    BST::push(data);
    balance(root);
}

void AVL::remove(const int &data) {
    BST::remove(data);
    balance(root);
}
