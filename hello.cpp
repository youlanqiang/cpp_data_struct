#include "toolbox.h"

typedef struct
{
    int age;
    std::string name;
} Node;

int main()
{
    Node node = {10, "hello"};
    toolbox::println(node.age);
    return 0;
}
