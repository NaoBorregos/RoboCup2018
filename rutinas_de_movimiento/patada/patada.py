import almath
import time
import argparse
import qi
import sys
from naoqi import ALProxy

#void robot1(AL::ALRobotPostureProxy posture, AL::ALMotionProxy motion, AL::ALVideoDeviceProxy camProxy, AL::ALLandMarkDetectionProxy naoMark, AL::ALMemoryProxy memProxy);
#int getOrientation(vector<Point> &pts, Mat &img);

# TODO Esta cosa esta lentisima por no pre-alojar el tama;o de los arreglos
def rightFootKick(posture, motion):
    names = []
    times = []
    keys = []

    #motion.moveTo(0.0,0.03,0);
    #motion.moveTo(0,0.0,(-5*M_PI/180));
    #names.reserve(22);
    #times.arraySetSize(22);
    #keys.arraySetSize(22);

    names.append("HeadPitch");
    times.append([])
    keys.append([])
    
    
    time_delay = 1
    '''
    delay1 = 0.44000 * time_delay
    delay2 = 1.20000 * time_delay
    delay3 = 1.96000 * time_delay
    delay4 = 2.80000 * time_delay
    delay5 = 3.04000 * time_delay
    
    '''
    delay1 = 0.44000 * time_delay
    delay2 = 1.20000 * time_delay
    delay3 = 1.96000 * time_delay
    delay4 = 2.80000 * time_delay
    delay5 = 3.04000 * time_delay
    
    

    times[0].append(delay1)
    keys[0].append([0.0245020, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[0].append(delay2)
    keys[0].append([0.0214340, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[0].append(delay3)
    keys[0].append([0.0229680, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[0].append(delay4)
    keys[0].append([0.0214340, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[0].append(delay5)
    keys[0].append([0.0229680, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("HeadYaw")
    times.append([])
    keys.append([])

    times[1].append(delay1)
    keys[1].append([-0.00617796, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[1].append(delay2)
    keys[1].append([-0.00924597, [3, -0.253333, 0.000766999], [3, 0.253333, -0.000766999]])
    times[1].append(delay3)
    keys[1].append([-0.0107800, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[1].append(delay4)
    keys[1].append([-0.00310997, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[1].append(delay5)
    keys[1].append([-0.0107800, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LAnklePitch")
    times.append([])
    keys.append([])

    times[2].append(delay1)
    keys[2].append([-0.408086, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[2].append(delay2)
    keys[2].append([-0.567621, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[2].append(delay3)
    keys[2].append([-0.567621, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[2].append(delay4)
    keys[2].append([-0.567621, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[2].append(delay5)
    keys[2].append([-0.576826, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LAnkleRoll")
    times.append([])
    keys.append([])

    times[3].append(delay1)
    keys[3].append([-0.00302603, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[3].append(delay2)
    keys[3].append([0.0521979, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[3].append(delay3)
    keys[3].append([0.0521979, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[3].append(delay4)
    keys[3].append([0.0521979, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[3].append(delay5)
    keys[3].append([0.0521980, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LElbowRoll")
    times.append([])
    keys.append([])

    times[4].append(delay1)
    keys[4].append([-0.00872665, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[4].append(delay2)
    keys[4].append([-0.0306380, [3, -0.253333, 0.00441891], [3, 0.253333, -0.00441891]])
    times[4].append(delay3)
    keys[4].append([-0.0352401, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[4].append(delay4)
    keys[4].append([-0.0306380, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[4].append(delay5)
    keys[4].append([-0.0352400, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LElbowYaw")
    times.append([])
    keys.append([])

    times[5].append(delay1)
    keys[5].append([-1.37451, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[5].append(delay2)
    keys[5].append([-1.37757, [3, -0.253333, 0.00102276], [3, 0.253333, -0.00102276]])
    times[5].append(delay3)
    keys[5].append([-1.38064, [3, -0.253333, 0.000728725], [3, 0.280000, -0.000805433]])
    times[5].append(delay4)
    keys[5].append([-1.38218, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[5].append(delay5)
    keys[5].append([-1.38064, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LHipPitch")
    times.append([])
    keys.append([])

    times[6].append(delay1)
    keys[6].append([-0.464760, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[6].append(delay2)
    keys[6].append([-0.618161, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[6].append(delay3)
    keys[6].append([-0.616627, [3, -0.253333, -0.000485813], [3, 0.280000, 0.000536952]])
    times[6].append(delay4)
    keys[6].append([-0.615092, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[6].append(delay5)
    keys[6].append([-0.622762, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LHipRoll")
    times.append([])
    keys.append([])

    times[7].append(delay1)
    keys[7].append([4.19617e-05, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[7].append(delay2)
    keys[7].append([0.493989, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[7].append(delay3)
    keys[7].append([0.493989, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[7].append(delay4)
    keys[7].append([0.492455, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[7].append(delay5)
    keys[7].append([0.493990, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LHipYawPitch")
    times.append([])
    keys.append([])

    times[8].append(delay1)
    keys[8].append([-0.00456004, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[8].append(delay2)
    keys[8].append([0.0614019, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[8].append(delay3)
    keys[8].append([0.0614019, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[8].append(delay4)
    keys[8].append([0.0614019, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[8].append(delay5)
    keys[8].append([0.0614020, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LKneePitch")
    times.append([])
    keys.append([])

    times[9].append(delay1)
    keys[9].append([0.794570, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[9].append(delay2)
    keys[9].append([1.04001, [3, -0.253333, -0.00460241], [3, 0.253333, 0.00460241]])
    times[9].append(delay3)
    keys[9].append([1.04461, [3, -0.253333, -0.00145717], [3, 0.280000, 0.00161055]])
    times[9].append(delay4)
    keys[9].append([1.04921, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[9].append(delay5)
    keys[9].append([1.04768, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LShoulderPitch")
    times.append([])
    keys.append([])

    times[10].append(delay1)
    keys[10].append([1.63213, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[10].append(delay2)
    keys[10].append([1.62600, [3, -0.253333, 0.00357938], [3, 0.253333, -0.00357938]])
    times[10].append(delay3)
    keys[10].append([1.61066, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[10].append(delay4)
    keys[10].append([1.61526, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[10].append(delay5)
    keys[10].append([1.60299, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LShoulderRoll")
    times.append([])
    keys.append([])

    times[11].append(delay1)
    keys[11].append([0.601287, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[11].append(delay2)
    keys[11].append([0.592082, [3, -0.253333, 0.00383506], [3, 0.253333, -0.00383506]])
    times[11].append(delay3)
    keys[11].append([0.578276, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[11].append(delay4)
    keys[11].append([0.578276, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[11].append(delay5)
    keys[11].append([0.576742, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RAnklePitch")
    times.append([])
    keys.append([])

    times[12].append(delay1)
    keys[12].append([-0.408002, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[12].append(delay2)
    keys[12].append([-0.1321720, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    #keys[12].append([-0.0321720, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[12].append(delay3)
    keys[12].append([-0.880473, [3, -0.253333, 0.0902144], [3, 0.280000, -0.0997107]])
    times[12].append(delay4)
    #keys[12].append([-0.980184, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    keys[12].append([-0.50184, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[12].append(delay5)
    keys[12].append([0.360532, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RAnkleRoll")
    times.append([])
    keys.append([])

    times[13].append(delay1)
    keys[13].append([0.00464395, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[13].append(delay2)
    keys[13].append([0.180475, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    #keys[13].append([0.380475, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[13].append(delay3)
    keys[13].append([0.165714, [3, -0.253333, 0.0333097], [3, 0.280000, -0.0368160]])
    times[13].append(delay4)
    keys[13].append([0.128898, [3, -0.280000, 0.0119311], [3, 0.0800000, -0.00340889]])
    times[13].append(delay5)
    keys[13].append([0.119694, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RElbowRoll")
    times.append([])
    keys.append([])

    times[14].append(delay1)
    keys[14].append([0.00872665, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[14].append(delay2)
    keys[14].append([0.0245859, [3, -0.253333, -0.00306812], [3, 0.253333, 0.00306812]])
    times[14].append(delay3)
    keys[14].append([0.0276540, [3, -0.253333, -0.000971542], [3, 0.280000, 0.00107381]])
    times[14].append(delay4)
    keys[14].append([0.0307220, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[14].append(delay5)
    keys[14].append([0.0291880, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RElbowYaw")
    times.append([])
    keys.append([])

    times[15].append(delay1)
    keys[15].append([1.40817, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[15].append(delay2)
    keys[15].append([1.40203, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[15].append(delay3)
    keys[15].append([1.40510, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[15].append(delay4)
    keys[15].append([1.40357, [3, -0.280000, 0.00119303], [3, 0.0800000, -0.000340865]])
    times[15].append(delay5)
    keys[15].append([1.40050, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RHipPitch")
    times.append([])
    keys.append([])

    times[16].append(delay1)
    keys[16].append([-0.466378, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[16].append(delay2)
    keys[16].append([-0.156510, [3, -0.253333, -0.0871824], [3, 0.253333, 0.0871824]])
    times[16].append(delay3)
    keys[16].append([0.0567160, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[16].append(delay4)
    keys[16].append([0.00302603, [3, -0.280000, 0.0536900], [3, 0.0800000, -0.0153400]])
    times[16].append(delay5)
    keys[16].append([-0.699546, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RHipRoll")
    times.append([])
    keys.append([])

    times[17].append(delay1)
    keys[17].append([-0.00456004, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[17].append(delay2)
    keys[17].append([0.282298, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[17].append(delay3)
    keys[17].append([0.257754, [3, -0.253333, 0.0119013], [3, 0.280000, -0.0131541]])
    times[17].append(delay4)
    keys[17].append([0.207132, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[17].append(delay5)
    keys[17].append([0.280764, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RHipYawPitch")
    times.append([])
    keys.append([])

    times[18].append(delay1)
    keys[18].append([-0.00456004, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[18].append(delay2)
    keys[18].append([0.0614019, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[18].append(delay3)
    keys[18].append([0.0614019, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[18].append(delay4)
    keys[18].append([0.0614019, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[18].append(delay5)
    keys[18].append([0.0614020, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RKneePitch")
    times.append([])
    keys.append([])

    times[19].append(delay1)
    keys[19].append([0.797722, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[19].append(delay2)
    keys[19].append([0.50302603, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    #keys[19].append([-0.00302603, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[19].append(delay3)
    keys[19].append([0.859083, [3, -0.253333, -0.279802], [3, 0.280000, 0.309255]])
    times[19].append(delay4)
    keys[19].append([0.5000, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    #keys[19].append([1.76414, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[19].append(delay5)
    keys[19].append([-0.0923279, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RShoulderPitch")
    times.append([])
    keys.append([])

    times[20].append(delay1)
    keys[20].append([1.52944, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[20].append(delay2)
    keys[20].append([1.50950, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[20].append(delay3)
    keys[20].append([1.51103, [3, -0.253333, -0.000728451], [3, 0.280000, 0.000805130]])
    times[20].append(delay4)
    keys[20].append([1.51410, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[20].append(delay5)
    keys[20].append([1.50643, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RShoulderRoll")
    times.append([])
    keys.append([])

    times[21].append(delay1)
    keys[21].append([-0.779314, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[21].append(delay2)
    keys[21].append([-0.739430, [3, -0.253333, -0.00613479], [3, 0.253333, 0.00613479]])
    times[21].append(delay3)
    keys[21].append([-0.733295, [3, -0.253333, -0.00170007], [3, 0.280000, 0.00187902]])
    times[21].append(delay4)
    keys[21].append([-0.728692, [3, -0.280000, -0.00238645], [3, 0.0800000, 0.000681843]])
    times[21].append(delay5)
    keys[21].append([-0.724090, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    try:
        motion.angleInterpolationBezier(names, times, keys);
        #posture.goToPosture("StandInit", 0.5);
        motion.moveTo(0.01,0,0);
    except:
        print("Error in Right kick")
    

def leftFootKick(posture, motion):
    names = []
    times = []
    keys = []

    #motion.moveTo(0.0,-0.03,0);
    #motion.moveTo(0,0.0,(5*M_PI/180]])

    #names.reserve(22);
    #times.arraySetSize(22);
    #keys.arraySetSize(22);

    names.append("HeadPitch");
    times.append([])
    keys.append([])

    times[0].append(delay1)
    keys[0].append([-0.0245020, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[0].append(delay2)
    keys[0].append([-0.0214340, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[0].append(delay3)
    keys[0].append([-0.0229680, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[0].append(delay4)
    keys[0].append([-0.0214340, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[0].append(delay5)
    keys[0].append([-0.0229680, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("HeadYaw")
    times.append([])
    keys.append([])

    times[1].append(delay1)
    keys[1].append([-0.00617796, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[1].append(delay2)
    keys[1].append([-0.00924597, [3, -0.253333, 0.000766999], [3, 0.253333, -0.000766999]])
    times[1].append(delay3)
    keys[1].append([-0.0107800, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[1].append(delay4)
    keys[1].append([-0.00310997, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[1].append(delay5)
    keys[1].append([-0.0107800, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RAnklePitch")
    times.append([])
    keys.append([])

    times[2].append(delay1)
    keys[2].append([-0.408086, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[2].append(delay2)
    keys[2].append([-0.567621, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[2].append(delay3)
    keys[2].append([-0.567621, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[2].append(delay4)
    keys[2].append([-0.567621, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[2].append(delay5)
    keys[2].append([-0.576826, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RAnkleRoll")
    times.append([])
    keys.append([])

    times[3].append(delay1)
    keys[3].append([0.00302603, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[3].append(delay2)
    keys[3].append([-0.0521979, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[3].append(delay3)
    keys[3].append([-0.0521979, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[3].append(delay4)
    keys[3].append([-0.0521979, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[3].append(delay5)
    keys[3].append([-0.0521980, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RElbowRoll")
    times.append([])
    keys.append([])

    times[4].append(delay1)
    keys[4].append([0.00872665, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[4].append(delay2)
    keys[4].append([0.0306380, [3, -0.253333, 0.00441891], [3, 0.253333, -0.00441891]])
    times[4].append(delay3)
    keys[4].append([0.0352401, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[4].append(delay4)
    keys[4].append([0.0306380, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[4].append(delay5)
    keys[4].append([0.0352400, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RElbowYaw")
    times.append([])
    keys.append([])

    times[5].append(delay1)
    keys[5].append([1.37451, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[5].append(delay2)
    keys[5].append([1.37757, [3, -0.253333, 0.00102276], [3, 0.253333, -0.00102276]])
    times[5].append(delay3)
    keys[5].append([1.38064, [3, -0.253333, 0.000728725], [3, 0.280000, -0.000805433]])
    times[5].append(delay4)
    keys[5].append([1.38218, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[5].append(delay5)
    keys[5].append([1.38064, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RHipPitch")
    times.append([])
    keys.append([])

    times[6].append(delay1)
    keys[6].append([-0.464760, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[6].append(delay2)
    keys[6].append([-0.618161, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[6].append(delay3)
    keys[6].append([-0.616627, [3, -0.253333, -0.000485813], [3, 0.280000, 0.000536952]])
    times[6].append(delay4)
    keys[6].append([-0.615092, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[6].append(delay5)
    keys[6].append([-0.622762, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RHipRoll")
    times.append([])
    keys.append([])

    times[7].append(delay1)
    keys[7].append([-4.19617e-05, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[7].append(delay2)
    keys[7].append([-0.493989, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[7].append(delay3)
    keys[7].append([-0.493989, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[7].append(delay4)
    keys[7].append([-0.492455, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[7].append(delay5)
    keys[7].append([-0.493990, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RHipYawPitch")
    times.append([])
    keys.append([])

    times[8].append(delay1)
    keys[8].append([-0.00456004, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[8].append(delay2)
    keys[8].append([0.0614019, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[8].append(delay3)
    keys[8].append([0.0614019, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[8].append(delay4)
    keys[8].append([0.0614019, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[8].append(delay5)
    keys[8].append([0.0614020, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RKneePitch")
    times.append([])
    keys.append([])

    times[9].append(delay1)
    keys[9].append([0.794570, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[9].append(delay2)
    keys[9].append([1.04001, [3, -0.253333, -0.00460241], [3, 0.253333, 0.00460241]])
    times[9].append(delay3)
    keys[9].append([1.04461, [3, -0.253333, -0.00145717], [3, 0.280000, 0.00161055]])
    times[9].append(delay4)
    keys[9].append([1.04921, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[9].append(delay5)
    keys[9].append([1.04768, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RShoulderPitch")
    times.append([])
    keys.append([])

    times[10].append(delay1)
    keys[10].append([1.63213, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[10].append(delay2)
    keys[10].append([1.62600, [3, -0.253333, 0.00357938], [3, 0.253333, -0.00357938]])
    times[10].append(delay3)
    keys[10].append([1.61066, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[10].append(delay4)
    keys[10].append([1.61526, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[10].append(delay5)
    keys[10].append([1.60299, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("RShoulderRoll")
    times.append([])
    keys.append([])

    times[11].append(delay1)
    keys[11].append([-0.601287, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[11].append(delay2)
    keys[11].append([-0.592082, [3, -0.253333, 0.00383506], [3, 0.253333, -0.00383506]])
    times[11].append(delay3)
    keys[11].append([-0.578276, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[11].append(delay4)
    keys[11].append([-0.578276, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[11].append(delay5)
    keys[11].append([-0.576742, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LAnklePitch")
    times.append([])
    keys.append([])

    times[12].append(delay1)
    keys[12].append([-0.408002, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[12].append(delay2)
    keys[12].append([-0.0321720, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[12].append(delay3)
    keys[12].append([-0.880473, [3, -0.253333, 0.0902144], [3, 0.280000, -0.0997107]])
    times[12].append(delay4)
    keys[12].append([-0.980184, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[12].append(delay5)
    keys[12].append([0.360532, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LAnkleRoll")
    times.append([])
    keys.append([])

    times[13].append(delay1)
    keys[13].append([-0.00464395, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[13].append(delay2)
    keys[13].append([-0.380475, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[13].append(delay3)
    keys[13].append([-0.165714, [3, -0.253333, 0.0333097], [3, 0.280000, -0.0368160]])
    times[13].append(delay4)
    keys[13].append([-0.128898, [3, -0.280000, 0.0119311], [3, 0.0800000, -0.00340889]])
    times[13].append(delay5)
    keys[13].append([-0.119694, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LElbowRoll")
    times.append([])
    keys.append([])

    times[14].append(delay1)
    keys[14].append([-0.00872665, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[14].append(delay2)
    keys[14].append([-0.0245859, [3, -0.253333, -0.00306812], [3, 0.253333, 0.00306812]])
    times[14].append(delay3)
    keys[14].append([-0.0276540, [3, -0.253333, -0.000971542], [3, 0.280000, 0.00107381]])
    times[14].append(delay4)
    keys[14].append([-0.0307220, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[14].append(delay5)
    keys[14].append([-0.0291880, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LElbowYaw")
    times.append([])
    keys.append([])

    times[15].append(delay1)
    keys[15].append([-1.40817, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[15].append(delay2)
    keys[15].append([-1.40203, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[15].append(delay3)
    keys[15].append([-1.40510, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[15].append(delay4)
    keys[15].append([-1.40357, [3, -0.280000, 0.00119303], [3, 0.0800000, -0.000340865]])
    times[15].append(delay5)
    keys[15].append([-1.40050, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LHipPitch")
    times.append([])
    keys.append([])

    times[16].append(delay1)
    keys[16].append([-0.466378, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[16].append(delay2)
    keys[16].append([-0.156510, [3, -0.253333, -0.0871824], [3, 0.253333, 0.0871824]])
    times[16].append(delay3)
    keys[16].append([0.0567160, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[16].append(delay4)
    keys[16].append([0.00302603, [3, -0.280000, 0.0536900], [3, 0.0800000, -0.0153400]])
    times[16].append(delay5)
    keys[16].append([-0.699546, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LHipRoll")
    times.append([])
    keys.append([])

    times[17].append(delay1)
    keys[17].append([0.00456004, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[17].append(delay2)
    keys[17].append([-0.282298, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[17].append(delay3)
    keys[17].append([-0.257754, [3, -0.253333, 0.0119013], [3, 0.280000, -0.0131541]])
    times[17].append(delay4)
    keys[17].append([-0.207132, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[17].append(delay5)
    keys[17].append([-0.280764, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LHipYawPitch")
    times.append([])
    keys.append([])

    times[18].append(delay1)
    keys[18].append([-0.00456004, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[18].append(delay2)
    keys[18].append([0.0614019, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[18].append(delay3)
    keys[18].append([0.0614019, [3, -0.253333, -0.00000], [3, 0.280000, 0.00000]])
    times[18].append(delay4)
    keys[18].append([0.0614019, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[18].append(delay5)
    keys[18].append([0.0614020, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LKneePitch")
    times.append([])
    keys.append([])

    times[19].append(delay1)
    keys[19].append([0.797722, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[19].append(delay2)
    keys[19].append([-0.00302603, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[19].append(delay3)
    keys[19].append([0.859083, [3, -0.253333, -0.279802], [3, 0.280000, 0.309255]])
    times[19].append(delay4)
    keys[19].append([1.76414, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[19].append(delay5)
    keys[19].append([-0.0923279, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LShoulderPitch")
    times.append([])
    keys.append([])

    times[20].append(delay1)
    keys[20].append([1.52944, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[20].append(delay2)
    keys[20].append([1.50950, [3, -0.253333, -0.00000], [3, 0.253333, 0.00000]])
    times[20].append(delay3)
    keys[20].append([1.51103, [3, -0.253333, -0.000728451], [3, 0.280000, 0.000805130]])
    times[20].append(delay4)
    keys[20].append([1.51410, [3, -0.280000, -0.00000], [3, 0.0800000, 0.00000]])
    times[20].append(delay5)
    keys[20].append([1.50643, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    names.append("LShoulderRoll")
    times.append([])
    keys.append([])

    times[21].append(delay1)
    keys[21].append([0.779314, [3, -0.146667, -0.00000], [3, 0.253333, 0.00000]])
    times[21].append(delay2)
    keys[21].append([0.739430, [3, -0.253333, -0.00613479], [3, 0.253333, 0.00613479]])
    times[21].append(delay3)
    keys[21].append([0.733295, [3, -0.253333, -0.00170007], [3, 0.280000, 0.00187902]])
    times[21].append(delay4)
    keys[21].append([0.728692, [3, -0.280000, -0.00238645], [3, 0.0800000, 0.000681843]])
    times[21].append(delay5)
    keys[21].append([0.724090, [3, -0.0800000, -0.00000], [3, 0.00000, 0.00000]])

    try:
        motion.angleInterpolationBezier(names, times, keys);
        #posture.goToPosture("StandInit", 0.5);
        motion.moveTo(0.01,0,0);
    except:
        print("Error Left Kick")




def main(robotIP, PORT = 9559):
    motion = ALProxy("ALMotion", robotIP, PORT)
    session = qi.Session()
    session.connect("tcp://" + robotIP + ":" + str(PORT))
    posture = session.service("ALRobotPosture")
    #posture = ALProxy("AlRobotPosture", robotIP, PORT)
    motion.setFallManagerEnabled(False);
    posture.goToPosture("StandInit", 0.5)
    
    for x in range(0,2):
        rightFootKick(posture, motion)
        #leftFootKick(posture, motion)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--ip", type=str, default="127.0.0.1",
                        help="Robot ip address")
    parser.add_argument("--port", type=int, default=9559,
                        help="Robot port number")

    args = parser.parse_args()
    main(args.ip, args.port)