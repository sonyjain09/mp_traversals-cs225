/**
 * @file BFS.h
 */

#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

using namespace cs225;

class BFS : public ImageTraversal {
public:
  BFS(const PNG & png, const Point & start, double tolerance);

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
  std::queue<Point> traversal;
  std::vector<std::vector<bool>> visited;
};

