#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	cv::Mat srcMat = imread("D:\\solar_cell_01.png");
	float histgram[256] = { 0 };
	float d[256] = { 0 };
	int height = srcMat.rows;//行数
	int width = srcMat.cols;//每行元素的总元素量
	float sum = 0;
	for (int j = 0; j < height; j++)
	{
		uchar* data = srcMat.ptr<uchar>(j);
		for (int i = 0; i < width; i++)
		{
			int rgbvaule = data[i];
			histgram[rgbvaule]++;
		}
	}
	for (int n = 0; n < 256; n++)
	{
		sum = sum + histgram[n];
		std::cout << histgram[n] << std::endl;
	}
	for (int a = 0; a < 256; a++)
	{

		d[a] = histgram[a] / sum;
		std::cout << d[a] << std::endl;
	}
	waitKey(0);
	return 0;
}