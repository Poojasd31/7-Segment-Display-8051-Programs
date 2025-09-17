//SEVEN SEGMENT DISPLAY (2 DIGIT) with 2 Switch
#include<reg51.h>

#define Segment P1 // Port 1 = Segment

//Switch 1 and 2
sbit SW1 = P3^0; //SW1=P3.0
sbit SW2 = P3^1; //SW2=P3.1

//Digit 1 and Digit 0
sbit D0 = P0^0; //D0 =P0.0
sbit D1 = P0^1; //D1 = P0.1

unsigned char seg_array[10]={
	0x3F, // 0
  0x06, // 1
  0x5B, // 2
  0x4F, // 3
  0x66, // 4
  0x6D, // 5
  0x7D, // 6
  0x07, // 7
  0x7F, // 8
  0x6F  // 9
};

void delay(unsigned int);//forward declaration for delay fun

void delay_seg(unsigned int); //Forward declaration for delay_segment fun

void display_segment(unsigned int); //Forward declaration for display_segment function

void main()
{
	int count = 0;
	//Both switches are off
	SW1 = 1;
	SW2 = 1;
	
	
	while(1)
	{
		if(SW1 == 0)
		{
			delay(75);
			if(count<99)
			{
				count++;
			}
		}
		else if(SW2 == 0)
		{
			delay(75);
			if(count>0)
			{
				count--;
			}
		}
		display_segment(count);
		
	}
}

void delay(unsigned int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<1000;j++)
		{
		}
	}
}

void delay_seg(unsigned int t1)
{
	int k,l;
	for(k=0;k<t1;k++)
	{
		for(l=0;l<134;l++)
		{
		}
	}
}

void display_segment(unsigned int num)
{
	D0 = 1;
	D1 = 0;
	Segment = seg_array[num%10];
	delay_seg(2);
	
	D0 = 0;
	D1 = 1;
	Segment = seg_array[num/10];
	delay_seg(2);
}










