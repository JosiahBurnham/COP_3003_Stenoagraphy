//---------------------------------------------------------
// File     : pixel.h
// Author   : J.Burnham
// Purpose  : definition file for the Pixel class
//---------------------------------------------------------
#ifndef COP_3003_TEST2_PIXEL_H
#define COP_3003_TEST2_PIXEL_H

#include "bitmapReader.h"
#include "bitmapWriter.h"

class Pixel {
public:
    // Constructors
    //-----------------------------------------------------
    Pixel(BYTE red = 0, BYTE green = 0, BYTE blue = 0);
    Pixel(BitmapReader* bitmapReader, BitmapWriter* bitmapWriter);

    // Accessors
    //-----------------------------------------------------
    BitmapReader *getBmReader();
    BitmapWriter *getBmWriter();
    BYTE getRed();
    BYTE getGreen();
    BYTE getBlue();

    void setBmReader(BitmapReader *value);
    void setBmWriter(BitmapWriter *value);
    void setRed(BYTE value);
    void setGreen(BYTE value);
    void setBlue(BYTE value);

    // Member Methods
    //-----------------------------------------------------
    int load();
    int store();
    std::string toString();

protected:

    // Properties
    //-----------------------------------------------------
    BitmapReader* bmReader;
    BitmapWriter* bmWriter;
    BYTE red;
    BYTE green;
    BYTE blue;
};


#endif //COP_3003_TEST2_PIXEL_H
