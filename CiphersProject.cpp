#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

string caeserCipher(char chc, string msg, int ky);
string atbashCipher(string msg);
string simpleSubCipher(char chc, string msg, string ky);
string affineCipher(char chc, string msg, int a, int b, int c);
string vignereCipher(char chc,string ky, string msg);
string baconianCipher(char chc, string msg);
string polybiusCipher(char chc, int ky[], string msg);
string morsecodecipher(char chc, string msg);
string routeCipher(char chc, string msg, int ky);

int main(){
    // variables
    char choice;
    int menu;
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
        cout << "   1- Caeser Cipher\n";
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

        cout << "Enter the number of letters shifted: ";
        cin >> key;
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

        cout << caeserCipher(choice, message, key);
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

        //Loop to make sure 'key' is made up of unique letters
        bool isUnique = false;
        while (!isUnique)
        {
            for (int i = 0; i < key.length() - 1; i++)
            {
                for (int j = i+1; j < key.length(); j++)
                {
                    if (key[i] == key[j])
                    {
                        cout << "Invalid key, please reneter the key with unique letters: ";
                        cin >> key;
                        isUnique = false;
                        break;
                    }
                    else {
                        isUnique = true;
                    }
                }   
                if (isUnique == false)
                {
                    break;
                }
            }
        }
        
        if (choice == 'e') {
            cout << "Enter message you wish to encrypt: ";
        }
        else if (choice == 'd') {
            cout << "Enter message you wish to decrypt: ";
        }
        cin.ignore();
        getline(cin, message);
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
        // turns the string "key" into upper case
        for(int i = 0; i < key.length(); i++){
            if (key[i] >= 'a' && key[i] <= 'z')
            {
                key[i] = key[i] - 32;
            }
        }
        // turns the string "message" into upper case
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
        int key[5];
        int i = 0;

        cout << "Enter key elements in any order: \n";
        //Ensures only values from 1 to 5 are allowed into the key
        while (i < 5)
        {
            cin >> key[i];
            if (key[i] > 0  && key[i] < 6) {
                i++;
            }
            else {
                cout << "Invalid key elements. Choose only numbers from 1 to 5.\n";
            }
        }
        
        if (choice == 'e') {
            cout << "Enter message you wish to encrypt: ";
        }
        else if (choice == 'd') {
            cout << "Enter message you wish to decrypt: ";
        }
   
        cin.ignore();
        getline(cin, message);

        // turns the string "message" into upper case
        for (int i = 0; i < message.length(); i++)
        {
            if (message[i] >= 'a' && message[i] <= 'z') {
                message[i] = message[i] - 32;
            }
        }
        
        cout << polybiusCipher(choice, key, message);
    }

    else if (menu == 8)
    {
        if(choice == 'e'){
            cout << "Enter message you wish to encrypt: ";
        }
        else if (choice == 'd'){

            cout << "Enter message you wish to decrypt, ensure there is a single space after every letter and three spaces in between words: ";
        }
        cin.ignore();
        getline(cin, message);
        // turns the string "message" into upper case
        for (int i = 0; i < message.length(); i++){
            if (message[i] >= 'a' && message[i] <= 'z')
            {
                message[i] = message[i] -  32;
            }
        }

        cout << morsecodecipher(choice, message);
    }

    else if (menu == 9)
    {
        int key;

        cout << "Enter Key: ";
        cin >> key;
        if (choice == 'e')
        {
            cout << "Enter message you wish to encrypt: ";
        }
        else if (choice == 'd'){

            cout << "Enter message you wish to decrypt: ";
        }
        cin.ignore();
        getline(cin, message);
        // turns the string "message" into upper case
        for(int i = 0; i < message.length(); i++){
            if (message[i] >= 'a' && message[i] <= 'z')
            {
                message[i] = message[i] - 32;
            }
        }

        cout << routeCipher(choice, message, key);
    }
    
    return 0;
}

string caeserCipher(char chc, string msg, int ky) {
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
string polybiusCipher(char chc, int ky[], string msg) {
    //Variables used in function
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char table[5][5];
    int currentIndex = 0;
    bool isFound = false;
    bool isLetter = false;
    string output;
    
    // this loop inserts letters into 5x5 matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // if current letter = 'J', exclude 'J' from table matrix. 
            if (currentIndex >= 9)
            {
                table[i][j] = letters[currentIndex + 1]; 
            }
            else
            {
                table[i][j] = letters[currentIndex];
            }
            currentIndex++;
        }
    }

    //Encryption
    if (chc == 'e') {
        // first for loop cycles through each character of the message
        for (int i = 0; i < msg.length(); i++) {
            // 2nd and 3rd loops  compare each 'message' letter to letters in table
            for (int j = 0; j < 5; j++)
            {
                //If the letter is found in the matrix break the loop
                if (isFound)
                {
                    break;
                }
                for (int k = 0; k < 5; k++)
                {
                    if (msg[i] == table[j][k]) {
                        output += to_string(ky[j]); // converts int type of key to string in order to append it
                        output += to_string(ky[k]);
                        isFound = true;
                        isLetter = true;
                        break;
                    }
                    // if current character is 'J', it is replaced with 'I'
                    else if (msg[i] == 'J') {
                        output += to_string(ky[1]);
                        output += to_string(ky[3]);
                        isFound = true;
                        isLetter = true;
                        break;
                    }
                }
            }
            //if the current character is not a letter add to 'output'
            if (!isLetter)
            {
                output += msg[i];
            }
            isLetter = false;
            isFound = false;
        }
    }
    //Decryption
    else if(chc == 'd') {
        for (int i = 0; i < msg.length(); ) 
        {
            if ((msg[i] - '0') > 0 && (msg[i] - '0') < 6)
            {
                for (int j = 0; j < 5; j++)
                {
                    if ((msg[i] - '0') == ky[j])
                    {
                        for (int k = 0; k < 5; k++)
                        {
                            if ((msg[i + 1] - '0') == ky[k])
                            {
                                output += table[j][k];
                                i += 2;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
            //if the current character is not a letter add to 'output'
            else {
                output += msg[i];
                i++;
            }
        }
    }

    return output;
}

string morsecodecipher(char chc, string msg){
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

    string output="";
    bool isLetter = false;
    //Encryption;
    if(chc == 'e') {
        //for loop to iterate through 'msg'
        for(int i = 0; i < msg.length(); i++){
            //conditional statement to ensure only characters that are letters are encrypted
            if(int(msg[i]) > 64 && int(msg[i]) < 91){
                output += morsecodeDictionary.at(msg[i]) + " ";
                isLetter = true;
            }
            else {
                isLetter = false;
            }
            //if the current character is not a letter add to 'output'
            if(!isLetter){
                output += msg[i];
                output+="    ";
            }
    
        }
    }
    //Decryption
    else if(chc == 'd'){
        int count = 0;
        string currentChar;

        for (int i = 0; i < msg.length(); i++)
        {
            //if statement to seperate morse code characters by space
            if (msg[i] == ' ')
            {
                isLetter = false;
                
                //for loop to isolate characters into variable current character
                for (int j = count; j > 0; j--)
                {
                    currentChar += msg[i-j];
                    
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
            else if(msg[i] == '.' || msg[i] == '-' ) {
                count++;
            }
            else {
                output += msg[i];
            }
            // addition of spaces in between words
            if(msg[i] == ' ' && msg[i + 1] == ' ' && msg[i + 2] == ' ') {
               output += " ";
               i+=3;
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
                    route[i][j] = 'X';
                }
            }
        }
        //For loop to preform spiral 
        for (int i = 0; i < loopInterations; i++)
        {
            // mod 4 used to change directions
            //South
            if (i%4 == 0){
                for (int j = ope; j < rows-ope; j++)
                {
                    output += route[j][(ky-1)-ope];
                }
            }
            //West
            else if(i%4 == 1){
                for (int j = (ky-1)-ope; j > ope; j--)
                {
                    output += route[rows-1-ope][j-1];
                }
            }
            //North
            else if(i%4 == 2){
                for (int j = (rows-1)-ope; j > ope; j--)
                {
                    output += route[j-1][ope];
                }
            }
            //East
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

        //For loop to input values from 'route' to 'output'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < ky; j++) {
                    if (route[i][j] != "X")
                    {
                        output += route[i][j];
                    }
                    
            }
        }
    }
    
    return output;
}
