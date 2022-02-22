//---------------------------------------------------------
// File     : bitmapWriter.h
// Author   : J.Burnham
// Purpose  : Definition file for the BitmapWriter class
//---------------------------------------------------------

#include <fstream>
#include "bitmapDefs.h"

#ifndef COP_3003_TEST2_BITMAPWRITER_H
#define COP_3003_TEST2_BITMAPWRITER_H


class BitmapWriter {
public:
    // Constructor(s)
    //-----------------------------------------------------
    BitmapWriter();
    BitmapWriter(std::ofstream* bmFileReader);

    // Accessors
    //-----------------------------------------------------
    std::ofstream* getBMWriter();
    void setBMWriter(std::ofstream &bmReader);

    // Member Method(s)
    //-----------------------------------------------------
    int writeByte(BYTE &value);
    int writeWord(WORD &value);
    int writeDWord(DWORD &value);

private:
    // Properties
    //-----------------------------------------------------
    std::ofstream* outputStream;
};


#endif //COP_3003_TEST2_BITMAPWRITER_H
