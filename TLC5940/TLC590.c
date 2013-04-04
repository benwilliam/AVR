#include<stdio.h>

#define BASIS 8
#define BITS 12
#define LEDS 16
#define BYTES ((BITS*LEDS)+BASIS-1)/BASIS

void printarraytoBase(unsigned char *ar, unsigned char length, unsigned char bitsWidth)
{
  unsigned char counter = 0;
	int i;
	for(i = 0; i<length; i++)
	{
		int a;
		for(a = 7; a >= 0; a--)
		{
			unsigned char value = ar[i];
			value = (value >> a);
			value = value & 1;
			printf("%d", value);
			counter++;

			if(counter >= bitsWidth)
			{
				printf("\n");
				counter = 0;
			}
		}
	}
}

void setValue(unsigned char *ar, unsigned short value, unsigned char pos)
{
	


}

void SetLED(unsigned char *pwm_data_raw, unsigned char led, unsigned short value)
{
     unsigned char adr;

    if (led%2 == 0 ||led == 0)
    {
        // Blöcke 0, 2, 4, ...
        adr = (led * 3) / 2 + 1;
        pwm_data_raw[adr - 1] = (unsigned char)(value >> 4);
        pwm_data_raw[adr] &= 0xF;
        pwm_data_raw[adr] |= (unsigned char)(value << 4);
    }
    else
    {
        // Blöcke 1, 3, 5, ...
        led++;
        adr = (led * 3) / 2 - 2;
        pwm_data_raw[adr] &= 0xF0;
        pwm_data_raw[adr] |= (unsigned char)(value >> 8);
        pwm_data_raw[adr + 1] = (unsigned char)(value);
    }
}

void setGrayScaleValue(unsigned char* packedGrayScaleDataBuffer1 , unsigned char channel, int value)
{
	unsigned char eightBitIndex = channel;
	unsigned char *twelveBitIndex = packedGrayScaleDataBuffer1 + ((channel * 3) >> 1);

	if(eightBitIndex & 1) 
	  {
		// Value starts in the middle of the byte
		// Set only the top 4 bits
		*twelveBitIndex = (*twelveBitIndex & 0xF0) | (value >> 8);

		// Now set the lower 4 bits of the next byte
		*(++twelveBitIndex) = value & 0xFF;
	  } 
	else 
	  {
		// Value starts at the start of the byte
		*(twelveBitIndex++) = value >> 4;

		// Now set the 4 lower bits of the next byte leaving the top 4 bits alone
		*twelveBitIndex = ((unsigned char)(value << 4)) | (*twelveBitIndex & 0xF);
	  }		
}

int main()
{
	unsigned char GS_LEDS[BYTES] = {0};	
	
	//setValue(temp.GS_LEDS, 0xFFF, 2);
	
	//SetLED(GS_LEDS, 15, 0xFFF);
	
	setGrayScaleValue(GS_LEDS, 0, 0xFFF);
	
	printarraytoBase(GS_LEDS, BYTES, BITS);
	getchar();
	return 0;
}
