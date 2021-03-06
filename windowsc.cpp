#include <windows.h>
#include <graphics.h>
#include <conio.h>

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

HWND textfield;
HWND button;

char className[] = "Prima aplicatie";

int WINAPI WinMain(HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpstrArgument,
                   int nCmdShow)
{
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;

    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = className;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof(WNDCLASSEX);

    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if(!RegisterClassEx(&wincl))
        return 0;

    hwnd = CreateWindowEx (
            0,
            className,
            "Prima aplicatie",
            WS_MINIMIZEBOX | WS_SYSMENU,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            500,
            500,
            HWND_DESKTOP,
            NULL,
            hThisInstance,
            NULL
            );

    ShowWindow(hwnd, nCmdShow);

    while(GetMessage(&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
        case WM_CREATE:
            textfield = CreateWindow ("Static", "Mie imi place info! Daca iti place si tie, apasa butonul!", WS_VISIBLE | WS_CHILD,
                                      20, 20, 365, 25,
                                      hwnd, NULL, NULL, NULL);

            button = CreateWindow ("BUTTON", "Si mie imi place info!", WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   20, 50, 365, 20,
                                   hwnd, (HMENU) 1, NULL, NULL);
            break;

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case 1:
                    //::MessageBeep(MB_ICONERROR);
                    ::MessageBox(hwnd, "Butonul a fost apasat. \nContinuati pentru a vedea un program de grafica!", "Butonul a fost apasat", MB_OK);

                    int gd = DETECT, gm, left=100, top=100, right=200, bottom=200, x=300, y=150, radius=50;

                    initgraph(&gd, &gm, "C:\\TC\\BGI");

                    rectangle(left, top, right, bottom);
                    circle(x, y, radius);
                    bar(left + 300, top, right + 300, bottom);
                    line(left - 10, top + 150, left + 410, top + 150);
                    ellipse(x, y + 200, 0, 360, 100, 50);
                    outtextxy(left + 100, top + 325, "Primul meu program de grafica");

                    getch();
                    closegraph();

                    break;
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}
