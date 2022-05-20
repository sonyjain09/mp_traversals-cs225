#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"

DFS::DFS(const PNG & png, const Point & start, double tolerance){  
  png_ = png;
  start_ = start;
  tolerance_ = tolerance;
  traversal.push(start);
  visited.resize(png.width());
  for(int i = 0; i < int(png.width()); i++) visited[i].resize(png.height(),false);
  visited[start.x][start.y] = true;
}

ImageTraversal::Iterator DFS::begin() {
  //ask ab just returning *this or need to make new DFS object
  return ImageTraversal::Iterator(this, start_, tolerance_, png_);
}

ImageTraversal::Iterator DFS::end() {
  return ImageTraversal::Iterator();
}

void DFS::add(const Point & point) {
  traversal.push(point);
}

Point DFS::pop() {
  Point removed = traversal.top();
  traversal.pop();
  return removed;
}

Point DFS::peek() const {
  return traversal.top();
}

bool DFS::empty() const {
  return traversal.empty();
}

void DFS::markVisited(int x, int y){
  visited[x][y] = true;
}

bool DFS::isVisited(int x, int y) const{
  return visited[x][y];
}

