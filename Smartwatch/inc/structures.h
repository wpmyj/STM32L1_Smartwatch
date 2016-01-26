#ifndef STRUCTURES_H
#define STRUCTURES_H

// Icon structures

typedef struct Icon{

    short width;
    short height;
    const uint8_t *pixels;

} Icon;

// Picture structures

typedef struct Frame{

    short locationX; // Location of a frame
    short locationY;
    Icon icon; // Icon structure

 } Frame;

typedef struct PictureFrames{

    uint8_t numOfFrames;
    Frame *frames;

} PictureFrames;

typedef struct Picture{

    short cols; // Number of bytes per row
    short rows;  // Number of rows
    const uint8_t* pixels;

}Picture;

// Time structures

typedef struct Time{

    // Calendar
    uint8_t day;
    uint8_t month;
    uint8_t year;

    // Time
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;

} Time;

// Sensor structures

typedef struct Sensor{

    uint8_t temperature;
    uint8_t humidity;

}Sensor;

#endif
