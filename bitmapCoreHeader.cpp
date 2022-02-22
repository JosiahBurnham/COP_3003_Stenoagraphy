//---------------------------------------------------------
// File     : bitmapCoreHeader.cpp
// Author   : J.Burnham
// Purpose  : implementation file for the BitmapCoreHeader class
//---------------------------------------------------------

#include "bitmapCoreHeader.h"

// Constructor(s)
//-----------------------------------------------------

/**
 * Default Constructor, creates an "empty object"
 */
BitmapCoreHeader::BitmapCoreHeader(){
    bmReader = nullptr;
    bmWriter = nullptr;
    headerSize = 0;
    bitmapWidth = 0;
    bitmapHeight = 0;
    colorPanels = 0;
    bitDepth = 0;
}

/**
 * Property Constructor for when the bitmap Reader and Writer is known at instantiation;
 * @param bmReader -    the bitmap reader
 * @param bmWriter -    the bitmap writer
 */
BitmapCoreHeader::BitmapCoreHeader(BitmapReader* bmReader, BitmapWriter* bmWriter){
    this->bmReader = bmReader;
    this->bmWriter = bmWriter;
    headerSize = 0;
    bitmapWidth = 0;
    bitmapHeight = 0;
    colorPanels = 0;
    bitDepth = 0;
}

// Assessors
//-----------------------------------------------------

/**
 * get the value of bmReader
 * @return -    the value of bmReader
 */
BitmapReader *BitmapCoreHeader::getBmReader() {return bmReader;}


/**
 * get the value of bmWriter
 * @return -    the value of bmWriter
 */
BitmapWriter *BitmapCoreHeader::getBmWriter() {return bmWriter;}


/**
 * get the value of headerSize
 * @return -    the value of headerSize
 */
DWORD BitmapCoreHeader::getHeaderSize() {return headerSize;}


/**
 * get the value of bitmapWidth
 * @return -    the value of bitmapWidth
 */
WORD BitmapCoreHeader::getBitmapWidth() {return bitmapWidth;}


/**
 * get the value of bitmapHeight
 * @return -    the value of bitmapHeight
 */
WORD BitmapCoreHeader::getBitmapHeight() {return bitmapHeight;}


/**
 * get the value of colorPanels
 * @return -    the value of colorPanels
 */
WORD BitmapCoreHeader::getColorPanels() {return colorPanels;}


/**
 * get the value of bitDepth
 * @return -    the value of bitDepth
 */
WORD BitmapCoreHeader::getBitDepth() {return bitDepth;}


/**
 * set the value of bmReader
 * @param value - the value to set the property to
 */
void BitmapCoreHeader::setBmReader(BitmapReader *value) {bmReader = value;}


/**
 * set the value of bmWriter
 * @param value - the value to set the property to
 */
void BitmapCoreHeader::setBmWriter(BitmapWriter *value) {bmWriter = value;}


/**
 * set the value of headerSize
 * @param value - the value to set the property to
 */
void BitmapCoreHeader::setHeaderSize(DWORD value) {headerSize = value;}


/**
 * set the value of bitmapWidth
 * @param value - the value to set the property to
 */
void BitmapCoreHeader::setBitmapWidth(WORD value) {bitmapWidth = value;}


/**
 * set the value of bitmapHeight
 * @param value - the value to set the property to
 */
void BitmapCoreHeader::setBitmapHeight(WORD value) {bitmapHeight = value;}


/**
 * set the value of colorPanels
 * @param value - the value to set the property to
 */
void BitmapCoreHeader::setColorPanels(WORD value) {colorPanels = value;}


/**
 * set the value of bitDepth
 * @param value - the value to set the property to
 */
void BitmapCoreHeader::setBitDepth(WORD value) {bitDepth = value;}


// Member Methods
//-----------------------------------------------------

/**
 * load the data from the file, into the class properties
 * @return int  - the amount of bytes read during the load method
 */
int BitmapCoreHeader::load(){
    int bytes;
    bytes = bmReader->readDWord(headerSize);
    bytes += bmReader->readDWord(bitmapWidth);
    bytes += bmReader->readDWord(bitmapHeight);
    bytes += bmReader->readWord(colorPanels);
    bytes += bmReader->readWord(bitDepth);

    return bytes;
}


/**
 * write the class properties to a file
 * @return int  -   the amount of bytes written to the file.
 */
int BitmapCoreHeader::store(){
    int bytes;
    bytes = bmWriter->writeDWord(headerSize);
    bytes += bmWriter->writeDWord(bitmapWidth);
    bytes += bmWriter->writeDWord(bitmapHeight);
    bytes += bmWriter->writeWord(colorPanels);
    bytes += bmWriter->writeWord(bitDepth);

    return bytes;
}


/**
 * Print the attributes of the bitmapfile that was passed
 * @return string   -   the string containing all the attributes of the file passed
 */
std::string BitmapCoreHeader::toString(){
    std::string out = "\n Header Size: " + std::to_string(headerSize) + "\n";
    out += "Bitmap Width: " + std::to_string(bitmapWidth) + "\n";
    out += "Bitmap Height: " + std::to_string(bitmapHeight) + "\n";
    out += "Number of Color Panels: " + std::to_string(colorPanels) + "\n";
    out += "Bit Depth: " + std::to_string(bitDepth) + "\n";
    return out;
}
