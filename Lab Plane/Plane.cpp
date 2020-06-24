/*
 * Plane Game
 * Created by Bob_Huang
 * 信息1901 黄燊
 * Student ID: 2019310220123
 * Homework for C++ Programming
 * Not allowed to partly or completely copy my code to other's homework
 * Main frame finished on May 2nd, 2020
 * Last edited on May 11th, 2020
 * Pushed on https://github.com/strophehs/Homework/blob/CppBasic/Lab%20Plane/Plane.cpp
 */

// This program can only run in Microsoft(R) Visual Studio 2019
// If you find any bugs or problems, please contact bobhuang0917@outlook.com directly.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <utility>
#include <conio.h>
#include <Windows.h>
using namespace std;

// Symbols
constexpr auto MINE = 0,
			   ENEMY = 1,
			   BOSS = 2,
			   BULLET = 3,
			   EBULLET = 4,
			   BORDER = 5,
			   RAY = 6,
			   BUFF = 7,
			   BLANK = 8;
constexpr auto UP = 72,
			   DOWN = 80,
			   LEFT = 75,
			   RIGHT = 77,
			   SPACE = 32,
			   PAUSE = 112;

// APIs
inline void gotoxy(int x, int y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(h, pos);
}
inline void color(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
inline void reload()
{
	system("cls");
	gotoxy(0, 0);
}
void hideCursor()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO c;
	GetConsoleCursorInfo(h, &c);
	c.bVisible = 0;
	SetConsoleCursorInfo(h, &c);
}
inline int read()
{
	/*
	 Fast-read template
	 @param length: to limit the valid input data
	*/
	char ch = getchar();
	int x = 0, f = 1, length = 0;
	while (!isdigit(ch))
	{
		length++;
		if (length > 3)
			return -1;
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		length++;
		if (length > 3)
			return -1;
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

// Constants
const int icon[9] = {'^', '#', '$', '|', '*', '@', '!', '~', ' '};

// Settings
struct setting
{
	int HEIGHT_LIMIT;
	int WIDTH_LIMIT;
	int MAX_LIFE_LIMIT;
	int MAX_ENEMY_LIMIT;
	int isBossmode;
	int BOSS_BLOOD_LIMIT;
	int EBUL_SHOOT_FREQUENCY;
	int BUFF_LOAD_FREQUENCY;
	int BOSS_RAY_FREQUENCY;
	int SPEED;
	void loadSetting()
	{
		HEIGHT_LIMIT = 20;
		WIDTH_LIMIT = 41;
		MAX_LIFE_LIMIT = 3;
		MAX_ENEMY_LIMIT = 3;
		isBossmode = 0;
		BOSS_BLOOD_LIMIT = 50;
		EBUL_SHOOT_FREQUENCY = 3;
		BUFF_LOAD_FREQUENCY = 8;
		BOSS_RAY_FREQUENCY = 12;
		SPEED = 25;
	}
} settings;
#define height settings.HEIGHT_LIMIT
#define width settings.WIDTH_LIMIT
struct sh
{
	bool flag1 = 1;
	bool flag2 = 1;
	bool flag3 = 1;
	bool flag4 = 1;
	bool flag5 = 1;
	void update()
	{
		flag1++;
		flag2++;
		flag3++;
	}
} sh;

// Data Structures
struct Coordinate
{
	int x, y;
	Coordinate(int x, int y) : x(x), y(y) { ; }
	bool operator==(const Coordinate &b)
	{
		return this->x == b.x && this->y == b.y;
	}
};
inline Coordinate regenerate(int o)
{
	return Coordinate(o ? o : (rand() % (height - 2) + 1), rand() % (width - 2) + 1);
}

// Game
class Game
{
private:
	Coordinate my, boss, buff;
	vector<Coordinate> bul;
	vector<Coordinate> em;
	vector<Coordinate> ebul;
	int ray = -1;
	int score, life, bossLength, bossAttackTime;
	int canvas[100][100];
	int speed;
	void Async()
	{
		for (int i = 1; i < height - 1; i++)
			for (int j = 1; j < width - 1; j++)
				canvas[i][j] = BLANK;
		canvas[my.x][my.y] = MINE;
		if (buff.x != -1 && buff.y != -1)
			canvas[buff.x][buff.y] = BUFF;
		if (settings.isBossmode)
			canvas[boss.x][boss.y] = BOSS;
		for (int i = 0; i < em.size(); i++)
			canvas[em[i].x][em[i].y] = ENEMY;
		for (int i = 0; i < bul.size(); i++)
			canvas[bul[i].x][bul[i].y] = BULLET;
		for (int i = 0; i < ebul.size(); i++)
			canvas[ebul[i].x][ebul[i].y] = EBULLET;
		for (int i = 2; i < height - 1; i++)
			canvas[i][ray] = RAY;
	}
	void init()
	{
		bul.clear();
		em.clear();
		ebul.clear();
		color(0x0f);
		reload();
		score = 0;
		life = settings.MAX_LIFE_LIMIT;
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				canvas[i][j] = BLANK;
		for (int i = 0; i < width; i++)
			canvas[0][i] = canvas[height - 1][i] = BORDER;
		for (int i = 0; i < height; i++)
			canvas[i][0] = canvas[i][width - 1] = BORDER;
		my = Coordinate(height - 2, width / 2 + 1);
		buff = Coordinate(-1, -1);
		canvas[my.x][my.y] = MINE;
		for (int i = 0; i < settings.MAX_ENEMY_LIMIT; i++)
		{
			Coordinate q = regenerate(2);
			em.push_back(q);
			canvas[q.x][q.y] = ENEMY;
		}
		if (settings.isBossmode)
		{
			bossLength = settings.BOSS_BLOOD_LIMIT;
			boss = Coordinate(1, width / 2 + 1);
			canvas[boss.x][boss.y] = BOSS;
		}
	}
	void draw()
	{
		gotoxy(0, 0);
		color(0x0f);
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				putchar(icon[canvas[i][j]]);
			putchar('\n');
		}
	}
	void drawSidebar()
	{
		gotoxy(50, 5);
		printf("Plane Game");
		gotoxy(50, 6);
		printf("Mode: ");
		if (settings.isBossmode)
			printf("Boss");
		else
			printf("Normal");
		gotoxy(50, 7);
		printf("Press P to pause");
		gotoxy(50, 9);
		printf("Score: %d", score);
		gotoxy(50, 10);
		printf("Lives: %d", life);
		if (settings.isBossmode)
		{
			gotoxy(50, 12);
			printf("Boss has %d lives remained.", bossLength);
			gotoxy(50, 13);
			printf("%d points before boss activating X-ray", bossAttackTime);
		}
	}
	void update()
	{
		if (speed == 0 || speed == (settings.SPEED >> 1))
		{
			for (int i = 0; i < ebul.size(); i++)
			{
				ebul[i].x++;
				if (ebul[i].x == height - 1)
				{
					ebul.erase(ebul.begin() + i);
					i--;
					continue;
				}
			}
		}
		if (speed == 0)
		{
			for (int i = 0; i < em.size(); i++)
			{
				em[i].x++;
				em[i].y += (rand() % 3 - 1);
				if (em[i].y == 0)
					em[i].y = 1;
				if (em[i].y == width - 1)
					em[i].y = width - 2;
				if (em[i].x == height - 1)
				{
					em.erase(em.begin() + i);
					i--;
					em.push_back(regenerate(2));
				}
			}
			if (settings.isBossmode)
			{
				boss.y += (rand() % 3 - 1);
				if (boss.y == 0)
					boss.y = 1;
				if (boss.y == width - 1)
					boss.y = width - 2;
			}
			speed = settings.SPEED + 1;
		}
		speed--;
		for (int i = 0; i < bul.size(); i++)
		{
			bul[i].x--;
			if (bul[i].x == 0)
			{
				bul.erase(bul.begin() + i);
				i--;
				continue;
			}
		}
		if (score % settings.EBUL_SHOOT_FREQUENCY == settings.EBUL_SHOOT_FREQUENCY - 1 && sh.flag1)
		{
			for (int i = 0; i < em.size(); i++)
				if (em[i].x < height - 2)
					ebul.push_back(Coordinate(em[i].x + 1, em[i].y));
			sh.flag1 = 0;
		}
		if (score % settings.BUFF_LOAD_FREQUENCY == settings.BUFF_LOAD_FREQUENCY - 1 && sh.flag2)
			buff = regenerate(0), sh.flag2 = 0;
	}
	void updateBoss()
	{
		int dtime = settings.BOSS_RAY_FREQUENCY;
		bossAttackTime = dtime - score % dtime;
		if (bossAttackTime == dtime && score != 0 && sh.flag3)
		{
			ray = rand() % (width - 2) + 1;
			sh.flag3 = 0;
		}
		else
			ray = -1;
	}
	void processKbhit()
	{
		char q;
		if (_kbhit())
		{
			q = _getch();
			if (q == UP && my.x > 1)
				my.x--;
			else if (q == DOWN && my.x < height - 2)
				my.x++;
			else if (q == LEFT && my.y > 1)
				my.y--;
			else if (q == RIGHT && my.y < width - 2)
				my.y++;
			else if (q == SPACE && my.x > 1)
			{
				bul.push_back(Coordinate(my.x - 1, my.y));
				if (!sh.flag4)
				{
					sh.flag4 = 1;
					if (my.y > 1)
						bul.push_back(Coordinate(my.x - 1, my.y - 1));
					if (my.y < width - 2)
						bul.push_back(Coordinate(my.x - 1, my.y + 1));
				}
			}
			else if (q == PAUSE)
				system("pause");
		}
	}
	int crashCheck()
	{
		for (int i = 0; i < bul.size(); i++)
			for (int j = 0; j < em.size(); j++)
				if (bul[i] == em[j])
				{
					score++;
					sh.update();
					bul.erase(bul.begin() + i);
					em.erase(em.begin() + j);
					i--, j--;
					em.push_back(regenerate(2));
					break;
				}
		for (int i = 0; i < bul.size(); i++)
			for (int j = 0; j < ebul.size(); j++)
				if (bul[i] == ebul[j])
				{
					bul.erase(bul.begin() + i);
					ebul.erase(ebul.begin() + j);
					i--, j--;
					break;
				}
		for (int i = 0; i < bul.size(); i++)
			if (settings.isBossmode)
				if (bul[i] == boss)
				{
					bossLength--;
					score += 2;
					if (bossLength == 0)
						return 0 * winGame();
					bul.erase(bul.begin() + i);
					i--;
				}

#define lost()                                      \
	{                                               \
		dlife--;                                    \
		i--;                                        \
		my = Coordinate(height - 2, width / 2 + 1); \
	}
		int dlife = 0;
		for (int i = 0; i < em.size(); i++)
		{
			if (em[i] == my)
			{
				em.erase(em.begin() + i);
				em.push_back(regenerate(2));
				lost();
			}
		}
		for (int i = 0; i < ebul.size(); i++)
		{
			if (ebul[i] == my)
			{
				ebul.erase(ebul.begin() + i);
				lost();
			}
		}
		for (int i = 0; i < bul.size(); i++)
		{
			if (bul[i] == my)
			{
				bul.erase(bul.begin() + i);
				lost();
			}
		}
		if (settings.isBossmode)
		{
			if (ray == my.y)
			{
				int i = 1; // Nonsense
				lost();
			}
		}
		if (dlife)
			life--;
		if (life == 0)
			return 0 * endGame();
	}
	void buffActivate()
	{
		if (my == buff)
		{
			buff = Coordinate(-1, -1);
			int op = rand() % 3;
			switch (op)
			{
			case 0:
				life++;
				break;
			case 1:
				em.clear();
				ebul.clear();
				for (int i = 0; i < settings.MAX_ENEMY_LIMIT; i++)
					em.push_back(regenerate(2));
				break;
			case 2:
				sh.flag4 = 0;
				break;
			}
		}
	}

public:
	Game() : my(Coordinate(height - 2, width / 2 + 1)),
			 boss(Coordinate(1, width / 2 + 1)),
			 buff(Coordinate(0, 0)) {}
	int welcome()
	{
		reload();
		hideCursor();
		if (sh.flag5)
			settings.loadSetting();
		gotoxy(40, 15);
		color(0x0a);
		printf("PLANE GAME");
		color(0x0b);
		gotoxy(35, 22);
		printf("1. Start");
		gotoxy(48, 22);
		printf("2. Read Instruction");
		gotoxy(35, 24);
		printf("3. Options");
		gotoxy(48, 24);
		printf("Other: exit");
		gotoxy(30, 28);
		printf("Input your choice: ");
		color(0x07);
		int op = read();
		switch (op)
		{
		case 1:
			startGame();
			break;
		case 2:
			loadInstructions();
			break;
		case 3:
			changeSettingOptions();
			break;
		default:
			exit(0);
			break;
		}
		return 0;
	}
	void startGame()
	{
		init();
		while (life)
		{
			Async();
			draw();
			drawSidebar();
			update();
			if (settings.isBossmode)
				updateBoss();
			processKbhit();
			crashCheck();
			buffActivate();
		}
		endGame();
	}
	void loadInstructions()
	{
		reload();
		gotoxy(0, 0);
		color(0x0e);
		int buf[394] = {0x48, 0x65, 0x6c, 0x70, 0x20, 0x44, 0x6f, 0x63, 0x73, 0x0a, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x0a, 0x41, 0x75, 0x74, 0x68, 0x6f, 0x72, 0x3a, 0x42, 0x6f, 0x62, 0x5f, 0x48, 0x75, 0x61, 0x6e, 0x67, 0x0a, 0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x3a, 0x31, 0x2e, 0x30, 0x0a, 0x59, 0x6f, 0x75, 0x72, 0x20, 0x70, 0x6c, 0x61, 0x6e, 0x65, 0x20, 0x69, 0x73, 0x20, 0x73, 0x68, 0x6f, 0x77, 0x6e, 0x20, 0x61, 0x73, 0x20, 0x5e, 0x0a, 0x54, 0x68, 0x65, 0x20, 0x65, 0x6e, 0x65, 0x6d, 0x79, 0x27, 0x73, 0x20, 0x70, 0x6c, 0x61, 0x6e, 0x65, 0x20, 0x69, 0x73, 0x20, 0x73, 0x68, 0x6f, 0x77, 0x6e, 0x20, 0x61, 0x73, 0x20, 0x23, 0x0a, 0x54, 0x68, 0x65, 0x20, 0x42, 0x6f, 0x73, 0x73, 0x20, 0x70, 0x6c, 0x61, 0x6e, 0x65, 0x20,
						0x69, 0x73, 0x20, 0x73, 0x68, 0x6f, 0x77, 0x6e, 0x20, 0x61, 0x73, 0x20, 0x24, 0x0a, 0x59, 0x6f, 0x75, 0x72, 0x20, 0x62, 0x75, 0x6c, 0x6c, 0x65, 0x74, 0x73, 0x20, 0x61, 0x72, 0x65, 0x20, 0x73, 0x68, 0x6f, 0x77, 0x6e, 0x20, 0x61, 0x73, 0x20, 0x7c, 0x0a, 0x54, 0x68, 0x65, 0x20, 0x65, 0x6e, 0x65, 0x6d, 0x79, 0x27, 0x73, 0x20, 0x62, 0x75, 0x6c, 0x6c, 0x65, 0x74, 0x73, 0x20, 0x61, 0x72, 0x65, 0x20, 0x73, 0x68, 0x6f, 0x77, 0x6e, 0x20, 0x61, 0x73, 0x20, 0x2a, 0x0a, 0x54, 0x68, 0x65, 0x20, 0x62, 0x6f, 0x73, 0x73, 0x27, 0x20, 0x58, 0x2d, 0x72, 0x61, 0x79, 0x20, 0x69, 0x73, 0x20, 0x73, 0x68, 0x6f, 0x77, 0x6e, 0x20, 0x61, 0x73, 0x20, 0x21, 0x0a, 0x7e, 0x20, 0x6d, 0x65, 0x61, 0x6e, 0x73, 0x20, 0x62, 0x75, 0x66, 0x66, 0x2c, 0x20,
						0x79, 0x6f, 0x75, 0x20, 0x63, 0x61, 0x6e, 0x20, 0x74, 0x61, 0x6b, 0x65, 0x20, 0x69, 0x74, 0x20, 0x69, 0x6e, 0x20, 0x74, 0x6f, 0x20, 0x67, 0x65, 0x74, 0x20, 0x62, 0x6f, 0x6e, 0x75, 0x73, 0x2e, 0x0a, 0x50, 0x72, 0x65, 0x73, 0x73, 0x20, 0x55, 0x50, 0x2f, 0x44, 0x6f, 0x77, 0x6e, 0x2f, 0x4c, 0x45, 0x46, 0x54, 0x2f, 0x52, 0x49, 0x47, 0x48, 0x54, 0x20, 0x74, 0x6f, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x20, 0x79, 0x6f, 0x75, 0x72, 0x20, 0x70, 0x6c, 0x61, 0x6e, 0x65, 0x0a, 0x50, 0x72, 0x65, 0x73, 0x73, 0x20, 0x53, 0x50, 0x41, 0x43, 0x45, 0x20, 0x74, 0x6f, 0x20, 0x73, 0x68, 0x6f, 0x6f, 0x74, 0x20, 0x6f, 0x75, 0x74, 0x0a, 0x50, 0x72, 0x65, 0x73, 0x73, 0x20, 0x50, 0x20, 0x74, 0x6f, 0x20, 0x6b, 0x65, 0x65, 0x70, 0x20,
						0x74, 0x68, 0x65, 0x20, 0x67, 0x61, 0x6d, 0x65, 0x20, 0x70, 0x61, 0x75, 0x73, 0x65, 0x0a, 0x45, 0x6e, 0x6a, 0x6f, 0x79, 0x20, 0x79, 0x6f, 0x75, 0x72, 0x20, 0x67, 0x61, 0x6d, 0x65, 0x21};
		for (int i = 0; i < 394; i++)
			putchar(buf[i]);
		system("pause");
		welcome();
	}
	void changeSettingOptions()
	{
		reload();
		int op;
		printf("If you don't want to change, please input -1.\n");
		printf("(1)Set the height of canvas(10~30):");
		op = read();
		if (op >= 10 && op <= 30)
			settings.HEIGHT_LIMIT = op;
		printf("(2)Set the width of canvas(10~50):");
		op = read();
		if (op >= 10 && op <= 50)
			settings.WIDTH_LIMIT = op;
		printf("(3)Set the number of your lives(1~10):");
		op = read();
		if (op >= 1 && op <= 10)
			settings.MAX_LIFE_LIMIT = op;
		printf("(4)Set the maximum number of the enemy(1~10):");
		op = read();
		if (op >= 1 && op <= 10)
			settings.MAX_ENEMY_LIMIT = op;
		printf("(5)Enter the interval between enemy bullet launches(1~10):");
		op = read();
		if (op >= 1 && op <= 10)
			settings.EBUL_SHOOT_FREQUENCY = op;
		printf("(6)Enter the interval between buff's loading(3~10):");
		op = read();
		if (op >= 3 && op <= 10)
			settings.BUFF_LOAD_FREQUENCY = op;
		printf("(7)Enter the speed parameter(15~50):");
		op = read();
		if (op >= 15 && op <= 50)
			settings.SPEED = op;
		printf("(8)Set if you want to enter Boss mode(0/1):");
		op = read();
		if (op == 0 || op == 1)
			settings.isBossmode = op;
		if (settings.isBossmode)
		{
			printf("(9)Set the boss' blood(10~1000):");
			op = read();
			if (op >= 10 && op <= 1000)
				settings.BOSS_BLOOD_LIMIT = op;
			printf("(10)Enter the interval between boss' X-ray(10~99):");
			op = read();
			if (op >= 10 && op <= 99)
				settings.BOSS_RAY_FREQUENCY = op;
		}
		printf("Finish.\n");
		sh.flag5 = 0;
		system("pause");
		welcome();
	}
	int winGame()
	{
		reload();
		gotoxy(15, 18);
		color(0x0c);
		printf("Wonderful!\nYou killed the boss with %d points!\n", score);
		system("pause");
		return 0 * welcome();
	}
	int endGame()
	{
		reload();
		gotoxy(15, 18);
		color(0x0c);
		printf("Lose!\n");
		printf("Your score is: %d\n", score);
		if (settings.isBossmode)
			printf("The boss has %d lives remained.\n", bossLength);
		system("pause");
		return 0 * welcome();
	}
};

int main()
{
	srand((unsigned)time(NULL));
	Game b;
	b.welcome();
	return 0;
}