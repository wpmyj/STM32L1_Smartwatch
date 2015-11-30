#include "picture.h"

void createPictureFromFrames(PictureFrames pictureFrames, Picture picture){

    uint8_t frameIndex;
    short framePixelIndex;

    // Iterate through all frames
    for(frameIndex = 0; frameIndex < pictureFrames.numOfFrames; frameIndex++){
        Frame currentFrame = pictureFrames.frames[frameIndex];
        // Iterate through all pixels of a single frame
        for(framePixelIndex = 0; framePixelIndex < currentFrame.icon->width * currentFrame.icon->height; framePixelIndex++){
            // Set new pixel
            picture.pixels[(currentFrame.y + framePixelIndex / currentFrame.icon->width) * currentFrame.icon->width + (framePixelIndex % currentFrame.icon->width)] = currentFrame.icon->pixels[framePixelIndex];
        }
    }

}

