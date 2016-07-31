#include "functions.h" 

void PicProcessing()
{
	cout << "\n图片处理：腐蚀、模糊、边缘检测\n" << endl;
	system("pause");
	Mat srcImage = imread("pic1.JPG");
	imshow("图像处理【原图】", srcImage);
	/*-----------------腐蚀操作-------------------*/
	//返回指定形状和尺寸的内核矩阵

	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dsfImage;
	erode(srcImage, dsfImage, element);
	//显示腐蚀效果
	imshow("腐蚀【效果图】", dsfImage);

	/*-----------------模糊操作-------------------*/
	Mat dslImage;
	//进行均值滤波
	blur(srcImage, dslImage, Size(7, 7));
	//显示模糊效果
	imshow("模糊【效果图】", dslImage);

	/*-----------------模糊操作-------------------*/
	Mat dsbImage, edge, grayImge;
	dsbImage.create(srcImage.size(), srcImage.type());
	//原图转灰度图像
	cvtColor(srcImage, grayImge, CV_BGR2GRAY);
	//降噪点
	blur(grayImge, edge, Size(3, 3));
	//运行Canny算子
	Canny(edge, edge, 3, 9, 3);
	imshow("边缘检测【效果图】", edge);
	while (char(waitKey(0) != 27))
	{
	}
	destroyAllWindows();
}
