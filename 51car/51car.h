#ifndef car
#define car
#include<reg52.h>
#include<stdio.h>
#define uint unsigned int              //16λ�������ֽ�
#define uchar unsigned char                     //8λ��һ���ֽ�


/*uint count_R, count_R_10ms, count_L, count_L_10ms, count_time = 0;//���������������½��ؼ���,10ms�ļ���
int pulse_revolutions = 400; //תһȦ������	,ȫ������ÿ10ms17������
int count_all_R, count_all_L = 0;
bit direction_R, direction_L;//����������ת����*/

int LeftActualSpeed = 0;
int RightActualSpeed = 0;
float Kp=0,Ki=5,Kd=0;  //ϵ��
uint Error1=0,Error2=0,Error3=0,Error4=0;     //���
uint LeftCount = 0;
uint RightCount = 0;

uint Left_Speed = 0; //�涨�ٶ�
uint Right_Speed = 0;
int time=0;   //PWMʱ��ѭ��

int Left_Pwm = 0;//�涨ռ�ձ�
int Right_Pwm = 0;

sbit Left_led = P0^0; //ѭ��ģ��
sbit Right_led = P0^2;

sbit IN1 = P1^2; //L289N�����Ķ���
sbit IN2 = P1^3;
sbit IN3 = P1^5;
sbit IN4 = P1^4;
sbit ENA = P1^6;
sbit ENB = P1^7;

//A�������½���ʱB����ߵ͵�ƽ�ж�����ת
/*sbit RIGHT_B = P1^1;
sbit LEFT_B = P1^0 ;*/



void delay(int k)//��ʱk ms
{
        uint i;
        uchar j;
        for(i = 0; i < k; i++) 
        {
                for(j = 0; j < 200; j++) ;
                for(j = 0; j < 102; j++) ;
        }
}

void Right_moto_go()
{
        IN3 = 0;
        IN4 = 1;
}

void Left_moto_go()
{
        IN1 = 1;
        IN2 = 0;
}

void Right_moto_back()
{
        IN3 = 1;
        IN4 = 0;
}


void Left_moto_back()
{
        IN1 = 0;
        IN2 = 1;
}

/*void pid()
{
        int Leftpwm_output = 0;
        int Rightpwm_output = 0;
        if (direction_L == 1)
		        LeftActualSpeed =  count_L_10ms ;//10ms�������*100
	      else 
		        LeftActualSpeed=  -(int)count_L_10ms ;

        if (direction_R == 1)
		        RightActualSpeed =  count_R_10ms;//10ms�������
	      else
		        RightActualSpeed =  -(int)count_R_10ms;
        Error3 = Left_Speed - LeftActualSpeed;
        Error4 = Right_Speed - RightActualSpeed;//Kp*(Error3-Error2)||Kp*(Error4-Error2)+
        Leftpwm_output = Ki*(Error3)+Kd*(Error3-2*Error2+Error1);
        Rightpwm_output = Ki*(Error4)+Kd*(Error4-2*Error2+Error1);
	      Left_Pwm += Leftpwm_output;
        Right_Pwm += Rightpwm_output;
       //Left_Pwm = Left_Speed;
       //Right_Pwm = Right_Speed;


	
	     if((Left_Pwm >= 20)||(Right_Pwm >= 20))
	     {
	         Left_Pwm = Right_Pwm = 20;
          
	     }
	     else if((Left_Pwm < -20)||(Right_Pwm < -20))
	     {
	         Left_Pwm = Right_Pwm = -20;
         
	     }
	     
}*/


void frontRun(int right,int left) 
{
        Right_Speed = right;
        Left_Speed = left;
        Right_moto_go();
        Left_moto_go();
        
}

void backRun(int right,int left)
{
        Right_Speed = right;
        Left_Speed = left;
        Right_moto_back();
        Left_moto_back();
        
}

void turnLeft(int right,int left)//��ת
{  
        Left_Speed = left;
        Right_Speed = right;
        Left_moto_back();
        Right_moto_go();
        
        
}
void turnRight(int right,int left)//��ת
{
        Right_Speed = right;
        Left_Speed = left;
        Right_moto_back();
        Left_moto_go();
       

}
void stop()
{
        ENA = 0;
        ENB = 0;
        
}

void pwm_out_left()
{
        if(time < Left_Speed)
        ENA = 1;
        else
        ENA = 0;
        
}

void pwm_out_right()
{
        if(time < Right_Speed)
        ENB = 1;
        else
        ENB = 0;
        
}

//void int0() interrupt 0  //�ⲿ�ж�0����������ź�         
//{
//				LeftCount ++;
//        if (LEFT_B == 0)
//	      {
//		      direction_L = 1; //��ת
//		      count_all_L++;
//	      }
//	      else
//	      {
//		      direction_L = 0;
//		      count_all_L--;
//	      }
//}	


//void int1() interrupt 2  //�ⲿ�ж�1����������ź�         
//{
//	      RightCount ++;	
//        if (RIGHT_B == 1)
//        {
//	       direction_R = 1;	//��ת
//	       count_all_R++;
//        }
//        else
//        {
//	       direction_R = 0;
//	       count_all_R--;
//        }                            
//}

void timer0() interrupt 1   //��ʱ��0�жϴ�����       
{	
        time++;  
 	      TR0 = 0;   //�ر�T0
        TH0 = 0XFc;//����װ�붨ʱʱ��,50hz
	      TL0 = 0X18;
	      
	      pwm_out_left();
        pwm_out_right();
        if (time >= 20) //	 	 
	          {
              time = 0;
            }
        TR0 = 1;   //��T0
		
}

//void timer1() interrupt 3	 //��ʱ��1�жϴ�����,��һ����
//{   
//       
//	     TR1=0;
//	     TH1 = 0XD8;
//	     TL1 = 0XF0;
//	     TR1=1;
//	  
//		   count_L_10ms = LeftCount;
//	     LeftCount = 0;
//	     count_R_10ms = RightCount;
//	     RightCount = 0;
//       
//	
//}
#endif