#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>
#define NUMBER_OF_IMAGE 5
using namespace std;

int imageCounter = 1, timer = 0;

void delayDefineByMyself(float time_want_to_wait)
{
	clock_t bef=0, aft=0;
	bef=clock();
	aft=clock()-bef;
	float diff=((int)aft)/CLOCKS_PER_SEC;
	while(diff<time_want_to_wait)
	{
		aft=clock()-bef;
		diff=((float)aft)/CLOCKS_PER_SEC;
	}
}


void Decide_Image_Name(IplImage* image){
	char s[50];// need to use array, or get segmentation fault
	cout<<imageCounter<<endl;
	sprintf(s, "%06d.jpg", imageCounter++);
	cvSaveImage(s, image, 0);
}

void Capture_Image(IplImage* image, CvCapture* capture){
	int i;
	char *s;
	while( imageCounter < NUMBER_OF_IMAGE ){
		//delayDefineByMyself(1);
		image = cvQueryFrame(capture);
		cvWaitKey(1000);
		timer++;
		if( timer == 10){
			timer = 0;
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
	capture = cvCaptureFromCAM(1);
	if( capture ){
		//cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 320);
		//cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 240);
	}
	else
		cout<<"camera is null..."<<endl;

	//work for a while
	//delayDefineByMyself(30);
	for(i=0; i<15; i++){
		if( img = cvQueryFrame(capture) )
			cvWaitKey(20);
		else
			cout<<"cannot capture the image..."<<endl;
	}

	//capture Image
	Capture_Image(img, capture);

	return 0;
}
