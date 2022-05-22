#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;
using namespace cv;


void Output(Mat mat)
{
	tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	string output = "";
	output.append(to_string(t.tm_year + 1900));
	output.append("_");
	output.append(to_string(t.tm_mon + 1));
	output.append("_");
	output.append(to_string(t.tm_mday));
	output.append("_");
	output.append(to_string(t.tm_hour));
	output.append("-");
	output.append(to_string(t.tm_min));
	output.append("-");
	output.append(to_string(t.tm_sec));
	output.append(".png");
	imwrite(output, mat);
}

void Default() 
{
	int rows = 0, cols = 0, alpha = -1;
	while (cols <= 0)
	{
		cout << "输入长：";
		cin >> cols;
	}
	while (rows <= 0)
	{
		cout << "输入高：";
		cin >> rows;
	}
	while (alpha != 0 && alpha != 1)
	{
		cout << "alpha通道（0为关闭，1为开启）：";
		cin >> alpha;
	}
	srand(time(0));
	if (alpha)
	{
		Mat mat(rows, cols, CV_8UC4);
		for (int i = 0; i < mat.rows; i++)
		{
			for (int j = 0; j < mat.cols; j++)
			{
				mat.at<Vec4b>(i, j)[0] = rand() % 256;
				mat.at<Vec4b>(i, j)[1] = rand() % 256;
				mat.at<Vec4b>(i, j)[2] = rand() % 256;
				mat.at<Vec4b>(i, j)[3] = rand() % 256;
			}
		}
		Output(mat);
	}
	else
	{
		Mat mat(rows, cols, CV_8UC3);
		for (int i = 0; i < mat.rows; i++)
		{
			for (int j = 0; j < mat.cols; j++)
			{
				mat.at<Vec3b>(i, j)[0] = rand() % 256;
				mat.at<Vec3b>(i, j)[1] = rand() % 256;
				mat.at<Vec3b>(i, j)[2] = rand() % 256;
			}
		}
		Output(mat);
	}
}

void Xue_Hua_Piao_Piao()
{
	int rows = 0, cols = 0, alpha = -1;
	while (cols <= 0)
	{
		cout << "输入长：";
		cin >> cols;
	}
	while (rows <= 0)
	{
		cout << "输入高：";
		cin >> rows;
	}
	while (alpha != 0 && alpha != 1)
	{
		cout << "alpha通道（0为关闭，1为开启）：";
		cin >> alpha;
	}
	srand(time(0));
	if (alpha)
	{
		Mat mat(rows, cols, CV_8UC4);
		for (int i = 0; i < mat.rows; i++)
		{
			for (int j = 0; j < mat.cols; j++)
			{
				int temp = (rand() % 2) * 255;
				mat.at<Vec4b>(i, j)[0] = temp;
				mat.at<Vec4b>(i, j)[1] = temp;
				mat.at<Vec4b>(i, j)[2] = temp;
				mat.at<Vec4b>(i, j)[3] = temp;
			}
		}
		Output(mat);
	}
	else
	{
		Mat mat(rows, cols, CV_8UC3);
		for (int i = 0; i < mat.rows; i++)
		{
			for (int j = 0; j < mat.cols; j++)
			{
				int temp = (rand() % 2) * 255;
				mat.at<Vec3b>(i, j)[0] = temp;
				mat.at<Vec3b>(i, j)[1] = temp;
				mat.at<Vec3b>(i, j)[2] = temp;
			}
		}
		Output(mat);
	}
}

void Star_Light_Star_Bright()
{
	int cols = 0, rows = 0, bgc = 0, count = -1;
	while (cols < 1000)
	{
		cout << "输入长：";
		cin >> cols;
		if (cols < 1000)
			cout << "为确保观赏性，请输入不小于1000的数" << endl;
	}
	while (rows < 1000)
	{
		cout << "输入高：";
		cin >> rows;
		if (rows < 1000)
			cout << "为确保观赏性，请输入不小于1000的数" << endl;
	}
	while (bgc != 1 && bgc != 2)
	{
		cout << "选择背景色（ 1：黑      2：白 ）：";
		cin >> bgc;
	}
	if (bgc == 1)
		bgc = 0;
	else
		bgc = 255;
	while (count < 0)
	{
		cout << "输入星星数：";
		cin >> count;
	}
	srand(time(0));
	Mat mat(rows, cols, CV_8UC3, Scalar(bgc, bgc, bgc));
	for (int i = 0; i < count; i++)
	{
		int horizontal = rand() % cols, vertical = rand() % rows;
		mat.at<Vec3b>(vertical, horizontal)[0] = rand() % 256;
		mat.at<Vec3b>(vertical, horizontal)[1] = rand() % 256;
		mat.at<Vec3b>(vertical, horizontal)[2] = rand() % 256;
	}
	Output(mat);
}

//void Art_Is_Bomb()
//{
//	int cols = 0,bgc = 0,count = -1;
//	while (cols < 1000)
//	{
//		cout << "输入边长：";
//		cin >> cols;
//		if (cols < 1000)
//			cout << "为确保观赏性，请输入不小于1000的数" << endl;
//	}
//	int mid_cols = cols / 2;
//	while (bgc != 1 && bgc != 2)
//	{
//		cout << "选择背景色（ 1：黑      2：白 ）：";
//		cin >> bgc;
//	}
//	if (bgc == 1)
//		bgc = 0;
//	else
//		bgc = 255;
//	while (count < 0)
//	{
//		cout << "输入爆炸数：";
//		cin >> count;
//	}
//	srand(time(0));
//	Mat mat(cols, cols, CV_8UC3, Scalar(bgc, bgc, bgc));
//	for (int i = 0; i < count; i++)
//	{
//		int horizontal = rand() % 91, vertical = rand() % 91;
//		int horizontal_dir = rand() % 2, vertical_dir = rand() % 2;
//		if (horizontal >= vertical)
//		{
//			int j = horizontal / vertical;
//			int length = rand() % mid_cols;
//
//		}
//	}
//	Output(mat);
//}

void Bigger()
{
	int rows = 0, cols = 0, alpha = -1, min = 0, max = 0;
	bool *filled;
	while (cols < 1000)
	{
		cout << "输入长：";
		cin >> cols;
		if (cols < 1000)
			cout << "为确保观赏性，请输入不小于1000的数" << endl;
	}
	while (rows < 1000)
	{
		cout << "输入高：";
		cin >> rows;
		if (rows < 1000)
			cout << "为确保观赏性，请输入不小于1000的数" << endl;
	}
	while (min <= 0)
	{
		cout << "输入矩形最小边长：";
		cin >> min;
	}
	while (max <= 0 || max < min)
	{
		cout << "输入矩形最大边长：";
		cin >> max;		
	}
	int temp = cols * rows;
	filled = new bool[temp];
	for (int i = 0; i < cols * rows; i++)
		filled[i] = 0;
	while (alpha != 0 && alpha != 1)
	{
		cout << "alpha通道（0为关闭，1为开启）：";
		cin >> alpha;
	}
	srand(time(0));
	if (alpha)
	{
		Mat mat(rows, cols, CV_8UC4);
		for (int i = 0; i < mat.rows; i++)
		{
			for (int j = 0; j < mat.cols; j++)
			{
				if (filled[i * cols + j])
					continue;
				else
				{
					int a = rand() % max + 1, b = rand() % max + 1;
					if (a < min)
						a = min;
					if (b < min)
						b = min;
					if (a + i > rows)
						a = rows - i;
					if (b + j > cols)
						b = cols - j;
					int red = rand() % 256, green = rand() % 256, blue = rand() % 256, rand_alpha = rand() % 256;
					for (int  m = 0; m < a; m++)
					{
						for (int n = 0; n < b; n++)
						{
							mat.at<Vec4b>(i + m, j + n)[0] = red;
							mat.at<Vec4b>(i + m, j + n)[1] = green;
							mat.at<Vec4b>(i + m, j + n)[2] = blue;
							mat.at<Vec4b>(i + m, j + n)[3] = rand_alpha;
							filled[(i + m) * cols + (j + n)] = true;
						}
					}
				}
			}
		}
		delete[] filled;
		Output(mat);
	}
	else
	{
		Mat mat(rows, cols, CV_8UC3);
		for (int i = 0; i < mat.rows; i++)
		{
			for (int j = 0; j < mat.cols; j++)
			{
				if (filled[i * cols + j])
					continue;
				else
				{
					int a = rand() % max + 1, b = rand() % max + 1;
					if (a < min)
						a = min;
					if (b < min)
						b = min;
					if (a + i > rows)
						a = rows - i;
					if (b + j > cols)
						b = cols - j;
					int red = rand() % 256, green = rand() % 256, blue = rand() % 256;
					for (int m = 0; m < a; m++)
					{
						for (int n = 0; n < b; n++)
						{
							mat.at<Vec3b>(i + m, j + n)[0] = red;
							mat.at<Vec3b>(i + m, j + n)[1] = green;
							mat.at<Vec3b>(i + m, j + n)[2] = blue;
							filled[(i + m) * cols + (j + n)] = true;
						}
					}
				}
			}
		}
		delete[] filled;
		Output(mat);
	}
}

int main()
{
	int choice = 0;
	cout << "----------------------------------------------" << endl
		<< "                   选择预设                   " << endl
		<< "                   1：默认                    " << endl
		<< "                   2：繁星                    " << endl
		<< "             3：雪花飘飘，北风萧萧            " << endl
		<< "                  4：极巨化                    " << endl
		<< "----------------------------------------------" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		Default();
		break;
	case 2:
		Star_Light_Star_Bright();
		break;
	case 3:
		Xue_Hua_Piao_Piao();
		break;
	case 4:
		Bigger();
		break;
	default:
		cout << endl << "¯\_(ツ)_/¯" << endl;
		break;
	}
	return 0;
}