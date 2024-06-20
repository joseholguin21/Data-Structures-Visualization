//
// Created by Jose Holguin on 5/21/24.
//

#include "BinarySearchTree.h"

void BinarySearchTree::push(std::string data) {
    list.push(std::stoi(data));
}

void BinarySearchTree::remove(std::string data) {
    list.remove(std::stoi(data));
}

void BinarySearchTree::breadth_first() {
    order.setString("");
    std::string t = list.getOrder(BREADTHFIRST);
    t.pop_back();
    t.pop_back();
    order.setString(t);
    order.setPosition({breadth_order.getSize().left + breadth_order.getSize().width, breadth_order.getSize().top});
}

void BinarySearchTree::in_order() {
    order.setString("");
    std::string t = list.getOrder(INORDER);
    t.pop_back();
    t.pop_back();
    order.setString(t);
    order.setPosition({inorder.getSize().left + inorder.getSize().width, inorder.getSize().top});
}

void BinarySearchTree::pre_order() {
    order.setString("");
    std::string t = list.getOrder(PREORDER);
    t.pop_back();
    t.pop_back();
    order.setString(t);
    order.setPosition({preorder.getSize().left + preorder.getSize().width, preorder.getSize().top});
}

void BinarySearchTree::post_order() {
    order.setString("");
    std::string t = list.getOrder(POSTORDER);
    t.pop_back();
    t.pop_back();
    order.setString(t);
    order.setPosition({postorder.getSize().left + postorder.getSize().width, postorder.getSize().top});
}

BinarySearchTree::BinarySearchTree(sf::RenderWindow &window) {
    window_dimensions.x = (float)window.getSize().x;
    window_dimensions.y = (float)window.getSize().y;

    list.setDimensions(window_dimensions);

    TitleCard t(30, {window_dimensions.x/3, 0}, "Binary Search Tree");
    title = t;

    order.setFont(FontManager::getFont(ARIAL));
    order.setCharacterSize(25);
    order.setFillColor(sf::Color::Black);

    TextInput textbox1(sf::Color::Black, {150, 40}, {150, window_dimensions.y/1.5f}, "Insert");
    push_textbox = textbox1;

    TextInput autogen(sf::Color::Black, {150, 40}, {textbox1.getPosition().x*5, textbox1.getPosition().y}, "Autogenerate Tree Size");
    autogenerate_textbox = autogen;

    TextInput textbox2(sf::Color::Black, {150, 40}, {150, textbox1.getPosition().y + 50}, "Remove");
    remove_textbox = textbox2;

    Button b(30, {50, textbox2.getPosition().y + 50}, "Breadth Order");
    breadth_order = b;

    Button in(30, {50, b.getPosition().y + 50}, "Inorder");
    inorder = in;

    Button pre(30, {50, in.getPosition().y + 50}, "Preorder");
    preorder = pre;

    Button post(30, {50, pre.getPosition().y + 50}, "Postorder");
    postorder = post;

    Button clr(30, {50, post.getPosition().y + 50}, "Clear Tree");
    clear = clr;
}


//void BinarySearchTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
//    window.draw(list);
//    window.draw(push_textbox);
//    window.draw(remove_textbox);
//    window.draw(breadth_order);
//    window.draw(inorder);
//    window.draw(postorder);
//    window.draw(preorder);
//    if (!order.getString().isEmpty()) {
//        window.draw(order);
//    }
//    window.draw(title);
//}

void BinarySearchTree::draw(sf::RenderWindow &window) {
    window.draw(list);
    window.draw(push_textbox);
    window.draw(remove_textbox);
    window.draw(breadth_order);
    window.draw(inorder);
    window.draw(postorder);
    window.draw(preorder);
    window.draw(clear);
    window.draw(autogenerate_textbox);
    if (!order.getString().isEmpty()) {
        window.draw(order);
    }
    window.draw(title);
}

void BinarySearchTree::movement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        list.move({10, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        list.move({-10, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        list.move({0, -10});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        list.move({0, 10});
    }
}


void BinarySearchTree::eventHandler(sf::RenderWindow &window, sf::Event event) {
    movement();

    push_textbox.eventHandler(window, event);
    remove_textbox.eventHandler(window, event);
    breadth_order.eventHandler(window, event);
    inorder.eventHandler(window, event);
    preorder.eventHandler(window, event);
    postorder.eventHandler(window, event);
    clear.eventHandler(window,event);
    autogenerate_textbox.eventHandler(window,event);

}

void BinarySearchTree::update() {
    push_textbox.update();
    remove_textbox.update();
    breadth_order.update();
    inorder.update();
    preorder.update();
    postorder.update();
    clear.update();
    autogenerate_textbox.update();


    if (push_textbox.checkState(ENTERED)) {
        push(push_textbox.getInput());
        push_textbox.disableState(ENTERED);
    }
    if (remove_textbox.checkState(ENTERED)) {
        remove(remove_textbox.getInput());
        remove_textbox.disableState(ENTERED);
    }
    if (breadth_order.checkState(CLICKED)) {
        breadth_first();
        breadth_order.disableState(CLICKED);
    }
    if (inorder.checkState(CLICKED)) {
        in_order();
        inorder.disableState(CLICKED);
    }
    if (preorder.checkState(CLICKED)) {
        pre_order();
        preorder.disableState(CLICKED);
    }
    if (postorder.checkState(CLICKED)) {
        post_order();
        postorder.disableState(CLICKED);
    }
    if (clear.checkState(CLICKED)) {
        list.clear();
        order.setString("");
    }
    if (autogenerate_textbox.checkState(ENTERED)) {
        autogenerate(stoi(autogenerate_textbox.getInput()));
        autogenerate_textbox.disableState(ENTERED);
    }

}


void BinarySearchTree::autogenerate(int size) {
    srand(time(0));
    list.clear();

    for (int i=0; i < size; i++) {
        push(std::to_string((rand() % 1000) + 1));
    }

}


