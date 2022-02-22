//---------------------------------------------------------
// File     : bitmapReader.h
// Author   : J.Burnham
// Purpose  : definition file for the BitmapReader class
//---------------------------------------------------------

#include <fstream>
#include "bitmapDefs.h"

#ifndef BITMAPREADER_H
#define BITMAPREADER_H


class BitmapReader {
public:
    // Constructor(s)
    //-----------------------------------------------------
    BitmapReader();
    BitmapReader(std::ifstream* bmFileReader);


    // Accessors
    //-----------------------------------------------------
    std::ifstream* getBMReader();
    void setBMReader(std::ifstream &bmReader);

    // Member Methods
    //-----------------------------------------------------
    int readByte(BYTE& field);
    int readWord(WORD& field);
    int readDWord(DWORD& field);


private:
    // Properties
    //-----------------------------------------------------
    std::ifstream* bmFileReader;
};


#endif //BITMAPREADER_H
