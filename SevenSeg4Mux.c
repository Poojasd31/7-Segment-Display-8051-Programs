#include<reg51.h>

sfr Segment = 0X90; //port 1 = Segment

sbit D0 = P0^0; //P0.0 = D0
sbit D1 = P0^1; //P0.1 = D1
sbit D2 = P0^2; //P0.2 = D2
sbit D3 = P0^3; //P0.3 = D3

unsigned char array_seg[10] = { 0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};

void delay(int); //forward declaration for delay

void segment_display(unsigned int);//forward declaration for Segment

void main()
{
	int i,j;
	while(1)
	{
		for(i=0;i<=9999;i++)
		{
			for(j=0;j<10;j++)
			{
				segment_display(i); // function is called with arguement is passed
			}
		}
		
	}
}

//Delay Function

void delay(int t)
{
	int k,l;
	for(k=0;k<t;k++)
	{
		for(l=0;l<134;l++)
		{
		}
	}
}


void segment_display(unsigned int num)
{
	D0 = 1; D1 = 0; D2 =0 ; D3 = 0;
	Segment = array_seg[num%10];
	delay(2);
	
	D0 = 0; D1 = 1; D2 =0 ; D3 = 0;
	Segment = array_seg[(num/10)%10];
	delay(2);
	
	D0 = 0; D1 = 0; D2 =1 ; D3 = 0;
	Segment = array_seg[(num/100)%10];
	delay(2);
	
	D0 = 0; D1 = 0; D2 =0 ; D3 = 1;
	Segment = array_seg[num/1000];
	delay(2);
	
}
