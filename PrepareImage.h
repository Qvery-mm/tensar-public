

#ifndef WORKSHOP_PREPAREIMAGE_H
#define WORKSHOP_PREPAREIMAGE_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>


/**
 *
 * @param inputImage - cv::Mat input image
 * @param alpha - value getting from GUI
 * @param beta - value getting from GUI
 * @param depth - value getting from GUI
 * @return Transformed cv::Mat image
 */
cv::Mat prepareImage(cv::Mat inputImage, double alpha, int beta, int depth);

#endif //WORKSHOP_PREPAREIMAGE_H
