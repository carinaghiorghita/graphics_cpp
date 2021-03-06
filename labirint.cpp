#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cstdlib>

void labirint(int x, int y)
{
    setcolor(3);
    line(50, 50, 70, 50);
    line(90, 50, 290, 50);
    line(290, 50, 290, 290);
    line(290, 310, 290, 370);
    line(50, 370, 290, 370);
    line(50, 50, 50, 370);
    line(70, 70, 70, 90);
    line(50, 90, 70, 90);
    line(90, 70, 90, 90);
    line(90, 90, 270, 90);
    line(50, 110, 250, 110);
    line(270, 90, 270, 230);
    line(270, 230, 150, 230);
    line(150, 230, 150, 150);
    line(150, 150, 90, 150);
    line(250, 110, 250, 150);
    line(250, 150, 200, 150); // 17
    line(200, 150, 200, 130);
    line(200, 130, 70, 130);
    line(70, 130, 70, 310);
    line(70, 310, 150, 310);
    line(150, 310, 150, 350);
    line(150, 350, 250, 350);
    line(250, 350, 250, 310); // 24
    line(250, 310, 170, 310);
    line(170, 310, 170, 330);
    line(170, 330, 230, 330);
    line(90, 150, 90, 290);
    line(90, 290, 290, 290);
    line(170, 130, 170, 170);
    line(270, 290, 270, 350);
    rectangle(170, 170, 250, 210);
    line(70, 50, 70, 30);
    line(90, 50, 90, 30);
    line(290, 290, 310, 290);
    line(290, 310, 310, 310);
    setcolor(WHITE);
    outtextxy(65, 15, "Entry");
    outtextxy(315, 297, "Exit");
    setcolor(YELLOW);
    circle(x, y, 3);
    setfillstyle(1, 2);
    floodfill(x, y, 14);
}

int main()
{
    int x, y;
    char ch = 0;

    initwindow(650, 400, "Labirint");

    x=80, y=40;
    labirint(x, y);
    ch=0;

    while(ch!=27) // 27 = KEY_ESCAPE
    {
        ch=getch();
        if((x==80&&y==40)&&(ch!=KEY_DOWN)) // caz particular de incepere joc
        {
            outtextxy(350,200,"Invalid!");
            continue;
        }

        switch(ch)
        {
            case KEY_UP:
                if(getpixel(x, y-10)==3)
                {
                    outtextxy(350, 200, "Invalid!");
                    continue;
                }
                else y-=10;
                break;

            case KEY_DOWN:
                if(getpixel(x, y+10)==3)
                {
                    outtextxy(350, 200, "Invalid!");
                    continue;
                }
                else y+=10;
                break;

            case KEY_RIGHT:
                if(getpixel(x + 10, y)==3)
                {
                    outtextxy(350, 200, "Invalid!");
                    continue;
                }
                else x+=10;
                break;

            case KEY_LEFT:
                if(getpixel(x - 10, y)==3)
                {
                    outtextxy(350, 200, "Invalid!");
                    continue;
                }
                else x-=10;
                break;

        }

        cleardevice();
        labirint(x,y);

        if(x==310)
        {
            outtextxy(350, 200, "Ati castigat!");
            break;
        }
    }

    getch();
    outtextxy(350, 200, "Apasa orice tasta pentru a iesi!");
    getch();
    closegraph();
    return 0;
}
