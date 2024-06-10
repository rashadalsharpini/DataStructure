#include <iostream>
#include "LinkedList.h"
#include "Queue.h"
using namespace std;
int main() {
    LinkedList<Queue<int>> ll;
    Queue<int> qq(4);
    for (int i = 0; i < 4; ++i) {
        qq.enqueue(i);
    }
    ll.insert_end(qq);
    ll.print();

}
//int precedence(char op) {
//    if(op=='+'||op=='-')
//        return 1;
//    if(op=='*'||op=='/')
//        return 2;
//    return 0;
//}
//void infixtopostfix(string infix){
//    Stack<string> operators(infix.size());
//    string postfix;
//    for (int i = 0; i < (int)infix.size(); ++i) {
//        if(isdigit(infix[i]))
//            postfix+=infix[i];
//        else{
//            while(!operators.isEmpty()&&(precedence(operators.peek top())>= precedence(infix[i])))
//                postfix+=operators.pop();
//        }
//    }
//    while(!operators.isEmpty())
//        postfix+=operators.pop();
//}