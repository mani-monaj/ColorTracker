/*
Copyright (c) 2015, Mostafa Mohamed (Mostafa Izz)
izz.mostafa@gmail.com

All rights reserved.

Redistribution and use in source and binary forms, with or without modification
, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "color_tracker.hpp"

using namespace cv::colortracker;

void test_video()
{
	ColorTrackerParameters params;

	params.visualization = 1;

	params.video_path = "Pigeon.avi";
	
	cv::Point pos = cv::Point(500, 365);
	cv::Size target_sz = cv::Size(60, 60);
	params.init_pos.x = (int)(floor(pos.x) + floor(target_sz.width / 2));
	params.init_pos.y = (int)(floor(pos.y) + floor(target_sz.height / 2));
	params.wsize = cv::Size((int)floor(target_sz.width), (int)floor(target_sz.height));
	ColorTracker tracker(params);
	tracker.track_video(1, 3.5);
}

void test_deer()
{
	ColorTrackerParameters params;

	params.visualization = 1;
	cv::Point pos = cv::Point(306,5);
	cv::Size target_sz = cv::Size(95,65);
	params.init_pos.x = (int)(floor(pos.x) + floor(target_sz.width / 2));
	params.init_pos.y = (int)(floor(pos.y) + floor(target_sz.height / 2));
	params.wsize = cv::Size((int)floor(target_sz.width), (int)floor(target_sz.height));
	
	ColorTracker tracker(params);
	tracker.init_tracking();
	for(int frame_index = 1;frame_index <= 71;frame_index++)
	{
		ostringstream ostr;
		ostr << "sequences/deer/imgs/img";
		ostr << setfill('0') << setw(5) << frame_index << ".jpg";
		cv::Mat current_frame = cv::imread(ostr.str());
		tracker.track_frame(current_frame);
	}
	cv::waitKey(0);
}

void test_soccer()
{
	ColorTrackerParameters params;

	params.visualization = 1;
	cv::Point pos = cv::Point(302,135);
	cv::Size target_sz = cv::Size(67,81);
	params.init_pos.x = (int)(floor(pos.x) + floor(target_sz.width / 2));
	params.init_pos.y = (int)(floor(pos.y) + floor(target_sz.height / 2));
	params.wsize = cv::Size((int)floor(target_sz.width), (int)floor(target_sz.height));
	
	ColorTracker tracker(params);
	tracker.init_tracking();
	for(int frame_index = 1;frame_index <= 392;frame_index++)
	{
		ostringstream ostr;
		ostr << "sequences/Soccer/img/";
		ostr << setfill('0') << setw(4) << frame_index << ".jpg";
		cv::Mat current_frame = cv::imread(ostr.str());
		tracker.track_frame(current_frame);
	}
	cv::waitKey(0);
}

void test_Scate()
{
	ColorTrackerParameters params;

	params.visualization = 1;
	cv::Point pos = cv::Point(162,188);
	cv::Size target_sz = cv::Size(34,84);
	params.init_pos.x = (int)(floor(pos.x) + floor(target_sz.width / 2));
	params.init_pos.y = (int)(floor(pos.y) + floor(target_sz.height / 2));
	params.wsize = cv::Size((int)floor(target_sz.width), (int)floor(target_sz.height));
	
	ColorTracker tracker(params);
	tracker.init_tracking();
	for(int frame_index = 1;frame_index <= 400;frame_index++)
	{
		ostringstream ostr;
		ostr << "sequences/Skating1/img/";
		ostr << setfill('0') << setw(4) << frame_index << ".jpg";
		cv::Mat current_frame = cv::imread(ostr.str());
		tracker.track_frame(current_frame);
	}
	cv::waitKey(0);
}

int main(int argc, char** argv)
{
	test_Scate();
	test_soccer();
	test_video();
	test_deer();
	return 0;
}
