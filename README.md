# 51car
51智能小车
# 51智能小车

## 1.实现的功能

通过识别赛道两边的黑线进行循迹

## 2.需要用到的元器件原理图

1. 51最小系统

   ![image](https://user-images.githubusercontent.com/91321570/205480134-0e55d44d-51e5-4f9e-bb3a-0169b88cac04.png)


2. st188

   ![image](https://user-images.githubusercontent.com/91321570/205480153-ed6c9c71-d87d-4481-9300-dd3a9b14c3fb.png)

3. lm324引脚图

   ![image](https://user-images.githubusercontent.com/91321570/205480169-f4a16410-70ce-4479-8bc6-8f05be185dc3.png)

4. l298驱动

  ![image](https://user-images.githubusercontent.com/91321570/205480177-d9309a83-9817-4cc7-8b7a-bbe1efb426c1.png)


5. 稳压电路，我用的是7805

   ![image](https://user-images.githubusercontent.com/91321570/205480186-3cae2c86-5769-45d6-8c7a-281606994e0e.png)
## 3.具体的硬件接法

51通过不断检测st188的高低电平，改变给l298的信号，进而控制电机的状态，具体的接法百度

