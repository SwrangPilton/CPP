#include <iostream>
// #include <iterator>
#include <list>
using namespace std;

int main() {
    list<int> mylist;
    for (int i = 1; i <= 10; i++) mylist.push_back(i);

    // list<int>::iterator first = mylist.begin();
    for (auto it = mylist.begin(); it != mylist.end(); it++) {
        cout << *it << "<->" << &it << endl;
    }
    cout << endl;

    list<int>::iterator first = mylist.begin();
    list<int>::iterator last = mylist.end();

    cout << "The distance is: " << distance(first, last) << '\n';

    return 0;
}