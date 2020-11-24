#pragma once
#ifndef TREE_H
#define TREE_H 

#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>

template <typename ValueType>
/*static private */class Node {
private:
    ValueType value;
    bool isLastChar = false;
    Node<ValueType> parent; // Pointer to the node containing this node
    vector<Node* <ValueType>> children = null; // Pointer to the node on the left which should contain a value below this.value

    int height = 0;

    Node* getChild(std::string value) {
        for (ValueType childValue : children) {
            if (childValue == value.r)
                children.is

        }
    }

public:
    Node(ValueType value, Node<ValueType> parent, bool isLastChar)
    {
        this.value = value;
        this.parent = parent;
        this.isLastChar = isLastChar;
    }
    ValueType getValue(){ return value; }
    Vector<Node*<ValueType> getChildren(){ return children; }
};

template <typename ValueType>
class AvlTree {

    // Only node which has its parent to null
private:

    Node* <ValueType> root;

public:

    AvlTree() { }
    public void add(ValueType value) {
        Boolean insertionSuccess = false;
        if (root == null)
        {
            root = Node<>(value, null);
            return;
        }
    }
    // Prend le noeud de départ et la valeur qu'il cherche.
    // Cherche la valeur dans les liste des enfants noeuds 
    // S'il le trouve il retourne le noeud qui contient la valeur
    // Sinon il retourne le noeud ou on doit ajouter la valeur dans la liste de ses enfants
    public Node* getChild(Node* node, std::string value) {
        while((node->getValue()!=value) && (!(node->getChildren().empty()))
            for (Node<ValueType>* child : node.children) {
                if (child->getValue() == value.substr(0, child->getValue().length()))
                {
                    node = child;
                    if (child->getValue().length() == value.length())
                        return node;
                    value = value.substr(0,value.length()-1);
                }
        }
        return node;
    }
};

#endif

 /*
    if (contains(value))
        return;
    BinaryNode<ValueType> node = root;
    while ((node != null) && (node.value != value))
    {
        int compareResult = value.compareTo(node.value);
        if (compareResult < 0) {
            if ((node.left != null))
                node = node.left;
            else {
                node.left = new BinaryNode<>(value, node);
                //node.height = Math.max(node.left.height, node.right.height)+1;
                insertionSuccess = true;

                break;
            }
        }
        else if (compareResult > 0) {
            if ((node.right != null))
                node = node.right;
            else {
                node.right = new BinaryNode<>(value, node);
                //node.height = Math.max(node.left.height, node.right.height)+1;
                insertionSuccess = true;
                break;
            }
        }
    }
    if (insertionSuccess) {
        AvlTree tree = new AvlTree<ValueType>();
        tree.root = node;
        node.height = tree.getHeight();
        balance(root);
}*/