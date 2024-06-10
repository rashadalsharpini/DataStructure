//
// Created by rashadalsharpini on 25/12/23.
//

#ifndef BINARYTREE_BST_H
#define BINARYTREE_BST_H

#include <iostream>
#include <queue>
using namespace std;
class Node{
public:
    Node* lchild;
    int data;
    int height;
    Node* rchild;
};

class BST{
private:

public:
    Node* root= nullptr;
    BST(){ root = nullptr; }
    Node* getRoot(){ return root; }
    int getRootdata(){ return root->data; }
    void iInsert(int key);
    void Inorder(Node* p);
    void Preorder(Node*p);
    void Postorder(Node*p);
    void Levelorder(Node*p);
    Node* iSearch(int key);
    Node* rInsert(Node* p, int key);
    Node* rSearch(Node* p, int key);
    Node* Delete(Node* p, int key);
    int Height(Node* p);
    int NodeHeight(Node* p);
    int BalanceFactor(Node*p);
    Node* LLRotation(Node*p);
    Node* LRRotation(Node*p);
    Node* RLRotation(Node*p);
    Node* RRRotation(Node*p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);
};


#endif //BINARYTREE_BST_H
