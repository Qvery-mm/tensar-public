/******************************************************************************
* File: configuration.cpp
* Description: Global constants of application
* Created: 06 feb 2020
* Author: Aleksandr Kovalchukov
* Email: aleksandr.kovalchukov@mail.ru

******************************************************************************/

#ifndef WORKSHOP_CONFIGURATION_H
#define WORKSHOP_CONFIGURATION_H

#include <string>

#define BLUE cv::Scalar(255, 0, 0)
#define RED cv::Scalar(0, 0, 255)
#define GREEN cv::Scalar(0, 255, 0)
#define YELLOW cv::Scalar(0, 255, 255)

extern std::string MODE; // debug \ realise
extern std::string DEBUG_FILENAME;
extern std::string ORIENTATION; //vertical \ horizontal
extern int BLACK_PIXEL_THRESHOLD; // 0 - 255
extern int MINIMAL_DISTANCE_BETWEEN_LINES; //pixels
extern float IS_LINE_THRESHOLD; // % of black pixels on line
extern int MAX_WHITE_LINE_STRAIGHT;
extern int BREAK_SIGNAL_PIN;
extern int LINE_SIGNAL_PIN;
extern int MIN_X;
extern int MAX_WIDTH;
extern int MIN_Y;
extern int MAX_HEIGHT;
extern int BLACK_LINE_POSITION;
extern int MIN_HUE;
extern int MAX_HUE;
extern int MIN_SATURATION;
extern int MAX_SATURATION;
extern int MIN_VALUE;
extern int MAX_VALUE;
void LoadConfiguration();

#endif //WORKSHOP_CONFIGURATION_H
