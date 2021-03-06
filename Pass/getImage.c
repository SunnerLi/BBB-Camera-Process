#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <stdio.h>
#define NUMBER_OF_FRAME 100
 
int totel = 0;

void main(){
	IplImage* capimg;
	CvCapture *capture;
	char *imageName;
 
	capture = cvCaptureFromCAM(0);
	if( ! capture ){
		fprintf( stderr, "unable to create camera 0 \n" );
		exit( 1 );
	}
 
	//cvNamedWindow( "camera0", 1 );
 
	for(totel=0; totel<NUMBER_OF_FRAME; totel++){
		capimg=cvQueryFrame(capture);
		//cvShowImage(  "camera0", capimg );
		if(((totel%10) == 0 ) && ( totel != 0 ) ){
			sprintf(imageName, "%06d.png", totel/10);
			cvSaveImage(imageName, capimg, 0);
		}
		printf("%d\n", totel);
	}
	printf("!");
  	cvReleaseCapture(&capture);
	//cvDestroyWindow("camera0");
 }
