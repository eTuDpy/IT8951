#include <string.h>
#include <inttypes.h>
#include "IT8951.h"

int main (int argc, char *argv[])
{
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
	
	if (!strcmp(argv[1], "bmp"))
	{
		printf("Render Bitmap\r\n");

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
		printf("Direct Write\r\n");

		if (argc != 6)
		{
			printf("Error: argc!=5.\n");
			exit(1);
		}

		uint32_t x,y;
		uint16_t usDpyMode;
		sscanf(argv[2], "%d", &x);
		sscanf(argv[3], "%d", &y);
		sscanf(argv[4], "%hu", &usDpyMode);

		IT8951_DIRECT(x, y, usDpyMode, argv[5]);
	}
	else if(!strcmp(argv[1], "boot"))
	{
		printf("Direct Write\r\n");
		printf("Eugen");

		if (argc != 7)
		{
			printf("Error: argc!=5.\n");
			exit(1);
		}

		uint32_t x,y;
		uint16_t usDpyMode;
		sscanf(argv[2], "%d", &x);
		sscanf(argv[3], "%d", &y);
		sscanf(argv[4], "%hu", &usDpyMode);
		sscanf(argv[5], "%d", &upper);

		IT8951_BOOT(x, y, usDpyMode, upper, argv[6]);

	}
	else if(!strcmp(argv[1], "sequence"))
	{
		printf("Sequence\r\n");

		int startFrame, endFrame, wait;
		uint16_t usDpyMode;
		sscanf(argv[4], "%d", &startFrame);
		sscanf(argv[5], "%d", &endFrame);
		sscanf(argv[6], "%hu", &usDpyMode);
		sscanf(argv[7], "%d", &wait);

		IT8951_SEQUENCE(argv[2], argv[3], startFrame, endFrame, usDpyMode, wait);

	} else if(!strcmp(argv[1], "clear"))
	{
		printf("Clearing Screen...\r\n");
		IT8951_CLEAR();

	} else {
		IT8951_CLEAR();
	}

	// IT8951_DIRECT
	
	IT8951_Cancel();

	return 0;
}


