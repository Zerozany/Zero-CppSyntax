#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <windows.h>
#include <vector>
#include <map>


#define CIRCLE_SIZE 10
#define LINE_SIZE 1

//�߶νṹ��
typedef struct
{
    cv::Point _point;         //�߶���ʼ��
    int _pointsize = 1;       //�߶δ�ϸ��
}DrawLineInfo;

//��������������
std::vector<DrawLineInfo> SingleLine{};

//����ͼƬ�߶�������
std::map<int, std::vector<DrawLineInfo>> AllLine{};

//����ƶ���λ��λ����
std::vector<cv::Point> MovepointVector;


//����ͼ��
void DrawPixMethod(cv::Mat _drawpix,cv::Point _startpoint,cv::Point _endpoint)
{
    cv::line(_drawpix,_startpoint,_endpoint,cv::Scalar(0,255,255),LINE_SIZE, cv::LINE_AA);
    cv::circle(_drawpix, _startpoint, CIRCLE_SIZE, cv::Scalar(0,100,255), -1);
    cv::circle(_drawpix, _endpoint, CIRCLE_SIZE, cv::Scalar(0,100,255), -1);
}

#endif // DATASTRUCTURE_H