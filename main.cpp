/******************************************************************************

* File: main.cpp
* Description: Startup point of application.
* Created: 10 sep 2019
* Author: Aleksandr Kovalchukov
* Email: aleksandr.kovalchukov@mail.ru

******************************************************************************/


#include "Interface.h"
#include "PrepareImage.h"
#include "FindLines.h"
#include "FindBreaks.h"
#include "experimental.h"
#include "configuration.h"


int main(int argc, char** argv )
{
    //Threshold();
    /**
     * see configuration file for fine tuning
     */
    LoadConfiguration();

    GUI myGUI;
    myGUI.create();
    
    wiringPiSetup();			// Setup the library
    pinMode(BREAK_SIGNAL_PIN, OUTPUT);
    pinMode(LINE_SIGNAL_PIN, OUTPUT);

    /** main loop of application */
    while (true)
    {
        /** Capture frame-by-frame */
        myGUI.getCapture();

        /** make some transformation */
        cv::Mat processedImage = prepareImage(myGUI.frame, myGUI.alpha / 100.0, -myGUI.beta, myGUI.depth);

        /** Finding edges */
        EdgeExtractor edgeExtractor{};
        edgeExtractor.FindLines(processedImage, myGUI.maxLinesCount);

        /** Finding breaks */
        BreaksExtractor breaksExtractor{};
        breaksExtractor.FindBreaks(processedImage);
        breaksExtractor.DrawCircles(processedImage, breaksExtractor.breaksList);

        /** Press  ESC on keyboard to  exit */
        auto c = (char) cv::waitKey(1);
        if (c == 27)
            break;
    }

    return 0;
}


