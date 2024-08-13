#include "SetByCriteria.h"
#include "SetByString.h"

int main()
{
    SetByString s(1000, "1 5 9");
    s.print();
    std::cout << std::endl;
    s.setAt(1, '0');
    std::cout << std::endl;
    s.print();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    SetByCriteria s2(11, [](unsigned i) {return i % 2 == 0; });
    s2.print();
}