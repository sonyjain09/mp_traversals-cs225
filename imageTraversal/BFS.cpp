#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "BFS.h"

using namespace cs225;

BFS::BFS(const PNG & png, const Point & start, double tolerance) {  
  png_ = png;
  start_ = start;
  tolerance_ = tolerance;
  traversal.push(start);
  visited.resize(png.width());
  for(int i = 0; i < int(png.width()); i++) visited[i].resize(png.height(),false);
  visited[start.x][start.y] = true;
}

ImageTraversal::Iterator BFS::begin() {
  return ImageTraversal::Iterator(this, start_, tolerance_, png_);
}

ImageTraversal::Iterator BFS::end() {
  return ImageTraversal::Iterator();
}

void BFS::add(const Point & point) {
  traversal.push(point);
}

Point BFS::pop() {
  Point removed = traversal.front();
  traversal.pop();
  return removed;
}

Point BFS::peek() const {
  return traversal.front();
}

bool BFS::empty() const {
  return traversal.empty();
}

void BFS::markVisited(int x, int y){
  visited[x][y] = true;
}

bool BFS::isVisited(int x, int y) const{
  return visited[x][y];
}


