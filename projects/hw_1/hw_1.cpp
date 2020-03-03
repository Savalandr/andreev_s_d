#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("C:/Users/savan/Desktop/andreev_s_d/cross_0256x0256.png", 1);

	Mat diffimage(Mat::zeros(512, 1024, CV_8UC3));
	for (int i = 0; i < 256; i += 1)
		for (int j = 0; j < 256; j += 1)
		{
			//значения bgr 1 картинки
			int b1 = img.at<cv::Vec3b>(i, j)[0];
			int g1 = img.at<cv::Vec3b>(i, j)[1];
			int r1 = img.at<cv::Vec3b>(i, j)[2];
			
			diffimage.at<cv::Vec3b>(i, j)[0] = b1;
			diffimage.at<cv::Vec3b>(i, j)[1] = g1;
			diffimage.at<cv::Vec3b>(i, j)[2] = r1;

			diffimage.at<cv::Vec3b>(i, j + 256)[0] = b1;
			diffimage.at<cv::Vec3b>(i, j + 256)[1] = b1;
			diffimage.at<cv::Vec3b>(i, j + 256)[2] = b1;
			
			diffimage.at<cv::Vec3b>(i, j + 512)[0] = g1;
			diffimage.at<cv::Vec3b>(i, j + 512)[1] = g1;
			diffimage.at<cv::Vec3b>(i, j + 512)[2] = g1;
			
			diffimage.at<cv::Vec3b>(i, j + 768)[0] = r1;
			diffimage.at<cv::Vec3b>(i, j + 768)[1] = r1;
			diffimage.at<cv::Vec3b>(i, j + 768)[2] = r1;
			
			diffimage.at<cv::Vec3b>(i+256, j+256)[0] = b1;
			diffimage.at<cv::Vec3b>(i+256, j+256)[1] = 0;
			diffimage.at<cv::Vec3b>(i+256, j+256)[2] = 0;

			diffimage.at<cv::Vec3b>(i+256, j + 512)[0] = 0;
			diffimage.at<cv::Vec3b>(i+256, j + 512)[1] = g1;
			diffimage.at<cv::Vec3b>(i+256, j + 512)[2] = 0;

			diffimage.at<cv::Vec3b>(i+256, j + 768)[0] = 0;
			diffimage.at<cv::Vec3b>(i+256, j + 768)[1] = 0;
			diffimage.at<cv::Vec3b>(i+256, j + 768)[2] = r1;

		}
	imshow("Resault", diffimage);
	waitKey(0);
	return 0;
}