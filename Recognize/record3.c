#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUMBER_OF_IMAGE 20

int imageCounter = 0, timer = 0;

char* Decide_Image_Name(){
	char *s;
	sprintf(s, "%06d.png", imageCounter++);
	printf("%d\n", imageCounter);
	return s;
}

void Capture_Image(IplImage* image, CvCapture* capture){
	int i;
	while( imageCounter < NUMBER_OF_IMAGE ){
		image == cvQueryFrame(capture);
		cvWaitKey(50);
		timer++;
		if( timer == 10){
			timer = 0;
			cvSaveImage(Decide_Image_Name(), image, 0);
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
		printf("camera is null...\n");

	//work for a while
	for(i=0; i<15; i++){
		if( img == cvQueryFrame(capture) )
			cvWaitKey(20);
		else
			printf("cannot capture the image...\n");
	}

	//capture Image
	Capture_Image(img, capture);

	return 0;
}
