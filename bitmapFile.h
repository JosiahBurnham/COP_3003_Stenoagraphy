//---------------------------------------------------------
// File     : bitmapFile.h
// Author   : J.Burnham
// Purpose  : definition file for the BitmapFile class
//---------------------------------------------------------

#include "pixel.h"
#include "bitmapInfoHeader.h"
#include "bitmapFileHeader.h"
#include "bitmapReader.h"
#include "bitmapWriter.h"

#ifndef COP_3003_TEST2_BITMAPFILE_H
#define COP_3003_TEST2_BITMAPFILE_H


class BitmapFile {
public:
    // Constructors
    //-----------------------------------------------------
    BitmapFile(std::ifstream* reader = nullptr,  std::ofstream* = nullptr);
    ~BitmapFile();

    // Accessors
    //-----------------------------------------------------
    BitmapWriter *getBmWriter();
    BitmapReader *getBmReader();
    BitmapFileHeader getBmFileHeader();
    BitmapInfoHeader getBmInfoHeader();
    Pixel **getPixelArr();

    void setBmWriter(BitmapWriter *value);
    void setBmReader(BitmapReader *value);
    void setBmFileHeader(BitmapFileHeader value);
    void setBmInfoHeader(BitmapInfoHeader value);
    void setPixelArr(Pixel **value);

    // Member Methods
    //-----------------------------------------------------
    int load();
    int store();

protected:
    // Properties
    //-----------------------------------------------------
    BitmapWriter bmWriter;
    BitmapReader bmReader;
    BitmapFileHeader bmFileHeader;
    BitmapInfoHeader bmInfoHeader;
    Pixel** pixelArr;

};


#endif //COP_3003_TEST2_BITMAPFILE_H
