#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
	int gm, gd = DETECT;
	char a[100];
	initgraph(&gd, &gm, "");

	for(int i=2; i<=100; i+=10)
		for(int j=2; j<=100; j+=10)
		{
			int x = rand() %15 + 1;
			setcolor(x);
			circle(i, j, 2);
		}
	getch();
	closegraph();
	return 0;
}
