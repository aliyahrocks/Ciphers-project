#include <iostream>
using namespace std;

int main () {
    string morse[26] =

        { "._", "_...", "_._.", "_..", ".", ".._.", "__.", "....", "..", ".___",

        "_._", "._..", "__", "___.", "___", ".__.", "__._", "._.", "...", "_",

        ".._", "..._", ".__", "_.._", "_.__", "__.."};
    string input;
    cin >> input;
    string letters = "abcdefghijklmnopqrstuvwxyz";
    //nested for loop to call elements from the vector into the morsecode array bitch 
    for (int i = 0; i < input.length(); i++)
    {
        for (int j = 0; j < letters.length(); j++)
        {
            if (input[i] == letters[j])
            {
                cout << morse[j];
                break;
            }
            
        }
        
    }
    

}