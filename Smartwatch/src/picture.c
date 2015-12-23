#include "picture.h"

static void appendFramesToPicture(PictureFrames* pictureFrames);
static uint8_t getBitAt(uint8_t byte, uint8_t pos);
static void changeBitAt(uint8_t* byte, uint8_t pos, uint8_t val);

static uint8_t screenPicture[(WIDTH / WIDTH_DIV) * HEIGHT];

void getPicture(Picture* picture){

    picture->cols = WIDTH / WIDTH_DIV;
    picture->rows = HEIGHT;
    picture->pixels = screenPicture;

}

void addLogoFrame(void){

    Frame logoFrame;
    PictureFrames frames;
    
    logoFrame.locationX = logoFrame.locationY = 0;
    logoFrame.icon = getLogoIcon();

    frames.numOfFrames = 1;
    frames.frames = &logoFrame;

    appendFramesToPicture(&frames);

}

void addBatteryFrame(uint8_t batPercentage){

    Frame batteryFrame;
    PictureFrames frames;

    batteryFrame.locationX = 110;
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

    appendFramesToPicture(&frames);

}

void addCallFrame(void){

    Frame missedCallFrame;
    PictureFrames frames;

    missedCallFrame.locationX = 3;
    missedCallFrame.locationY = 3;

    missedCallFrame.icon = getMissedCallIcon();

    frames.numOfFrames = 1;
    frames.frames = &missedCallFrame;

    appendFramesToPicture(&frames);

}

void removeCallFrame(void){

    Frame removeCallFrame;
    PictureFrames frames;

    removeCallFrame.locationX = 3;
    removeCallFrame.locationY = 3;

    removeCallFrame.icon = removeNotificationIcon();

    frames.numOfFrames = 1;
    frames.frames = &removeCallFrame;

    appendFramesToPicture(&frames);

}

void addSmsFrame(void){

    Frame newSmsFrame;
    PictureFrames frames;

    newSmsFrame.locationX = 22;
    newSmsFrame.locationY = 3;

    newSmsFrame.icon = getNewSmsIcon();

    frames.numOfFrames = 1;
    frames.frames = &newSmsFrame;

    appendFramesToPicture(&frames);

}

void removeSmsFrame(void){

    Frame removeSmsFrame;
    PictureFrames frames;

    removeSmsFrame.locationX = 22;
    removeSmsFrame.locationY = 3;

    removeSmsFrame.icon = removeNotificationIcon();

    frames.numOfFrames = 1;
    frames.frames = &removeSmsFrame;

    appendFramesToPicture(&frames);

}

void addMailFrame(void){

    Frame newMailFrame;
    PictureFrames frames;

    newMailFrame.locationX = 42;
    newMailFrame.locationY = 3;

    newMailFrame.icon = getNewMailIcon();

    frames.numOfFrames = 1;
    frames.frames = &newMailFrame;

    appendFramesToPicture(&frames);


}

void removeMailFrame(void){

    Frame removeMailFrame;
    PictureFrames frames;

    removeMailFrame.locationX = 42;
    removeMailFrame.locationY = 3;

    removeMailFrame.icon = removeNotificationIcon();

    frames.numOfFrames = 1;
    frames.frames = &removeMailFrame;

    appendFramesToPicture(&frames);

}

void addHumidityFrame(uint8_t humidity){

    Frame framesArray[3];
    PictureFrames frames;
    uint8_t i;
    uint8_t digit;
    uint8_t coordX = 61;

    // Correct humidity
    if(humidity > 99)
        humidity = 99;

    // Set positions for digit frames. Set icons also
    for(i = 0; i < 3; i++, coordX+=8){
        framesArray[i].locationX = coordX;
        framesArray[i].locationY = 3;

        if(i == 0 || i == 1)
            digit = (i == 0) ? humidity / 10 : humidity % 10;
        else{
            framesArray[i].icon = getSmallPercentIcon();
            continue;
        }

        // Set icons for humidity
        switch(digit){
            case 0: framesArray[i].icon = getSmallZeroNumberIcon();break;
            case 1: framesArray[i].icon = getSmallOneNumberIcon();break;
            case 2: framesArray[i].icon = getSmallTwoNumberIcon();break;
            case 3: framesArray[i].icon = getSmallThreeNumberIcon();break;
            case 4: framesArray[i].icon = getSmallFourNumberIcon();break;
            case 5: framesArray[i].icon = getSmallFiveNumberIcon();break;
            case 6: framesArray[i].icon = getSmallSixNumberIcon();break;
            case 7: framesArray[i].icon = getSmallSevenNumberIcon();break;
            case 8: framesArray[i].icon = getSmallEightNumberIcon();break;
            case 9: framesArray[i].icon = getSmallNineNumberIcon();break;
        }
    
    }

    frames.numOfFrames = 3;
    frames.frames = framesArray;

    appendFramesToPicture(&frames);
    

}

void addTemperatureFrame(uint8_t temp){

    Frame framesArray[3];
    PictureFrames frames;
    uint8_t i;
    uint8_t digit;
    uint8_t coordX = 85;

    // Correct temperature
    if(temp > 60)    
        temp = 60;

    // Set positions for digit frames. Set icons also
    for(i = 0; i < 3; i++, coordX+=8){
        framesArray[i].locationX = coordX;
        framesArray[i].locationY = 3;

        if(i == 0 || i == 1)
            digit = (i == 0) ? temp / 10 : temp % 10;
        else{
            framesArray[i].icon = getSmallCelsiusIcon();
            continue;
        }

        // Set icons for temperature
        switch(digit){
            case 0: framesArray[i].icon = getSmallZeroNumberIcon();break;
            case 1: framesArray[i].icon = getSmallOneNumberIcon();break;
            case 2: framesArray[i].icon = getSmallTwoNumberIcon();break;
            case 3: framesArray[i].icon = getSmallThreeNumberIcon();break;
            case 4: framesArray[i].icon = getSmallFourNumberIcon();break;
            case 5: framesArray[i].icon = getSmallFiveNumberIcon();break;
            case 6: framesArray[i].icon = getSmallSixNumberIcon();break;
            case 7: framesArray[i].icon = getSmallSevenNumberIcon();break;
            case 8: framesArray[i].icon = getSmallEightNumberIcon();break;
            case 9: framesArray[i].icon = getSmallNineNumberIcon();break;
        }
    
    }

    frames.numOfFrames = 3;
    frames.frames = framesArray;

    appendFramesToPicture(&frames);
    

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

    appendFramesToPicture(&frames);
        
}

void addTimeFrame(uint8_t hours, uint8_t minutes){

    Frame framesArray[5];
    PictureFrames frames;
    uint8_t i;
    uint8_t digit;
    uint8_t coordX = 2;

    // Set positions for digit frames. Set icons also
    for(i = 0; i < 5; i++, coordX+=25){
        framesArray[i].locationX = coordX;
        framesArray[i].locationY = 80;

        if(i == 0 || i == 1)
            digit = (i == 0) ? hours / 10 : hours % 10;
        else if(i == 3 || i == 4)
            digit = (i == 3) ? minutes / 10 : minutes % 10;
        else{
            framesArray[i].icon = getBigColonIcon();
            continue;
        }

        // Set icons for day, month and year
        switch(digit){
            case 0: framesArray[i].icon = getBigZeroNumberIcon();break;
            case 1: framesArray[i].icon = getBigOneNumberIcon();break;
            case 2: framesArray[i].icon = getBigTwoNumberIcon();break;
            case 3: framesArray[i].icon = getBigThreeNumberIcon();break;
            case 4: framesArray[i].icon = getBigFourNumberIcon();break;
            case 5: framesArray[i].icon = getBigFiveNumberIcon();break;
            case 6: framesArray[i].icon = getBigSixNumberIcon();break;
            case 7: framesArray[i].icon = getBigSevenNumberIcon();break;
            case 8: framesArray[i].icon = getBigEightNumberIcon();break;
            case 9: framesArray[i].icon = getBigNineNumberIcon();break;
        }
    
    }

    frames.numOfFrames = 5;
    frames.frames = framesArray;

    appendFramesToPicture(&frames);

}

static void appendFramesToPicture(PictureFrames* pictureFrames){

    uint8_t frameIndex;
    short iconIndex, pictureX, pictureY;
    Frame currentFrame;

    // Iterate through frames
    for(frameIndex = 0; frameIndex < pictureFrames->numOfFrames; frameIndex++){
        
        // Extract current frame
        currentFrame = pictureFrames->frames[frameIndex];
        
        // X and Y initialization
        pictureY = currentFrame.locationY;
        pictureX = currentFrame.locationX;

        // Iterate through the picture and apply changes
        for(iconIndex = 0; iconIndex < currentFrame.icon.width * currentFrame.icon.height; iconIndex++){

            // Change bit at position X,Y
            changeBitAt(&screenPicture[(pictureY * WIDTH + pictureX) / WIDTH_DIV], 7 - (pictureX % WIDTH_DIV), getBitAt(currentFrame.icon.pixels[iconIndex / WIDTH_DIV], 7 - (iconIndex % WIDTH_DIV)));

            if(pictureX == currentFrame.locationX + currentFrame.icon.width - 1){
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

