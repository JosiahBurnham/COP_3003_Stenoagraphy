//---------------------------------------------------------
// File     : encryptedBitmap.h
// Author   : J.Burnham
// Purpose  : configuration file for the EncryptedBitmap class
//---------------------------------------------------------

#include "encryptedBitmap.h"

/**
 * Default/Properties constructor for when the bitmap reader and writer are known
 * @param bmReader - input stream object pointer
 * @param bmWriter - output stream object pointer
 */
EncryptedBitmap::EncryptedBitmap(std::ifstream* bmReader ,  std::ofstream* bmWriter  )
: BitmapFile{bmReader, bmWriter}{}



/**
 *  encrypt the given bitmap file's pixel array with the given string
 *  @param message - the message to encode into the image
 *  @return int    - the amount of bytes loaded - the amount of bytes stored (it should be zero)
 */
int EncryptedBitmap::encrypt(std::string message){
    int bytesRead = load();

    int row = 0, column = 0;
    for (int next = 0; next < message.length(); next++) {
        char nextChar = message[next];

        // for 8 bits
        for (int bit = 0; bit < 8; bit++) {

            Pixel *nextPixel = &pixelArr[row][column];

            uint8_t blue = nextPixel->getBlue();

            // encode the blue
            if (nextChar & 1) {
                blue |= 1;
            }
            else {
                blue &= 0xFE;
            }

            nextPixel->setBlue(blue);
            nextChar >>= 1; // move to the next bit to encode

            column++;   // move to the next pixel to encode
            if (column == bmInfoHeader.getBitmapWidth()) {
                row++;
                column = 0;
            }
        }
    }
    // encode the null terminator
    for (int term = 0; term < 8; term++ ) {
        Pixel *nextPixel = &pixelArr[row][column];
        uint8_t blue = nextPixel->getBlue();
        blue &= 0xFE;
        nextPixel->setBlue(blue);
        column++;
        if (column == bmInfoHeader.getBitmapWidth()) {
            row++;
            column = 0;
        }
    }

    bytesRead -= store();   // to check if the bytes read in and the bytes stored were the same.
    return bytesRead;
}



/**
 * decrypt the string inside the given encrypted bitmap file.
 * @return string - the message embedded in the file
 */
std::string EncryptedBitmap::decrypt(){
    load();
    int row = 0, column = 0;
    char nextChar;
    std::string secretMessage = "";

// until we hit the null terminator
    do {
        nextChar = 0; // reset the char for next iteration.
        for (int i = 0; i < 8; i++) {
            Pixel *nextPixel = &pixelArr[row][column];

            //or the result of {Blue & 1 (isolate bit-0) shifted i times to the left}
            nextChar |= (nextPixel->getBlue() & 1) << i;

            // get next pixel
            column++;
            if (column == bmInfoHeader.getBitmapWidth()) {
                row++;
                column = 0;
            }
        } // end eight bits
        secretMessage += nextChar;
    } while (nextChar);

    return secretMessage;
}