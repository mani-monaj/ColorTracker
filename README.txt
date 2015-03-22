This C++ code is an implementation of the visual tracking method proposed in [1]. The implementation is based on the Matlab code provided by the authors of the paper.
The implementation in C++ using openCV was done by Mostafa Izz.

Instructions:
The code is not provided as executable, you need to compile. It was created for integration with openCV.
There are two interfaces provided in the code in class "color_tracker"
1) cv::Rect track_frame(cv::Mat &current_frame)
Provided to track frame by frame
So, the parameters needed to be passed to the constructor are used for intializing the bounding box only.
2) void track_video(double start_second = 0, double end_second = 0)
Provided to track video
In the second case the video path should be provided in the parameters passed to the constructor.

There are examples on both interfaces in the file "source.cpp"
There is a simple example in the file "static.cpp" for usage with the VOT challenge.

The code was tested under two environments:

1- Windows 7 using visual studio 2013 with openCV 2.4.9
2- Ubuntu 14.04 with GCC 4.8.2 with openCV 2.4.9

Contact:
Mostafa Izz
izz.mostafa@gmail.com


[1] Martin Danelljan, Fahad Shahbaz Khan, Michael Felsberg and Joost van de Weijer.
    "Adaptive Color Attributes for Real-Time Visual Tracking".
    Proceedings of IEEE Conference on Computer Vision and Pattern Recognition (CVPR), 2014.
