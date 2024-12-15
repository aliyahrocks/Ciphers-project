#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

string ceaserCipher(char chc, string msg, int ky);
string atbashCipher(string msg);
string simpleSubCipher(char chc, string msg, string ky);
string affineCipher(char chc, string msg, int a, int b, int c);
string vignereCipher(char chc,string ky, string msg);
string baconianCipher(char chc, string msg);
string morsecodecipher(char chc, string input);
string routeCipher(char chc, string msg, int ky);

int main(){
    // variables
    char choice;
    int menu;
    int shift;
    string message;
    cout << "Encryption or Decryption:\n";
    
    // first loop to only allow valid inputs
    while (true)
    {
        cout << "   Enter 'e' for Encryption\n";
        cout << "   Enter 'd' for Decryption\n";
        cin >> choice;
        if (choice == 'd' || choice == 'e')
        {
            break;
        }
        else{
            cout << "Invalid input! Please enter again\n";
        }
    }

    cout << "Choose Cipher:\n";

    // second loop to only allow valid inputs
    while (true)
    {
        cout << "   1- Ceaser Cipher\n";
        cout << "   2- Atbash Cipher\n";
        cout << "   3- Simple Substitution Cipher\n";
        cout << "   4- Affine Cipher\n";
        cout << "   5- Vignere Cipher\n";
        cout << "   6- Baconian Cipher\n";
        cout << "   7- Polybius Square Cipher\n";
        cout << "   8- Morse Code\n";
        cout << "   9- Route Cipher\n";

        cin >> menu;
        
        if (menu >= 1 && menu <= 9)
        {
            break;
        }
        else {
            cout << "Invalid Input! Please enter again.\n";
        }
    }

    // conditionals to declare the correct function
    if (menu == 1)
    {
        int key;
        if (choice == 'e')
        {
            cout << "Enter message you wish to encrypt: ";
        }
        else if (choice == 'd'){

            cout << "Enter message you wish to decrypt: ";
        }
        cin.ignore();
        getline(cin, message);
        cout << "Enter the number of letters shifted: ";
        cin >> key;
        // turns the string "message" into lower case
        for (int i = 0; i < message.length(); i++)
        {
            if (message[i] >= 'A' && message[i] <= 'Z')
            {
                message[i] = message[i] + 32;
            }
        }

        cout << ceaserCipher(choice, message, key);
    }

    else if (menu == 2)
    {
        if (choice == 'e')
        {
            cout << "Enter message you wish to encrypt: ";
        }
        else if (choice == 'd'){

            cout << "Enter message you wish to decrypt: ";
        }
        cin.ignore();
        getline(cin, message);
        // turns the string "message" into lower case
        for (int i = 0; i < message.length(); i++)
        {
            if (message[i] >= 'A' && message[i] <= 'Z')
            {
                message[i] = message[i] + 32;
            }
        }
        cout << atbashCipher(message);
    }

    else if (menu == 3)
    {
        string key;

        cout << "Enter the key: ";
        cin >> key;
        if (choice == 'e') {
            cout << "Enter message you wish to encrypt: ";
        }
        else if (choice == 'd') {
            cout << "Enter message you wish to decrypt: ";
        }
        cin.ignore();
        getline(cin, message);
        // turns the string "key" into lower case
        for(int i = 0; i < key.length(); i++){
            if (key[i] >= 'A' && key[i] <= 'Z')
            {
                key[i] = key[i] + 32;
            }
        }
        // turns the string "message" into lower case
        for (int i = 0; i < message.length(); i++)
        {
            if (message[i] >= 'A' && message[i] <= 'Z') {
                message[i] = message[i] + 32;
            }
        }
        
        cout << simpleSubCipher(choice, message, key);
    }

    else if (menu == 4)
    {
        // coefficients in affine cipher
        int a = 0, b = 0, c = 0;

        if (choice == 'e') {
            cout << "Enter key pairs: " << '\n';
            cin >> a ;
            cin >> b;
        }
        else if (choice == 'd') {
            cout << "Enter key pairs: " << '\n';
            cin >> c;
            cin >> b;
        }
        cout << "Enter message you wish to decrypt: ";
        cin.ignore();
        getline(cin, message);
        // turns the string "message" into lower case
        for (int i = 0; i < message.length(); i++)
        {
            if (message[i] >= 'A' && message[i] <= 'Z')
            {
                message[i] = message[i] + 32;
            }
        }
        cout << affineCipher(choice, message, a, b, c);
    }

    else if (menu == 5)
    {   
        string key;
        cout << "Enter the key: ";
        cin >> key;
        if (choice == 'e') {
            cout << "Enter message you wish to encrypt: ";
        }
        else if (choice == 'd') {
            cout << "Enter message you wish to decrypt: ";
        }
        cin.ignore();
        getline(cin, message);
        // turns the string "key" into lower case
        for(int i = 0; i < key.length(); i++){
            if (key[i] >= 'a' && key[i] <= 'z')
            {
                key[i] = key[i] - 32;
            }
        }
        // turns the string "message" into lower case
        for(int i = 0; i < message.length(); i++){
            if (message[i] >= 'a' && message[i] <= 'z')
            {
                message[i] = message[i] - 32;
            }
        }

        cout << vignereCipher(choice, key, message);
    }

    else if (menu == 6)
    {
        if (choice == 'e')
        {
            cout << "Enter message you wish to encrypt: ";
        }
        else if (choice == 'd'){

            cout << "Enter message you wish to decrypt: ";
        }
        cin.ignore();
        getline(cin, message);
        // turns the string "message" into lower case
        for (int i = 0; i < message.length(); i++)
        {
            if (message[i] >= 'A' && message[i] <= 'Z')
            {
                message[i] = message[i] + 32;
            }
        }

        cout << baconianCipher(choice, message);
    }

    else if (menu == 7)
    {
        
    }

    else if (menu == 8)
    {
        
    }

    else if (menu == 9)
    {
        int key;
        if (choice == 'e')
        {
            cout << "Enter message you wish to encrypt: ";
        }
        else if (choice == 'd'){

            cout << "Enter message you wish to decrypt: ";
        }
        cin.ignore();
        getline(cin, message);
        cout << "Enter Key:";
        cin >> key;
        // turns the string "message" into lower case
        for (int i = 0; i < message.length(); i++)
        {
            if (message[i] >= 'A' && message[i] <= 'Z')
            {
                message[i] = message[i] + 32;
            }
        }
        cout << routeCipher(choice, message, key);
    }
    
    return 0;
}

string ceaserCipher(char chc, string msg, int ky) {
    //Variables used in function
    string letters = "abcdefghijklmnopqrstuvwxyz";
    string output;
    bool isLetter = false;

    //Encryption
    if (chc == 'e')
    {
        //First for loop to cycle through characters in 'msg'
        for (int i = 0; i < msg.length(); i++)
        {
            //Second for loop to compare each letter to the current character
            for (int j = 0; j < letters.length(); j++)
            {
                //Conditional to compare letters and preform algorithim
                if (msg[i] == letters[j])
                {

                    if ((j+ky) > 25)
                    {
                        output += letters[(j+ky)-26];
                    }
                    else{
                        output += letters[j+ky];
                    }
                    isLetter = true;
                    break;
                }
                else {
                    isLetter = false;
                }
            }
            //if the current character is not a letter add to 'output'
            if (!isLetter)
            {
                output += msg[i];
            }
        }
    }
    //Decryption
    else if( chc == 'd') {
        //First for loop to cycle through characters in 'msg'
        for (int i = 0; i < msg.length(); i++)
        {
            //Second for loop to compare each letter to the current character
            for (int j = 0; j < letters.length(); j++)
            {   
                //Conditional to compare letters and preform algorithim
                if (msg[i] == letters[j])
                {
                    if (j < ky)
                    {
                        output += letters[(j-ky)+26];
                    }
                    else{
                        output += letters[j-ky];
                    }
                    isLetter = true;
                    break;
                }
                else {
                    isLetter = false;
                }
            }
            //if the current character is not a letter add to 'output'
            if (!isLetter)
            {
                output += msg[i];
            }
        }
    }
    
    return output;
}

string atbashCipher(string msg) {
    //Variables used in function
    string letters = "abcdefghijklmnopqrstuvwxyz";
    string output;
    bool isLetter = false;

    //First for loop to cycle through characters in 'msg'
    for (int i = 0; i < msg.length(); i++)
    {
        //Second for loop to compare each letter to the current character
        for (int j = 0; j < letters.length(); j++)
        {
            //Conditional to compare letters and preform algorithim
            if (msg[i] == letters[j])
            {
                output += letters[25-j];
                isLetter = true;
                break;
            }
            else {
                isLetter = false;
            }
        }
        //if the current character is not a letter add to 'output'
        if (!isLetter)
        {
            output+= msg[i];
        }
    }
    
    return output;
}

string simpleSubCipher(char chc, string msg, string ky)
{
    //Variables used in function
    string letters = "abcdefghijklmnopqrstuvwxyz";
    string cipherLetters = ky;
    bool isLetter = false;
    string output;

    //For loops and conditional to remove each letter in 'letters' that matches the letters of given ky
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < letters.length(); j++) {
            if (ky[i] == letters[j]) {
                letters.erase(letters.begin() + j);
                break;
            }
        }
    }
    //Adds modified alphabet to cipher alphabet then resets 'letters' alphabet
    cipherLetters += letters; 
    letters = "abcdefghijklmnopqrstuvwxyz"; 

    //Encryption
    if (chc == 'e')
    {
        for (int i = 0; i < msg.length(); i++) {
            for (int j = 0; j < letters.length(); j++) {
                //If the current character matches the letter, a letter with the same index is added to 'output'
                if (msg[i] == letters[j]) {
                    output += cipherLetters[j];
                    isLetter = true;
                    break;
                }
                else {
                    isLetter = false;
                }
            }
            //if the current character is not a letter add to 'output'
            if (!isLetter)
            {
                output += msg[i];
            }
        }
    }
    //Decryption
    else if (chc == 'd')
    {
        for (int i = 0; i < msg.length(); i++) {
            for (int j = 0; j < cipherLetters.length(); j++) {
                //If the current character matches the letter, a letter with the same index is added to 'output'
                if (msg[i] == cipherLetters[j]) {
                    output += letters[j];
                    isLetter = true;
                    break;
                }
                else {
                    isLetter = false;
                }
            }
            //if the current character is not a letter add to 'output'
            if (!isLetter)
            {
                output += msg[i];
            }
        }
    }

    return output;
}

string affineCipher(char chc, string msg, int a, int b, int c)
{
    //Variables used in function
    string letters = "abcdefghijklmnopqrstuvwxyz";
    bool isLetter = false;
    int decryptVar;
    string output;

    //Encryption
    if (chc == 'e') {
        for (int i = 0; i < msg.length(); i++) {
            for (int j = 0; j < letters.length(); j++)
            {
                if (msg[i] == letters[j])
                {
                    output += letters[(a * j + b) % 26];
                    isLetter = true;
                    break;
                }
                else {
                    isLetter = false;
                }
            }
            //if the current character is not a letter add to 'output'
            if (!isLetter)
            {
                output += msg[i];
            }
        }
    }
    //Decryption
    else if (chc == 'd') {
        for (int i = 0; i < msg.length(); i++) {
            for (int j = 0; j < letters.length(); j++)
            {
                if (msg[i] == letters[j])
                {
                    //Depending on if c*(j - b) is a negative number or less than 26 a different formula will be used
                    if (abs(c*(j - b)) <= 26)
                    {
                        output += letters[(abs(c*(j - b)+26))%26];
                    }
                    else if (c*(j - b) < 0){
                        output += letters[26-(abs(c*(j - b))%26)];
                    }
                    else{
                        output += letters[((c*(j - b)+26))%26];
                    }
                    isLetter = true;
                    break;
                }
                else {
                    isLetter = false;
                }
            }
            //if the current character is not a letter add to 'output'
            if (!isLetter)
            {
                output += msg[i];
            }
        }
    }

    return output;
}

string vignereCipher(char chc, string ky, string msg){
    //Variables used in function
    string rptKey;
    bool isLetter = false;
    string output;

    //Creates repeated keyword string
    for(int j = 0; j < msg.length(); j += ky.length()){
        rptKey += ky;
        }
    if (chc == 'e'){
        for (int i = 0; i < msg.length(); i++) {
            if(int(msg[i])>64 && int(msg[i]<91)) {
                // calculation to find the ASCII code
                output+= char( int((msg[i] + rptKey[i]) % 26) + 65);
                isLetter = true;
            }
            else {
                isLetter = false;
            }
            if(!isLetter){
                output += msg[i];
            }
    }
    }
    else if (chc == 'd'){
        for (int i = 0; i < msg.length(); i++) {
            if(int(msg[i])>64 && int(msg[i]<91)){
                output+= char( int((msg[i] - rptKey[i] + 26) % 26) + 65);
            isLetter = true;
            }
            else {
            isLetter = false;
            }
            if(!isLetter){
            output += msg[i];
            }
        }
        
    }
    return output;

}

string baconianCipher(char chc, string msg) {
    //Variables used in function
    string letters = "abcdefghijklmnopqrstuvwxyz";
    string currenBit = "     ";
    int currentIndex = 0;
    bool isLetter = false;
    string output;

    //Encryption
    if (chc == 'e')
    {
        for (int i = 0; i < msg.length(); i++)
        {
            for (int j = 0; j < letters.length(); j++)
            {
                if (msg[i] == letters[j] )
                {
                    isLetter = true;
                    currentIndex = j;
                    //Make the current index into the form bits
                    for (int k = 4; k >= 0; k--)
                    {
                        if (currentIndex%2 == 0)
                        {
                            currenBit[k] = 'a';
                        }
                        else{
                            currenBit[k] = 'b';
                        }
                        currentIndex/=2;
                    }
                    //To correct the order of current bit
                    output += currenBit;
                    currenBit = "     ";
                    break;
                }
                else {
                    isLetter = false;
                }
            }
            //if the current character is not a letter add to 'output'
            if (!isLetter)
            {
                output += msg[i];
            }
        }
    }
    //Decryption
    else if (chc == 'd')
    {
        for (int i = 0; i < msg.length();)
        {
            //if the current character is not 'a' or 'b' then add to 'output' and continue the loop
            if (msg[i] != 'a' && msg[i] != 'b')
            {
                output += msg[i];
                i++;
            }
            else {
                //Turns the string of 'a' and 'b' into a decimal number
                for (int j = 0; j < 5; j++)
                {   
                    //'a' = 0
                    if (msg[i+j] == 'a')
                    {
                        currentIndex += 0;
                        isLetter = true;
                    }
                    //'b' = 1
                    else if (msg[i+j] == 'b')
                    {
                        currentIndex += pow(2, (4-j));
                        isLetter = true;
                    }
                }
                //add a letter by using new decimal as index
                output += letters[currentIndex];
                //Resets 'currentIndex' back into 0
                currentIndex = 0;
                i += 5;
            }
        }
    }

    return output;
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
            //if statement to output spaces and other characters
            if(!isLetter){
                output += inputUp[i];
                output+="    ";
            }
    
        }
    }
    else if(chc == 'd'){
        int count = 0;
        string currentChar;
        int spacecount = 0;

        for (int i = 0; i < input.length(); i++)
        {
            //if statement to seperate morse code characters by space
            if (input[i] == ' ')
            {
                isLetter = false;
                
                //for loop to isolate characters into variable current character
                for (int j = count; j > 0; j--)
                {
                    currentChar += input[i-j];
                    
                }
                //for loop to output the key of the element current char by adding 65 to the index thus getting the asciicode
                for (int k = 0;  k < 26; k++)
                {
                    if (currentChar == morsecodeDictionary.at(char(k+65)))
                    {
                        output+= char(k+65);
                        break;
                    }
                    
                }

                //resetting currentChar and count
                currentChar = "";
                count = 0;
            }
            //ensuring characters that aren't part of the morse code are outputted as is
            else if(input[i] == '.' || input[i] == '-' ) {
                count++;
            }
            else {
                output += input[i];
            }
            // addition of spaces in between words
            if(input[i] == ' ' && input[i + 1] == ' ' && input[i + 2]) {
               output += " ";
            }
            
        }

     }

return output;

}

string routeCipher(char chc, string msg, int ky) {
    int rows =  ceil((double)msg.length()/ky); 
    string route[rows][ky];

    //Variables used in the loop
    int currentIndex = 0;
    int loopInterations;
    int ope = 0;

    string output;

    //Conditional decides which formula to use
    if (ky > rows)
    {
        loopInterations = 2*rows;
    }
    else {
        loopInterations = (2*ky)-1;
    }

    //Encryption
    if (chc == 'e')
    {
        //Loop to create the matrix
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < ky; j++)
            {
                if (currentIndex < msg.length())
                {
                    route[i][j] = msg[currentIndex]; 
                    currentIndex++;
                }
                else {
                    route[i][j] = 'x';
                }
            }
        }
        //For loop to preform spiral 
        for (int i = 0; i < loopInterations; i++)
        {
            // mod 4 used to change directions
            if (i%4 == 0){
                for (int j = ope; j < rows-ope; j++)
                {
                    output += route[j][(ky-1)-ope];
                }
            }
            else if(i%4 == 1){
                for (int j = (ky-1)-ope; j > ope; j--)
                {
                    output += route[rows-1-ope][j-1];
                }
            }
            else if(i%4 == 2){
                for (int j = (rows-1)-ope; j > ope; j--)
                {
                    output += route[j-1][ope];
                }
            }
            else if(i%4 == 3){
                for (int j = 1+ope; j < (ky-1)-ope; j++)
                {
                    output += route[ope][j];
                }
                ope ++;
            }
        }
    }
    //Decryption
    else if(chc == 'd'){
        for (int i = 0; i < loopInterations; i++) {
            if (i % 4 == 0) {
                for (int j = ope; j < rows - ope; j++)
                {
                    route[j][(ky - 1) - ope] = msg[currentIndex];
                    currentIndex++;
                }
            }
            else if (i % 4 == 1) {
                for (int j = (ky - 1) - ope; j > ope; j--)
                {
                    route[rows - 1 - ope][j - 1] = msg[currentIndex];
                    currentIndex++;
                }
            }
            else if (i % 4 == 2) {
                for (int j = (rows - 1) - ope; j > ope; j--)
                {
                    route[j - 1][ope] = msg[currentIndex];
                    currentIndex++;
                }
            }
            else if (i % 4 == 3) {
                for (int j = 1 + ope; j < (ky - 1) - ope; j++)
                {
                    route[ope][j] = msg[currentIndex];
                    currentIndex++;
                }
                ope++;
            }
    }

    //For loop to input values from 'route' eto 'output'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < ky; j++) {
                    output += route[i][j];
            }
        }
    }
    
    return output;
}
