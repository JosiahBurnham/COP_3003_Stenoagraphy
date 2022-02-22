//---------------------------------------------------------
// File     : bitmapFileHeader.h
// Author   : J.Burnham
// Purpose  : definition file for the BitmapFileHeader class
//---------------------------------------------------------

#include "bitmapReader.h"
#include "bitmapWriter.h"

#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H


class BitmapFileHeader {
public:
    // Constructors
    //-----------------------------------------------------
    BitmapFileHeader();
    BitmapFileHeader(BitmapReader* bmReader, BitmapWriter* bmWriter);


    // Accessors
    //-----------------------------------------------------
    BitmapReader* getBMReader();
    BitmapWriter* getBMWriter();
    std::string getBitmapType();
    int getFileSize();
    int getReserved1();
    int getReserved2();
    int getOffset();

    void setBMReader(BitmapReader* value);
    void setBMWriter(BitmapWriter* value);
    void setBitmapType1(BYTE value);
    void setBitmapType2(BYTE value);
    void setFileSize(DWORD value);
    void setReserved1(WORD value);
    void setReserved2(WORD value);
    void setOffset(DWORD value);

    // Member Methods
    //-----------------------------------------------------
    int load();
    int store();
    std::string toString();

private:

    // Properties
    //-----------------------------------------------------
    BYTE bitmapType[2];
    DWORD fileSize;
    WORD reserved1;
    WORD reserved2;
    DWORD offset;
    BitmapReader* bmReader;
    BitmapWriter* bmWriter;

};


#endif //BITMAPFILEHEADER_H
