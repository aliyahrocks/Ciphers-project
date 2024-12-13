#include <iostream>
#include <vector>
using namespace std;

vector < string > strings;
// Create custom split() function.  
void customSplit(string str, char separator) {
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= str.size(); i++) {
        
        // If we reached the end of the word or the end of the input.
        if (str[i] == separator || i == str.size()) {
            endIndex = i;
            string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
}

int main () {
    string morse[] =

        { "._", "_...", "_._.", "_..", ".", ".._.", "__.", "....", "..", ".___",

        "_._", "._..", "__", "___.", "___", ".__.", "__._", "._.", "...", "_",

        ".._", "..._",

        ".__",

        "_.._", "_.__", "__.."

        };
    string input = "ALIYAH";
    //split function
    /*customSplit(input, ' ');
    for (auto it: strings){
        cout << it << "   ";
    }*/
    //initialisation of vector with ascii code of input letters
    vector <int> asciicode;
    //for loop for inserting stuff right
    for (int i = 0; i < input.size(); i++ ){
        asciicode.push_back(int(input[i]-65));
        cout << asciicode[i] << endl;
    }
    //nested for loop to call elements from the vector into the morsecode array bitch 
    for(std::vector<int>::size_type i = 0; i != asciicode.size(); i++){
    for (int j = 0; i < input.size(); j++){
        if (asciicode[i] = j){
            cout << morse[j] << " / ";
        }

    }
    }

}