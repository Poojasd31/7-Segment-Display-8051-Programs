//SEVEN SEGMENT DISPLAY with 3 SSD

#include<reg51.h>

sfr SevenSegment=0X90; //PORT 1 = SEVEN SEGMENT
sbit D0 = P0^0; //P0.0  = D2
sbit D1 = P0^1; //P0.1 = D1
sbit D2 = P0^2; //P0.2 = D0


unsigned char seven_segment[10] = { 0X3F, 0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F}; // Hex value from 0 to 9

void delay(unsigned int); // forward declaration for delay function
void seg_display(unsigned int); //forward declaration for segment display

void main()
{
	int i,j;
	while(1)
	{

		for(i=0;i<=999;i++)
		{
			for(j=0;j<20;j++)
			{
				seg_display(i); //actual Argument is passed
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

//Function of Segment Display
void seg_display(unsigned int num) // Actual argument is catched by formal argument num
{
	D0 = 1; //D0 = ON
	D1 = 0; //D1 = OFF
	D2 = 0; //D2 = OFF
	SevenSegment = seven_segment[num%10]; //It will store unit place digit
	delay(2);
	
	D0 = 0; //D0 = OFF
	D1 = 1; //D1 = ON
	D2 = 0; //D2 = OFF
	SevenSegment = seven_segment[(num/10)%10];//First it will take remainder then it will take quotient
	delay(2);
	
	D0 = 0; //D0 = OFF
	D1 = 0; //D1 = OFF
	D2 = 1; //D2 = ON
	SevenSegment = seven_segment[num/100];//It will store  remaninder in Digit 2 place
	delay(2);
}
	
