#include "picture.h"

static void appendFramesToPicture(PictureFrames pictureFrames);
static uint8_t getBitAt(uint8_t byte, uint8_t pos);
static void changeBitAt(uint8_t* byte, uint8_t pos, uint8_t val);

static uint8_t picture[(WIDTH / WIDTH_DIV) * HEIGHT];


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

void addDateFrame(uint8_t day, uint8_t month, uint8_t year){

    Frame framesArray[8];
    PictureFrames frames;
    uint8_t i;
    uint8_t digit;
    uint8_t coordX = 1;

    // Set positions for digit frames. Set icons also
    for(i = 0; i < 8; i++, coordX+=16){
        framesArray[i].locationX = coordX;
        framesArray[i].locationY = 30;

        if(i == 0 || i == 1)
            digit = (i == 0) ? day / 10 : day % 10;
        else if(i == 3 || i == 4)
            digit = (i == 3) ? month / 10 : month % 10;
        else if(i == 6 || i == 7)
            digit = (i == 6) ? year / 10 : year % 10;
        else{
            framesArray[i].icon = getMediumDotIcon();
            continue;
        }

        // Set icons for day, month and year
        switch(digit){
            case 0: framesArray[i].icon = getMediumZeroNumberIcon();break;
            case 1: framesArray[i].icon = getMediumOneNumberIcon();break;
            case 2: framesArray[i].icon = getMediumTwoNumberIcon();break;
            case 3: framesArray[i].icon = getMediumThreeNumberIcon();break;
            case 4: framesArray[i].icon = getMediumFourNumberIcon();break;
            case 5: framesArray[i].icon = getMediumFiveNumberIcon();break;
            case 6: framesArray[i].icon = getMediumSixNumberIcon();break;
            case 7: framesArray[i].icon = getMediumSevenNumberIcon();break;
            case 8: framesArray[i].icon = getMediumEightNumberIcon();break;
            case 9: framesArray[i].icon = getMediumNineNumberIcon();break;
        }
    
    }

    frames.numOfFrames = 8;
    frames.frames = framesArray;

    appendFramesToPicture(frames);
        
}

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

static uint8_t getBitAt(uint8_t byte, uint8_t pos){

    return (byte >> pos) & 0x1; 

}

static void changeBitAt(uint8_t* byte, uint8_t pos, uint8_t val){

    *byte = (*byte & ~(1 << pos)) | (val << pos);   

}

