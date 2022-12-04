#include"51car.h"
void main()
{     
        TMOD = 0X11;//T0 T1工作在方式1
	
//	      TH1 = 0XD8;//T1 
//	      TL1 = 0XF0;

	      TH0 = 0XFc;//T0 1ms计时一次
	      TL0 = 0X18;

	      ET0 = 1; //定时器0中断允许
	      TR0 = 1; //启动T0
//	      ET1 = 1; //定时器1中断允许
//	      TR1 = 1; //启动T1
	      /*IT0 = 1; //外部中断0 下降沿触发
        IT1 = 1; //外部中断1 下降沿触发
	      EX0 = 1; //外部中断0中断允许
        EX1 = 1; //外部中断1中断允许*/
	      EA = 1;	 //总中断
        

        
        while(1) 
        {       
                
                if(Left_led == 0 && Right_led == 0) 
                   {
                     frontRun(12,12);
                   }

                else if(Left_led == 1 && Right_led == 0) 
                       {
                        turnRight(12,13);
                       }//int right,int left

                else if(Right_led == 1 && Left_led == 0) 
                       {
                        turnLeft(12,13);//int right,int left
                       } 
                else if(Right_led == 1 && Left_led == 1)
                       stop();
                
        }
        

}
