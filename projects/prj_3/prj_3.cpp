#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
    //WARNING! ОСТОРОЖНО! КОЛХОЗ! ATTANTION!
    Mat img(Mat::zeros(256, 256, CV_8UC1));
    img = imread("C:/Users/savan/Desktop/andreev_s_d/cross_0256x0256.png", 0); //Читаем картинку (0 - ч/б, 1 - цветная)

    int hist[256]; //создаем массив гистограммы
    for (int i = 0; i < 256; i++) //забиваем его нулями (не на питоне ж пишем, так что канон)
    {
        hist[i] = 0;
    }
    for (int i_strok = 0; i_strok < 256; i_strok++)     //фигачим по пикселям изображения прибавляя еденичку
        for (int j_stolb = 0; j_stolb < 256; j_stolb++) //к элементу массива соответсвующему по индексу
        {                                               //насыщенонсти данного пикселя
            hist[img.at<uchar>(i_strok, j_stolb)] += 1;
        }

    Mat img2(Mat::zeros(256, 768, CV_8UC1));        //создаем картинку, куда будем рисовать гистограмму

    int mashtab_k = 0;              //высчитываем коэффициент маштабирования гистограммы
    for (int i = 0; i < 256; i++)   //что бы она потом не вылазила за окно вывода 
    {
        if (hist[i] > mashtab_k)
            mashtab_k = hist[i];
    }
    mashtab_k /= 265;

    for (int i_strok = 255; i_strok >= 0; i_strok--)  // отрисовываем гистограмму
        for (int j_stolb = 0; j_stolb < 256; j_stolb++)
        {
            if (hist[j_stolb] > 0)
            {
                img2.at<uchar>(i_strok, j_stolb*3) = 255;       //для наглядности делаем столбцы шире
                img2.at<uchar>(i_strok, j_stolb*3 + 1) = 255;   //окрашивая по 3 пикселя
                img2.at<uchar>(i_strok, j_stolb*3 + 2) = 255;
                hist[j_stolb] -= mashtab_k; //маштабируем ее, относительно самого большого значения
            }
        }
    for (int i_strok = 255; i_strok >= 0; i_strok--)            // а теперь меням черый и белый местами
        for (int j_stolb = 0; j_stolb < 768; j_stolb++)         // потому что пол часа гугления не обяснили как
        {                                                       // просто создать белую картинку
            if (img2.at<uchar>(i_strok, j_stolb) == 255)
            {
                img2.at<uchar>(i_strok, j_stolb) = 0;
            }
            else
            {
                img2.at<uchar>(i_strok, j_stolb) = 255;
            }
        }

    imshow("Исходная картинка", img);     //выводим исходную картинку
    imshow("Гистограмма для исходной картинки", img2); //выводим гистограмму
    
    //ЧАСТЬ 2============================================================================================   
    // Построить график функции
    
    Mat imgG(Mat::zeros(257, 257, CV_8UC1)); //окно для вывода графика
    int mass[256]; //массив для значений функции
    for (int i = 0; i < 256; i++) //снова обнуляем
    {
        mass[i] = 0;
    }
    int stlb = 0;
    for (int i = 0; i < 256; i++) //забиваем массив значениями функции
    {
        if (i<=128)
        {
            mass[i] =  i + ((abs(i - 128)) * 2);
        }
        else
        {
            mass[i] = i - ((abs(i - 128)) / 2);
        }
    }

    for (int j_stolb = 0; j_stolb < 256; j_stolb++) // отрисовываем графиик
    {
        imgG.at<uchar>(mass[j_stolb], j_stolb) = 255;
    }
            
    imshow("График функции", imgG); //вывод графика на экран

    //-----------------------------------------------------------------------------------------------------
    //Применение функции яркостного преобразования

    Mat img3 = imread("C:/Users/savan/Desktop/andreev_s_d/cross_0256x0256.png", 0); //задаем картинку
    for (int i_strok = 0; i_strok < 256; i_strok++) //применяем функцию
        for (int j_stolb = 0; j_stolb < 256; j_stolb++)
        {
            if (img3.at<uchar>(i_strok, j_stolb) > 128) // если яркость больше половины 128, то понижаем в 2 раза, если меньше, повышаем
            {           
                img3.at<uchar>(i_strok, j_stolb) -= ((abs((img3.at<uchar>(i_strok, j_stolb)) - 128)) / 2);
            }
            else
            {
                img3.at<uchar>(i_strok, j_stolb) += ((abs((img3.at<uchar>(i_strok, j_stolb)) - 128)) * 2);
            }
        }
    int hist2[256]; // дальше все так-же как в первой части
    for (int i = 0; i < 256; i++)
    {
        hist2[i] = 0;
    }
    for (int i_strok = 0; i_strok < 256; i_strok++)
        for (int j_stolb = 0; j_stolb < 256; j_stolb++)
        {
            hist2[img3.at<uchar>(i_strok, j_stolb)] += 1;
        }

    Mat img4(Mat::zeros(256, 768, CV_8UC1));

    int mashtab_k2 = 0;
    for (int i = 0; i < 256; i++)
    {
        if (hist2[i] > mashtab_k2)
            mashtab_k2 = hist2[i];
    }
    mashtab_k2 /= 265;

    for (int i_strok = 255; i_strok >= 0; i_strok--)
        for (int j_stolb = 0; j_stolb < 256; j_stolb++)
        {
            if (hist2[j_stolb] > 0)
            {
                img4.at<uchar>(i_strok, j_stolb * 3) = 255;
                img4.at<uchar>(i_strok, j_stolb * 3 + 1) = 255;
                img4.at<uchar>(i_strok, j_stolb * 3 + 2) = 255;
                hist2[j_stolb] -= mashtab_k2;
            }
        }
    for (int i_strok = 255; i_strok >= 0; i_strok--)
        for (int j_stolb = 0; j_stolb < 768; j_stolb++)
        {
            if (img4.at<uchar>(i_strok, j_stolb) == 255)
            {
                img4.at<uchar>(i_strok, j_stolb) = 0;
            }
            else
            {
                img4.at<uchar>(i_strok, j_stolb) = 255;
            }
        }
    imshow("Картинка с яркостным преобразованием", img3);
    imshow("Гистограмма картинки с яркостным преобразованием", img4);
    
    //===================================================================================================
    
    waitKey(0);
    return 0;


    //Это остатки неудачных попыток сделать меньше колхоза.
    //void bitwise_not(InputArray src, OutputArray dst, InputArray mask = noArray());
    //#define w 200
    //void rectangle(Mat & img2, Point i_stolb, Point j_strok, const Scalar & green, int thickness = 1, int lineType = 8, int shift = 0);
    //Point pt1 = Point(10, 10);
    //Point pt2 = Point(100, 100);
    //Scalar(150, 0, 0);
    //rectangle(img2,
    //    Point(0, 7 * w / 8),
    //    Point(w, w),
    //    Scalar(0, 255, 255),
    //    FILLED,
    //    LINE_8);

    //void rectangle(Mat & img2, Point pt1, Point pt2, const Scalar & color, int thickness = 1, int lineType = 8, int shift = 0);

    //for (int i_stolb = 0; i_stolb < 256; i_stolb++)
    //   for (int j_strok = 0; j_strok < 256; j_strok++)
    //    {
    //        void rectangle(Mat & img2, Point i_stolb, Point j_strok, const Scalar & blue, int thickness = 1, int lineType = 8, int shift = 0);
    //    }

    //for (int i_stolb = 0; i_stolb < 256; i_stolb++)
    //    for (int j_strok = 0; j_strok < 256; j_strok++)
    //    {
    //        void rectangle(Mat & img3, Point pt1, Point pt2, const Scalar & color, int thickness = 1, int lineType = 8, int shift = 0);
    //    }
}