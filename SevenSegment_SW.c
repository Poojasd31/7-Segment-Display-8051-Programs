#include<reg51.h>

#define Segment P1 //Port 1= 7 Segment
sbit SW1 = P3^0; //P2.0=SW1
sbit SW2 = P3^1; //P2.1=SW1

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

void delay(unsigned int);
void display_seg(unsigned int);
void main()
{
	int count = 0;
	SW1 = 1; //SWITCH ONE IS OFF
	SW2 = 1; //SWITCG TWO IS OFF
	
	while(1)
	{ 
		if(SW1 == 0) //Switch1 is On
		{
			delay(75);
			if(count<9)
			{
				count++;
			}
		}
		else if(SW2 == 0) //Switch2 is On
		{
			delay(75);
			if(count>0)
			{
				count--;
			}
		}
		display_seg(count);
	}
}
	


void delay(int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<1000;j++)
		{
		}
	}
}

void display_seg(unsigned int num)
{
	Segment = seg_array[num];
	delay(10);
}