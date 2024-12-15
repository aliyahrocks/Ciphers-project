#include <iostream>
#include <map>
using namespace std;

int main (){
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
string input = ".-|-...";
int count = 0;
string currentChar;

for (int i = 0; i < input.length(); i++)
{
    if (input[i] == '|')
    {
        for (int j = count; j > 0; j--)
        {
            currentChar += input[i-j];
            
        }

        cout << currentChar;
        for(std::map<char,string>::iterator it = morsecodeDictionary.begin(); it != count; ++it){
          cout << it -> first;
        }
        
    
        currentChar = "";
    }
    else {
        count++;
    }
    
}



}