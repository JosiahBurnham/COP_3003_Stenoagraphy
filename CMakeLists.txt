cmake_minimum_required(VERSION 3.20)
project(COP_3003_Test2)

set(CMAKE_CXX_STANDARD 14)

add_executable(COP_3003_Test2 bitmap.cpp bitmapDefs.h bitmapReader.cpp bitmapReader.h bitmapFileHeader.cpp bitmapFileHeader.h bitmapFile.cpp bitmapFile.h bitmapCoreHeader.cpp bitmapCoreHeader.h bitmapInfoHeader.cpp bitmapInfoHeader.h pixel.cpp pixel.h bitmapWriter.cpp bitmapWriter.h encryptedBitmap.cpp encryptedBitmap.h)
