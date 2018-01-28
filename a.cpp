#include "iostream"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int g_ValudeSize = 1;
int size,x,y;

void on_filter(int , void *);

Mat scrImage = imread("a.jpg");

int main()
{
    namedWindow("各种滤波",1);
    createTrackbar("内核大小", "各种滤波", &g_ValudeSize, 10, on_filter);
    createTrackbar("x", "各种滤波", &x, 10, on_filter);
    createTrackbar("y", "各种滤波", &y, 10, on_filter); 

    on_filter(g_ValudeSize,0);

    waitKey();

    return 0;
}

void on_filter(int, void*)
{
    Mat dstImage(scrImage.size(),scrImage.type());
    size = g_ValudeSize*2 + 1;
    GaussianBlur(scrImage, dstImage,Size(size,size),x,y);
    imshow("各种滤波",dstImage);
}