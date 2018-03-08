# -*- encoding: UTF-8 -*- 
######################################################################################################
######################################################################################################
############                                CODE MADE BY:                                 ############
############                             Juan Carlos Aguilera                             ############
############                              aguilerapjc@gmail.com                           ############
############                                                                              ############
######################################################################################################
######################################################################################################

##Actuators and sensors list http://doc.aldebaran.com/2-1/family/nao_dcm/actuator_sensor_names.html#dcm-angles

import sys
import motion
import time
import almath
from math import exp,pow,fabs,cos,sin,sqrt
from naoqi import ALProxy
from collections import OrderedDict

class globalVariables:
    def __init__(self, robotIP):
        self.IP = robotIP
        print(self.IP)
        PORT = 9559
        try:
            self.motion = ALProxy("ALMotion", self.IP, PORT)
        except Exception, e:
            print "Could not create proxy to ALMotion"
            print "Error was: ", e

        try:
            self.posture = ALProxy("ALRobotPosture", self.IP, PORT)
        except Exception, e:
            print "Could not create proxy to ALRobotPosture"
            print "Error was: ", e
       
        try:
            self.memory = ALProxy("ALMemory", self.IP, PORT)
        except Exception,e:
            print "Could not create proxy to ALRobotPosture"
            print "Error was: ", e

        try:
            self.sonar = ALProxy("ALSonar", self.IP, PORT)
        except Exception, e:
            print "Could not create proxy to ALSonar"
            print "Error was: ", e

    
    pi = 3.14159265359
    walkParameterFixedRotation      = [ ["MaxStepX", 0.08],["MaxStepY", 0.14],["MaxStepTheta", 0.1963],["MaxStepFrequency", 0.5],["StepHeight", 0.04],["TorsoWx", 0.0],["TorsoWy", 0.0]]
    walkParameterAngularAdjustment  = [ ["MaxStepX", 0.08],["MaxStepY", 0.14],["MaxStepTheta", 0.0175],["MaxStepFrequency", 0.5],["StepHeight", 0.04],["TorsoWx", 0.0],["TorsoWy", 0.0]]
    walkParameterSideAdjustment     = [ ["MaxStepX", 0.08],["MaxStepY", 0.101],["MaxStepTheta", 0.0175],["MaxStepFrequency", 0.5],["StepHeight", 0.04],["TorsoWx", 0.0],["TorsoWy", 0.0]]

    #position = [X,Y,ABSTHETA,RELTHETA]
    X = 0
    Y = 1
    ABSTHETA = 2
    RELTHETA = 3
    INITIAL_POSITION = [X,Y,ABSTHETA,RELTHETA]
    
    #Paths
    LSONAR = "Device/SubDeviceList/US/Left/Sensor/Value"
    RSONAR = "Device/SubDeviceList/US/Right/Sensor/Value"
    ANGLEZ = "Device/SubDeviceList/InertialSensor/AngleZ/Sensor/Value" 
    HEAD = "Head"
    LHAND = "LHand"
    RHAND = "RHand"
    LFOOT = "LFoot"
    RFOOT = "RFoot"
    BODY = "Body"
    CHEST = "Chest"
  
    #SONAR
    THRESHOLDSONAR = 0.45

def StiffnessOff(gVars):
    # We use the "Body" name to signify the collection of all joints
    pNames = "Body"
    pStiffnessLists = 0.0
    pTimeLists = 1.0
    gVars.motion.stiffnessInterpolation(pNames, pStiffnessLists, pTimeLists)

def StiffnessOn(gVars):
    # We use the "Body" name to signify the collection of all joints
    pNames = "Body"
    pStiffnessLists = 1.0
    pTimeLists = 1.0
    gVars.motion.stiffnessInterpolation(pNames, pStiffnessLists, pTimeLists)

def getSonars(gVars):
    arr = []
    arr.append(gVars.memory.getData(gVars.LSONAR));
    arr.append(gVars.memory.getData(gVars.LSONAR));
    return arr;

def getTouchSensors(gVars,part):
    arr = []
    if(part == gVars.HEAD ):
        ##[FRONT,REAR,MIDDLE]
        arr.append(gVars.memory.getData("Device/SubDeviceList/Head/Touch/Front/Sensor/Value"));
        arr.append(gVars.memory.getData("Device/SubDeviceList/Head/Touch/Rear/Sensor/Value"));
        arr.append(gVars.memory.getData("Device/SubDeviceList/Head/Touch/Middle/Sensor/Value"));
        return arr;
    elif (part == gVars.LHAND):
        ##[FRONT,REAR,MIDDLE]
        arr.append(gVars.memory.getData("Device/SubDeviceList/LHand/Touch/Front/Sensor/Value"));
        arr.append(gVars.memory.getData("Device/SubDeviceList/LHand/Touch/Rear/Sensor/Value"));
        arr.append(gVars.memory.getData("Device/SubDeviceList/LHand/Touch/Middle/Sensor/Value"));
        return arr;
    elif (part == gVars.RHAND):
        ##[FRONT,REAR,MIDDLE]
        arr.append(gVars.memory.getData("Device/SubDeviceList/RHand/Touch/Front/Sensor/Value"));
        arr.append(gVars.memory.getData("Device/SubDeviceList/RHand/Touch/Rear/Sensor/Value"));
        arr.append(gVars.memory.getData("Device/SubDeviceList/RHand/Touch/Middle/Sensor/Value"));
        return arr;
    else:
        return [];

##Get bumber infomration and chest button
def getSwitches(gVars,part): 
    arr = []
    if(part == gVars.CHEST):
        return gVars.memory.getData("Device/SubDeviceList/ChestBoard/Button/Sensor/Value");
    elif(part == gVars.LFOOT):
        arr.append(gVars.memory.getData("Device/SubDeviceList/LFoot/Bumper/Right/Sensor/Value"));
        arr.append(gVars.memory.getData("Device/SubDeviceList/LFoot/Bumper/Left/Sensor/Value"));
        return arr;
    elif(part == gVars.RFOOT):
        arr.append(gVars.memory.getData("Device/SubDeviceList/RFoot/Bumper/Right/Sensor/Value"));
        arr.append(gVars.memory.getData("Device/SubDeviceList/RFoot/Bumper/Left/Sensor/Value"));
        return arr;

def getGyroscope(gVars):
    ##[X,Y,Z]
    arr = []
    arr.append(gVars.memory.getData("Device/SubDeviceList/InertialSensor/GyroscopeX/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/InertialSensor/GyroscopeY/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/InertialSensor/GyroscopeZ/Sensor/Value"));
    return arr;

def getAngles(gVars):
    ##[X,Y,Z]
    arr = []
    arr.append(gVars.memory.getData("Device/SubDeviceList/InertialSensor/AngleX/Sensor/Value"))
    arr.append(gVars.memory.getData("Device/SubDeviceList/InertialSensor/AngleY/Sensor/Value"))
    arr.append(gVars.memory.getData("Device/SubDeviceList/InertialSensor/AngleZ/Sensor/Value"))
    return arr

def getAccelerometers(gVars):
    ##[X,Y,Z]
    arr = []
    arr.append(gVars.memory.getData("Device/SubDeviceList/InertialSensor/AccelerometerX/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/InertialSensor/AccelerometerY/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/InertialSensor/AccelerometerZ/Sensor/Value"));
    return arr;

def getBatteryInformation(gVars):
    ##[%Charge, ACurrent, %Temp]
    arr = []
    arr.append(gVars.memory.getData("Device/SubDeviceList/Battery/Charge/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/Battery/Current/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/Battery/Temperature/Sensor/Value"));
    return arr;

def getInertialMeasurements(gVars):
    ##[[ANGLES],[ACCELEROMETER],[GYROSCOPE]]
    arr = []
    arr.append(getAngles(gVars));
    arr.append(getAccelerometers(gVars));
    arr.append(getGyroscope(gVars));
    return arr;

def getFSR(gVars):
    ##[[LFootFSR],[RFootFSR]]
    arr = []
    arr.append(getLFootFSR(gVars));
    arr.append(getRFootFSR(gVars));
    return arr;

def getLFootFSR(gVars):
    ##[FRONT_L,FRONT_R,REAR_L,REAR_R,TOTAL_WEIGHT, CENTER_OF_PRESSURE_X,CENTER_OF_PRESSURE_Y]
    arr = []
    arr.append(gVars.memory.getData("Device/SubDeviceList/LFoot/FSR/FrontLeft/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/LFoot/FSR/FrontRight/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/LFoot/FSR/RearLeft/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/LFoot/FSR/TotalWeight/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/LFoot/FSR/CenterOfPressure/X/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/LFoot/FSR/CenterOfPressure/Y/Sensor/Value"));
    return arr;
    
def getRFootFSR(gVars):
    ##[FRONT_L,FRONT_R,REAR_L,REAR_R,TOTAL_WEIGHT, CENTER_OF_PRESSURE_X,CENTER_OF_PRESSURE_Y]
    arr = []
    arr.append(gVars.memory.getData("Device/SubDeviceList/RFoot/FSR/FrontLeft/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/RFoot/FSR/FrontRight/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/RFoot/FSR/RearLeft/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/RFoot/FSR/TotalWeight/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/RFoot/FSR/CenterOfPressure/X/Sensor/Value"));
    arr.append(gVars.memory.getData("Device/SubDeviceList/RFoot/FSR/CenterOfPressure/Y/Sensor/Value"));
    return arr;

def setInitialPosition(gVars):
    #position = [X,Y,abdTh,relTh]
    angle                       = (gVars.memory.getData(gVars.ANGLEZ))
    gVars.INITIAL_POSITION      = (gVars.motion.getRobotPosition(False))
    gVars.INITIAL_POSITION.append(angle)

def getInitialPosition(gVars):
    return gVars.INITIAL_POSITION;

def getIsFallManagerEnabled(gVars):
    return gVars.motion.getFallManagerEnabled();

def setFallManager(gVars,enable):
    if(enable == True):
        gVars.motion.setFallManagerEnabled(True);
    elif(enable == False):
        gVars.motion.setFallManagerEnabled(False);

def getWalkCalibration(theta):
    if(theta < 0):
	theta*=-1
    if(theta > 0.349):
        theta /= 2

#-------------------------------------------------------------------------------------------------------------#
#                                           Main()                                                            #
#-------------------------------------------------------------------------------------------------------------#
def main(robotIP):
    
    # Init proxies.    
    gVars = globalVariables(robotIP);


    StiffnessOff(gVars) # Apaga los motores, se puede caer si esta parado
    StiffnessOn(gVars) # Prende los motores, si lo mueves se puede da;ar
    print(getSonars(gVars)) # Obtiene lectura ultrasonicos
    print(getTouchSensors(gVars,gVars.HEAD)) # No funciona en webots
    print(getSwitches(gVars,gVars.CHEST)) # Obtiene bumpers de los pies y boton del pecho
    print(getGyroscope(gVars)) # Obtiene info giroscopio. En simulador no funciona el eje Z. Los modelos nuevos si tiene este sensor (eje Z), los viejos no
    print(getAngles(gVars)) # YAW PITCH ROLL. En simulador no funciona el eje Z. Los modelos nuevos si tiene este sensor (eje Z), los viejos no
    print(getAccelerometers(gVars)) # Aceleracion en X,Y,Z
    print(getBatteryInformation(gVars)) # Energia restante, corriente y temperatura de bateria
    print(getInertialMeasurements(gVars)) # Da Angulos, Acelerometro y Giroscopio en una sola estructura
    print(getFSR(gVars)) # Sensor de presion en los pies. Sirve para saber el equilibrio del robot y el peso
    print(getLFootFSR(gVars)) # Lo mismo que anterior, solo pie izquierdo
    print(getRFootFSR(gVars)) # Lo mismo que anterior, solo pie derecho
    print(setInitialPosition(gVars)) # Asigna la posicion inicial absoluta, debe llamarse al iniciar el robot antes de hacer cualquier movimiento
    print(getInitialPosition(gVars)) # Obtiene la posicion absoluta inicial
    print(getIsFallManagerEnabled(gVars)) # Revisa si esta activado la deteccion de caidas
    print(setFallManager(gVars,True)) # Habilita o no la deteccion de caidas. Puede ayudar a proteger el robot
    
    gVars.posture.goToPosture("StandInit",0.5); # Pone el robot en posicion inicial. Para ver otras posiciones, busca en la documentacion

    # Hacer girar el robot
    for i in range(1,10):
        time.sleep(4)
        
        # motion.moveto(X,Y,Theta) que indicas posicion en (metros, metros, radianes)
        # motion.move(X,Y,Theta) que mandas velocidades (m/s , m/s , rad/s)
        # Leer bien la API, al parecer el moveto detiene los otros procesos hasta terminar su ejecusion, instruccion atomica
        gVars.motion.move(0.0,0.0,0.1963) # Hace que el robot gire hacia la izquierda
        
        # Obtiene valores de YPR, acelerometro y giro. No funciona el eje Z para giro
        a = getInertialMeasurements(gVars); # 
        print(str(a[0][0]) + '\t' + str(a[0][1]) + '\t' + str(a[0][2]) )
        print(str(a[1][0]) + '\t' + str(a[1][1]) + '\t' + str(a[1][2]) )
        print(str(a[2][0]) + '\t' + str(a[2][1]) + '\t' + str(a[2][2]) )
    StiffnessOff(gVars)
    
    
if __name__ == "__main__":
    robotIp = "127.0.0.1"

    if len(sys.argv) <= 1:
        print "Usage python motion_wbKick.py robotIP (optional default: 127.0.0.1)"
    else:
        robotIp = sys.argv[1]

    main(robotIp)

