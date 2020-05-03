#include "visualLayers.h"
#include <shape.h>
#include <lcdutils.h>
#include <lcddraw.h> 

// Orange hair section. 
const AbRect mainOrangeBlobRect = {abRectGetBounds, abRectCheck, {42, 50}};

Layer mainOrangeLayer = {
  (AbShape *)&mainOrangeBlobRect, {68, 80},
  {0,0}, {0, 0},
  COLOR_ORANGE, &mainGreenLayer
}; 

// Green backGround
const AbRect mainGreenBlobRect = {abRectGetBounds, abRectCheck,
				  {(screenWidth/2)-11, (screenHeight/2)-11}};
Layer mainGreenLayer = {
  (AbShape *)&mainGreenBlobRect, {screenWidth/2, screenHeight/2},
    {0,0}, {0,0}, COLOR_SPRING_GREEN, 0
};

// This will be the head stuff

const AbRectOutline headOutline = {abRectOutlineGetBounds, abRectOutlineCheck, {30, 26}};

Layer headLayerOutline = {
  (AbShape *)&headOutline,
  {75, 85}, {0,0}, {0,0},
  COLOR_BLACK, &mainOrangeLayer
}; 
const AbRect head = {abRectGetBounds, abRectCheck, {29, 25}};

Layer headLayer = {
  (AbShape *)&head,
  {75, 85}, {0,0}, {0,0},
  COLOR_ROYAL_BLUE,
  &headLayerOutline
};

//Shoulder Code. 

const AbRect shoulder = {abRectGetBounds, abRectCheck, {10, 30}};

Layer shoulderLayer = {
  (AbShape *)&shoulder,
  {20, 70}, {0,0}, {0,0},
  COLOR_ROYAL_BLUE, &headLayer
}; 

const AbRect neck = {abRectGetBounds, abRectCheck, {15, 12}};

Layer neckLayer = {
  (AbShape *)&neck,
  {29, 88}, {0,0}, {0,0},
  COLOR_ROYAL_BLUE, &shoulderLayer
}; 

// Outer stuff. Looks about done.
const AbRectOutline fieldOutline  = {abRectOutlineGetBounds, abRectOutlineCheck,
				     {(screenWidth/2)-10, (screenHeight/2)-10}
}; 
Layer fieldLayer = {
  (AbShape *)&fieldOutline, {(screenWidth/2), (screenHeight/2)}, {0,0}, {0,0},
  COLOR_BLACK, &neckLayer
};
Region fieldFence; 


void drawFace() {
  unsigned char eye_y = 95;
  unsigned char eye_x = 88;
  unsigned char sideLength = 10; 

  // Pupuils
  fillRectangle(eye_x, eye_y, sideLength, sideLength, COLOR_WHITE);
  fillRectangle(eye_x, eye_y-30, sideLength, sideLength, COLOR_WHITE);

  sideLength = sideLength/2;
  fillRectangle(eye_x+2, eye_y+5, sideLength, sideLength, COLOR_DARK_OLIVE_GREEN);
  fillRectangle(eye_x+2, eye_y-25, sideLength, sideLength, COLOR_DARK_OLIVE_GREEN); 
}




