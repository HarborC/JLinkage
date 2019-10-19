#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/line_descriptor/descriptor.hpp>
#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include  <fstream>

using namespace std;
using namespace cv;
using namespace cv::line_descriptor;

int main(int argc, const char* argv[])
{
    if(argc<3) {
		std::cout<<argv[0]<<" infilename outfilename"<<std::endl;
		return 1;
	}

    cv::Mat img = cv::imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
    cv::imshow("WS", img);
    cv::waitKey(0);

    std::vector<KeyLine> keylines;

    Ptr<line_descriptor::LSDDetector> lsd = line_descriptor::LSDDetector::createLSDDetector();
    lsd->detect(img, keylines, 1.2, 1, cv::Mat());

    ofstream out(argv[2]);

    for(size_t i = 0; i<keylines.size() ; i++)
    {
        out<<keylines[i].startPointX<<" "<<keylines[i].startPointY<<" "<<keylines[i].endPointY<<" "<<keylines[i].endPointY<<endl;
    }

    out.close();


    return 0;
}