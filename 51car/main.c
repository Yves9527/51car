#include"51car.h"
void main()
{     
        TMOD = 0X11;//T0 T1�����ڷ�ʽ1
	
//	      TH1 = 0XD8;//T1 
//	      TL1 = 0XF0;

	      TH0 = 0XFc;//T0 1ms��ʱһ��
	      TL0 = 0X18;

	      ET0 = 1; //��ʱ��0�ж�����
	      TR0 = 1; //����T0
//	      ET1 = 1; //��ʱ��1�ж�����
//	      TR1 = 1; //����T1
	      /*IT0 = 1; //�ⲿ�ж�0 �½��ش���
        IT1 = 1; //�ⲿ�ж�1 �½��ش���
	      EX0 = 1; //�ⲿ�ж�0�ж�����
        EX1 = 1; //�ⲿ�ж�1�ж�����*/
	      EA = 1;	 //���ж�
        

        
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
