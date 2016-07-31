#include "functions.h"

int g_nContrastValue;
int g_nBrightValue;
Mat gsrcImage, g_dstImage;
static void on_ContrastAndBright(int, void *);
void PicAdj()
{
	cout << "\n调用摄像头,拍照并存储到本地（pic1.jpg)\n" << endl;
	system("pause");
	VideoCapture capture(0);
	
	g_nContrastValue = 80;
	g_nBrightValue = 80;
	namedWindow("【效果窗口图】",0);
	createTrackbar("对比度", "【效果窗口图】", &g_nContrastValue, 350, on_ContrastAndBright);
	createTrackbar("亮 度", "【效果窗口图】", &g_nBrightValue, 350, on_ContrastAndBright);
	char key = 0;
	while (key != 27)
	{
		capture >> gsrcImage;
		//g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());
		//on_ContrastAndBright(g_nContrastValue, 0);
		on_ContrastAndBright(g_nBrightValue, 0);
		key = waitKey(1);
		if (key == 115)                   //按s拍照并保存
		{
			imwrite("pic1.jpg", g_dstImage);
			imshow("pic1.jpg", g_dstImage);
			//			MessageBoxA(NULL, "pic1.jpg已保存", "保存成功", MB_OK);
		}
	}
	destroyAllWindows();
}
//回调用函数
static void on_ContrastAndBright(int, void *)
{
	g_dstImage = gsrcImage.clone();
	int rowNumber = g_dstImage.rows;
	int colNumber = g_dstImage.cols*g_dstImage.channels();
	//用指针的方法访问每个像素
	for (int i = 0; i < rowNumber; i++)
	{
		uchar* data = g_dstImage.ptr<uchar>(i);
		for (int j = 0; j < colNumber; j++)
		{
			data[j]=saturate_cast<uchar>((g_nContrastValue*0.01)*(data[j]) + g_nBrightValue);
		}
	}
	/*for (int y = 0; y < g_srcImage.rows; y++)
	{
		for (int x = 0; x < g_srcImage.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				g_dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(y, x)[c]) + g_nBrightValue);
			}
		}
	}
	*/
	imshow("【效果窗口图】", g_dstImage);
}
