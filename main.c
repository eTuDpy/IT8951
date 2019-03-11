#include <string.h>
#include <inttypes.h>
#include "IT8951.h"

int main (int argc, char *argv[])
{
	printf("Bah \n");
	/*
	printf("ReadReg = 0x%x\n",IT8951ReadReg(LISAR));
	IT8951WriteReg(LISAR,0x1234);
	printf("ReadReg = 0x%x\n",IT8951ReadReg(LISAR));
	*/

	if(IT8951_Init())
	{
		printf("IT8951_Init error \n");
		return 1;
	}
	printf("Baah \n");
	
	// IT8951DisplayExample();
	// IT8951DisplayExample2();
	// printf("IT8951_GUI_Example\n");
	// IT8951_GUI_Example();
	
	if (!strcmp(argv[1], "bmp"))
	{
		printf("Bitmap time!\n\r");
		if (argc != 5)
		{
			printf("Error: argc!=5.\n");
			exit(1);
		}

		uint32_t x,y;
		sscanf(argv[2],"%d",&x);
		sscanf(argv[3],"%d",&y);

		IT8951_BMP_Example(x,y,argv[4]);
	} else if(!strcmp(argv[1], "direct"))
	{
		if (argc != 6)
		{
			printf("Error: argc!=5.\n");
			exit(1);
		}
		printf("Direct Write...\n\r");
		uint32_t x,y;
		uint16_t usDpyMode;
		sscanf(argv[2], "%d", &x);
		sscanf(argv[3], "%d", &y);
		sscanf(argv[4], "%hu", &usDpyMode);

		IT8951_DIRECT(x, y, usDpyMode, argv[5]);
	} else if(!strcmp(argv[1], "clear")) {
		printf("Clearing Screen...\n\r");
		IT8951_CLEAR();
	} else {
		IT8951_CLEAR();
	}

	// IT8951_DIRECT
	
	IT8951_Cancel();

	return 0;
}


