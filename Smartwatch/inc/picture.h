#ifndef PICTURE_H
#define PICTURE_H

#include "stm32l1xx.h"
#include "icons.h"

// picture width and height

#define WIDTH 128
#define HEIGHT 128

typedef struct Frame{

    short x; // Location of a frame
    short y;
    Icon icon; // Pointer to an Icon

 } Frame;

typedef struct PictureFrames{

    uint8_t numOfFrames;
    Frame *frames;

} PictureFrames;

typedef struct Picture{

    short width;
    short height;
    const uint8_t* pixels;

}Picture;


Picture createPictureFromFrames(PictureFrames pictureFrames);

#endif
