/* 
 *  Author : Tomas Vojir
 *  Date   : 2013-06-05
 *  Desc   : Example of VOT integration for C++ tracker.
 */ 

#include "ColorTracker/vot.hpp"
#include "ColorTracker/color_tracker.hpp"


using namespace cv;
using namespace cv::colortracker;

int main(int argc, char* argv[])
{
    ColorTrackerParameters params;

    params.visualization = 0;
	
    cv::Mat img;

    //load region, images and prepare for output
    VOT vot_io("region.txt", "images.txt", "output.txt");
    
    //img = firts frame, initPos = initial position in the first frame
    VOTPolygon initPos = vot_io.getInitPolygon();
    vot_io.getNextImage(img);
    
    //output init also bbox
    //vot_io.outputPolygon(initPos);

    //tracker initialization
    //tracker.init(img, initPos);

	float x = (initPos.x1 + initPos.x2 + initPos.x3 + initPos.x4) / 4;
	float y = (initPos.y1 + initPos.y2 + initPos.y3 + initPos.y4) / 4;
	//cout << "init x = " << x << endl;
	//cout << "init y = " << y << endl;
	params.init_pos = cv::Point(x,y);

	//cout << "Pos x = " << pos.x << endl;
	//cout << "Pos y = " << pos.y << endl;
	
	cv::Size target_sz = cv::Size(std::max(std::max(initPos.x1,initPos.x2),std::max(initPos.x3,initPos.x4))
				-std::min(std::min(initPos.x1,initPos.x2),std::min(initPos.x3,initPos.x4))+1,
				std::max(std::max(initPos.y1,initPos.y2),std::max(initPos.y3,initPos.y4))
				-std::min(std::min(initPos.y1,initPos.y2),std::min(initPos.x3,initPos.y4))+1);

	params.wsize = cv::Size((int)floor(target_sz.width), (int)floor(target_sz.height));

	//cout << "Width = " << params.wsize.width << endl;
	//cout << "Height = " << params.wsize.height << endl;

	// 1st
	//params.init_pos.x = (int)(floor(pos.x));// + floor(target_sz.width / 2));
	//params.init_pos.y = (int)(floor(pos.y));// + floor(target_sz.height / 2));
	
	ColorTracker tracker(params);
	tracker.init_tracking();
    //track   
    do{
	cv::Rect rect = tracker.track_frame(img);
	
	//cout << "Rect = " << rect.x << " " << rect.y << endl;

	//cv::rectangle(img, rect, Scalar(0, 0, 255), 2);
	//imshow("current_frame", img);
	//cv::waitKey(10);

        VOTPolygon poly;
	poly.x1 = rect.x;
	poly.y1 = rect.y;
	poly.x2 = rect.x + rect.width;
	poly.y2 = rect.y;
	poly.x3 = rect.x + rect.width;
	poly.y3 = rect.y + rect.height;
	poly.x4 = rect.x;
	poly.y4 = rect.y + rect.height;
        vot_io.outputPolygon(poly);
    }while (vot_io.getNextImage(img) == 1);
    //cv::waitKey(0);
    return 0;
}

