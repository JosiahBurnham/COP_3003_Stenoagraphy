//---------------------------------------------------------
// File     : bitmapInfoHeader.h
// Author   : J.Burnham
// Purpose  : definition file for the BitmapInfoHeader class
//---------------------------------------------------------

#include "bitmapInfoHeader.h"

// Constructor
//-----------------------------------------------------
/**
 * default constructor, creates an "empty" bitmap Info header
 */
BitmapInfoHeader::BitmapInfoHeader()
: BitmapCoreHeader{}{
    compressionMethod = 0;
    imageSize = 0;
    horizontalRez = 0;
    verticalRez = 0;
    colorPalette = 0;
    importantColors = 0;
}


/**
 * Property constructor for BitmapInfoHeader, for when the input and output streams are known at instantiation
 * @param bmReader - the input stream object
 * @param bmWriter - the output stream object
 */
BitmapInfoHeader::BitmapInfoHeader(BitmapReader* bmReader, BitmapWriter* bmWriter)
    : BitmapCoreHeader{bmReader, bmWriter}{
    this->bmReader = bmReader;
    this->bmWriter = bmWriter;
    compressionMethod = 0;
    imageSize = 0;
    horizontalRez = 0;
    verticalRez = 0;
    colorPalette = 0;
    importantColors = 0;
}

// Accessors
//-----------------------------------------------------

/**
 * get the compression method property
 * @return DWORD - the value of compressionMethod
 */
DWORD BitmapInfoHeader::getCompressionMethod()  {return compressionMethod;}


/**
 * get the image size property
 * @return DWORD - the value of imageSize
 */
DWORD BitmapInfoHeader::getImageSize()  {return imageSize;}


/**
 * get the horizontal resolution property
 * @return DWORD - the value of horizontalRez
 */
DWORD BitmapInfoHeader::getHorizontalRez()  {return horizontalRez;}


/**
 * get the vertical resolution property
 * @return DWORD - the value of verticalRez
 */
DWORD BitmapInfoHeader::getVerticalRez()  {return verticalRez;}


/**
 * get the color palette property
 * @return DWORD - the value of colorPalette
 */
DWORD BitmapInfoHeader::getColorPalette()  {return colorPalette;}


/**
 * get the important colors property
 * @return DWORD - the value of importantColors
 */
DWORD BitmapInfoHeader::getImportantColors()  {return importantColors;}


/**
 * set the value of the compression method property
 * @param value - the value of  compressionMethod
 */
void BitmapInfoHeader::setCompressionMethod(DWORD value) {compressionMethod = value;}


/**
 * set the value of the image size property
 * @param value - the value of imageSize
 */
void BitmapInfoHeader::setImageSize(DWORD value) {imageSize = value;}


/**
 * set the value of the horizontal resolution property
 * @param value - the value of horizontalRez
 */
void BitmapInfoHeader::setHorizontalRez(DWORD value) {horizontalRez = value;}


/**
 * set the value of the vertical resolution property
 * @param value - the value of verticalRez
 */
void BitmapInfoHeader::setVerticalRez(DWORD value) {verticalRez = value;}


/**
 * set the value of the color palette property
 * @param value - the value of colorPalette
 */
void BitmapInfoHeader::setColorPalette(DWORD value) {colorPalette = value;}


/**
 * set the value of the important colors property
 * @param value - the value of importantColors
 */
void BitmapInfoHeader::setImportantColors(DWORD value) {importantColors = value;}

// Public Methods
//-----------------------------------------------------


/**
 * load the data from a file, into the class properties
 * @return int  - the amount of bytes read during the load method
 */
int BitmapInfoHeader::load() {
    int bytes = 0;
    bytes += BitmapCoreHeader::load();
    bytes += bmReader->readDWord(compressionMethod);
    bytes += bmReader->readDWord(imageSize);
    bytes += bmReader->readDWord(horizontalRez);
    bytes += bmReader->readDWord(verticalRez);
    bytes += bmReader->readDWord(colorPalette);
    bytes += bmReader->readDWord(importantColors);

    return bytes;
}


/**
 * write the class properties to a file
 * @return int  -   the amount of bytes written to the file.
 */
int BitmapInfoHeader::store() {
    int bytes = 0;
    bytes += BitmapCoreHeader::store();
    bytes += bmWriter->writeDWord(compressionMethod);
    bytes += bmWriter->writeDWord(imageSize);
    bytes += bmWriter->writeDWord(horizontalRez);
    bytes += bmWriter->writeDWord(verticalRez);
    bytes += bmWriter->writeDWord(colorPalette);
    bytes += bmWriter->writeDWord(importantColors);

    return bytes;
}


/**
 * Print the attributes of the bitmapInfoHeader that was passed
 * @return string   -   the string containing all the attributes of the file passed
 */
std::string BitmapInfoHeader::toString(){
    std::string out = BitmapCoreHeader::toString();
    out += "\nCompression Method: " + compressionMethod + '\n';
    out += "Image Size: " +std::to_string(imageSize) + "\n";
    out += "Horizontal Resolution: " +std::to_string(horizontalRez) + "\n";
    out += "Vertical Resolution: " + std::to_string(verticalRez) + "\n";
    out += "Color Palette: " + std::to_string(colorPalette) + "\n";
    out += "Important Colors: " + std::to_string(importantColors) + "\n";

    return out;
}
