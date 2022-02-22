//---------------------------------------------------------
// File     : bitmap.cpp
// Author   : J.Burnham
// Purpose  : main application file, to read the attributes of a bitmap file
//---------------------------------------------------------


#include "encryptedBitmap.h"
#include <iostream>

using namespace std;

// Function Definitions
//---------------------------------------------------------
void encryptSelected(string filename, string encryptedFile, string msg, EncryptedBitmap encryptedBitmap);
string decryptSelected(string encryptedFile, EncryptedBitmap encryptedBitmap);


int main() {

    EncryptedBitmap encryptedBitmap = EncryptedBitmap(nullptr, nullptr);

    string input;
    cout << "\nAre you encrypting or decrypting? (E:encrypt/D:decrypt): ";
    std::getline(std::cin, input);

    string filename;        // the name of the bitmapfile
    string msg;             // the message to encrypt
    string encryptedFile;   // the name of the encrypted bitmap

    if(input == "E" || input == "e"){   // if encrypted was chosen

        cout << "\nBitmap file name:  ";
        std::getline(std::cin, filename);
        cout << "\nThe message to encrypt: ";
        std::getline(std::cin, msg);
        cout << "\nEncrypted file name: ";
        std::getline(std::cin, encryptedFile);

        encryptSelected(filename, encryptedFile, msg, encryptedBitmap);
    }
    else if (input == "d" || input == "D"){ // if decrypt was chosen

        cout << "\nEncrypted file name: ";
        std::getline(std::cin, encryptedFile);

        string secretMessage = decryptSelected(encryptedFile, encryptedBitmap);
        cout << "\n The secret message is: " + secretMessage;
    }
    else{
        cout << "That was not valid input!";
        main();
    }

    return 0;
}



/**
 * if the encrypt option was selected by the user
 * @param filename          - the name of the original file
 * @param encryptedFile     - the name of the file to encrypt the message into
 * @param msg               - the message to encrypt
 * @param encryptedBitmap   - an encryptedBitmap object
 */
void encryptSelected(string filename, string encryptedFile, string msg, EncryptedBitmap encryptedBitmap){
    // set up the input and output streams
    ifstream inStream;
    ofstream outStream;
    inStream.open(filename, ios::binary);
    outStream.open(encryptedFile,  std::ios::out|std::ios::trunc|std::ios::binary);

    // Load the file data and copy it to a new file
    encryptedBitmap = EncryptedBitmap(&inStream, &outStream);
    int outBytes = encryptedBitmap.encrypt(msg);

    // check to make sure that the number of bytes loaded is the same as the number written to the file.
    if(0 == outBytes){
        std::cout << "\nFile \"" + filename + "\" copied successfully into output file \"" + encryptedFile + "\""
                  << std::endl;
    }else{
        std::cout << "\n ERROR: File \"" + filename + "\" has not copied successfully into output file \"" + encryptedFile+
                     "\"" << std::endl;
    }

}



/**
 * if the decrypt option is selected by the user
 * @param encryptedFile     - the name of the encrypted file to read from
 * @param encryptedBitmap   - a encryptedBitmap object.
 * @return string           - the decrypted message
 */
string decryptSelected(string encryptedFile, EncryptedBitmap encryptedBitmap){
    string msg = "";

    ifstream inStream;
    ofstream outStream; // not initializing because we will only be reading
    inStream.open(encryptedFile, ios::binary);

    encryptedBitmap = EncryptedBitmap(&inStream, &outStream);
    msg += encryptedBitmap.decrypt();

    return msg;
}