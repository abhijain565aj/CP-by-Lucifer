#include <iostream>
#include <string>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        string S;
        cin >> S;
        int a = 0;
        for (char ch : S) {
            if (ch == 'A') {
                a++;
            }
        }
        if (a >= 3) {
            cout << "A" << endl;
        } else {
            cout << "B" << endl;
        }
    }
    return 0;
}
