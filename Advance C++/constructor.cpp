#include <iostream>
using namespace std;

class Widget {
public:
    Widget(){
        cout << "Default constructor called." << endl;
    }
    Widget(const Widget& rhs){
        cout << "Copy constructor called." << endl;
    }
    Widget& operator=(const Widget& rhs){
        cout << "Assignment operator called." << endl;
        return *this;
    }
};

int main() {
    Widget w1;
    Widget w2(w1);
    w1 = w2;
    Widget w3 = w1;
}
