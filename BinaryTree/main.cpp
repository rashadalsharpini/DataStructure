#include <iostream>
using namespace std;
#include "BST.h"
int main() {
    BST bb;
    bb.root=bb.rInsert(bb.root,10);
    cout<<endl<<bb.getRootdata()<<endl;

    bb.root=bb.rInsert(bb.root,20);
    bb.root=bb.rInsert(bb.root,30);
    bb.Inorder(bb.root);
    cout<<endl<<bb.getRootdata()<<endl;

    cout << "\n\n\nHello, World!" << endl;

    return 0;
}
