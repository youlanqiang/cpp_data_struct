#include <iostream>
#include <string>

using namespace std;

namespace toolbox
{
    template <typename T>
    void println(T str)
    {
        std::cout << str << std::endl;
    }
}
