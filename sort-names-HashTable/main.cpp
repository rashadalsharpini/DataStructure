#include <iostream>
#include <algorithm>
#include <vector>
#include"HashTable.h"
#include"student.h"
using namespace std;
int main() {
//    HashTable h(26);
//    student s;
//    cin>>s;
//    h.insert(s);
//    cin>>s;
//    h.insert(s);
//    cout<<endl;
//    h.print();
    cout << "\n\nHello, World!" << endl;
//    student stu[4];
//    for(auto & i : stu)
//        cin>>i;
//    sort(stu,stu+4,student::compareByName);
//    for(const auto & i : stu)
//        cout<<i;
//    sort(stu,stu+4,student::compareById);
//    for(const auto & i : stu)
//        cout<<i;
//    vector<int>arr;
//    for(int i = 0; i < 4 ; i++) {
//        int value;cin >> value;
//        arr.push_back(value);
//    }
//    for(int i = 0; i < 4 ; i++)
//        cout << arr[i] << " ";
//    for(int i = 0; i < 4 ; i++) {
//        int value;cin >> value;
//        arr.push_back(value);
//    }
//    for(int i = 0 ; i < 8 ; i++)
//        cout << arr[i] << " ";
    int size;cin>>size;
//    int * arr=new int[size];
    string arr[size];
    for(auto &i : arr)
        cin >> i;
    for(const auto &i : arr)
        cout << i<< " ";
    return 0;
}
