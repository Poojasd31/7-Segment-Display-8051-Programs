//SEVEN SEGMENT DISPLAY

#include<reg51.h>

#define SevenSegment P1 //port 1 = SevenSegment

void delay(int); //Forward declaration

void main()
{
	unsigned char segment_array[16]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F,0X77,0X7C,0X39,0X5E,0X79,0X71}; // Hex value for 0 to F
	int i;
	while(1)
	{
		for(i=0;i<16;i++)
		{
			SevenSegment = segment_array[i]; //assigning hex value to port 1=sevensegment
			delay(100);//calling to delay function
		}
	}
}


//Delay function
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