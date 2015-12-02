#include "picture.h"

static void appendFramesToPicture(PictureFrames pictureFrames);
static uint8_t getBitAt(uint8_t byte, uint8_t pos);
static void changeBitAt(uint8_t* byte, uint8_t pos, uint8_t val);

static uint8_t picture[(WIDTH / WIDTH_DIV) * HEIGHT];


static void appendFramesToPicture(PictureFrames pictureFrames){

    uint8_t frameIndex;
    short iconIndex, pictureX, pictureY;
    Frame currentFrame;
    Icon icon;

    // Iterate through frames
    for(frameIndex = 0; frameIndex < pictureFrames.numOfFrames; frameIndex++){
        
        // Extract current frame and icon in the frame
        currentFrame = pictureFrames.frames[frameIndex];
        icon = currentFrame.icon;
        
        // X and Y initialization
        pictureY = currentFrame.locationY;
        pictureX = currentFrame.locationX;

        // Iterate through the picture and apply changes
        for(iconIndex = 0; iconIndex < icon.width * icon.height; iconIndex++){

            // Change bit at position X,Y
            changeBitAt(&picture[(pictureY * WIDTH + pictureX) / WIDTH_DIV], 7 - (pictureX % WIDTH_DIV), getBitAt(icon.pixels[iconIndex / WIDTH_DIV], 7 - (iconIndex % WIDTH_DIV)));

            if(pictureX == currentFrame.locationX + icon.width - 1){
                pictureY++;
                pictureX = currentFrame.locationX;
            }
            else
                pictureX++;
            
        }
        
    }

}

Picture getPicture(void){

    Picture pic = {WIDTH / WIDTH_DIV, HEIGHT, picture};

    return pic;

}

void addBatteryFrame(uint8_t batPercentage){

    Frame batteryFrame;
    PictureFrames frames;

    batteryFrame.locationX = 108;
    batteryFrame.locationY = 3;

    if(batPercentage >= 0 && batPercentage < 10)
        batteryFrame.icon = getBatteryIcon0();
    else if(batPercentage >= 10 && batPercentage <= 25)
        batteryFrame.icon = getBatteryIcon25();
    else if(batPercentage > 25 && batPercentage <= 50)
        batteryFrame.icon = getBatteryIcon50();
    else if(batPercentage > 50 && batPercentage <= 75)
        batteryFrame.icon = getBatteryIcon75();
    else
        batteryFrame.icon = getBatteryIcon100();

    frames.numOfFrames = 1;
    frames.frames = &batteryFrame;

    appendFramesToPicture(frames);

}

void addCallFrame(void){

    Frame missedCallFrame;
    PictureFrames frames;

    missedCallFrame.locationX = 4;
    missedCallFrame.locationY = 3;

    missedCallFrame.icon = getMissedCallIcon();

    frames.numOfFrames = 1;
    frames.frames = &missedCallFrame;

    appendFramesToPicture(frames);

}

void removeCallFrame(void){

    Frame removeCallFrame;
    PictureFrames frames;

    removeCallFrame.locationX = 24;
    removeCallFrame.locationY = 3;

    removeCallFrame.icon = removeNotificationIcon();

    frames.numOfFrames = 1;
    frames.frames = &removeCallFrame;

    appendFramesToPicture(frames);

}

void addSmsFrame(void){

    Frame newSmsFrame;
    PictureFrames frames;

    newSmsFrame.locationX = 24;
    newSmsFrame.locationY = 3;

    newSmsFrame.icon = getNewSmsIcon();

    frames.numOfFrames = 1;
    frames.frames = &newSmsFrame;

    appendFramesToPicture(frames);

}

void removeSmsFrame(void){

    Frame removeSmsFrame;
    PictureFrames frames;

    removeSmsFrame.locationX = 24;
    removeSmsFrame.locationY = 3;

    removeSmsFrame.icon = removeNotificationIcon();

    frames.numOfFrames = 1;
    frames.frames = &removeSmsFrame;

    appendFramesToPicture(frames);

}

void addMailFrame(void){

    Frame newMailFrame;
    PictureFrames frames;

    newMailFrame.locationX = 44;
    newMailFrame.locationY = 3;

    newMailFrame.icon = getNewMailIcon();

    frames.numOfFrames = 1;
    frames.frames = &newMailFrame;

    appendFramesToPicture(frames);


}

void removeMailFrame(void){

    Frame removeMailFrame;
    PictureFrames frames;

    removeMailFrame.locationX = 44;
    removeMailFrame.locationY = 3;

    removeMailFrame.icon = removeNotificationIcon();

    frames.numOfFrames = 1;
    frames.frames = &removeMailFrame;

    appendFramesToPicture(frames);

}

static uint8_t getBitAt(uint8_t byte, uint8_t pos){

    return (byte >> pos) & 0x1; 

}

static void changeBitAt(uint8_t* byte, uint8_t pos, uint8_t val){

    *byte = (*byte & ~(1 << pos)) | (val << pos);   

}

