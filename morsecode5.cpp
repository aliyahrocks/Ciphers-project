#include <iostream>
#include <map>
using namespace std;

string morsecodecipher(char chc, string input);

int main () {
    char c = 'e';
    string msg = "ALIYAH ROCKS!";
    string enc = morsecodecipher(c, msg);
    cout << enc;

}

string morsecodecipher(char chc, string input){
    //map containing characters and their morsecode
    map <char, string> morsecodeDictionary = {
            { 'A', ".-"  },    { 'B', "-..."  },
            { 'C', "-.-." },  { 'D', "-.." },
            { 'E', "."  },     { 'F', "..-."  },
            { 'G', "--." },   { 'H', "...."  },
            { 'I', ".."  },    {  'J', ".---" },
            { 'K', "-.-" },   { 'L', ".-.."  },
            { 'M', "--" },    { 'N', "-." },
            { 'O', "---" },   { 'P', ".--." },
            { 'Q', "--.-"  },  { 'R', ".-."  },
            { 'S', "..." },   { 'T', "-" },
            { 'U', "..-" },   { 'V', "...-"  },
            {  'W', ".--" },   { 'X', "-..-" },
            {  'Y', "-.--" },  { 'Z', "--.."  }
    };

    string inputUp;
    //for loop to change input into upper case as their is no distinction in the morse of upper and lower case alphabets
    for(int i = 0; i < input.length(); i++){
        inputUp += toupper(input[i]);
    }

    string output="";
    bool isLetter = false;
    //conditional statment for encryption or decryption
    if(chc == 'e') {
        //for loop to iterate through input string
        for(int i = 0; i < inputUp.length(); i++){
            //conditional statement to ensure only characters that are uppercase alphabets are encrypted
            if(int(inputUp[i]) > 64 && int(inputUp[i]) < 91){
                output += morsecodeDictionary.at(input[i]) + " / ";
                isLetter = true;
            }
            else {
                isLetter = false;
            }
            if(!isLetter){
                output += inputUp[i];
                output+="    ";
            }
    
        }
    }
    /*if(chc == 'd'){

    }*/

return output;

}
