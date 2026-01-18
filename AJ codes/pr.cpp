#include <bits/stdc++.h>
using namespace std;
struct Animal {
  int x;
  Animal() {
    x = 10;
  }
  void virtual sound() {
    cout << "Hello" << endl;
  }
};

struct Dog : Animal {
  int x;
  Dog() {
    x = 20;
  }
  void sound() {
    cout << "Woof" << endl;
  }
};

int main() {
  Dog* a = new Dog();
  Animal b = Dog();
  a->sound();
  cout << a->x << endl;
  b.sound();
  return 0;
}
