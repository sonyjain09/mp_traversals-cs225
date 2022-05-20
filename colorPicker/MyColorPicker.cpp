#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  HSLAPixel dark(271,38,43,1);
  HSLAPixel light(271,38,81,1);
  //if both are even return dark purple pixel
  //else return light purple pixel
  if(x%2==0 and y%2==0) return dark;
  else return light;
}
