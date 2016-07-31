#include "functions.h"

//-----宏定义----
#define WINDOW_NAME1 "[绘制图1]"
#define WINDOW_NAME2 "[绘制图2]"
#define WINDOW_WIDTH 200//定义窗口宏大小
//绘制椭圆
void DrawELLipse(Mat image, double angle)
{
	int thickness = 2;
	int lineType = 8;
	ellipse(image,
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16),
		angle,
		0,
		360,
		Scalar(255, 129, 0),
		thickness,
		lineType
		);
}
//绘制实心圆
void DrawFilledCircle(Mat img, Point center)
{
	int thickness = 2;
	int lineType = 8;
	circle(img,
		center,
		WINDOW_WIDTH / 32,
		Scalar(0, 0, 255),
		thickness,
		lineType
		);

}
void Painting()
{
	cout << "\n绘制图片\n" << endl;
	system("pause");
	Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	//绘制多个椭圆相互交叠
	DrawELLipse(atomImage, 90);
	DrawELLipse(atomImage, 0);
	DrawELLipse(atomImage, 45);
	DrawELLipse(atomImage, -45);
	imshow(WINDOW_NAME1, atomImage);
	imwrite("pic2.png", atomImage);
	while (char(waitKey(0) != 27))
	{
	}
	destroyAllWindows();
}
