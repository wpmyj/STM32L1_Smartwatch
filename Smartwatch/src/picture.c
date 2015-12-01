#include "picture.h"

static uint8_t getBitAt(uint8_t byte, uint8_t pos);
static void changeBitAt(uint8_t* byte, uint8_t pos, uint8_t val);

uint8_t picture[(WIDTH / WIDTH_DIV) * HEIGHT];
static Picture pic = {WIDTH, HEIGHT, picture};


Picture createPictureFromFrames(PictureFrames pictureFrames){

    uint8_t frameIndex;
    short iconIndex, pictureX, pictureY;
    Frame currentFrame;
    Icon *icon;

    // Iterate through frames
    for(frameIndex = 0; frameIndex < pictureFrames.numOfFrames; frameIndex++){
        
        // Extract current frame and icon in the frame
        currentFrame = pictureFrames.frames[frameIndex];
        icon = currentFrame.icon;
        
        // X and Y initialization
        pictureY = currentFrame.y;
        pictureX = currentFrame.x;

        // Iterate through the picture and apply changes
        for(iconIndex = 0; iconIndex < icon->width * icon->height; iconIndex++){

            // Change bit at position X,Y
            changeBitAt(&picture[(pictureY * WIDTH + pictureX) / WIDTH_DIV], 7 - (pictureX % WIDTH_DIV), getBitAt(icon->pixels[iconIndex / WIDTH_DIV], 7 - (iconIndex % WIDTH_DIV)));

            if(pictureX == currentFrame.x + icon->width - 1){
                pictureY++;
                pictureX = currentFrame.x;
            }
            else
                pictureX++;
            
        }
        
    }

    return pic;

}

static uint8_t getBitAt(uint8_t byte, uint8_t pos){

    return (byte >> pos) & 0x1; 

}

static void changeBitAt(uint8_t* byte, uint8_t pos, uint8_t val){

    *byte = (*byte & ~(1 << pos)) | (val << pos);   

}

