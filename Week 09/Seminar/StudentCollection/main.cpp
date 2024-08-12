#include <iostream>
#include "StudentCollection.h"
#include <string>

MyString to_string(size_t s)
{
    return MyString(std::to_string(s).c_str());
}

int main()
{
    StudentCollection sc;
    size_t idx = 0;
    for (size_t i = 0; i < 300; i += 3)
    {
        sc.push({ "Name" + MyString("_") + to_string(i), 10 });
        sc.push({ "Name" + MyString("_") + to_string(i + 1), 10 });
        sc.push({ "Name" + MyString("_") + to_string(i + 2), 10 });
    }


    for (size_t i = 0; i < 300; i += 2)
    {
        sc.removeAt(i);
    }


    for (size_t i = 0; i < sc.getCapacity(); i++)
    {
        if (sc.contains(i))
            std::cout << sc.at(i).getName() << std::endl;
    }

}