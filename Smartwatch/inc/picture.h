#ifndef PICTURE_H
#define PICTURE_H

#include "stm32l1xx.h"
#include "icons.h"

typedef struct Frame{

    short x; // Location of a frame
    short y;
    Icon *icon; // Pointer to an Icon

 } Frame;

typedef struct PictureFrames{

    uint8_t numOfFrames;
    Frame *frames;

} PictureFrames;

typedef struct Picture{

    short width;
    short height;
    uint8_t* pixels;

} Picture;


void createPictureFromFrames(PictureFrames pictureFrames, Picture picture);

#endif
