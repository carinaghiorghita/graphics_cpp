#include <iostream>
#include <graphics.h>
#include <cmath>
#include <conio.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    int x, y, r;

    cout<<"Abscisa centrului: "; cin>>x;
    cout<<"Ordonata centrului: "; cin>>y;
    cout<<"Raza cercului: "; cin>>r;

    initgraph(&gd, &gm, "");

    circle(x, y, r);
    while(1)
    {
        for(int i1=x, i2=x, i3=x+r, i4=x-r; i1<=x+r && i2>=x-r && i3>=x && i4<=x; ++i1, --i2, --i3, ++i4)
        {
            circle(x, y, r);
            int A1 = r*r - (i1-x)*(i1-x) - y*y;
            int A2 = r*r - (i2-x)*(i2-x) - y*y;
            int A3 = r*r - (i3-x)*(i3-x) - y*y;
            int A4 = r*r - (i4-x)*(i4-x) - y*y;
            int k = 2*y;
            float j1 = (float) (k+sqrt(k*k+4*A1))/2.0;
            float j2 = (float) (k-sqrt(k*k+4*A2))/2.0;
            float j3 = (float) (k-sqrt(k*k+4*A3))/2.0;
            float j4 = (float) (k+sqrt(k*k+4*A4))/2.0;
            circle(i1, j1, 10);
            circle(i2, j2, 10);
            circle(i3, j3, 10);
            circle(i4, j4, 10);
            line(i1, j1, i2, j2);
            line(i3, j3, i4, j4);
            delay(50);
            cleardevice();
            if(i1==x+r)
            {
                circle(i1, j1, 10);
                circle(i2, j2, 10);
                circle(i3, j3, 10);
                circle(i4, j4, 10);
            }
        }
    }

    circle(x, y, r);

    getch();
    closegraph();
}
