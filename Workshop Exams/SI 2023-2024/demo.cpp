#include "Utils.h"
#include "HexArrayView.h"

#include "Serializator.h"
#include "BinarySerializator.h"
#include "TxtHexSerializator.h"
#include "TxtDecimalSerializator.h"
#include "RecSerializator.h"

#include "Deserializator.h"
#include "BinaryDeserializator.h"
#include "TxtHexDeserializator.h"
#include "TxtDecimalDeserializator.h"

Serializator* serializatorFactory(const HexArray& arr, const char* str)
{
    const char* extension = getFileExtension(str);
    if (strcmp(extension, ".dat"))
        return new BinarySerializator(str, arr);
    if (strcmp(extension, ".txtHex"))
        return new TxtHexSerializator(str, arr);
    if (strcmp(extension, ".dat"))
        return new TxtDecimalSerializator(str, arr);
    if (strcmp(extension, ".rec"))
        return new RecSerializator(str, arr);
    return nullptr;
}

Deserializator* deserializatorFactory(const char* str)
{
    const char* extension = getFileExtension(str);
    if (strcmp(extension, ".dat"))
        return new BinaryDeserializator(str);
    if (strcmp(extension, ".txtHex"))
        return new TxtHexDeserializator(str);
    if (strcmp(extension, ".dat"))
        return new TxtDecimalDeserializator(str);
    return nullptr;
}


int main()
{
    char temp[1024], inputName[128] = "hex.txtHex", outputName[128];
    //std::cin >> inputName;
    //std::cin >> temp; //read
    unsigned char str[4] = "abc";
    HexArray ha(str, 4);
    
    int n = 65;
    n >> ha;

    std::cout << ha << std::endl;

    Serializator* ser = serializatorFactory(ha, inputName);
    ser->serialize();

    Deserializator* des = deserializatorFactory(inputName);
    HexArray ha2 = des->deserialize();

    std::cout << ha2 << std::endl;
    

    delete ser;
    delete des;

}