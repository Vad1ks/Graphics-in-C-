#include <windows.h>
#include <conio.h>
#include <iostream>
#define PI 3.14159265359
using namespace std;

POINT pointTop;
POINT pointBottom;
POINT pointLeft;
POINT pointRight;

int main()
{
	pointTop.x = 500 - 10;
	pointTop.y = 35 + 10;
	pointRight.x = 580 - 10;
	pointRight.y = 315 + 10;
	pointBottom.x = 500 - 10;
	pointBottom.y = 570 + 10;
	pointLeft.x = 420 - 10;
	pointLeft.y = 315 + 10;

	POINT *rhomb = new POINT[4];
	rhomb[0] = pointTop;
	rhomb[1] = pointRight;
	rhomb[2] = pointBottom;
	rhomb[3] = pointLeft;

	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd); //получаем DC(контекст устройства) дл€ рисовани€
	HPEN hpen1; //объ€вл€ем объект перо
	HGDIOBJ hpenOld, hbrushOld;
	HBRUSH hbrush; //объ€вл€ем кисть

	hpen1 = CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); //логическое перо с заданным стилем, шириной и цветом
	hpenOld = (HPEN)SelectObject(hdc, hpen1);

	MoveToEx(hdc, 500 - 10, 15 + 10, NULL);//устанавливает текущей позицией указанную точку
	LineTo(hdc, 590 - 10, 315 + 10);
	// Sleep( 100 );
	LineTo(hdc, 500 - 10, 585 + 10);
	// Sleep( 100 );
	LineTo(hdc, 410 - 10, 315 + 10);
	// Sleep( 100 );
	LineTo(hdc, 500 - 10, 15 + 10);

	hpen1 = CreatePen(PS_SOLID, 7, RGB(255, 255, 255)); //логическое перо с заданным стилем, шириной и цветом
	hpenOld = (HPEN)SelectObject(hdc, hpen1);

	hbrush = CreateSolidBrush(RGB(0, 0, 255));
	hbrushOld = (HBRUSH)SelectObject(hdc, hbrush);
	
	MoveToEx(hdc, 500 - 10, 35 + 10, NULL);
	// Sleep( 100 );
	LineTo(hdc, 580 - 10, 315 + 10);
	// Sleep( 100 );
	LineTo(hdc, 500 - 10, 570 + 10);
	// Sleep( 100 );
	LineTo(hdc, 420 - 10, 315 + 10);
	// Sleep( 100 );
	LineTo(hdc, 500 - 10, 35 + 10);

	Polygon(hdc, rhomb, 4);

	MoveToEx(hdc, 495 - 10, 240 + 10, NULL);
	hpen1 = CreatePen(PS_SOLID, 8, RGB(255, 255, 255)); //логическое перо с заданным стилем, шириной и цветом
	hpenOld = (HPEN)SelectObject(hdc, hpen1);
	// Sleep( 100 );
	LineTo(hdc, 495 - 10, 345 + 10);//вертикальна€ вниз
	// Sleep( 100 );
	LineTo(hdc, 482 - 10, 355 + 10);//петл€(влево вниз)
	// Sleep( 100 );
	LineTo(hdc, 470 - 10, 345 + 10);//петл€(влево вверх)
	// Sleep( 100 );
	LineTo(hdc, 482 - 10, 335 + 10);//петл€(вправо вверх)
	// Sleep( 100 );
	LineTo(hdc, 508 - 10, 355 + 10);//петл€(вправо вниз)
	// Sleep( 100 );
	LineTo(hdc, 515 - 10, 355 + 10);
	// Sleep( 100 );
	LineTo(hdc, 523 - 10, 352 + 10);//ду спра
	// Sleep( 100 );
	LineTo(hdc, 541 - 10, 335 + 10);//га ва
	// Sleep( 100 );
	LineTo(hdc, 547 - 10, 325 + 10);
	// Sleep( 100 );
	LineTo(hdc, 549 - 10, 315 + 10);
	// Sleep( 100 );
	LineTo(hdc, 550 - 10, 290 + 10);//pryamaya na duge
	// Sleep( 100 );
	LineTo(hdc, 550 - 10, 276 + 10);
	// Sleep( 100 );
	LineTo(hdc, 536 - 10, 255 + 10);//вертикальна€ вверх
	// Sleep( 100 );
	LineTo(hdc, 525 - 10, 245 + 10);//дуга
	// Sleep( 100 );
	LineTo(hdc, 510 - 10, 239 + 10);//вверху
	// Sleep( 100 );
	LineTo(hdc, 480 - 10, 242 + 10);//горизонтальна€ влево
	// Sleep( 100 );
	LineTo(hdc, 471 - 10, 253 + 10);//конечна€ дуга
	// Sleep( 100 );
	LineTo(hdc, 464 - 10, 267 + 10);//справа налево
	// Sleep( 100 );
	LineTo(hdc, 464 - 10, 275 + 10);

	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(255, 222, 0));
	HBRUSH hBrush = CreateSolidBrush(RGB(239, 255, 0));
	SelectObject(hdc, hPen);
	SelectObject(hdc, hBrush);

	int R1 = 15, R2 = 7, count = -1, XC = 450, YC = 45;
	double step = 0.2 * PI, angle = 1.6 * PI;

	POINT P[10];

	while (++count < 10)
	{
		P[count].x = XC + R1 * sin(angle);
		P[count].y = YC - R1 * cos(angle);
		angle += step;
		P[++count].x = XC + R2 * sin(angle);
		P[count].y = YC - R2 * cos(angle);
		angle += step;
	}

	Polygon(hdc, P, 10);

	DeleteObject(hPen);
	DeleteObject(hBrush);


	SelectObject(hdc, hPen);
	SelectObject(hdc, hBrush);

	int R12 = 15, R22 = 7, XC2 = 530, YC2 = 45;
	count = -1;
	double step2 = 0.2 * PI, angle2 = 1.6 * PI;

	POINT P2[10];

	while (++count < 10)
	{
		P2[count].x = XC2 + R12 * sin(angle2);
		P2[count].y = YC2 - R12 * cos(angle2);
		angle2 += step2;
		P2[++count].x = XC2 + R22 * sin(angle2);
		P2[count].y = YC2 - R22 * cos(angle2);
		angle2 += step2;
	}

	Polygon(hdc, P2, 10);

	DeleteObject(hpen1);
	getchar();
	system("pause");
	return 0;
}