#ifndef __PPTRESTORE_H
#define __PPTRESTORE_H
#include <cmath>
#include <iostream>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/ml/ml.hpp>  
#include <memory>
using namespace cv;
using namespace std;
#define WINDOW_NAME1 "��ԭʼͼ���ڡ�"			 
#define WINDOW_NAME2 "������Warp���ͼ��"        
#define WINDOW_NAME3 "���پ�����ǿ���ͼ��"        
struct IsCloseToEdge
{
	bool operator()(Vec4i line)
	{
		return abs(line[0] - line[2]) < 10 || abs(line[1] - line[3]) < 10;
	}
};
struct CmpContoursSize//������С����
{
	bool operator()(const vector<Point>& lhs, const vector<Point>& rhs) const
	{
		return lhs.size() > rhs.size();
	}
};
struct CmpDistanceToZero//�����㵽ԭ�����
{
	bool operator()(const Point& lhs, const Point& rhs) const
	{
		return lhs.x + lhs.y < rhs.x + rhs.y;
	}
};
class PPTRestore
{
public:
	PPTRestore();
	PPTRestore(const PPTRestore&);
	PPTRestore(PPTRestore&&);
	PPTRestore& operator=(PPTRestore other);
	~PPTRestore();
	void imageRestoreAndEnhance(const string name);//ͼ��ԭ����ǿ
private:
	struct Ximpl;
	Ximpl* pImpl;
};

#endif