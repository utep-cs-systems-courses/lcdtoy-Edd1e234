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

const AbRectOutline headOutline = {abRectOutlineGetBounds, abRectOutlineCheck, {30, 24}};

Layer headLayerOutline = {
  (AbShape *)&headOutline,
  {75, 85}, {0,0}, {0,0},
  COLOR_BLACK, &mainOrangeLayer
}; 
const AbRect head = {abRectGetBounds, abRectCheck, {29, 23}};

Layer headLayer = {
  (AbShape *)&head,
  {75, 85}, {0,0}, {0,0}, COLOR_BLUE,
  &headLayerOutline
}; 

// Outer stuff. Looks about done.
const AbRectOutline fieldOutline  = {abRectOutlineGetBounds, abRectOutlineCheck,
				     {(screenWidth/2)-10, (screenHeight/2)-10}
}; 
Layer fieldLayer = {
  (AbShape *)&fieldOutline, {(screenWidth/2), (screenHeight/2)}, {0,0}, {0,0},
  COLOR_BLACK, &headLayer
};
Region fieldFence; 
