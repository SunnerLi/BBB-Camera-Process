#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>
#define NUMBER_OF_IMAGE 50
using namespace std;

int imageCounter = 1, timer = 0;

void Decide_Image_Name(IplImage* image){
	char *s;
	cout<<imageCounte<<endl;
	sprintf(s, "%06d.png", imageCounter++);
	cout<<imageCounte<<endl;
	cvSaveImage(s, image, 0);
}

void Capture_Image(IplImage* image, CvCapture* capture){
	int i;
	char *s;
	while( imageCounter < NUMBER_OF_IMAGE ){
		image = cvQueryFrame(capture);
		cvWaitKey(10000);
		timer++;
		if( timer == 10){
			timer = 0;
			cout<<"capture!"<<endl;
			Decide_Image_Name(image);
		}
	}
}

int main(){
	//variable declaration
	IplImage *img;
	int i;
	CvCapture *capture = 0;

	//assign the property about camera
	capture = cvCaptureFromCAM(0);
	if( capture ){
		cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 320);
		cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 240);
	}
	else
		cout<<"camera is null..."<<endl;

	//work for a while
	for(i=0; i<15; i++){
		if( img = cvQueryFrame(capture) )
			cvWaitKey(2000);
		else
			cout<<"cannot capture the image..."<<endl;
	}

	//capture Image
	Capture_Image(img, capture);

	return 0;
}
