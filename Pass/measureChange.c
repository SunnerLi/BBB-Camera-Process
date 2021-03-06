/*
 * This program displays the names of all files in the current directory.
 */

#include <dirent.h> 
#include <stdio.h> 
#include <time.h>
#define FILE_ADD 10

int main(void)
{
	DIR           *d;
	struct dirent *dir;
	int originNumber = 0, i, afterNumber;
	clock_t bef=0, aft=0;

	//calculate the origin file number
	d = opendir(".");
	if (d){
		while ((dir = readdir(d)) != NULL){
			printf("%s\n", dir->d_name);
			originNumber++;
		}

		closedir(d);
	}

	//calculate the limit and wait for interrupt
	afterNumber = originNumber + FILE_ADD;
	printf("origin number of folder: %d\n", originNumber);
	scanf("%d", &i);
	bef = clock();

	//keep looping until detecting the limit number of file
	while( originNumber < afterNumber ){
		originNumber = 0;
		d = opendir(".");
		while ((dir = readdir(d)) != NULL){
			//printf("%s\n", dir->d_name);
			originNumber++;
		}

		closedir(d);
	}

	//calculate and show the result
	aft=clock()-bef;
	float diff=((int)aft)/CLOCKS_PER_SEC;
	printf("result: %f\n", diff);
	return(0);
}
