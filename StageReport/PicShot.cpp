#include "functions.h"

//调用摄像头拍照并保存pic1.jpg
void PicShot()
{
	cout << "\n调用摄像头,拍照并存储到本地（pic1.jpg)\n" << endl;
	system("pause");
	VideoCapture capture(0);     //调用摄像头
	char key = 0;               //监听按键
	while (key != 27)
	{
		Mat frame;          
		capture >> frame;           //记录每一帧
		imshow("摄像头画面", frame);       //显示每一帧
		key = waitKey(1);
		if (key == 115)                   //按s拍照并保存
		{
			imwrite("pic1.jpg", frame);
			imshow("pic1.jpg", frame);
//			MessageBoxA(NULL, "pic1.jpg已保存", "保存成功", MB_OK);
		}
	}
	destroyAllWindows();
}