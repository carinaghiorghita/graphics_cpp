#include <iostream>
#include <windows.h>
#include <graphics.h>
using namespace std;

int x=1, y=1;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x = 300, y = 200, r = 60;
    circle(x, y, r);
    while(1)
    {
        if(GetAsyncKeyState(VK_RIGHT))
        {
            cleardevice();
            x += 15;
            circle(x, y, r);
            delay(100);
        }

        if(GetAsyncKeyState(VK_LEFT))
        {
            cleardevice();
            x -= 15;
            circle(x, y, r);
            delay(100);
        }

        if(GetAsyncKeyState(VK_UP))
        {
            cleardevice();
            y -= 15;
            circle(x, y, r);
            delay(100);
        }

        if(GetAsyncKeyState(VK_DOWN))
        {
            cleardevice();
            y += 15;
            circle(x, y, r);
            delay(100);
        }

        if(GetAsyncKeyState(82))
        {
            setcolor(RED);
            circle(x, y, r);
        }

        if(GetAsyncKeyState(89))
        {
            setcolor(YELLOW);
            circle(x, y, r);
        }

        if(GetAsyncKeyState(87))
        {
            setcolor(WHITE);
            circle(x, y, r);
        }

        if(GetAsyncKeyState(66))
        {
            setcolor(BLUE);
            circle(x, y, r);
        }

        if(GetAsyncKeyState(VK_ESCAPE))
        {
            closegraph();
            return 0;
        }
    }
}