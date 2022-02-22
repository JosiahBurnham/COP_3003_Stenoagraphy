//---------------------------------------------------------
// File     : bitmapWriter.cpp
// Author   : J.Burnham
// Purpose  : Configuration file for the BitmapWriter class
//---------------------------------------------------------

#include "bitmapWriter.h"

// Constructor(s)
//-----------------------------------------------------
/**
 * Default Constructor, creates an "empty" bitmap writer
 */
BitmapWriter::BitmapWriter(){
    this->outputStream = nullptr;
}

/**
 * Property Constructor, when the file writer is know before instantiation
 * @param bmFileWriter  - the output stream object
 */
BitmapWriter::BitmapWriter(std::ofstream* bmFileWriter){
    this->outputStream = bmFileWriter;
}


// Accessors
//-----------------------------------------------------

/**
 * get the output stream object
 * @return ofstream* - the output stream object
 */
std::ofstream* BitmapWriter::getBMWriter(){ return outputStream;}


/**
 * set the output stream object
 * @param bmWriter - an ofstream object
 */
void BitmapWriter::setBMWriter(std::ofstream &bmWriter){ outputStream = &bmWriter;}

// Member Method(s)
//-----------------------------------------------------
/**
 * Write a Byte sized value to a bitmap file
 * @param value     - the value to write to the file
 * @return int      - the amount of Bytes written to the file
 */
int BitmapWriter::writeByte(BYTE &value){
    int out = sizeof(value);
    outputStream->write(reinterpret_cast<char *>(&value), out);
    return out;
}


/**
 * Write a Word sized value to a bitmap file
 * @param value- the value to write to the file
 * @return int      - the amount of Bytes written to the file
 */
int BitmapWriter::writeWord(WORD &value){
    int out = sizeof(value);
    outputStream->write(reinterpret_cast<char *>(&value), out);
    return out;
}


/**
 * Write a DWord sized value to a bitmap file
 * @param value- the value to write to the file
 * @return int      - the amount of Bytes written to the file
 */
int BitmapWriter::writeDWord(DWORD &value){
    int out = sizeof(value);
    outputStream->write(reinterpret_cast<char *>(&value), out);
    return out;
}