#include<reg51.h>

#define SevenSegment P1 // PORT1 for 7-segment display

sbit D1 = P0^0; // Control for digit 1
sbit D0 = P0^1; // Control for digit 0

void delay(int); // delay function declaration
void segment(); // 7-segment function declaration



void main()
{
	
	while(1)
	{
		segment(); // Call segment function with value to display
		delay(100);
	}
}

// Delay function
void delay(int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<1000;j++);
	}
}

// 7-segment display function
void segment()
{
	unsigned char seven_seg[10] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F};
  int l,k;
	for(l=0;l<=99;l++) // it will show 00 to 99 digits
		{
			for(k=0;k<30;k++)
			{
			D1 = 1; //D1 IS ON 
			D0 = 0; //D0 IS OFF
			SevenSegment = seven_seg[l/10]; //so in SSD it will store quotient
			delay(1);
			
			D1 = 0; //D1 IS OFF
			D0 = 1; //D0 IS ON
			SevenSegment = seven_seg[l%10]; //so in SSD it will store remainder
			delay(1);
			}
		}
}
