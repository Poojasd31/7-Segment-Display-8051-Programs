//SEVEN SEGMENT Multiplexig with 2 SSD

#include <reg51.h>

#define SevenSegment  P1 

sbit D1= P0^0;  //P0.0 = D1
sbit D0= P0^1;  //P0.1 = D0

void delay(int); //Forward declaration

void main()
{
	int i,k;
	unsigned char seven_seg[10] = {0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F}; //Hex value from 0 to 9
	
	while(1)
	{
		for(i=0;i<=99;i++) // it will show 00 to 99 digits
		{
			for(k=0;k<30;k++)
			{
			D1 = 1; //D1 IS ON 
			D0 = 0; //D0 IS OFF
			SevenSegment = seven_seg[i/10]; //so in SSD it will store quotient
			delay(1);
			
			D1 = 0; //D1 IS OFF
			D0 = 1; //D0 IS ON
			SevenSegment = seven_seg[i%10]; //so in SSD it will store remainder
			delay(1);
			}
		}
	}
}

//DELAY Function
void delay(int t)
{
	int j,k;
	for(j=0;j<t;j++)
	{
		for(k=0;k<1000;k++)
		{
		}
	}
}
			
	


