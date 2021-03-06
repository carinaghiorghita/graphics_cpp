#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

int main()
{
	int gd = DETECT, gm, left=0, top=0, right=500, bottom=500, k=0;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	for(int i=top; i<=bottom; i++)
		for(int j=left; j<=right; j++)
			if(i % 10 == 0 && j % 10 == 0)
			{
				circle(i, j, 1);
				delay(100);
				cleardevice();
			}
	getch();
	closegraph();
	return 0;
}
