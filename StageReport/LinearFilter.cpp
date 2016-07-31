//线性滤波：方框滤波，均值滤波，高斯滤波
#include "functions.h"


Mat g_srcImage, g_dstImage1, g_dstImage2, g_dstImage3;   //存储处理结果
int g_nBoxFilterValue = 6;    //方框滤波默认参数
int g_nMeanBlurValue = 6;    //均值滤波默认参数
int g_nGaussianBlurValue = 6;    // 高斯滤波默认参数

//方框滤波
static void on_BoxFilter(int, void *)
{
	boxFilter(g_srcImage, g_dstImage1, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
	imshow("【<1>方框滤波】", g_dstImage1);
}

//均值滤波
static void on_MeanBlur(int, void *)
{
	blur(g_srcImage, g_dstImage2, Size(g_nMeanBlurValue + 1, g_nMeanBlurValue + 1), Point(-1, -1));
	imshow("【<2>均值滤波】", g_dstImage2);
}

//高斯滤波
static void on_GaussianBlur(int, void *)
{
	GaussianBlur(g_srcImage, g_dstImage3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
	imshow("【<3>高斯滤波】", g_dstImage3);
}

//主功能函数
void LinearFilter()
{
	cout << "\n三种线性滤波处理方法处理pic.jpg\n" << endl;
	system("pause");
	//载入图片
	g_srcImage = imread("pic.jpg", 1);
	if (!g_srcImage.data)       //读取判断
	{
		cout << "读取错误！\n";
		return;
	}
	//复制三份原图用于三种方式的处理
	g_dstImage1 = g_srcImage.clone();
	g_dstImage2 = g_srcImage.clone();
	g_dstImage3 = g_srcImage.clone();
	namedWindow("【<0>原图窗口】", 1);    //创建窗口
	imshow("【<0>原图窗口】", g_srcImage);    //显示图片

	namedWindow("【<1>方框滤波】", 1);
	//创建轨迹条
	createTrackbar("内核值：", "【<1>方框滤波】", &g_nBoxFilterValue, 40, on_BoxFilter);
	on_MeanBlur(g_nBoxFilterValue, 0);

	namedWindow("【<2>均值滤波】", 1);
	createTrackbar("内核值：", "【<2>均值滤波】", &g_nMeanBlurValue, 40, on_MeanBlur);
	on_MeanBlur(g_nMeanBlurValue, 0);

	namedWindow("【<3>高斯滤波】", 1);
	createTrackbar("内核值：", "【<3>高斯滤波】", &g_nGaussianBlurValue, 40, on_GaussianBlur);
	on_GaussianBlur(g_nBoxFilterValue, 0);
	//esc退出
	while (char(waitKey(0) != 27))
	{
	}
	destroyAllWindows();
}