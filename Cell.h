//
//  Cell.h
//  Practical 4.5
//
//  Created by Otgonbileg on 10/9/2023.
//  SID :22037760
//
/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.
I hold a copy of this assignment that I can produce if the original
is lost or damaged.
**************************/

#ifndef CELL_H_
#define CELL_H_

struct Cell {
    int x;
    int y;
    double heuristic;

    Cell(int xx, int yy, double hh):x(xx), y(yy), heuristic(hh) {}

    bool operator<(const Cell& c) const {
        return heuristic < c.heuristic;
    }
};

#endif /* CELL_H_ */
