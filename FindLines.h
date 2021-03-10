/******************************************************************************

* File: FindLines.h
* Description: Find Lines on grid image.
* Created: 10 sep 2019
* Author: Aleksandr Kovalchukov
* Email: aleksandr.kovalchukov@mail.ru

******************************************************************************/

#ifndef WORKSHOP_FINDLINES_H
#define WORKSHOP_FINDLINES_H

#include <opencv2/opencv.hpp>
#include <vector>
#include <wiringPi.h>


class VerticalEdge
{

public:
    /**
     * Target color: BLACK or WHITE
     */
    int color;
    /**
     * position from left border of picture.
     * possible values from 0 to width of image
     */
    int position;

    /**
     * count of targeting pixels
     */
    int lenght;

};


class EdgeExtractor {

public:
    /**
     * Find and returns lines on grid.
     * @param img - cv::Mat image, where expected grid with edges
     * @param alpha - value getting from GUI
     * @param beta - value getting from GUI
     * @param depth - value getting from GUI
     * @param maxLinesCount - value getting from GUI
     * @note Current implementation support only vertical edges; For more details about alpha, beta, depth and
     * maxLinesCount params see GUI documentation.
     */
    void FindLines(const cv::Mat& img, int maxLinesCount);


protected:
    /**
     * Draws vertical lines on given image
     * @param img - cv::Mat object
     * @param lines - cols with supposed edges as vector of integers from 0 to imageWidth - 1
     */
    static void DrawLines(cv::Mat img, std::vector<int> lines);

    /**
     * Shows the image with highlighted edges
     * @param windowName
     * @param grayImage
     * @param lines - vector of known edges
     */
    static void visualize(const std::string& windowName, cv::Mat &grayImage, std::vector<int> lines);

private:
    /**
     * Internal comparator
     */
    static bool cmp(std::pair<int, int> a, std::pair<int, int> b);
    /**
     * changes pixel value as following "depth" times: x' = alpha * x + beta
     */
    int width;
    int height;
};

#endif //WORKSHOP_FINDLINES_H
