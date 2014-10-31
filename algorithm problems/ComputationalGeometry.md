# dot product
* cosθ
# cross product
* area, counter clockwise
* distance between point and segment
# point in polygon
* randomly select a far point p2, count the number of intersections between
  segment (p, p2) and all the segments of the polygon. If even, then p is
  exterior, otherwise p is interior.
# convex hull
* Graham scan
** first choose the leftmost one, then sort all points by its polar angle with
    this point
** then check according to the points with sort order.

