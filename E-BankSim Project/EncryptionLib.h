#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsEncryption
{
public:

    static string EncryptText(string Text, short Key)
    {
        for (char& c : Text)
        {
            c = char((int)c + Key);
        }

        return Text;
    }

    static string DecryptText(string Text, short Key)
    {
        for (char& c : Text)
        {
            c = char((int)c - Key);
        }

        return Text;
    }
};
