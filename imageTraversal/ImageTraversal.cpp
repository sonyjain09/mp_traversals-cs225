#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;
  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;
  return sqrt( (h*h) + (s*s) + (l*l) );
}

ImageTraversal::Iterator::Iterator(){
  /** @todo [Part 1] */
  traversal = NULL;
}

ImageTraversal::Iterator::Iterator(ImageTraversal* t, Point s, double tol, PNG& p): traversal(t){
  start = s;
  png = p;
  tolerance = tol;
  current = traversal->peek();
}

bool ImageTraversal::Iterator::isInRange(int width, int height, int checkX, int checkY){
  return (checkX < width and checkX >= 0 and checkY < height and checkY >= 0);
}

void ImageTraversal::Iterator::addToTraversal(Point insert){
  HSLAPixel& compare = png.getPixel(start.x, start.y);
  HSLAPixel& potential = png.getPixel(insert.x, insert.y);
  double delta = calculateDelta(compare,potential);
  if(delta < tolerance) traversal->add(insert);
}

ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  //Initialize current as startPoint
  Point curr = current;
  // Mark current as visited.
  traversal->markVisited(curr.x, curr.y);
  //Push current and neighbors(current) to S - R, D, L, U.
  int width = png.width();
  int height = png.height();
  if(isInRange(width,height,curr.x+1,curr.y)){
    Point right(curr.x+1,curr.y);
    addToTraversal(right);
  }
  if(isInRange(width,height,curr.x,curr.y+1)){
    Point down(curr.x,curr.y+1);
    addToTraversal(down);
  }
  if(isInRange(width,height,curr.x-1,curr.y)){
    Point left(curr.x-1,curr.y);
    addToTraversal(left);
  }
  if(isInRange(width,height,curr.x,curr.y-1)){
    Point up(curr.x,curr.y-1);
    addToTraversal(up);
  }
  //Until S is empty or point is not visited and within tolerance, point = S.pop()
  while(!(traversal->empty()) and (traversal->isVisited(curr.x,curr.y))) curr = traversal->pop();
  //If S is not empty. Set current = point. Go to step 3.
  if(!(traversal->empty())) current = curr;
  //If S is empty then we are done
  return *this;
}

Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current;
}

bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  bool thisEmpty = traversal != NULL ? traversal -> empty() : true;
	bool otherEmpty = other.traversal != NULL ? other.traversal -> empty() : true;
	return !(thisEmpty and otherEmpty);
}


