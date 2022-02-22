//---------------------------------------------------------
// File     : pixel.cpp
// Author   : J.Burnham
// Purpose  : implementation file for the Pixel class
//---------------------------------------------------------

#include "pixel.h"

// Constructors
//-----------------------------------------------------
/**
 * Default/Property Constructor for when the RGB values are either known or unkonwn at instantiation
 * @param red   - the value for red between (0-255)
 * @param green - the value for green between (0-255)
 * @param blue  - the value for blue between (0-255)
 */
Pixel::Pixel(BYTE red , BYTE green , BYTE blue ){
    bmWriter = nullptr;
    bmReader = nullptr;
    this->red = red;
    this->green = red;
    this->blue = blue;
}


/**
 * Property Constructor for when the bitmapReader and bitmapWriter are known at instantiation
 * @param bitmapReader - the ifstream object used for reading a file
 * @param bitmapWriter - the ofstream object used for writing to a file
 */
Pixel::Pixel(BitmapReader* bitmapReader, BitmapWriter* bitmapWriter){
    bmReader = bitmapReader;
    bmWriter = bitmapWriter;
    red = 0;
    green = 0;
    blue = 0;
}


// Accessors
//-----------------------------------------------------

/**
 * get the bmReader property
 * @return BitmapReader* - the value of
 */
BitmapReader *Pixel::getBmReader() {return bmReader;}


/**
 * get the property
 * @return BitmapWriter* - the value of
 */
BitmapWriter *Pixel::getBmWriter() {return bmWriter;}


/**
 * get the red property
 * @return Byte - the value of red
 */
BYTE Pixel::getRed() {return red;}


/**
 * get the green property
 * @return Byte - the value of green
 */
BYTE Pixel::getGreen() {return green;}


/**
 * get the blue property
 * @return Byte - the value of blue
 */
BYTE Pixel::getBlue() {return blue;}


/**
 * set the value of the bmReader property
 * @param value - the values to set the bmReader property to
 */
void Pixel::setBmReader(BitmapReader *value) {bmReader = value;}


/**
 * set the value of the bmWriter property
 * @param value - the values to set the bmWriter property to
 */
void Pixel::setBmWriter(BitmapWriter *value) {bmWriter = value;}


/**
 * set the value of the red property
 * @param value - the values to set the red property to
 */
void Pixel::setRed(BYTE value) {red = value;}


/**
 * set the value of the green property
 * @param value - the values to set the green property to
 */
void Pixel::setGreen(BYTE value) {green = value;}


/**
 * set the value of the blue property
 * @param value - the values to set the blue property to
 */
void Pixel::setBlue(BYTE value) {blue = value;}

// Member Methods
//-----------------------------------------------------

/**
 * load the data from a file, into the class RGB properties
 * @return int  - the amount of bytes read during the load method
 */
int Pixel::load(){
    int bytes;
    bytes = bmReader->readByte(red);
    bytes += bmReader->readByte(green);
    bytes += bmReader->readByte(blue);
    return bytes;
}

/**
 * write the class RGB properties to a file
 * @return int  -   the amount of bytes written to the file.
 */
int Pixel::store(){
    int bytes;
    bytes =  bmWriter->writeByte(red);
    bytes += bmWriter->writeByte(green);
    bytes += bmWriter->writeByte(blue);
    return bytes;
}

/**
 * creates a string of all the color values this pixel holds
 * @return string   - the RGB values for this pixel
 */
std::string Pixel::toString(){
    std::string out = "\nRed: " + std::to_string(red) + "\n";
    out += "Green: " + std::to_string(green) + "\n";
    out += "Blue: " + std::to_string(blue) + "\n";
    return out;
}
