#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
    Mat img(Mat::zeros(160, 768, CV_8UC1));
    int fontFace(FONT_HERSHEY_PLAIN);
    double fontScale(2.0);
    int thickness(3);
    Point textOrg(50, 50);
    int pix = 0;
    // ���������� �� ����������� ����� ���������� �����
    for (int i = 0; i < 80; i++)
        for (int j = 0; j < img.cols; j = j + 3)
        {
            img.at<uint8_t>(i, j) = pix;
            img.at<uint8_t>(i, j + 1) = pix;
            img.at<uint8_t>(i, j + 2) = pix;
            pix++;
        }
    Mat img2(Mat::zeros(160, 768, CV_8UC1));
    img.convertTo(img2, CV_32FC1, 1.0 / 255);
    for (int i = 80; i < 160; i++)
        for (int j = 0; j < img2.cols; j++)
        {
            img2.at<float_t>(i, j) = pow(img2.at<float_t>(i - 80, j), 2.2);
        }
    img2.convertTo(img, CV_8UC1, 255);
    imshow("", img);
    waitKey(0);
    return 0;
}

/*
#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
    Mat img(Mat::zeros(160, 768, CV_8UC1));
    int fontFace(FONT_HERSHEY_PLAIN);
    double fontScale(2.0);
    int thickness(3);
    Point textOrg(50, 50);
    int pix = 0;
    // ���������� �� ����������� ����� ���������� �����
    for (int i = 0; i < 80; i++)
    {
        for (int j = 0; j < img.cols; j = j + 30)
        {
            for (int jf = 0; jf < 30; jf++)
                if (jf + j < img.cols)
                    img.at<uint8_t>(i, j + jf) = pix;
            pix = pix + 10;
        }
        pix = 0;
    }
    Mat img2(Mat::zeros(160, 768, CV_8UC1));
    img.convertTo(img2, CV_32FC1, 1.0 / 255);
    for (int i = 80; i < 160; i++)
        for (int j = 0; j < img2.cols; j++)
        {
            img2.at<float_t>(i, j) = pow(img2.at<float_t>(i - 80, j), 2.2);
        }
    img2.convertTo(img, CV_8UC1, 255);
    imshow("", img);
    waitKey(0);
    return 0;
}
*/

/*
#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
   Mat image(Mat::zeros(800, 600, CV_8U));
   int fontFace(FONT_HERSHEY_PLAIN);
   double fontScale(2.0);
   int thickness(3);  
   Point textOrg(50, 50);
   putText(image, "Hello, world!", textOrg, fontFace, fontScale, Scalar::all(255), thickness, 8);
   imshow("Hello, word! Press any key...", image);
   waitKey(0);
   return 0;
}
*/