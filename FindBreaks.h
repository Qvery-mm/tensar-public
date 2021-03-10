/******************************************************************************

* File: FindBreaks.h
* Description: Find Breaks on grid image.
* Created: 6 feb 2020
* Author: Aleksandr Kovalchukov
* Email: aleksandr.kovalchukov@mail.ru

******************************************************************************/

#ifndef WORKSHOP_FINDBREAKS_H
#define WORKSHOP_FINDBREAKS_H

#include <opencv2/opencv.hpp>
#include <vector>
#include <wiringPi.h>


class LatticeBreak {
public:
    int x, y;
    LatticeBreak(int _x, int _y) {x = _x, y = _y;}
};

class WhiteEdge {
public:
    WhiteEdge(int _posX, int _startY, int _straight)
    {
        posX = _posX;
        startY = _startY;
        straight = _straight;
    }

    int posX;
    int startY;
    int straight;

    static bool cmp(WhiteEdge a, WhiteEdge b) {return a.straight > b.straight;}

};


class BreaksExtractor {

public:
    /**
     * Find and returns breaks on grid.
     * @param grayscaleImage - cv::Mat image, where expected lattice
     */
    void FindBreaks(cv::Mat grayscaleImage);

    /**
     * Draw circles around breaks
     * @param img - cv::Mat object
     * @param breaks - vector of breaks
     */
    void DrawCircles(cv::Mat img, std::vector<LatticeBreak> breaksList);

    std::vector<LatticeBreak> breaksList;


private:
    std::vector<WhiteEdge> whiteEdgesList;
    int width;
    int height;
};

#endif //WORKSHOP_FINDBREAKS_H
