#include <stdio.h>
#include <osbind.h>

#define BYTES_PER_SCREEN 32000
#define TANK_HEIGHT 16
typedef unsigned int UINT16;

const UINT16 P1BITMAP[TANK_HEIGHT] = {
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0FF0,
	0x0FF0,
	0X0F00,
	0X0FF8,
	0X0FF8,
	0X3FFC,
	0X3FFC,
	0X3FFC,
	0X3FFC,
	0X0FF0,
	0X0FF0
};

void disable_cursor();
void print_bitmap(UINT16 *base, int x, int y, const UINT16 *bitmap,
unsigned int height);
int main()
{


	UINT16 *base = Physbase();

	disable_cursor();          /* hide blinking text cursor */

print_bitmap(base, 0, 0, P1BITMAP, TANK_HEIGHT);

	Cnecin();                  /* wait for key press, don't echo */

	Cnecin();

	return 0;
}

void disable_cursor()
{
	printf("\033f");
	fflush(stdout);
}

void print_bitmap(UINT16 *base, int x, int y, const UINT16 *bitmap,
unsigned int height)
{

	int i;
	int offset;

	offset = (x>>4) + (y*40);
	for (i=0; i < height; i++)
	*(base + offset + (40*i)) |= bitmap[i];

	return;	
}
