//-----------------------------------------------------------------
//-- Otto will avoid obstacles with this code!
//-----------------------------------------------------------------
#include <Servo.h> 
#include <Oscillator.h>
#include <US.h>
#include <Otto.h>
Otto Otto;  //This is Otto!
//---------------------------------------------------------
//-- First step: Make sure the pins for servos are in the right position
/*
         --------------- 
        |     O   O     |
        |---------------|
YR 3==> |               | <== YL 2
         --------------- 
            ||     ||
RR 5==>   -----   ------  <== RL 4
         |-----   ------|
*/
  #define PIN_YL 2 //servo[2] //对应舵机在主板上的管脚2
  #define PIN_YR 3 //servo[3] //对应舵机在主板上的管脚3
  #define PIN_RL 4 //servo[4] //对应舵机在主板上的管脚4
  #define PIN_RR 5 //servo[5] //对应舵机在主板上的管脚5
///////////////////////////////////////////////////////////////////
//-- Global Variables -------------------------------------------//
///////////////////////////////////////////////////////////////////
//-- Movement parameters
int T=1000;              //Initial duration of movement
int moveId=0;            //Number of movement
int moveSize=15;         //Asociated with the height of some movements
//---------------------------------------------------------
bool obstacleDetected = false;
///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup(){                                   //程序起来会先进入setup()函数
  //Set the servo pins
  Otto.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,true); //初始化otto，将舵机对应的管脚配置进去
  Otto.sing(S_connection); //Otto wake up!     //otto 初始化音频
  Otto.home();                                 //四个舵机回中(回到90度的位置)
  delay(50);
  Otto.sing(S_happy); // a happy Otto :)       //otto 唱happy
}
///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop()                                     //setup()函数执行完后会一直循环跑loop()函数，一直循环
{
    obstacleDetector();                         //调用检测是否要碰着的函数                
	if(obstacleDetected)                        //要碰撞
	{  
		Otto.sing(S_surprise);                  //唱 surpise
		Otto.playGesture(OttoFretful);          //机器人执行跺脚程序
		Otto.sing(S_fart3);                     //唱歌
		Otto.walk(2,1300,-1);                   //往回走
		Otto.turn(2,1000,-1);                
		delay(50); 
	}        
	else
	{ 
		Otto.walk(1,1000,1);                    //向前走
	}           
  }  

///////////////////////////////////////////////////////////////////
//-- Function to read distance sensor & to actualize obstacleDetected variable
void obstacleDetector(){
   int distance = Otto.getDistance();           //超声波测距 
        if(distance<15){                        
          obstacleDetected = true;              //测出来距离小于15cm 即将要碰撞
        }else{
          obstacleDetected = false;             //测出来距离大于15cm 不会碰撞
        }
}
