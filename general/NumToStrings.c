/*
 * NumToStrings.c
 *
 *  Created on: Sep 13, 2019
 *      Author: Na
 */
#include "Std_types.h"
#include "NumToStrings.h"
void NumToString(f32 num,u8* string,u8 afterpoint,u8 length)/* length is the length of the array given to function*/
{
	f32 decimal;
	u32 integar,len;
	u8 i=1;
	integar=(u32)num;
	decimal=num-(f32)integar;
	if(integar==0)
	{
		string[0]='0';
		string[1]='.';
		len=2;
	}
	else
	{
		len=inttostring(integar,string);
		reverse(string,len);
		string[len++]='.';\
	}
	for(;i<=afterpoint;i++)
	{


		string[len++]=NumberToChara(((u32)(decimal*power(10,i)))%10);
	}
	while(len<(length-1))
	{
		string[len++]='0';
	}
	string[len]='\0';
}
u8 inttostring(u16 num,u8* string)
{
	u8 length=0;
	while(num>0)
	{
		string[length++]=num%10+'0';
		num/=10;
	}
	return length;
}
u32 power(u8 num,u8 pow)
{
	u32 result=1;
	while(pow>0)
	{
		result*=num;
		pow--;
	}
	return result;
}


void reverse(u8* string,u8 length)
{
	u8 temp[length],i;
	for(i=0;i<length;i++)
	{
		temp[i]=string[i];
	}

	for(i=0;i<length;i++)
	{
		string[i]=temp[length-1-i];
	}
	}
u8 NumberToChara(u8 num)
{
	switch (num)
	{
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 0:
		return '0';
	case 0xff:
		return 0;
	default:
		return num;
	}

}
