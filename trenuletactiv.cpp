#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

int main()
{
	int gd = DETECT, gm, left=0, top=0, right=500, bottom=500, k=0;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	for(int i = 0; i<= right; i++)
	{
		rectangle(i, 100, i + 100, 150);
		circle(i + 20, 162, 12);
		circle(i + 100 - 20, 162, 12);

		rectangle(i + 120, 100, i + 220, 150);
		circle(i + 140, 162, 12);
		circle(i + 200, 162, 12);
		line(i + 220, 150, i + 260, 150);
		line(i + 220, 100, i + 260, 150);

		line(i + 100, 135, i + 120, 135);

		delay(50);
		cleardevice();
	}
	getch();
	closegraph();
	return 0;
}
