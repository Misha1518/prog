#include "arrqueue.h"

using namespace std;

void check(Queue& a)
{
    cout << "Start of tests\n";
    cout << "Queue a size = " << a.size() << '\n';
    cout << "Check front function -> a.front() = " << a.front() << '\n';
    a.pop();
    cout << "Check pop function -> a.pop() -> a.front() now = " << a.front() << '\n';
    a.add(5);
    cout << "Check add function -> a.add(5) -> a.size() = " << a.size() << '\n';
    cout << "Check Queue(Queue) constructor\n";
    Queue b(a);
    cout << "Queue b(a)\nb.size() = " << b.size() << ' ' << ", a.size() = " << a.size();
    cout << "\na.front = " << a.front() << ", b.front() = " << b.front() << '\n';
    cout << "End of tests\n";
}

int main()
{
    Queue a(10);
    a.add(7);
    a.add(4);
    a.add(2);
    a.add(2);
    check(a);
    try {
        cout << "Try to construct Queue with wrong size\n";
        Queue b(-3);
    }
    catch (invalid_argument) {
        cout << "Exception catched!\n";
    }
    try {
        cout << "Try to get front element with empty queue\n";
        Queue c;
        c.front();
    }
    catch (out_of_range) {
        cout << "Exception catched!\n";
    }
    system("pause");
}