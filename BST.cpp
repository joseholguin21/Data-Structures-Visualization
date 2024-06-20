//
// Created by Jose Holguin on 3/25/24.
//

//#ifndef TREE_BST_CPP
//#define TREE_BST_CPP

#include "BST.h"


///second version
//void BST::inorder(Node *node) {
//    if (node) {
//        inorder(node->left);
//        std::cout << node->data;
//        inorder(node->right);
//    }
//}


//void BST::preorder(Node *node) {
//    if (node) {
//        preorder(node->left);
//        preorder(node->right);
//        std::cout << node->data;
//    }
//}


//void BST::postorder(Node *node) {
//    if (node) {
//        std::cout << node->data;
//        postorder(node->left);
//        postorder(node->right);
//    }
//}

///public
//void BST::inorder() {
//    inorder(root);
//}
//
//void BST::preorder() {
//    preorder(root);
//}
//
//
//void BST::postorder() {
//    postorder(root);
//}

///public
void BST::push(const int &data) {
    push(root, root, data);
    root->circle.setPosition({window_dimensions.x/2, 100});
    //updateHeight(root);
}

///private
void BST::push(Node*& node, Node*& prev, const int &data) {
    if (!node) {
        node = new Node;
        node->data = data;

        if (root == node) {
            CircleNode circle(60, position, std::to_string(data), 60, sf::Color::Cyan);
            node->circle = circle;
        }
        else {
            CircleNode circle(60, {0, 0}, std::to_string(data), 40, sf::Color::Cyan);
            node->circle = circle;
        }
        _size++;
    }
    else if (data <= node->data)
    {
        push(node->left, node, data);
    }
    else if (data > node->data)
    {
        push(node->right, node, data);
    }
}

///private search
Node *BST::search(Node*& prev, Node*& current, const int& data) {
        if (data == current->data) {
            //return parent
            return prev;
        }
        else if (data < current->data) {
            return search(current,current->left, data);
        }
        else if (data > current->data) {
            return search(current,current->right, data);
        }
}


///private remove
void BST::remove(Node *&node, Node *&prev, const int &data) {
    if (!node)
    {
        return;
    }
    else if (data < node->data) {
        remove(node->left, node, data);
    }
    else if (data > node->data) {
        remove(node->right, node, data);
    }
    else if (isLeaf(node))
    {
        delete node;
        node = nullptr;
        _size--;
    }
    else if (hasOneChild(node)) {
        Node* child = returnOneChild(node);
        Node* temp = node;
        node = child;
        //node->circle.setPosition(temp->circle.getPosition());
        delete temp;
        _size--;
    }
    else if (hasTwoChild(node))
    {
        Node*& successor = findSuccessor(node->right);
        swap(node, successor);
        remove(successor, node, data);
        //std::cout << node->circle.checkState(HIDDENR);
    }

}


void BST::swap(Node *&node1, Node *&node2) {

        int tempdata = node1->data;
        node1->data = node2->data;
        node2->data = tempdata;

        std::string temps = node1->circle.getData();
        node1->circle.setData(node2->circle.getData());
        node2->circle.setData(temps);


}

///public
void BST::remove(const int &data) {
    remove(root, root, data);
    root->circle.setPosition({window_dimensions.x / 2, 100});
}

std::string BST::breadth_first() {
    std::string order;
    std::queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        if (temp->left != nullptr) {
            q.push(temp->left);
        }
        if (temp->right != nullptr) {
            q.push(temp->right);
        }

        order +=  std::to_string(q.front()->data) + ", ";
        q.pop();
    }
    return order;
}


void BST::inorder(Node* node, std::string& order) {
    if (node) {
        inorder(node->left, order);
        std::string s = std::to_string(node->data);
        order += s + ", ";
        inorder(node->right, order);
    }
}
void BST::preorder(Node* node, std::string& order) {
    if (node) {
        preorder(node->left, order);
        preorder(node->right, order);
        std::string s = std::to_string(node->data);
        order += s + ", ";
    }
}
void BST::postorder(Node* node, std::string& order) {
    if (node) {
        std::string s = std::to_string(node->data);
        order += s + ", ";
        postorder(node->left, order);
        postorder(node->right, order);
    }
}


std::string BST::getOrder(OrderTraversal traversal) {
    if (traversal == BREADTHFIRST)
        return breadth_first();
    else if(traversal == INORDER) {
        std::string order;
        inorder(root, order);
        return order;
    }
    else if(traversal == PREORDER) {
        std::string order;
        preorder(root, order);
        return order;
    }
    else if(traversal == POSTORDER) {
        std::string order;
        postorder(root, order);
        return order;
    }
    else
        return "";
}

///public
///for setting position of circles
void BST::breadth_first(sf::RenderTarget &window) {
    std::queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        if (temp->left != nullptr) {
            temp->circle.enableState(HIDDENL);
            temp->left->circle.setPosition(temp->circle.getLeftEndPoint());
            q.push(temp->left);
        }
        else {
            temp->circle.disableState(HIDDENL);
        }
        if (temp->right != nullptr) {
            temp->circle.enableState(HIDDENR);
            temp->right->circle.setPosition(temp->circle.getRightEndPoint());
            q.push(temp->right);
        }
        else {
            temp->circle.disableState(HIDDENR);
        }

        window.draw(q.front()->circle);
        q.pop();
    }

}

bool BST::empty() {
    return (root->right == nullptr || root->left == nullptr);
}

int BST::size() {
    return _size;
}


///private functions for remove
bool BST::isLeaf(Node *node) {
    return (node->left == nullptr && node->right == nullptr);
}


bool BST::hasOneChild(Node *node) {
    if (node->left == nullptr && node->right != nullptr || node->left != nullptr && node->right == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool BST::hasTwoChild(Node *node) {
    return (node->left != nullptr && node->right != nullptr);
}


Node *& BST::returnOneChild(Node *node) {
    if (node->left == nullptr && node->right != nullptr)
    {
        return node->right;
    }
    else {
        return node->left;
    }
}


Node*& BST::findSuccessor(Node *&node) {
    if (isLeaf(node) || node->left == nullptr) {
        return node;
    }
    else
    {
        return findSuccessor(node->left);
    }
}

///for deleting
//private postorder
void BST::postorder(void (BST::*f)(Node*& data), Node*& node) {
    if (node){
        postorder(f, node->left);
        postorder(f, node->right);
        ((*this).*f)(node);
    }
}


void BST::clear() {
    postorder(&BST::deleteNode, root);
    _size = 0;
}

void BST::deleteNode(Node *&node) {
    delete node;
    node = nullptr;
}


BST::~BST() {
    clear();
}

///constructor
BST::BST() {
    position = {500, 100};
}

//copy constructor
BST::BST(const BST &rightlist) {

}

//operator=
BST& BST::operator=(const BST &rightlist) {
    if (&rightlist != this) {
        this->~BST();

    }
    return *this;
}



void BST::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    if (root) {
        int n=1;
        int i=0;
        float angle = 80;
        float size = 80;
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            if (i == (pow(2, n) - 1)) {
                n++;
                angle = angle - 28;
                size = size - 17;
            }
            i++;
            Node* temp = q.front();
            //temp->circle.setSize(size);
            temp->circle.setAngle(angle);
            temp->circle.setSize(size);

            if (temp->left != nullptr) {
                temp->circle.enableState(HIDDENL);
                temp->left->circle.setPosition(temp->circle.getLeftEndPoint());
                q.push(temp->left);
            }
            else {
                temp->circle.disableState(HIDDENL);
            }
            if (temp->right != nullptr) {
                temp->circle.enableState(HIDDENR);
                temp->right->circle.setPosition(temp->circle.getRightEndPoint());
                q.push(temp->right);
            }
            else {
                temp->circle.disableState(HIDDENR);
            }

            window.draw(q.front()->circle);
            q.pop();
        }
    }
}

void BST::move(const sf::Vector2f &position) {
    root->circle.move(position);
}

void BST::setDimensions(sf::Vector2f size) {
    window_dimensions = size;
}


//#endif //TREE_BST_H