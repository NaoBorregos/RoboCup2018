
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <alproxies/alrobotpostureproxy.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alvideodeviceproxy.h>
#include <alproxies/alledsproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <alvision/alimage.h>
#include <alvision/alvisiondefinitions.h>
#include <alproxies/allandmarkdetectionproxy.h>
#include <alproxies/almemoryproxy.h>
#include <qi/os.hpp>

using namespace std;
using namespace cv;
using namespace AL;

void robot1(AL::ALRobotPostureProxy posture, AL::ALMotionProxy motion, AL::ALVideoDeviceProxy camProxy, AL::ALLandMarkDetectionProxy naoMark, AL::ALMemoryProxy memProxy);


int getOrientation(vector<Point> &pts, Mat &img);

void rightFootKick(AL::ALRobotPostureProxy &posture, AL::ALMotionProxy &motion, ALTextToSpeechProxy &say){
    std::vector<std::string> names;
     AL::ALValue times, keys;

//    motion.moveTo(0.0,0.03,0);
  //  motion.moveTo(0,0.0,(-5*M_PI/180));
    names.reserve(22);
    times.arraySetSize(22);
    keys.arraySetSize(22);

    names.push_back("HeadPitch");
    times[0].arraySetSize(5);
    keys[0].arraySetSize(5);

    times[0][0] = 0.440000;
    keys[0][0] = AL::ALValue::array(0.0245020, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[0][1] = 1.20000;
    keys[0][1] = AL::ALValue::array(0.0214340, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[0][2] = 1.96000;
    keys[0][2] = AL::ALValue::array(0.0229680, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[0][3] = 2.80000;
    keys[0][3] = AL::ALValue::array(0.0214340, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[0][4] = 3.04000;
    keys[0][4] = AL::ALValue::array(0.0229680, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("HeadYaw");
    times[1].arraySetSize(5);
    keys[1].arraySetSize(5);

    times[1][0] = 0.440000;
    keys[1][0] = AL::ALValue::array(-0.00617796, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[1][1] = 1.20000;
    keys[1][1] = AL::ALValue::array(-0.00924597, AL::ALValue::array(3, -0.253333, 0.000766999), AL::ALValue::array(3, 0.253333, -0.000766999));
    times[1][2] = 1.96000;
    keys[1][2] = AL::ALValue::array(-0.0107800, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[1][3] = 2.80000;
    keys[1][3] = AL::ALValue::array(-0.00310997, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[1][4] = 3.04000;
    keys[1][4] = AL::ALValue::array(-0.0107800, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LAnklePitch");
    times[2].arraySetSize(5);
    keys[2].arraySetSize(5);

    times[2][0] = 0.440000;
    keys[2][0] = AL::ALValue::array(-0.408086, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[2][1] = 1.20000;
    keys[2][1] = AL::ALValue::array(-0.567621, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[2][2] = 1.96000;
    keys[2][2] = AL::ALValue::array(-0.567621, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[2][3] = 2.80000;
    keys[2][3] = AL::ALValue::array(-0.567621, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[2][4] = 3.04000;
    keys[2][4] = AL::ALValue::array(-0.576826, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LAnkleRoll");
    times[3].arraySetSize(5);
    keys[3].arraySetSize(5);

    times[3][0] = 0.440000;
    keys[3][0] = AL::ALValue::array(-0.00302603, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[3][1] = 1.20000;
    keys[3][1] = AL::ALValue::array(0.0521979, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[3][2] = 1.96000;
    keys[3][2] = AL::ALValue::array(0.0521979, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[3][3] = 2.80000;
    keys[3][3] = AL::ALValue::array(0.0521979, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[3][4] = 3.04000;
    keys[3][4] = AL::ALValue::array(0.0521980, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LElbowRoll");
    times[4].arraySetSize(5);
    keys[4].arraySetSize(5);

    times[4][0] = 0.440000;
    keys[4][0] = AL::ALValue::array(-0.00872665, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[4][1] = 1.20000;
    keys[4][1] = AL::ALValue::array(-0.0306380, AL::ALValue::array(3, -0.253333, 0.00441891), AL::ALValue::array(3, 0.253333, -0.00441891));
    times[4][2] = 1.96000;
    keys[4][2] = AL::ALValue::array(-0.0352401, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[4][3] = 2.80000;
    keys[4][3] = AL::ALValue::array(-0.0306380, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[4][4] = 3.04000;
    keys[4][4] = AL::ALValue::array(-0.0352400, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LElbowYaw");
    times[5].arraySetSize(5);
    keys[5].arraySetSize(5);

    times[5][0] = 0.440000;
    keys[5][0] = AL::ALValue::array(-1.37451, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[5][1] = 1.20000;
    keys[5][1] = AL::ALValue::array(-1.37757, AL::ALValue::array(3, -0.253333, 0.00102276), AL::ALValue::array(3, 0.253333, -0.00102276));
    times[5][2] = 1.96000;
    keys[5][2] = AL::ALValue::array(-1.38064, AL::ALValue::array(3, -0.253333, 0.000728725), AL::ALValue::array(3, 0.280000, -0.000805433));
    times[5][3] = 2.80000;
    keys[5][3] = AL::ALValue::array(-1.38218, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[5][4] = 3.04000;
    keys[5][4] = AL::ALValue::array(-1.38064, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LHipPitch");
    times[6].arraySetSize(5);
    keys[6].arraySetSize(5);

    times[6][0] = 0.440000;
    keys[6][0] = AL::ALValue::array(-0.464760, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[6][1] = 1.20000;
    keys[6][1] = AL::ALValue::array(-0.618161, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[6][2] = 1.96000;
    keys[6][2] = AL::ALValue::array(-0.616627, AL::ALValue::array(3, -0.253333, -0.000485813), AL::ALValue::array(3, 0.280000, 0.000536952));
    times[6][3] = 2.80000;
    keys[6][3] = AL::ALValue::array(-0.615092, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[6][4] = 3.04000;
    keys[6][4] = AL::ALValue::array(-0.622762, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LHipRoll");
    times[7].arraySetSize(5);
    keys[7].arraySetSize(5);

    times[7][0] = 0.440000;
    keys[7][0] = AL::ALValue::array(4.19617e-05, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[7][1] = 1.20000;
    keys[7][1] = AL::ALValue::array(0.493989, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[7][2] = 1.96000;
    keys[7][2] = AL::ALValue::array(0.493989, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[7][3] = 2.80000;
    keys[7][3] = AL::ALValue::array(0.492455, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[7][4] = 3.04000;
    keys[7][4] = AL::ALValue::array(0.493990, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LHipYawPitch");
    times[8].arraySetSize(5);
    keys[8].arraySetSize(5);

    times[8][0] = 0.440000;
    keys[8][0] = AL::ALValue::array(-0.00456004, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[8][1] = 1.20000;
    keys[8][1] = AL::ALValue::array(0.0614019, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[8][2] = 1.96000;
    keys[8][2] = AL::ALValue::array(0.0614019, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[8][3] = 2.80000;
    keys[8][3] = AL::ALValue::array(0.0614019, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[8][4] = 3.04000;
    keys[8][4] = AL::ALValue::array(0.0614020, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LKneePitch");
    times[9].arraySetSize(5);
    keys[9].arraySetSize(5);

    times[9][0] = 0.440000;
    keys[9][0] = AL::ALValue::array(0.794570, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[9][1] = 1.20000;
    keys[9][1] = AL::ALValue::array(1.04001, AL::ALValue::array(3, -0.253333, -0.00460241), AL::ALValue::array(3, 0.253333, 0.00460241));
    times[9][2] = 1.96000;
    keys[9][2] = AL::ALValue::array(1.04461, AL::ALValue::array(3, -0.253333, -0.00145717), AL::ALValue::array(3, 0.280000, 0.00161055));
    times[9][3] = 2.80000;
    keys[9][3] = AL::ALValue::array(1.04921, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[9][4] = 3.04000;
    keys[9][4] = AL::ALValue::array(1.04768, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LShoulderPitch");
    times[10].arraySetSize(5);
    keys[10].arraySetSize(5);

    times[10][0] = 0.440000;
    keys[10][0] = AL::ALValue::array(1.63213, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[10][1] = 1.20000;
    keys[10][1] = AL::ALValue::array(1.62600, AL::ALValue::array(3, -0.253333, 0.00357938), AL::ALValue::array(3, 0.253333, -0.00357938));
    times[10][2] = 1.96000;
    keys[10][2] = AL::ALValue::array(1.61066, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[10][3] = 2.80000;
    keys[10][3] = AL::ALValue::array(1.61526, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[10][4] = 3.04000;
    keys[10][4] = AL::ALValue::array(1.60299, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LShoulderRoll");
    times[11].arraySetSize(5);
    keys[11].arraySetSize(5);

    times[11][0] = 0.440000;
    keys[11][0] = AL::ALValue::array(0.601287, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[11][1] = 1.20000;
    keys[11][1] = AL::ALValue::array(0.592082, AL::ALValue::array(3, -0.253333, 0.00383506), AL::ALValue::array(3, 0.253333, -0.00383506));
    times[11][2] = 1.96000;
    keys[11][2] = AL::ALValue::array(0.578276, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[11][3] = 2.80000;
    keys[11][3] = AL::ALValue::array(0.578276, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[11][4] = 3.04000;
    keys[11][4] = AL::ALValue::array(0.576742, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RAnklePitch");
    times[12].arraySetSize(5);
    keys[12].arraySetSize(5);

    times[12][0] = 0.440000;
    keys[12][0] = AL::ALValue::array(-0.408002, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[12][1] = 1.20000;
    keys[12][1] = AL::ALValue::array(-0.0321720, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[12][2] = 1.96000;
    keys[12][2] = AL::ALValue::array(-0.880473, AL::ALValue::array(3, -0.253333, 0.0902144), AL::ALValue::array(3, 0.280000, -0.0997107));
    times[12][3] = 2.80000;
    keys[12][3] = AL::ALValue::array(-0.980184, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[12][4] = 3.04000;
    keys[12][4] = AL::ALValue::array(0.360532, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RAnkleRoll");
    times[13].arraySetSize(5);
    keys[13].arraySetSize(5);

    times[13][0] = 0.440000;
    keys[13][0] = AL::ALValue::array(0.00464395, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[13][1] = 1.20000;
    keys[13][1] = AL::ALValue::array(0.380475, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[13][2] = 1.96000;
    keys[13][2] = AL::ALValue::array(0.165714, AL::ALValue::array(3, -0.253333, 0.0333097), AL::ALValue::array(3, 0.280000, -0.0368160));
    times[13][3] = 2.80000;
    keys[13][3] = AL::ALValue::array(0.128898, AL::ALValue::array(3, -0.280000, 0.0119311), AL::ALValue::array(3, 0.0800000, -0.00340889));
    times[13][4] = 3.04000;
    keys[13][4] = AL::ALValue::array(0.119694, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RElbowRoll");
    times[14].arraySetSize(5);
    keys[14].arraySetSize(5);

    times[14][0] = 0.440000;
    keys[14][0] = AL::ALValue::array(0.00872665, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[14][1] = 1.20000;
    keys[14][1] = AL::ALValue::array(0.0245859, AL::ALValue::array(3, -0.253333, -0.00306812), AL::ALValue::array(3, 0.253333, 0.00306812));
    times[14][2] = 1.96000;
    keys[14][2] = AL::ALValue::array(0.0276540, AL::ALValue::array(3, -0.253333, -0.000971542), AL::ALValue::array(3, 0.280000, 0.00107381));
    times[14][3] = 2.80000;
    keys[14][3] = AL::ALValue::array(0.0307220, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[14][4] = 3.04000;
    keys[14][4] = AL::ALValue::array(0.0291880, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RElbowYaw");
    times[15].arraySetSize(5);
    keys[15].arraySetSize(5);

    times[15][0] = 0.440000;
    keys[15][0] = AL::ALValue::array(1.40817, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[15][1] = 1.20000;
    keys[15][1] = AL::ALValue::array(1.40203, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[15][2] = 1.96000;
    keys[15][2] = AL::ALValue::array(1.40510, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[15][3] = 2.80000;
    keys[15][3] = AL::ALValue::array(1.40357, AL::ALValue::array(3, -0.280000, 0.00119303), AL::ALValue::array(3, 0.0800000, -0.000340865));
    times[15][4] = 3.04000;
    keys[15][4] = AL::ALValue::array(1.40050, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RHipPitch");
    times[16].arraySetSize(5);
    keys[16].arraySetSize(5);

    times[16][0] = 0.440000;
    keys[16][0] = AL::ALValue::array(-0.466378, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[16][1] = 1.20000;
    keys[16][1] = AL::ALValue::array(-0.156510, AL::ALValue::array(3, -0.253333, -0.0871824), AL::ALValue::array(3, 0.253333, 0.0871824));
    times[16][2] = 1.96000;
    keys[16][2] = AL::ALValue::array(0.0567160, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[16][3] = 2.80000;
    keys[16][3] = AL::ALValue::array(0.00302603, AL::ALValue::array(3, -0.280000, 0.0536900), AL::ALValue::array(3, 0.0800000, -0.0153400));
    times[16][4] = 3.04000;
    keys[16][4] = AL::ALValue::array(-0.699546, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RHipRoll");
    times[17].arraySetSize(5);
    keys[17].arraySetSize(5);

    times[17][0] = 0.440000;
    keys[17][0] = AL::ALValue::array(-0.00456004, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[17][1] = 1.20000;
    keys[17][1] = AL::ALValue::array(0.282298, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[17][2] = 1.96000;
    keys[17][2] = AL::ALValue::array(0.257754, AL::ALValue::array(3, -0.253333, 0.0119013), AL::ALValue::array(3, 0.280000, -0.0131541));
    times[17][3] = 2.80000;
    keys[17][3] = AL::ALValue::array(0.207132, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[17][4] = 3.04000;
    keys[17][4] = AL::ALValue::array(0.280764, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RHipYawPitch");
    times[18].arraySetSize(5);
    keys[18].arraySetSize(5);

    times[18][0] = 0.440000;
    keys[18][0] = AL::ALValue::array(-0.00456004, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[18][1] = 1.20000;
    keys[18][1] = AL::ALValue::array(0.0614019, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[18][2] = 1.96000;
    keys[18][2] = AL::ALValue::array(0.0614019, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[18][3] = 2.80000;
    keys[18][3] = AL::ALValue::array(0.0614019, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[18][4] = 3.04000;
    keys[18][4] = AL::ALValue::array(0.0614020, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RKneePitch");
    times[19].arraySetSize(5);
    keys[19].arraySetSize(5);

    times[19][0] = 0.440000;
    keys[19][0] = AL::ALValue::array(0.797722, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[19][1] = 1.20000;
    keys[19][1] = AL::ALValue::array(-0.00302603, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[19][2] = 1.96000;
    keys[19][2] = AL::ALValue::array(0.859083, AL::ALValue::array(3, -0.253333, -0.279802), AL::ALValue::array(3, 0.280000, 0.309255));
    times[19][3] = 2.80000;
    keys[19][3] = AL::ALValue::array(1.76414, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[19][4] = 3.04000;
    keys[19][4] = AL::ALValue::array(-0.0923279, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RShoulderPitch");
    times[20].arraySetSize(5);
    keys[20].arraySetSize(5);

    times[20][0] = 0.440000;
    keys[20][0] = AL::ALValue::array(1.52944, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[20][1] = 1.20000;
    keys[20][1] = AL::ALValue::array(1.50950, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[20][2] = 1.96000;
    keys[20][2] = AL::ALValue::array(1.51103, AL::ALValue::array(3, -0.253333, -0.000728451), AL::ALValue::array(3, 0.280000, 0.000805130));
    times[20][3] = 2.80000;
    keys[20][3] = AL::ALValue::array(1.51410, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[20][4] = 3.04000;
    keys[20][4] = AL::ALValue::array(1.50643, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RShoulderRoll");
    times[21].arraySetSize(5);
    keys[21].arraySetSize(5);

    times[21][0] = 0.440000;
    keys[21][0] = AL::ALValue::array(-0.779314, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[21][1] = 1.20000;
    keys[21][1] = AL::ALValue::array(-0.739430, AL::ALValue::array(3, -0.253333, -0.00613479), AL::ALValue::array(3, 0.253333, 0.00613479));
    times[21][2] = 1.96000;
    keys[21][2] = AL::ALValue::array(-0.733295, AL::ALValue::array(3, -0.253333, -0.00170007), AL::ALValue::array(3, 0.280000, 0.00187902));
    times[21][3] = 2.80000;
    keys[21][3] = AL::ALValue::array(-0.728692, AL::ALValue::array(3, -0.280000, -0.00238645), AL::ALValue::array(3, 0.0800000, 0.000681843));
    times[21][4] = 3.04000;
    keys[21][4] = AL::ALValue::array(-0.724090, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    try
    {
    // motion.moveTo(0.165,0,0);
    motion.angleInterpolationBezier(names, times, keys);
    posture.goToPosture("StandInit", 0.5);
    }
    catch(const std::exception&)
    {
     cout << "Error in kick " << endl;
    }
}

void leftFootKick(AL::ALRobotPostureProxy &posture, AL::ALMotionProxy &motion, ALTextToSpeechProxy &say){
    std::vector<std::string> names;
    AL::ALValue times, keys;

    say.setVolume(1);
    say.say("KICK");


    motion.moveTo(0.0,-0.03,0);
    motion.moveTo(0,0.0,(5*M_PI/180));

    names.reserve(22);
    times.arraySetSize(22);
    keys.arraySetSize(22);

    names.push_back("HeadPitch");
    times[0].arraySetSize(5);
    keys[0].arraySetSize(5);

    times[0][0] = 0.440000;
    keys[0][0] = AL::ALValue::array(-0.0245020, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[0][1] = 1.20000;
    keys[0][1] = AL::ALValue::array(-0.0214340, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[0][2] = 1.96000;
    keys[0][2] = AL::ALValue::array(-0.0229680, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[0][3] = 2.80000;
    keys[0][3] = AL::ALValue::array(-0.0214340, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[0][4] = 3.04000;
    keys[0][4] = AL::ALValue::array(-0.0229680, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("HeadYaw");
    times[1].arraySetSize(5);
    keys[1].arraySetSize(5);

    times[1][0] = 0.440000;
    keys[1][0] = AL::ALValue::array(-0.00617796, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[1][1] = 1.20000;
    keys[1][1] = AL::ALValue::array(-0.00924597, AL::ALValue::array(3, -0.253333, 0.000766999), AL::ALValue::array(3, 0.253333, -0.000766999));
    times[1][2] = 1.96000;
    keys[1][2] = AL::ALValue::array(-0.0107800, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[1][3] = 2.80000;
    keys[1][3] = AL::ALValue::array(-0.00310997, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[1][4] = 3.04000;
    keys[1][4] = AL::ALValue::array(-0.0107800, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RAnklePitch");
    times[2].arraySetSize(5);
    keys[2].arraySetSize(5);

    times[2][0] = 0.440000;
    keys[2][0] = AL::ALValue::array(-0.408086, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[2][1] = 1.20000;
    keys[2][1] = AL::ALValue::array(-0.567621, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[2][2] = 1.96000;
    keys[2][2] = AL::ALValue::array(-0.567621, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[2][3] = 2.80000;
    keys[2][3] = AL::ALValue::array(-0.567621, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[2][4] = 3.04000;
    keys[2][4] = AL::ALValue::array(-0.576826, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RAnkleRoll");
    times[3].arraySetSize(5);
    keys[3].arraySetSize(5);

    times[3][0] = 0.440000;
    keys[3][0] = AL::ALValue::array(0.00302603, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[3][1] = 1.20000;
    keys[3][1] = AL::ALValue::array(-0.0521979, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[3][2] = 1.96000;
    keys[3][2] = AL::ALValue::array(-0.0521979, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[3][3] = 2.80000;
    keys[3][3] = AL::ALValue::array(-0.0521979, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[3][4] = 3.04000;
    keys[3][4] = AL::ALValue::array(-0.0521980, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RElbowRoll");
    times[4].arraySetSize(5);
    keys[4].arraySetSize(5);

    times[4][0] = 0.440000;
    keys[4][0] = AL::ALValue::array(0.00872665, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[4][1] = 1.20000;
    keys[4][1] = AL::ALValue::array(0.0306380, AL::ALValue::array(3, -0.253333, 0.00441891), AL::ALValue::array(3, 0.253333, -0.00441891));
    times[4][2] = 1.96000;
    keys[4][2] = AL::ALValue::array(0.0352401, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[4][3] = 2.80000;
    keys[4][3] = AL::ALValue::array(0.0306380, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[4][4] = 3.04000;
    keys[4][4] = AL::ALValue::array(0.0352400, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RElbowYaw");
    times[5].arraySetSize(5);
    keys[5].arraySetSize(5);

    times[5][0] = 0.440000;
    keys[5][0] = AL::ALValue::array(1.37451, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[5][1] = 1.20000;
    keys[5][1] = AL::ALValue::array(1.37757, AL::ALValue::array(3, -0.253333, 0.00102276), AL::ALValue::array(3, 0.253333, -0.00102276));
    times[5][2] = 1.96000;
    keys[5][2] = AL::ALValue::array(1.38064, AL::ALValue::array(3, -0.253333, 0.000728725), AL::ALValue::array(3, 0.280000, -0.000805433));
    times[5][3] = 2.80000;
    keys[5][3] = AL::ALValue::array(1.38218, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[5][4] = 3.04000;
    keys[5][4] = AL::ALValue::array(1.38064, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RHipPitch");
    times[6].arraySetSize(5);
    keys[6].arraySetSize(5);

    times[6][0] = 0.440000;
    keys[6][0] = AL::ALValue::array(-0.464760, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[6][1] = 1.20000;
    keys[6][1] = AL::ALValue::array(-0.618161, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[6][2] = 1.96000;
    keys[6][2] = AL::ALValue::array(-0.616627, AL::ALValue::array(3, -0.253333, -0.000485813), AL::ALValue::array(3, 0.280000, 0.000536952));
    times[6][3] = 2.80000;
    keys[6][3] = AL::ALValue::array(-0.615092, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[6][4] = 3.04000;
    keys[6][4] = AL::ALValue::array(-0.622762, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RHipRoll");
    times[7].arraySetSize(5);
    keys[7].arraySetSize(5);

    times[7][0] = 0.440000;
    keys[7][0] = AL::ALValue::array(-4.19617e-05, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[7][1] = 1.20000;
    keys[7][1] = AL::ALValue::array(-0.493989, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[7][2] = 1.96000;
    keys[7][2] = AL::ALValue::array(-0.493989, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[7][3] = 2.80000;
    keys[7][3] = AL::ALValue::array(-0.492455, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[7][4] = 3.04000;
    keys[7][4] = AL::ALValue::array(-0.493990, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RHipYawPitch");
    times[8].arraySetSize(5);
    keys[8].arraySetSize(5);

    times[8][0] = 0.440000;
    keys[8][0] = AL::ALValue::array(-0.00456004, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[8][1] = 1.20000;
    keys[8][1] = AL::ALValue::array(0.0614019, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[8][2] = 1.96000;
    keys[8][2] = AL::ALValue::array(0.0614019, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[8][3] = 2.80000;
    keys[8][3] = AL::ALValue::array(0.0614019, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[8][4] = 3.04000;
    keys[8][4] = AL::ALValue::array(0.0614020, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RKneePitch");
    times[9].arraySetSize(5);
    keys[9].arraySetSize(5);

    times[9][0] = 0.440000;
    keys[9][0] = AL::ALValue::array(0.794570, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[9][1] = 1.20000;
    keys[9][1] = AL::ALValue::array(1.04001, AL::ALValue::array(3, -0.253333, -0.00460241), AL::ALValue::array(3, 0.253333, 0.00460241));
    times[9][2] = 1.96000;
    keys[9][2] = AL::ALValue::array(1.04461, AL::ALValue::array(3, -0.253333, -0.00145717), AL::ALValue::array(3, 0.280000, 0.00161055));
    times[9][3] = 2.80000;
    keys[9][3] = AL::ALValue::array(1.04921, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[9][4] = 3.04000;
    keys[9][4] = AL::ALValue::array(1.04768, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RShoulderPitch");
    times[10].arraySetSize(5);
    keys[10].arraySetSize(5);

    times[10][0] = 0.440000;
    keys[10][0] = AL::ALValue::array(1.63213, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[10][1] = 1.20000;
    keys[10][1] = AL::ALValue::array(1.62600, AL::ALValue::array(3, -0.253333, 0.00357938), AL::ALValue::array(3, 0.253333, -0.00357938));
    times[10][2] = 1.96000;
    keys[10][2] = AL::ALValue::array(1.61066, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[10][3] = 2.80000;
    keys[10][3] = AL::ALValue::array(1.61526, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[10][4] = 3.04000;
    keys[10][4] = AL::ALValue::array(1.60299, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("RShoulderRoll");
    times[11].arraySetSize(5);
    keys[11].arraySetSize(5);

    times[11][0] = 0.440000;
    keys[11][0] = AL::ALValue::array(-0.601287, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[11][1] = 1.20000;
    keys[11][1] = AL::ALValue::array(-0.592082, AL::ALValue::array(3, -0.253333, 0.00383506), AL::ALValue::array(3, 0.253333, -0.00383506));
    times[11][2] = 1.96000;
    keys[11][2] = AL::ALValue::array(-0.578276, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[11][3] = 2.80000;
    keys[11][3] = AL::ALValue::array(-0.578276, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[11][4] = 3.04000;
    keys[11][4] = AL::ALValue::array(-0.576742, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LAnklePitch");
    times[12].arraySetSize(5);
    keys[12].arraySetSize(5);

    times[12][0] = 0.440000;
    keys[12][0] = AL::ALValue::array(-0.408002, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[12][1] = 1.20000;
    keys[12][1] = AL::ALValue::array(-0.0321720, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[12][2] = 1.96000;
    keys[12][2] = AL::ALValue::array(-0.880473, AL::ALValue::array(3, -0.253333, 0.0902144), AL::ALValue::array(3, 0.280000, -0.0997107));
    times[12][3] = 2.80000;
    keys[12][3] = AL::ALValue::array(-0.980184, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[12][4] = 3.04000;
    keys[12][4] = AL::ALValue::array(0.360532, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LAnkleRoll");
    times[13].arraySetSize(5);
    keys[13].arraySetSize(5);

    times[13][0] = 0.440000;
    keys[13][0] = AL::ALValue::array(-0.00464395, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[13][1] = 1.20000;
    keys[13][1] = AL::ALValue::array(-0.380475, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[13][2] = 1.96000;
    keys[13][2] = AL::ALValue::array(-0.165714, AL::ALValue::array(3, -0.253333, 0.0333097), AL::ALValue::array(3, 0.280000, -0.0368160));
    times[13][3] = 2.80000;
    keys[13][3] = AL::ALValue::array(-0.128898, AL::ALValue::array(3, -0.280000, 0.0119311), AL::ALValue::array(3, 0.0800000, -0.00340889));
    times[13][4] = 3.04000;
    keys[13][4] = AL::ALValue::array(-0.119694, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LElbowRoll");
    times[14].arraySetSize(5);
    keys[14].arraySetSize(5);

    times[14][0] = 0.440000;
    keys[14][0] = AL::ALValue::array(-0.00872665, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[14][1] = 1.20000;
    keys[14][1] = AL::ALValue::array(-0.0245859, AL::ALValue::array(3, -0.253333, -0.00306812), AL::ALValue::array(3, 0.253333, 0.00306812));
    times[14][2] = 1.96000;
    keys[14][2] = AL::ALValue::array(-0.0276540, AL::ALValue::array(3, -0.253333, -0.000971542), AL::ALValue::array(3, 0.280000, 0.00107381));
    times[14][3] = 2.80000;
    keys[14][3] = AL::ALValue::array(-0.0307220, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[14][4] = 3.04000;
    keys[14][4] = AL::ALValue::array(-0.0291880, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LElbowYaw");
    times[15].arraySetSize(5);
    keys[15].arraySetSize(5);

    times[15][0] = 0.440000;
    keys[15][0] = AL::ALValue::array(-1.40817, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[15][1] = 1.20000;
    keys[15][1] = AL::ALValue::array(-1.40203, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[15][2] = 1.96000;
    keys[15][2] = AL::ALValue::array(-1.40510, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[15][3] = 2.80000;
    keys[15][3] = AL::ALValue::array(-1.40357, AL::ALValue::array(3, -0.280000, 0.00119303), AL::ALValue::array(3, 0.0800000, -0.000340865));
    times[15][4] = 3.04000;
    keys[15][4] = AL::ALValue::array(-1.40050, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LHipPitch");
    times[16].arraySetSize(5);
    keys[16].arraySetSize(5);

    times[16][0] = 0.440000;
    keys[16][0] = AL::ALValue::array(-0.466378, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[16][1] = 1.20000;
    keys[16][1] = AL::ALValue::array(-0.156510, AL::ALValue::array(3, -0.253333, -0.0871824), AL::ALValue::array(3, 0.253333, 0.0871824));
    times[16][2] = 1.96000;
    keys[16][2] = AL::ALValue::array(0.0567160, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[16][3] = 2.80000;
    keys[16][3] = AL::ALValue::array(0.00302603, AL::ALValue::array(3, -0.280000, 0.0536900), AL::ALValue::array(3, 0.0800000, -0.0153400));
    times[16][4] = 3.04000;
    keys[16][4] = AL::ALValue::array(-0.699546, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LHipRoll");
    times[17].arraySetSize(5);
    keys[17].arraySetSize(5);

    times[17][0] = 0.440000;
    keys[17][0] = AL::ALValue::array(0.00456004, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[17][1] = 1.20000;
    keys[17][1] = AL::ALValue::array(-0.282298, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[17][2] = 1.96000;
    keys[17][2] = AL::ALValue::array(-0.257754, AL::ALValue::array(3, -0.253333, 0.0119013), AL::ALValue::array(3, 0.280000, -0.0131541));
    times[17][3] = 2.80000;
    keys[17][3] = AL::ALValue::array(-0.207132, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[17][4] = 3.04000;
    keys[17][4] = AL::ALValue::array(-0.280764, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LHipYawPitch");
    times[18].arraySetSize(5);
    keys[18].arraySetSize(5);

    times[18][0] = 0.440000;
    keys[18][0] = AL::ALValue::array(-0.00456004, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[18][1] = 1.20000;
    keys[18][1] = AL::ALValue::array(0.0614019, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[18][2] = 1.96000;
    keys[18][2] = AL::ALValue::array(0.0614019, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.280000, 0.00000));
    times[18][3] = 2.80000;
    keys[18][3] = AL::ALValue::array(0.0614019, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[18][4] = 3.04000;
    keys[18][4] = AL::ALValue::array(0.0614020, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LKneePitch");
    times[19].arraySetSize(5);
    keys[19].arraySetSize(5);

    times[19][0] = 0.440000;
    keys[19][0] = AL::ALValue::array(0.797722, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[19][1] = 1.20000;
    keys[19][1] = AL::ALValue::array(-0.00302603, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[19][2] = 1.96000;
    keys[19][2] = AL::ALValue::array(0.859083, AL::ALValue::array(3, -0.253333, -0.279802), AL::ALValue::array(3, 0.280000, 0.309255));
    times[19][3] = 2.80000;
    keys[19][3] = AL::ALValue::array(1.76414, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[19][4] = 3.04000;
    keys[19][4] = AL::ALValue::array(-0.0923279, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LShoulderPitch");
    times[20].arraySetSize(5);
    keys[20].arraySetSize(5);

    times[20][0] = 0.440000;
    keys[20][0] = AL::ALValue::array(1.52944, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[20][1] = 1.20000;
    keys[20][1] = AL::ALValue::array(1.50950, AL::ALValue::array(3, -0.253333, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[20][2] = 1.96000;
    keys[20][2] = AL::ALValue::array(1.51103, AL::ALValue::array(3, -0.253333, -0.000728451), AL::ALValue::array(3, 0.280000, 0.000805130));
    times[20][3] = 2.80000;
    keys[20][3] = AL::ALValue::array(1.51410, AL::ALValue::array(3, -0.280000, -0.00000), AL::ALValue::array(3, 0.0800000, 0.00000));
    times[20][4] = 3.04000;
    keys[20][4] = AL::ALValue::array(1.50643, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    names.push_back("LShoulderRoll");
    times[21].arraySetSize(5);
    keys[21].arraySetSize(5);

    times[21][0] = 0.440000;
    keys[21][0] = AL::ALValue::array(0.779314, AL::ALValue::array(3, -0.146667, -0.00000), AL::ALValue::array(3, 0.253333, 0.00000));
    times[21][1] = 1.20000;
    keys[21][1] = AL::ALValue::array(0.739430, AL::ALValue::array(3, -0.253333, -0.00613479), AL::ALValue::array(3, 0.253333, 0.00613479));
    times[21][2] = 1.96000;
    keys[21][2] = AL::ALValue::array(0.733295, AL::ALValue::array(3, -0.253333, -0.00170007), AL::ALValue::array(3, 0.280000, 0.00187902));
    times[21][3] = 2.80000;
    keys[21][3] = AL::ALValue::array(0.728692, AL::ALValue::array(3, -0.280000, -0.00238645), AL::ALValue::array(3, 0.0800000, 0.000681843));
    times[21][4] = 3.04000;
    keys[21][4] = AL::ALValue::array(0.724090, AL::ALValue::array(3, -0.0800000, -0.00000), AL::ALValue::array(3, 0.00000, 0.00000));

    try
    {
    // motion.moveTo(0.165,0,0);
    motion.angleInterpolationBezier(names, times, keys);
    posture.goToPosture("StandInit", 0.5);
    }
    catch(const std::exception&)
    {
      cout << "Error in kick2 " << endl;
    }
}



 int main( int argc, char** argv )
 {
    /*AL::ALRobotPostureProxy posture("127.0.0.1", 9559);
    AL::ALMotionProxy motion("127.0.0.1", 9559);
    ALTextToSpeechProxy say("127.0.0.1",9559);*/
    AL::ALRobotPostureProxy posture("192.168.0.103", 9559);
    AL::ALMotionProxy motion("192.168.0.103", 9559);
    ALTextToSpeechProxy say("192.168.0.103",9559);
     
    //motion.setFallManagerEnabled(false);
    posture.goToPosture("StandInit", 0.5);
    
    for(int i=0;i<1;i++){
        rightFootKick(posture, motion, say);
//        leftFootKick(posture, motion, say);
    }
    return 0;
}


/*

 int main( int argc, char** argv )

           if ((postura == "LyingBelly")||(postura == "LyingBack")||(postura == "Back"))
           {
              posture.goToPosture("Stand",1);
           }
            imshow("Thresholded Image", imgThresholded); //show the thresholded image
            imshow("Src", frame); //show the original image
            key = waitKey(50);
        }
        contFrames++;
    }
   camProxy.unsubscribe(clientName);

   return 0;
}
*/