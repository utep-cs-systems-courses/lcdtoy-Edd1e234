#include "visualLayers.h"
#include <shape.h>
#include <lcdutils.h>
#include <lcddraw.h> 

// Outer stuff. Looks about done.
const AbRectOutline fieldOutline  = {abRectOutlineGetBounds, abRectOutlineCheck, {(screenWidth/2)-10, (screenHeight/2)-10}
}; 
const Layer fieldLayer = {
  (AbShape *)&fieldOutline, {(screenWidth/2), (screenHeight/2)}, {0,0}, {0,0},
  COLOR_BLACK, 0
};
Region fieldFence; 
