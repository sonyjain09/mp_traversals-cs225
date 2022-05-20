#include "cs225/PNG.h"
#include <list>
#include <iostream>

#include "colorPicker/ColorPicker.h"
#include "imageTraversal/ImageTraversal.h"

#include "Point.h"
#include "Animation.h"
#include "FloodFilledImage.h"

using namespace cs225;

FloodFilledImage::FloodFilledImage(const PNG & png){
  /** @todo [Part 2] */
  png_ = png;
}

void FloodFilledImage::addFloodFill(ImageTraversal & traversal, ColorPicker & colorPicker) {
  /** @todo [Part 2] */
  ImageTraversal* trav = &traversal;
  ColorPicker* col = &colorPicker;
  travs.push_back(trav);
  colPicks.push_back(col);
}

Animation FloodFilledImage::animate(unsigned frameInterval) const {
  PNG output = png_;
  Animation animation;
  int count = 0;
  for(unsigned i = 0; i < travs.size(); i++){
    for(Point p : *travs[i]){
      if(count % frameInterval == 0) animation.addFrame(output);
      count++;
      output.getPixel(p.x,p.y) = colPicks[i]->getColor(p.x,p.y);
    } 
  }
  animation.addFrame(output);
  return animation;
}
