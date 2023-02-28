#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const int buffer_size = 10;

int main() {
    VideoCapture cap("rtsp://<username>:<password>@<ip_address>:<port>/"); // Your ip aders 

    if (!cap.isOpened()) {
        cerr << "Failed to open RTSP stream." << endl;
        return -1;
    }

    vector<Mat> buffer;
    for (int i = 0; i < buffer_size; i++) {
        Mat frame;
        cap.read(frame);
        buffer.push_back(frame.clone());
    }

    Mat prev_gray, prev_corners;
    cvtColor(buffer[0], prev_gray, COLOR_BGR2GRAY);
    goodFeaturesToTrack(prev_gray, prev_corners, 200, 0.01, 30);

    TermCriteria termcrit(TermCriteria::COUNT | TermCriteria::EPS, 20, 0.03);
    Size winSize(31, 31);
    vector<uchar> status;
    vector<float> err;
    vector<Point2f> next_corners;

    Mat next_gray, H;
    while (cap.read(frame)) {
        buffer.erase(buffer.begin());
        buffer.push_back(frame.clone());
        cvtColor(buffer[0], prev_gray, COLOR_BGR2GRAY);
        cvtColor(buffer[buffer_size - 1], next_gray, COLOR_BGR2GRAY);
        calcOpticalFlowPyrLK(prev_gray, next_gray, prev_corners, next_corners, status, err, winSize, 3, termcrit, 0, 0.001);
        H = findHomography(next_corners, prev_corners);
        warpPerspective(buffer[buffer_size - 1], frame, H, frame.size());
        imshow("Stabilized", frame);
        if (waitKey(1) == 27) {
            break;
        }
    }

    return 0;
}
