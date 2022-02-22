//---------------------------------------------------------
// File     : bitmapFile.cpp
// Author   : J.Burnham
// Purpose  : implementation file for the BitmapFile class
//---------------------------------------------------------

#include "bitmapFile.h"
#include <cmath>

// Constructors
//-----------------------------------------------------

/**
 * Default Constructor for the BitmapFile class, creates an "empty" bitmap
 */



/**
 * Property Constructor for the BitmapFile class, for when the bitmap reader and writer are known at instantiation
 * @param bitmapReader - an input stream object (ifstream)
 * @param bitmapWriter - an output stream object (ofstream)
 */
BitmapFile::BitmapFile(std::ifstream* reader,  std::ofstream* writer){
    bmWriter = BitmapWriter(writer);
    bmReader = BitmapReader(reader);
    bmFileHeader =   BitmapFileHeader(&bmReader, &bmWriter);
    bmInfoHeader =  BitmapInfoHeader(&bmReader, &bmWriter);
    pixelArr = nullptr;
}


/**
 * Destructor for the BitmapFile class, deletes the pixel arr and other dynamically allocated memory
 */
BitmapFile::~BitmapFile(){
    for (int row = 0; row < bmInfoHeader.getBitmapHeight(); row++){
        delete pixelArr[row];
    }
    delete pixelArr;
}

// Accessors
//-----------------------------------------------------



/**
 * get the value of the bmFileHeader property
 * @return BitmapFileHeader* - the value to set to
 */
BitmapFileHeader BitmapFile::getBmFileHeader(){return bmFileHeader;}


/**
 * get the value of the bmInfoHeader property
 * @return BitmapInfoHeader* - the value to set to bmInfoHeader
 */
BitmapInfoHeader BitmapFile::getBmInfoHeader(){return bmInfoHeader;}


/**
 * get the value of the pixelArr property
 * @return Pixel** - the value to set to pixelArr
 */
Pixel **BitmapFile::getPixelArr(){return pixelArr;}

/**
 * set the value of the bmFileHeader property
 * @param value - the value to set bmFileHeader to
 */
void BitmapFile::setBmFileHeader(BitmapFileHeader value) {bmFileHeader = value;}

/**
 * set the value of the bmInfoHeader property
 * @param value - the value to set bmInfoHeader to
 */
void BitmapFile::setBmInfoHeader(BitmapInfoHeader value) {bmInfoHeader = value;}

/**
 * set the value of the pixelArr property
 * @param value - the value to set pixelArr to
 */
void BitmapFile::setPixelArr(Pixel **value) {pixelArr = value;}

// Member Methods
//-----------------------------------------------------

/**
 * Load the data from a input stream, into the properties of this class
 * @return int - the number of bytes read from the input stream
 */
int BitmapFile::load(){
    int bytes = 0;

    // Load data from input stream into the two objects for the headers
    bytes += bmFileHeader.load();
    bytes += bmInfoHeader.load();

    // populate the pixel array form the input stream
    if(bmReader.getBMReader() && bmReader.getBMReader()->is_open()){

        int rowSize = floor((bmInfoHeader.getBitDepth() * bmInfoHeader.getBitmapWidth() + 31)
                            / 32) * 4; // used for calculating the padding later
        DWORD bmHeight = bmInfoHeader.getBitmapHeight();
        DWORD bmWidth = bmInfoHeader.getBitmapWidth();

        pixelArr = new Pixel * [bmHeight];
        for (int row = 0; row < bmHeight; row++){

            pixelArr[row] = new Pixel[bmWidth];
            int rowBytes = 0;
            for(int column = 0; column < bmWidth; column++){
                Pixel pixel = Pixel(&bmReader, &bmWriter);
                rowBytes += pixel.load();
                pixelArr[row][column] = pixel;
            }// end column for

            // calculate padding for the read in
            int padding = rowSize - rowBytes;
            for (int pad = 0; pad < padding; pad++) {
                BYTE scratch;
                rowBytes += bmReader.readByte(scratch);
            }
            bytes += rowBytes;
        }
    }
    return bytes;
}

/**
 * write the data from the class properties into a output stream
 * @return int - the number of bytes written to the file
 */
int BitmapFile::store(){
    int bytes = 0;

    // write the data stored in the header object to the file
    bytes += bmFileHeader.store();
    bytes += bmInfoHeader.store();

    // populate the pixel array
    if (bmWriter.getBMWriter() && bmWriter.getBMWriter()->is_open()) {

        DWORD bmHeight = bmInfoHeader.getBitmapHeight() ;
        DWORD bmWidth = bmInfoHeader.getBitmapWidth() ;
        int rowSize = floor((bmInfoHeader.getBitDepth() * bmWidth + 31)/ 32) * 4;

        if ( pixelArr) {
            for (int row = 0; row < bmHeight; row++) {
                int rowBytes = 0;
                for (int column = 0; column < bmWidth; column++ ) {
                    Pixel pixel = pixelArr[row][column];
                    rowBytes += pixel.store();
                }

                // calculate padding for output stream
                int padding = rowSize - rowBytes;
                for (int pad = 0; pad < padding; pad++) {
                    BYTE scratch;
                    rowBytes += bmWriter.writeByte(scratch);
                }
                bytes += rowBytes;
            }
        }
    }
    return bytes;
}

