#include <iostream>
#include <stdexcept>
#include <any>
#include <string>
using namespace std;
int main()
{
    try
    {
        float e1 = 10;
        std::any e = e1;
        throw e;
    }
    catch (std::any e)
    {
        std::cout << "Hello " << e << std::endl;
    }

    return 0;
}
