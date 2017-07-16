#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include "opencv2/opencv.hpp"  
#include<iostream>
#include <string>
#include <vector>


using namespace cv;

int HW01_TestFunction();
int HW02_ReadAndShowData(int numberOfImgs);

int main() {
	HW01_TestFunction();
	waitKey(0);
	destroyAllWindows();

	HW02_ReadAndShowData(8);

	waitKey(0);
	return 0;
}


int HW01_TestFunction() {

	// Fill your answer here

	Mat img = imread("testImage\\lena.jpg", 1);
	namedWindow("originalImage", CV_WINDOW_AUTOSIZE);
	moveWindow("originalImage",20, 20);
	imshow("originalImage", img);
	
	Mat img_gray = imread("testImage\\lena.jpg", 0);
	namedWindow("grayImage", CV_WINDOW_AUTOSIZE);
	moveWindow("grayImage", 20+img.cols, 20);
	imshow("grayImage", img_gray);

	Mat binary = img_gray > 100;
	namedWindow("binaryImage", CV_WINDOW_AUTOSIZE);
	moveWindow("binaryImage", 20 + img.cols*2, 20);
	imshow("binaryImage", binary);

	while (true) {
		if (waitKey(0) == 13)break;
	}	

	destroyAllWindows();

	return 0;
}

int HW02_ReadAndShowData(int numberOfImgs) {
	// Fill your answer here
	std::vector<Mat> originalImage;
	char s[38];
	int size;
	for (int i = 1; i < 9; i++) {
		sprintf(s, "testImage\\capture\\%d.jpg", i);
		Mat img = imread(s, 1);
		namedWindow("originalImage", CV_WINDOW_AUTOSIZE);
		moveWindow("originalImage", 20, 20);
		imshow("originalImage", img);

		Mat img_gray = imread(s, 0);
		namedWindow("grayImage", CV_WINDOW_AUTOSIZE);
		moveWindow("grayImage", 20 + 300, 20);
		imshow("grayImage", img_gray);

		Mat binary = img_gray > 100;
		namedWindow("binaryImage", CV_WINDOW_AUTOSIZE);
		moveWindow("binaryImage", 20 + 600, 20);
		imshow("binaryImage", binary);

		while (true) {
			if (waitKey(0) == 13)break;
		}
		destroyAllWindows();
	}
	
	return 0;
}





