#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<SFML/Graphics.hpp>
using namespace std;

bool Poop = 0;

#define ifor(m) for (int i = 0; i < m; ++i)
#define jfor(n) for (int j = 0; j < n; ++j)

void Turn1(int(*Line)[9][9], int *n)
{
	srand(time(0));
	int AddBall = 0,i,j;
	if (*n < 2) *n = 0;
	else
	{
		while (AddBall < 3)
		{
			i = rand() % 9;
			j = rand() % 9;
			if ((*Line)[i][j]==0)
			{
				++AddBall;
				(*Line)[i][j] = rand() % 5 + 1;
				--(*n);
			}
		}
		AddBall = 0;
		while (AddBall < 3)
		{
			i = rand() % 9;
			j = rand() % 9;
			if ((*Line)[i][j] == 0)
			{
				++AddBall;
				(*Line)[i][j] = rand() % 5 + 6;
			}
		}
	}
}



void EachTurn(int(*Line)[9][9], int *n)
{
	srand(time(0));
	int AddBall = 0, i, j;
	ifor(9)
		jfor(9)
	{
		if ((*Line)[i][j] == 6) (*Line)[i][j] = 1;
		if ((*Line)[i][j] == 7) (*Line)[i][j] = 2;
		if ((*Line)[i][j] == 8) (*Line)[i][j] = 3;
		if ((*Line)[i][j] == 9) (*Line)[i][j] = 4;
		if ((*Line)[i][j] == 10) (*Line)[i][j] = 5;
	}
	if (*n < 2) *n = 0;
	else
	{
		while (AddBall < 3)
		{
			i = rand() % 9;
			j = rand() % 9;
			if ((*Line)[i][j] == 0)
			{
				++AddBall;
				(*Line)[i][j] = rand() % 5 + 6;
			}
		}
	}
}

bool Checking(int Line[9][9],int x1,int y1,int x2,int y2)
{
	vector<vector<int>> BFS(9, vector<int>(9, 0));
	vector<vector<bool>> CBlank(9, vector<bool>(9, true));
	int bd = 1, loopturn = 0;
	BFS[x1][y1] = -1;
	BFS[x2][y2] = -2;
	if (x1 != 0) 
	{ 
		if (x1 - 1 == x2 and y1 == y2) return false; 
		if ((Line[x1 - 1][y1] == 0 or Line[x1 - 1][y1] > 5) and CBlank[x1 - 1][y1]) { ++BFS[x1 - 1][y1]; CBlank[x1 - 1][y1] = false; }
	}
	if (y1 != 0) 
	{ 
		if (x1 == x2 and y1 - 1 == y2) return false;
		if ((Line[x1][y1 - 1] == 0 or Line[x1][y1 - 1] > 5) and CBlank[x1][y1 - 1]) { ++BFS[x1][y1 - 1]; CBlank[x1][y1 - 1] = false; }
	}
	if (x1 != 8) 
	{ 
		if (x1 + 1 == x2 and y1 == y2) return false;
		if ((Line[x1 + 1][y1] == 0 or Line[x1 + 1][y1] > 5) and CBlank[x1 + 1][y1]) { ++BFS[x1 + 1][y1]; CBlank[x1 + 1][y1] = false; }
	}
	if (y1 != 8) 
	{ 
		if (x1 == x2 and y1 + 1 == y2) return false;
		if ((Line[x1][y1 + 1] == 0 or Line[x1][y1 + 1] > 5)and CBlank[x1][y1 + 1]) { ++BFS[x1][y1 + 1]; CBlank[x1][y1 + 1] = false; }
	}
	while (loopturn < 81)
	{
		ifor(9)
			jfor(9)
		{
			if (BFS[i][j] == bd)
			{
				if (i != 0)
				{
					if (i - 1 == x2 and j == y2) { return false; 
					cout << endl;
					ifor(9)
					{
						jfor(9)
						{
							cout << BFS[i][j] << ' ';
						}
						cout << endl;
					}
					}
					if ((Line[i - 1][j] == 0 or Line[i - 1][j] > 5) and CBlank[i - 1][j]) { BFS[i - 1][j] = bd + 1; CBlank[i - 1][j] = false; }
				}
				if (j != 0)
				{
					if (i == x2 and j - 1 == y2) {
						cout << endl;
						ifor(9)
						{
							jfor(9)
							{
								cout << BFS[i][j] << ' ';
							}
							cout << endl;
						}
					return false; }
					if ((Line[i][j - 1] == 0 or Line[i][j - 1] > 5) and CBlank[i][j - 1]) { BFS[i][j - 1] = bd + 1; CBlank[i][j - 1] = false; }
				}
				if (i != 8)
				{
					if (i + 1 == x2 and j == y2) {
						cout << endl;
						ifor(9)
						{
							jfor(9)
							{
								cout << BFS[i][j] << ' ';
							}
							cout << endl;
						}
						return false; }
					if ((Line[i + 1][j] == 0 or Line[i + 1][j] > 5) and CBlank[i + 1][j]) { BFS[i + 1][j] = bd + 1; CBlank[i + 1][j] = false; }
				}
				if (j != 8)
				{
					if (i == x2 and j + 1 == y2) {
						cout << endl;
						ifor(9)
						{
							jfor(9)
							{
								cout << BFS[i][j] << ' ';
							}
							cout << endl;
						}
						return false; }
					if ((Line[i][j + 1] == 0 or Line[i][j + 1] > 5) and CBlank[i][j + 1]) { BFS[i][j + 1] = bd + 1; CBlank[i][j + 1] = false; }
				}
			}
		}
		++bd;
		++loopturn;
	}
	return true;
}


void Update(int (*Line)[9][9], int *n)
{
	int bd,x,y;
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			if ((*Line)[i][j] != 0) // CHECK VERTICAL
			{
				bd = 1; 
				x = i;
				y = j;
				while ((*Line)[x][y] == (*Line)[x][y + 1])
				{
					++y;
					++bd;
				}
				if (bd >= 5)
				{
					Poop = 1;
					while (bd > 0)
					{
						(*Line)[x][y] = 0;
						--y;
						--bd;
						++(*n);
					}
				}
			}
			if ((*Line)[i][j] != 0) // CHECK HORIZONTAL
			{
				bd = 1; 
				x = i;
				y = j;
				while ((*Line)[x][y] == (*Line)[x + 1][y])
				{
					++x;
					++bd;
				}
				if (bd >= 5)
				{
					Poop = 1;
					while (bd > 0)
					{
						(*Line)[x][y] = 0;
						--x;
						--bd;
						++(*n);
					}
				}
			}
			if ((*Line)[i][j] != 0) // CHECK LEFT SLADE
			{
				bd = 1;
				x = i;
				y = j;
				while ((*Line)[x][y] == (*Line)[x + 1][y - 1])
				{
					++x;
					--y;
					++bd;
				}
				if (bd >= 5)
				{
					Poop = 1;
					while (bd > 0)
					{
						(*Line)[x][y] = 0;
						--x;
						++y;
						--bd;
						++(*n);
					}
				}
			}
			if ((*Line)[i][j] != 0) // CHECK RIGHT SLADE
			{
				bd = 1;
				x = i;
				y = j;
				while ((*Line)[x][y] == (*Line)[x + 1][y + 1])
				{
					++x;
					++y;
					++bd;
				}
				if (bd >= 5)
				{
					Poop = 1;
					while (bd > 0)
					{
						(*Line)[x][y] = 0;
						--x;
						--y;
						--bd;
						++(*n);
					}
				}
			}
		}
}


int main()
{
	int TILE_SIZE_x = 100, y = TILE_SIZE_x, r = 40, xr = TILE_SIZE_x / 2, yr = xr;
	bool playerloop = true, SelectBall = false;
	int Line[9][9], bt, n;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			Line[i][j] = 0;
		}
	n = 9 * 9;
	Turn1(&Line, &n);
	for (int i = 0; i < 9; ++i){
		for (int j = 0; j < 9; ++j)
		{
			cout << Line[i][j] << ' ';
		}
		cout << endl;
	}
	sf::Vector2i Resolution(TILE_SIZE_x * 9, y * 9);
	sf::Vector2i Block(TILE_SIZE_x, y);
	sf::Vector2i mousePos;
	sf::CircleShape RedB(r),BlueB(r),YellowB(r),GreenB(r),PurpleB(r), RedBS(r/3), BlueBS(r/3), YellowBS(r/3), GreenBS(r/3), PurpleBS(r/3);
	RedB.setFillColor(sf::Color::Red);
	RedB.setOrigin(xr, yr);
	BlueB.setFillColor(sf::Color::Blue);
	BlueB.setOrigin(xr, yr);
	YellowB.setFillColor(sf::Color::Yellow);
	YellowB.setOrigin(xr, yr);
	GreenB.setFillColor(sf::Color::Green);
	GreenB.setOrigin(xr, yr);
	PurpleB.setFillColor(sf::Color(148, 0, 211));
	PurpleB.setOrigin(xr, yr); 
	RedBS.setFillColor(sf::Color::Red);
	RedBS.setOrigin(xr, yr);
	BlueBS.setFillColor(sf::Color::Blue);
	BlueBS.setOrigin(xr, yr);
	YellowBS.setFillColor(sf::Color::Yellow);
	YellowBS.setOrigin(xr, yr);
	GreenBS.setFillColor(sf::Color::Green);
	GreenBS.setOrigin(xr, yr);
	PurpleBS.setFillColor(sf::Color(148, 0, 211));
	PurpleBS.setOrigin(xr, yr);
	sf::RenderWindow Window;
	Window.create(sf::VideoMode(Resolution.x, Resolution.y), "Line98", sf::Style::Close);
	Window.setPosition(sf::Vector2i(1000,200));
	mousePos = sf::Mouse::getPosition(Window);
	sf::ContextSettings settings;
	settings.antialiasingLevel = 18;

	sf::Vector2i *targetA = NULL;
	while (Window.isOpen())
	{
		sf::Event event;
		bool input = 0;
		int mid = 0;
		Update(&Line, &n);
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i click(sf::Mouse::getPosition(Window).x / 100,sf::Mouse::getPosition(Window).y / 100);
				cout << click.x << ' ' << click.y << endl;
				if (targetA == NULL) {
					if (Line[click.y][click.x] > 0 and Line[click.y][click.x] < 6) {
						targetA = new sf::Vector2i(click.x, click.y);
					}
				}
				else {
					if (Line[click.y][click.x] == 0 or Line[click.y][click.x] > 5) {
						cout << "click :\n";
						x1 = targetA->y;
						y1 = targetA->x;
						x2 = click.y;
						y2 = click.x;
						cout << "A: " << x1 << ' ' << y1 << '\n';
						cout << "B: " << x2 << ' ' << y2 << '\n';
						input = 1;
					}

						delete targetA;
						targetA = NULL;
				}
			}

		}
		Poop = 0;
		if (input) {
			if (Checking(Line, x1, y1, x2, y2) == false) {
				mid = Line[x2][y2];
				Line[x2][y2] = Line[x1][y1];
				Line[x1][y1] = 0;
				Update(&Line, &n);
				if (Poop == 0) {
					EachTurn(&Line, &n);
				}
				else Line[x2][y2] = mid;
			}
		}
			
		if (n == 0)
		{
			cout << "U HAVE BEEN GAME END" << endl;
			break;
		}


		Window.clear(sf::Color::White);
		for (int i = 0; i < 9; ++i) // RENDERGAME
		{
			for (int j = 0; j < 9; ++j)
			{
				if (Line[i][j] == 1)
				{
					RedB.setPosition(xr + j * Block.x + 10, yr + i * Block.y + 10);
					Window.draw(RedB);
				}
				if (Line[i][j] == 2)
				{
					BlueB.setPosition(xr + j * Block.x + 10, yr + i * Block.y + 10);
					Window.draw(BlueB);
				}
				if (Line[i][j] == 3)
				{
					YellowB.setPosition(xr + j * Block.x + 10, yr + i * Block.y + 10);
					Window.draw(YellowB);
				}
				if (Line[i][j] == 4)
				{
					GreenB.setPosition(xr + j * Block.x + 10, yr + i * Block.y + 10);
					Window.draw(GreenB);
				}
				if (Line[i][j] == 5)
				{
					PurpleB.setPosition(xr + j * Block.x + 10, yr + i * Block.y + 10);
					Window.draw(PurpleB);
				}if (Line[i][j] == 6)
				{
					RedBS.setPosition(xr + j * Block.x + 37, yr + i * Block.y + 37);
					Window.draw(RedBS);
				}
				if (Line[i][j] == 7)
				{
					BlueBS.setPosition(xr + j * Block.x + 37, yr + i * Block.y + 37);
					Window.draw(BlueBS);
				}
				if (Line[i][j] == 8)
				{
					YellowBS.setPosition(xr + j * Block.x + 37, yr + i * Block.y + 37);
					Window.draw(YellowBS);
				}
				if (Line[i][j] == 9)
				{
					GreenBS.setPosition(xr + j * Block.x + 37, yr + i * Block.y + 37);
					Window.draw(GreenBS);
				}
				if (Line[i][j] == 10)
				{
					PurpleBS.setPosition(xr + j * Block.x + 37, yr + i * Block.y + 37);
					Window.draw(PurpleBS);
				}
			}
		}
		ifor(9)
			jfor(9)
		{
			sf::VertexArray Outline(sf::LinesStrip, 4);
			Outline[0].position = sf::Vector2f(i * Block.x, j * Block.y);
			Outline[0].color = sf::Color::Black;
			Outline[1].position = sf::Vector2f(i * Block.x + Block.x, j * Block.y);
			Outline[1].color = sf::Color::Black;
			Outline[2].position = sf::Vector2f(i * Block.x + Block.x, j * Block.y + Block.y);
			Outline[2].color = sf::Color::Black;
			Outline[3].position = sf::Vector2f(i * Block.x, j * Block.y + Block.y);
			Outline[3].color = sf::Color::Black;
			Window.draw(Outline);
		}
		Window.display();
		
	}
	


	system("pause");
	return 0;
}