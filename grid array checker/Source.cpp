#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
#define player p;
class Player
{
public:
	int x, y;
	void move_m(int newx, int newy)
	{
		x = newx;
		if (x >= 41) { x = 40; }
		y = newy;
		if (y >= 3) { y = 2; }
	};
};
class Map
{
public:
	bool collision[3][41] = { //grid of true tiles you can move into and false tiles you cannot
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },//sky
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1 },//middle
		{ 1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1 } };//ground
	bool movecheck(int x, int y)
	{
		if (collision[y][x] == true)
		{
			return true;
		}
		else {
			return false;
		}
	};
};
int main()
{
	Map world;
	Player p;
	p.x = 4;
	p.y = 2;

	while(true)
	{
		int left = GetAsyncKeyState(VK_LEFT);
		int right = GetAsyncKeyState(VK_RIGHT);
		int up = GetAsyncKeyState(VK_UP);
		int down = GetAsyncKeyState(VK_DOWN);

		if(left != 0)
		{
			bool maymove = world.movecheck((p.x - 1), p.y);
			if(maymove == true)
			{
				p.move_m((p.x - 1), p.y);
				cout << p.x << "-" << p.y << endl;
			}
		}
		else if (right != 0)
		{
			bool maymove = world.movecheck((p.x + 1), p.y);
			if (maymove == true)
			{
				p.move_m((p.x + 1), p.y);
				cout << p.x << "-" << p.y << endl;
			}
		}
		else if (up != 0)
		{
			bool maymove = world.movecheck(p.x, (p.y - 1));
			if (maymove == true)
			{
				p.move_m(p.x, (p.y - 1));
				cout << p.x << "-" << p.y << endl;
			}
		}
		else if (down != 0)
		{
			bool maymove = world.movecheck(p.x, (p.y + 1));
			if (maymove == true)
			{
				p.move_m(p.x, (p.y + 1));
				cout << p.x << "-" << p.y << endl;
			}
		}
	}
}
