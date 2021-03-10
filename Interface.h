/******************************************************************************

* File: Interface.h
* Description: Provides graphical interface for the application.
* Created: 10 sep 2019
* Author: Aleksandr Kovalchukov
* Email: aleksandr.kovalchukov@mail.ru

******************************************************************************/

#ifndef WORKSHOP_INTERFACE_H
#define WORKSHOP_INTERFACE_H


#include <opencv2/highgui.hpp>
#include <string>

class GUI
{
public:
    /**
    * Creates GUI with image and some adjustments.
    */
    void create();

    /**
    * Get capture from camera
     * @param camera - number of camera (default 0)
    */
    void getCapture();

    /** main frame */
    cv::Mat frame;

    /** constants for future usage (see AlphaBetaTransformation and EdgeExtractor) */
    int alpha = 200, beta = 100, depth = 3, maxLinesCount = 7;

protected:
    /**
    * Creates TrackBar on image.
    * @param windowName - string object corresponding current window name.
    * @param alpha - alpha value in brightness transformation
    * @param beta - beta value in brightness transformation
    * @param depth - total count applying brightness transformation
    * @param maxLinesCount - maximum edges shown at the same time on screen
    * @note Brightness transformation procedure replaces value of every pixel with "alpha * x + beta", where x is initial value of brightness. The procedure repeats "depth" times.
    */
    static void CreateTrackBar(const std::string *windowName, int *alpha, int *beta, int *depth, int *maxLinesCount);

    /**
    * Creates Capture object and initialize imageWidth and imageHeight variables.
    */
    void CreateCapture();

    int imageWidth;
    int imageHeight;


    cv::VideoCapture capture;

};

#endif //WORKSHOP_INTERFACE_H


