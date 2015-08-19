//compile: g++ -o d1 device.cpp -lm `pkg-config --cflags --libs opencv` -fpermissive

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;

int countPicture = 0;

void writeImage(IplImage *image){
	char* str;

	//轉換並調整檔名
	sprintf(str, "%06d.png", countPicture++);
	cout<<"image name: "<<str<<endl;
	cvSaveImage(str, image);
}
 
int main()
{
    CvCapture *capture;
    IplImage *frame;
    char AviFileName[]="Output.avi";
    capture = cvCaptureFromAVI(AviFileName);
    //得到總幀數
    int frames = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
    //獲得幀率
    int fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
    cout<<"frames:"<<frames<<endl;
    cout<<"fps:"<<fps<<endl;
    cvNamedWindow("Video Player",0);
	int frameCounte = 0;
 
    while(true)
    {
        if(cvGrabFrame(capture))
        {
            frame=cvRetrieveFrame(capture);
            cvShowImage("Video Player",frame);
 
            if(cvWaitKey(50)>=0) break;
			if(!(frameCounte%10)){
				cout<<"write image"<<endl;
				writeImage(frame);
			}
			frameCounte++;
        }
        else
        {
            break;
        }
    }
    cvReleaseCapture(&capture);
    cvDestroyWindow("Video Player");
    return 0;
}
