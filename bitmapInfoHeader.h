//---------------------------------------------------------
// File     : bitmapInfoHeader.h
// Author   : J.Burnham
// Purpose  : definition file for the BitmapInfoHeader class
//---------------------------------------------------------

#include "bitmapCoreHeader.h"
#ifndef COP_3003_TEST2_BITMAPINFOHEADER_H
#define COP_3003_TEST2_BITMAPINFOHEADER_H


class BitmapInfoHeader: public BitmapCoreHeader {
public:
    // Constructor
    //-----------------------------------------------------
    BitmapInfoHeader();
    BitmapInfoHeader(BitmapReader* bmReader, BitmapWriter* bmWriter);

    // Accessors
    //-----------------------------------------------------
    DWORD getCompressionMethod() ;
    DWORD getImageSize() ;
    DWORD getHorizontalRez() ;
    DWORD getVerticalRez() ;
    DWORD getColorPalette() ;
    DWORD getImportantColors() ;

    void setCompressionMethod(DWORD value);
    void setImageSize(DWORD value);
    void setHorizontalRez(DWORD value);
    void setVerticalRez(DWORD value);
    void setColorPalette(DWORD value);
    void setImportantColors(DWORD value);

    // Public Methods
    //-----------------------------------------------------
    int load();
    int store();
    std::string toString();

protected:

    // Properties
    //-----------------------------------------------------
    DWORD compressionMethod;
    DWORD imageSize;
    DWORD horizontalRez;
    DWORD verticalRez;
    DWORD colorPalette;
    DWORD importantColors;

};


#endif //COP_3003_TEST2_BITMAPINFOHEADER_H
