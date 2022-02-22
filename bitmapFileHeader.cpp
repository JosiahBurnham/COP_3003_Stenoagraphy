//---------------------------------------------------------
// File     : bitmapFileHeader.cpp
// Author   : J.Burnham
// Purpose  : configuration file for the BitmapFileHeader class
//---------------------------------------------------------

#include "bitmapFileHeader.h"

// Constructors
//-----------------------------------------------------

/**
 * Default Constructor for the bitmapFileHeader class, instantiates an emtpy object
 */
BitmapFileHeader::BitmapFileHeader(){
    this->bmReader = nullptr;
    this->bmWriter = nullptr;
    this->bitmapType[0] = 0;
    this->bitmapType[1] = 0;
    this->fileSize = 0;
    this->reserved1 = 0;
    this->reserved2 = 0;
    this->offset = 0;
}

/**
 * Property constructor for when a bitmap file reader object is passed
 * @param bmReader - bitmap file reader object
 */
BitmapFileHeader::BitmapFileHeader(BitmapReader* bmReader, BitmapWriter* bmWriter){
    this->bmReader = bmReader;
    this->bmWriter = bmWriter;
    this->bitmapType[0] = 0;
    this->bitmapType[1] = 0;
    this->fileSize = 0;
    this->reserved1 = 0;
    this->reserved2 = 0;
    this->offset = 0;
}

// Accessors
//-----------------------------------------------------

/**
 * get the value of bmReader
 * @return  BitmapReader* - bmReader
 */
BitmapReader* BitmapFileHeader::getBMReader(){return bmReader;}


/**
 * get the value of bmWriter
 * @return  BitmapWriter* - bmWriter
 */
BitmapWriter* BitmapFileHeader::getBMWriter() {return bmWriter;}

/**
 * get the value of bitmaptype
 * @return string - the value of bitmaptype
 */
std::string BitmapFileHeader::getBitmapType(){
    std::string type = std::string(1,bitmapType[0]) + std::string(1,bitmapType[1]);
    return type;
}


/**
 * get the value of fileSize
 * @return int - the value of fileSize
 */
int BitmapFileHeader::getFileSize(){return fileSize;}


/**
 * get the value of reserved1
 * @return int - the value of reserved1
 */
int BitmapFileHeader::getReserved1(){return reserved1;}


/**
 * get the value of reserved2
 * @return int - the value of reserved2
 */
int BitmapFileHeader::getReserved2(){return reserved2;}


/**
 * get the value of offset
 * @return int - the value of offset
 */
int BitmapFileHeader::getOffset(){return offset;}


/**
 * set the value of the bmReader object
 * @param value -   the value to be passed
 */
void BitmapFileHeader::setBMReader(BitmapReader* value) {bmReader = value;}


/**
 * set the value of the bmWriter object
 * @param value -   the value to be passed
 */
void BitmapFileHeader::setBMWriter(BitmapWriter* value) {bmWriter = value;}


/**
 * set the value for the first index of the bitmap type
 * @param value - the value to be passed
 */
void BitmapFileHeader::setBitmapType1(BYTE value){ bitmapType[0] = value;}


/**
 * set the value for the second index of the bitmap type
 * @param value - the value to be passed
 */
void BitmapFileHeader::setBitmapType2(BYTE value){ bitmapType[1] = value;}


/**
 * set the value for the
 * @param value - the value to be passed filesize
 */
void BitmapFileHeader::setFileSize(DWORD value){ fileSize = value;}


/**
 * set the value for the reserved1 attribute
 * @param value - the value to be passed
 */
void BitmapFileHeader::setReserved1(WORD value){ reserved1 = value;}


/**
 * set the value for the reserved2 attribute
 * @param value - the value to be passed
 */
void BitmapFileHeader::setReserved2(WORD value){reserved2 = value;}


/**
 * set the value for the offset
 * @param value - the value to be passed
 */
void BitmapFileHeader::setOffset(DWORD value){ offset = value;}

// Member Methods
//-----------------------------------------------------


/**
 * load the data from a file, into the class properties
 * @return int  - the amount of bytes read during the load method
 */
int BitmapFileHeader::load(){
    int bytes;
    bytes =  bmReader->readByte(bitmapType[0]);
    bytes += bmReader->readByte(bitmapType[1]);
    bytes += bmReader->readDWord(fileSize);
    bytes += bmReader->readWord(reserved1);
    bytes += bmReader->readWord(reserved2);
    bytes += bmReader->readDWord(offset);

    return bytes;
}


/**
 * write the class properties to a file
 * @return int  -   the amount of bytes written to the file.
 */
int BitmapFileHeader::store(){
    int bytes;
    bytes =  bmWriter->writeByte(bitmapType[0]);
    bytes += bmWriter->writeByte(bitmapType[1]);
    bytes += bmWriter->writeDWord(fileSize);
    bytes += bmWriter->writeWord(reserved1);
    bytes += bmWriter->writeWord(reserved2);
    bytes += bmWriter->writeDWord(offset);

    return bytes;
}


/**
 * Print the attributes of the bitmapfile that was passed
 * @return string   -   the string containing all the attributes of the file passed
 */
std::string BitmapFileHeader::toString(){
    std::string out = "\nType = " + getBitmapType() + '\n';
    out += "FileSize = " +std::to_string(fileSize) + "\n";
    out += "Offset = " +std::to_string(offset) + "\n";
    out += "Reserved 1" + std::to_string(reserved1) + "\n";
    out += "Reserved 2" + std::to_string(reserved2) + "\n";

    return out;
}
