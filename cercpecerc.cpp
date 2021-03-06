#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cmath>

using namespace std;

int main()
{
	int gd = DETECT, gm;

	int x, y, r;
	cout << "Abscisa centrului: "; cin>>x;
	cout << "Ordonata centrului: "; cin>>y;
	cout << "Raza cercului: "; cin>>r;

	initgraph(&gd, &gm, "C:\\TC\\BGI");

	circle(x, y, r);
    while(1){
	for(int i=x; i<=x+r; ++i)
	{
		circle(x, y, r);
		int A = r*r - (i-x)*(i-x) - y*y;
		int k = 2*y;
		float j = (float) (k + sqrt(k*k + 4*A))/2.0;
		circle(i, j, r/8);
		delay(30);
		cleardevice();
	}

	for(int i=x+r; i>=x-r; --i)
	{
		circle(x, y, r);
		int A = r*r - (i-x)*(i-x) - y*y;
		int k = 2*y;
		float j = (float) (k - sqrt(k*k + 4*A))/2.0;
		circle(i, j, r/8);
		delay(30);
		cleardevice();
	}

	for(int i=x-r; i<=x; ++i)
	{
		circle(x, y, r);
		int A = r*r - (i-x)*(i-x) - y*y;
		int k = 2*y;
		float j = (float) (k + sqrt(k*k + 4*A))/2.0;
		circle(i, j, r/8);
		delay(30);
		cleardevice();
		if(i==x)
			circle(i, j, r/8);
	}}
	circle(x, y, r);
	outtextxy(x-50, y+r+30, "Aplicatie incheiata");

	getch();
	closegraph();
	return 0;
}
