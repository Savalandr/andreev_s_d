#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

int main()
{
	//part1
	Mat image1;
	//загружаем картинку в png
	image1 = imread("C:/Users/savan/Desktop/andreev_s_d/apple_256x256.png");
	std::vector<int> compression_params;
	compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
	compression_params.push_back(1);
	//уровень качества-95
	compression_params[1] = 95;
	//сохраняем картинку в jpeg-95
	imwrite("C:/Users/savan/Desktop/andreev_s_d/img2.jpeg", image1, compression_params);
	//уровень качества-65
	compression_params[1] = 65;
	//сохраняем картинку в jpeg-65
	imwrite("C:/Users/savan/Desktop/andreev_s_d/img3.jpeg", image1, compression_params);
	//imshow("", image1);
	Mat image2;
	image2 = imread("C:/Users/savan/Desktop/andreev_s_d/img2.jpeg");
	//imshow("", image2);
	Mat image3;
	image3 = imread("C:/Users/savan/Desktop/andreev_s_d/img3.jpeg");
	//imshow("", image3);
	//part2
	//общая картинка
	Mat diffimage(Mat::zeros(512, 768, CV_8UC3));
	for (int i = 0; i < 256; i += 1)
		for (int j = 0; j < 256; j += 1)
		{
			//значения bgr 1 картинки
			int b1 = image1.at<cv::Vec3b>(i, j)[0];
			int g1 = image1.at<cv::Vec3b>(i, j)[1];
			int r1 = image1.at<cv::Vec3b>(i, j)[2];
			//значения bgr 2 картинки
			int b2 = image2.at<cv::Vec3b>(i, j)[0];
			int g2 = image2.at<cv::Vec3b>(i, j)[1];
			int r2 = image2.at<cv::Vec3b>(i, j)[2];
			//значения bgr 3 картинки
			int b3 = image3.at<cv::Vec3b>(i, j)[0];
			int g3 = image3.at<cv::Vec3b>(i, j)[1];
			int r3 = image3.at<cv::Vec3b>(i, j)[2];
			//1 2 b
			diffimage.at<cv::Vec3b>(i, j)[0] = abs(b1 - b2);
			diffimage.at<cv::Vec3b>(i, j)[1] = 0;
			diffimage.at<cv::Vec3b>(i, j)[2] = 0;
			//1 2 g
			diffimage.at<cv::Vec3b>(i, j + 256)[0] = 0;
			diffimage.at<cv::Vec3b>(i, j + 256)[1] = abs(g1 - g2);
			diffimage.at<cv::Vec3b>(i, j + 256)[2] = 0;
			//1 2 r
			diffimage.at<cv::Vec3b>(i, j + 512)[0] = 0;
			diffimage.at<cv::Vec3b>(i, j + 512)[1] = 0;
			diffimage.at<cv::Vec3b>(i, j + 512)[2] = abs(r1 - r2);
			//1 3 b
			diffimage.at<cv::Vec3b>(i + 256, j)[0] = abs(b1 - b2);
			diffimage.at<cv::Vec3b>(i + 256, j)[1] = 0;
			diffimage.at<cv::Vec3b>(i + 256, j)[2] = 0;
			//1 3 g
			diffimage.at<cv::Vec3b>(i + 256, j + 256)[0] = 0;
			diffimage.at<cv::Vec3b>(i + 256, j + 256)[1] = abs(g1 - g2);
			diffimage.at<cv::Vec3b>(i + 256, j + 256)[2] = 0;
			//1 3 r
			diffimage.at<cv::Vec3b>(i + 256, j + 512)[0] = 0;
			diffimage.at<cv::Vec3b>(i + 256, j + 512)[1] = 0;
			diffimage.at<cv::Vec3b>(i + 256, j + 512)[2] = abs(r1 - r2);
		}
	imshow("", diffimage);
	waitKey(0);
	return 0;
}