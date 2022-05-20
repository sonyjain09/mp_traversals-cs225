/**
 * @file DFS.h
 */

#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

using namespace cs225;

class DFS : public ImageTraversal {
public:
  DFS(const PNG & png, const Point & start, double tolerance);

  ImageTraversal::Iterator begin();
  ImageTraversal::Iterator end();

  void add(const Point & point);
  Point pop();
  Point peek() const;
  bool empty() const;
  void markVisited(int x, int y);
  bool isVisited(int x, int y) const;

private:
	/** @todo [Part 1] */
	/** add private members here*/
  PNG png_;
  Point start_;
  double tolerance_;
  Point current; 
  std::stack<Point> traversal;
  std::vector<std::vector<bool>> visited;
};
