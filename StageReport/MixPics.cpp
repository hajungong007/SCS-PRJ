//图片叠加
#include "functions.h"

//ROI区域图像叠加
void MixPics() 
{
	cout << "\n图片叠加\n" << endl;
	system("pause");
	//读取图像pic1和pic2;
	Mat Pic_01 = imread("pic1.jpg");
	Mat Pic_02 = imread("pic2.jpg");
	//判断读取图片是否成功;
	if (!Pic_01.data) { printf("读取图像pic1失败"); return; }
	if (!Pic_02.data) { printf("读取图像pic2失败"); return; }
	//定义一个Mat类型给其设定ROI区域;
	//poc2叠加到pic1的位置可通过设置Rect()函数中的参数任意设置;
	Mat dstROI = Pic_01(Rect(10, 10, Pic_02.cols, Pic_02.rows));
	//加载掩膜
	Mat mask = imread("pic2.png", 0);
	//将掩膜复制到dstROI;
	Pic_02.copyTo(dstROI, mask);
	//显示叠加后的图像;
	namedWindow("pic1和pic2混合后的图像");
	imshow("pic1和pic2混合后的图像", Pic_01);
	//保存叠加后的图片命名为pic.jpg
	imwrite("pic.jpg", Pic_01);
	while (char(waitKey(0) != 27))
	{
	}
	destroyAllWindows();
}


