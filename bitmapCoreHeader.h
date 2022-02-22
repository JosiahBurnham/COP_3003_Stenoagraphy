//---------------------------------------------------------
// File     : bitmapCoreHeader.h
// Author   : J.Burnham
// Purpose  : definition file for the BitmapCoreHeader class
//---------------------------------------------------------

#include "bitmapWriter.h"
#include "bitmapReader.h"
#include "bitmapDefs.h"

#ifndef COP_3003_TEST2_BITMAPCOREHEADER_H
#define COP_3003_TEST2_BITMAPCOREHEADER_H


class BitmapCoreHeader {
public:
    // Constructor(s)
    //-----------------------------------------------------
    BitmapCoreHeader();
    BitmapCoreHeader(BitmapReader* bmReader, BitmapWriter* bmWriter);

    // Accessors
    //-----------------------------------------------------
    BitmapReader *getBmReader();
    BitmapWriter *getBmWriter();
    DWORD getHeaderSize();
    WORD getBitmapWidth();
    WORD getBitmapHeight();
    WORD getColorPanels();
    WORD getBitDepth();

    void setBmReader(BitmapReader *bmReader);
    void setBmWriter(BitmapWriter *bmWriter);
    void setHeaderSize(DWORD headerSize);
    void setBitmapWidth(WORD bitmapWidth);
    void setBitmapHeight(WORD bitmapHeight);
    void setColorPanels(WORD colorPanels);
    void setBitDepth(WORD bitDepth);

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
    DWORD headerSize;
    DWORD bitmapWidth;
    DWORD bitmapHeight;
    WORD colorPanels;
    WORD bitDepth;
};


#endif //COP_3003_TEST2_BITMAPCOREHEADER_H
