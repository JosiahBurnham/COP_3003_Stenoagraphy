//---------------------------------------------------------
// File     : encryptedBitmap.h
// Author   : J.Burnham
// Purpose  : definition file for the EncryptedBitmap class
//---------------------------------------------------------

#ifndef COP_3003_TEST3_ENCRYPTEDBITMAP_H
#define COP_3003_TEST3_ENCRYPTEDBITMAP_H

#include "bitmapFile.h"

class EncryptedBitmap: public BitmapFile{
public:
    EncryptedBitmap(std::ifstream* reader = nullptr,  std::ofstream* = nullptr );

    int encrypt(std::string message);
    std::string decrypt();

};


#endif //COP_3003_TEST3_ENCRYPTEDBITMAP_H
