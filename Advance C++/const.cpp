#include<bits/stdc++.h>
using namespace std;
class TextBlock {
public:
    // const before {} specifies that the function won't change the object
    int size() const
    { return text.size(); }

    const char& operator[](std::size_t position) const
    { return text[position]; }

    char& operator[](std::size_t position)
    { return text[position]; }

    TextBlock(const std::string& str) : text(str) {}

private:
    std::string text;
};
int main(){
    const TextBlock tb("Hello");
    // const objects can only call the const member functions
    char ch = tb[0];         // ✅ Allowed
    // tb[0] = 'X';             // ❌ Error: read-only

    // const always applied to the thing at left.. if nothing in left than right
}
