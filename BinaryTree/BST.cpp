//
// Created by rashadalsharpini on 25/12/23.
//

#include "BST.h"
void BST::iInsert(int key) {

    Node* t = root;
    Node* p;
    Node* r;

    // root is empty
    if (root == nullptr){
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }

    while(t != nullptr){
        r = t;
        if (key < t->data){
            t = t->lchild;
        } else if (key > t->data){
            t = t->rchild;
        } else {
            return;
        }
    }

    // Now t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;

    if (key < r->data){
        r->lchild = p;
    } else {
        r->rchild = p;
    }
    p->height= NodeHeight(p);
//    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
//        return LLRotation(p);
//    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
//        return LRRotation(p);
//    else if(BalanceFactor(p)==-2 && BalanceFactor(p->lchild)==-1)
//        return RRRotation(p);
//    else if(BalanceFactor(p)==-2 && BalanceFactor(p->lchild)==1)
//        return RLRotation(p);
}

void BST::Inorder(Node* p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void BST::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void BST::Preorder(Node *p) {
    if(p){
        cout<<p->data<<", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void BST::Levelorder(Node *p) {
    queue<Node*> q;
    cout<<root->data<<", "<<flush;
    q.emplace(root);
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p->lchild){
            cout<<p->lchild->data<<", "<<flush;
            q.emplace(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<", "<<flush;
            q.emplace(p->rchild);
        }
    }
}

Node* BST::iSearch(int key) {
    Node* t = root;
    while (t != nullptr){
        if (key == t->data){
            return t;
        } else if (key < t->data){
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    return nullptr;
}

Node* BST::rInsert(Node *p, int key) {
    Node* t;
    if (p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height=1;
//        root=t;
        return t;
    }

    if (key < p->data){
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }

    p->height= NodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);
    return p;  // key == p->data?

}

Node* BST::rSearch(Node *p, int key) {
    if (p == nullptr){
        return nullptr;
    }

    if (key == p->data){
        return p;
    } else if (key < p->data){
        return rSearch(p->lchild, key);
    } else {
        return rSearch(p->rchild, key);
    }
}

Node* BST::Delete(Node *p, int key) {
    if (p == nullptr){
        return nullptr;
    }

    if (p->lchild == nullptr && p->rchild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        Node* q;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){  // L-1 Rotation
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0){  // R0 Rotation
        return RRRotation(p);
    }

    return p;
}

int BST::Height(Node *p) {
    int x;
    int y;
    if (p == nullptr){
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

int BST::NodeHeight(Node *p) {
    int hl,hr;
    hl=p && p->lchild ? p->lchild->height:0;
    hr=p && p->rchild ? p->rchild->height:0;
    return hl > hr ? hl + 1 : hr + 1;
}

int BST::BalanceFactor(Node *p) {
    int hl,hr;
    hl=p && p->lchild ? p->lchild->height:0;
    hr=p && p->rchild ? p->rchild->height:0;
    return hl-hr;
}

Node* BST::InPre(Node *p) {
    while (p && p->rchild != nullptr){
        p = p->rchild;
    }
    return p;
}

Node* BST::InSucc(Node *p) {
    while (p && p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
}

Node *BST::LLRotation(Node *p) {
    Node*pl=p->lchild;
    Node*plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->height= NodeHeight(p);
    pl->height= NodeHeight(pl);
    if(root==p)
        root=pl;
    return pl;
}

Node *BST::LRRotation(Node *p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    // Update height
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    // Update root
    if (p == root){
        root = plr;
    }
    return plr;
}

Node *BST::RLRotation(Node *p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    // Update root
    if (root == p){
        root = prl;
    }
    return prl;
}

Node *BST::RRRotation(Node *p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // Update root
    if (root == p){
        root = pr;
    }
    return pr;
}



