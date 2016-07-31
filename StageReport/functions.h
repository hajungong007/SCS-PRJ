#pragma once
#include "windows.h"
#include "opencv.hpp"
#include "core.hpp"
#include "imgproc.hpp"
#include "highgui.hpp"
#include "iostream"
using namespace std;
using namespace cv;

//调用摄像头拍照并保存pic1.jpg
void PicShot();
void PicAdj();
void PicProcessing();
void Painting();
void MixPics();
//线性滤波
void LinearFilter();