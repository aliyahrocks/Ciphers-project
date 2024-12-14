#include <iostream>
using namespace std;

string morsecode(char chc, string input);


int main () {
    string msg = "I love C plus plus";
    char c = 'e';
    string encrypt = morsecode(c, msg);
    cout << encrypt;

}

string morsecode(char chc, string input){
    //array of morse code strings
    string morse [26] =  { "._", "_...", "_._.", "_..", ".", ".._.", "__.", "....", "..", ".___",

        "_._", "._..", "__", "___.", "___", ".__.", "__._", "._.", "...", "_",

        ".._", "..._", ".__", "_.._", "_.__", "__.."};
    //for loop to change input into lower case since there is no distinction between upper and lower case characters in morsecode
    string input2;
    for(int i = 0; i < input.size(); i++){
        input2 += tolower(input[i]);
    }
    bool isLetter = false;
    string letters = "abcdefghijklmnopqrstuvwxyz";
    string output;
    //conditional statement for encryption or decryption 
    if (chc == 'e'){
        //nested for loop to call elements from the vector into the morsecode array bitch 
       for(int i = 0; i < input2.size(); i++){
        for(int j = 0; j < letters.size(); j++){
            //condition to restrict letters in between lowercase alphabet only
            if(int(input2[i]) > 96 && int(input2[i]) < 123){
                isLetter = true;
                //nested if to output the morse code
                if(input2[i] == letters[j]){
                    output += morse[j] + " ";
                }
            }
            else {
                isLetter = false;
            }
        }
        if(!isLetter){
            output +=  "   ";
        }
       }
}
    else if(chc == 'd'){
        //nested for loop to call letters from the array based on the morse code
        for(int i = 0; i < input.size(); i++){
            for(int j = 0; j < morse->length(); j++){
                if(input[i] == morse[j]){
                    output += letters[j];
                }
                else {
                    output += input2;
                }
            }
        }
    }
    return output;
}
