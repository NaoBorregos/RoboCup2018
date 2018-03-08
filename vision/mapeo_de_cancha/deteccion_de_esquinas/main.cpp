/*
 Team: TEC-AI
 Data: February 25th, 2018
 Description:
 This program is used to process the soccer field. The process is the following:
 - Remove the unnecessary information
 Based on:
 https://www.dutchnaoteam.nl/publications/gudi2013feature.pdf
 https://stackoverflow.com/questions/35866411/opencv-how-to-detect-lines-of-a-specific-colour
 http://opencvpython.blogspot.mx/2012/07/background-extraction-using-running.html
 */

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void fieldDetection(char* imageName)
{
    cout << "Field detection.\n";
    
    bool greenFound = false;
    
    IplImage* imageSrc = cvLoadImage(imageName,1);
    IplImage* imageP1 = cvCreateImage(cvGetSize(imageSrc),8,3);
    IplImage* imageP2 = cvCreateImage(cvGetSize(imageSrc),8,3);
    IplImage* imageP3 = cvCreateImage(cvGetSize(imageSrc),8,3);
    IplImage* imageP4 = cvCreateImage(cvGetSize(imageSrc),8,3);
    IplImage* imageP6 = cvCreateImage(cvGetSize(imageSrc),8,3);
    
    CvScalar matrixSrc, matrixP1, matrixP2, matrixP2a, matrixP3, matrixP4, matrixP4b, matrixP6;
    
    // Show: The image source
    cvShowImage("Source", imageSrc);
    
    // P1: Try to delect the background
    for (int i=0; i < (imageSrc->width); i++)
    {
        for(int j=0; j < (imageSrc->height); j++)
        {
            matrixSrc = cvGet2D(imageSrc,j,i);
            if ( !greenFound )
            {
                // Configure Green Color Range
                if ( (matrixSrc.val[2] > 85 && matrixSrc.val[2] < 150) && (matrixSrc.val[1] > 120 && matrixSrc.val[1] < 190) && (matrixSrc.val[0] > 70 && matrixSrc.val[0] < 110) )
                {
                    greenFound = true;
                }
                else
                {
                    matrixP1.val[2]=0;
                    matrixP1.val[1]=0;
                    matrixP1.val[0]=0;
                    cvSet2D(imageP1,j,i,matrixP1);
                }
            }
            else
            {
                matrixP1.val[2] = matrixSrc.val[2];
                matrixP1.val[1] = matrixSrc.val[1];
                matrixP1.val[0] = matrixSrc.val[0];
                cvSet2D(imageP1,j,i,matrixP1);
            }
        }
        greenFound = false;
    }
    
    // Show: Image phase 1
    cvShowImage("Phase 1", imageP1);
    
    // P2: Try to detect white objects on the soccer field
    for (int i=0; i < (imageSrc->width); i++)
    {
        for(int j=0; j < (imageSrc->height); j++)
        {
            matrixP2 = cvGet2D(imageP1,j,i);
            matrixP2a = matrixP2;
            
            if ( j+1 < (imageSrc->height) )
            {
                matrixP2 = cvGet2D(imageP1, j+1, i);
            }
            
            if ( (matrixP2.val[2]>185) && (matrixP2.val[1]>185) && (matrixP2.val[0]>185) && (matrixP2a.val[2]>185) && (matrixP2a.val[1]>185) && (matrixP2a.val[0]>185) )
            {
                matrixP2.val[2]=255;
                matrixP2.val[1]=0;
                matrixP2.val[0]=0;
                cvSet2D(imageP2,j,i,matrixP2);
            }
            else
            {
                matrixP2.val[2]=255;
                matrixP2.val[1]=255;
                matrixP2.val[0]=255;
                cvSet2D(imageP2,j,i,matrixP2);
            }
        }
    }
    
    // Show: Image phase 2
    cvShowImage("Phase 2", imageP2);
    
    // P3: Detect white lines on the soccer field
    for (int i=0; i < (imageSrc->width); i++)
    {
        for(int j=0; j < (imageSrc->height); j++)
        {
            matrixP3 = cvGet2D(imageP1,j,i);
            
            if ( (matrixP3.val[2]>185) && (matrixP3.val[1]>185) && (matrixP3.val[0]>185) )
            {
                matrixP3.val[2]=255;
                matrixP3.val[1]=0;
                matrixP3.val[0]=0;
                cvSet2D(imageP3,j,i,matrixP3);
            }
            else
            {
                matrixP3.val[2]=255;
                matrixP3.val[1]=255;
                matrixP3.val[0]=255;
                cvSet2D(imageP3,j,i,matrixP3);
            }
        }
    }
    
    // Show: Image phase 3
    cvShowImage("Phase 3", imageP3);
    
    // P4: Remove objects from the field taking as base the image of the phase 3
    for (int i=0; i < (imageSrc->width); i++)
    {
        for(int j=0; j < (imageSrc->height); j++)
        {
            matrixP4 = cvGet2D(imageP3,j,i);
            matrixP4b = cvGet2D(imageP2,j,i);
            
            //cout << matrixP4b.val[2] << matrixP4b.val[1] << matrixP4b.val[0] << endl;
            
            if ( (matrixP4b.val[2]==255) && (matrixP4b.val[1]==0) && (matrixP4b.val[0]==0) )
            {
                matrixP4.val[2]=255;
                matrixP4.val[1]=255;
                matrixP4.val[0]=255;
                cvSet2D(imageP4,j,i,matrixP4);
            }
            else {
                cvSet2D(imageP4,j,i,matrixP4);
            }
        }
    }
    
    // Show: Image phase 4
    cvShowImage("Phase 4", imageP4);
    
    // P5: Detecct lines
    // Pre-process the image
    Mat matPhase5 = cvarrToMat(imageP2);
    Mat hsvImage;
    cvtColor(matPhase5, hsvImage, CV_BGR2HSV);
    vector<Mat> hsvChannels;
    split(hsvImage, hsvChannels);
    
    int hueValue = 0;
    int hueRange = 15;
    int minSaturation = 50;
    int minValue = 50;
    
    Mat hueImage = hsvChannels[0];
    
    Mat hueMask;
    inRange(hueImage, hueValue - hueRange, hueValue + hueRange, hueMask);
    
    if (hueValue - hueRange < 0 || hueValue + hueRange > 180)
    {
        Mat hueMaskUpper;
        int upperHueValue = hueValue + 180;
        inRange(hueImage, upperHueValue - hueRange, upperHueValue + hueRange, hueMaskUpper);
        hueMask = hueMask | hueMaskUpper;
    }
    
    Mat saturationMask = hsvChannels[1] > minSaturation;
    Mat valueMask = hsvChannels[2] > minValue;
    
    hueMask = (hueMask & saturationMask) & valueMask;
    
    // Start line detection
    vector<Vec4i> lines;
    HoughLinesP(hueMask, lines, 1.5, CV_PI / 180, 55, 35, 4);
    
    vector<double> slopesDetected;
    vector<Vec4i> finalLines;
    double slopeCurrentLine;
    int islopeCurrentLine;
    
    for (unsigned int i = 0; i < lines.size(); ++i)
    {
        // Calculate the slope of the current line
        slopeCurrentLine = double(lines[i][3] - lines[i][1]) / double(lines[i][2] - lines[i][0]);
        islopeCurrentLine = slopeCurrentLine * 100;
        slopeCurrentLine = islopeCurrentLine / 100.0;
        
        // Look if the slope of the current line is already on the vector of final lines
        int x = -1;
        for (int j = 0; j < slopesDetected.size(); j++)
        {
            if ((slopesDetected[j] - 0.20 < slopeCurrentLine) && (slopesDetected[j] + 0.20 > slopeCurrentLine))
            {
                x = j;
            }
        }
        
        if (x == -1)
        {
            slopesDetected.push_back(slopeCurrentLine);
            finalLines.push_back(lines[i]);
        }
        else
        {
            /*double slopeTwoLines = double(finalLines[x][3] - lines[i][1]) / double(finalLines[x][2] - lines[i][0]);
            if ((slopeTwoLines >= slopeCurrentLine - 0.025) && (slopeTwoLines <= slopeCurrentLine + 0.025))
            {
                if (lines[i][0] < finalLines[x][0])
                {
                    finalLines[x][0] = lines[i][0];
                    finalLines[x][1] = lines[i][1];
                }
                if (lines[i][3] > finalLines[x][3])
                {
                    finalLines[x][2] = lines[x][2];
                    finalLines[x][3] = lines[x][3];
                }
            } else {
                slopesDetected.push_back(slopeCurrentLine);
                finalLines.push_back(lines[i]);
            }*/
        }
        
        // Draw the lines in the vector lines
        //line(matPhase5, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(255, 0, 0), 5);
        
    }
    
    // Draw the lines in the vector finalLines
    for (unsigned int i = 0; i < finalLines.size(); i++)
    {
        line(matPhase5, Point(finalLines[i][0], finalLines[i][1]), Point(finalLines[i][2], finalLines[i][3]), Scalar(255, 0, 0), 5);
    }
    
    // Show: Image phase 5
    imshow("Phase 5", matPhase5);
    
    // P6: Keep only the possible lines of the soccer field
    IplImage* imagePP6aux = cvCreateImage(cvSize(matPhase5.cols, matPhase5.rows), 8, 3);
    IplImage imageP6aux = matPhase5;
    cvCopy(&imageP6aux, imagePP6aux);
    
    for (int i=0; i < (imageSrc->width); i++)
    {
        for(int j=0; j < (imageSrc->height); j++)
        {
            matrixP6 = cvGet2D(imagePP6aux,j,i);
            
            if ( (matrixP6.val[2]==255) && (matrixP6.val[1]==0) && (matrixP6.val[0]==0) )
            {
                matrixP6.val[2]=255;
                matrixP6.val[1]=255;
                matrixP6.val[0]=255;
                cvSet2D(imageP6,j,i,matrixP6);
            }
            else {
                cvSet2D(imageP6,j,i,matrixP6);
            }
        }
    }
    
    // Show: Image phase 6
    cvShowImage("Phase 6", imageP6);
}

int main()
{
    char name[]="./data/defensa/3.png";
    fieldDetection(name);
    cvWaitKey();
    return 0;
}
