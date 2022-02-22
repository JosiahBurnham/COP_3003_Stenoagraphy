//---------------------------------------------------------
// File     : bitmapReader.cpp
// Author   : J.Burnham
// Purpose  : configuration file for the BitmapReader class
//---------------------------------------------------------

#include "bitmapReader.h"


// Constructor(s)
//-----------------------------------------------------

/**
 * Default constructor, creating a new ifstream object for the bmFileReader
 */
BitmapReader::BitmapReader(){
  this->bmFileReader = nullptr;
}

/**
 * Property constructor for the BitmapReader class
 * @param bmFileReader - the ifstream bitmap file reader object
 */
BitmapReader::BitmapReader(std::ifstream* bmFileReader){
    this->bmFileReader = bmFileReader;
}


// Accessors
//-----------------------------------------------------

/**
 * get the bitmap file reader object
 * @return ifstream*    - the pointer to the bitmap file reader
 */
std::ifstream* BitmapReader::getBMReader(){return bmFileReader;}


/**
 * set the bitmap file reader for the class
 * @param bmReader - the bitmap reader ifstream object
 */
void BitmapReader::setBMReader(std::ifstream &bmReader){ bmFileReader = &bmReader;}

// Member Methods
//-----------------------------------------------------

/**
* read a single byte from file stream
* @param field  - field from files stream
* @return int   - number of bytes read
*/
int BitmapReader::readByte(BYTE& field) {
    int sizeRead = sizeof(BYTE);
    bmFileReader->read(reinterpret_cast<char *>(&field), sizeRead);
    return sizeRead;
}// end readByte


/**
* read two bytes from file stream
* @param field  - field from files stream
* @return int   - number of bytes read
*/
int BitmapReader::readWord(WORD& field){
    int sizeRead = sizeof(WORD);
    bmFileReader->read(reinterpret_cast<char *>(&field), sizeRead);
    return sizeRead;
}// end readWord


/**
* read four bytes from file stream
* @param field  - field from files stream
* @return int   - number of bytes read
*/
int BitmapReader::readDWord(DWORD& field){
    int sizeRead = sizeof(DWORD);
    bmFileReader->read(reinterpret_cast<char *>(&field), sizeRead);
    return sizeRead;
}// end readDWord