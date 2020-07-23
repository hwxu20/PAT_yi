#include <iostream>
using namespace std;

class TypeResult
{
public:
	TypeResult(int w = 0, int l = 0, int d = 0): win(w), lose(l), draw(d) {};
	int win, lose, draw;
	void update(int r);
};

void TypeResult::update(int r)
{
	if (r == 2) draw += 1;
	else if (r == 1) win += 1;
	else if (r == 0) lose += 1;
}

class GameResult
{
public:
	TypeResult C;
	TypeResult J;
	TypeResult B;
	TypeResult T;
	char Max_win;
	void update_result(int r, char type);
	void update_maxwin();
};

void GameResult:: update_result(int r, char type)
{
	switch (type)
	{
	case 'C':
		C.update(r); break;
	case 'J':
		J.update(r); break;
	case 'B':
		B.update(r); break;
	default:
		cout << "Wrong type!" << endl;
	}
	T.update(r);
}

void GameResult::update_maxwin()
{
	if ((C.win <= B.win) && (J.win <= B.win))
		Max_win = 'B';
	else if ((B.win < C.win) && (J.win <= C.win))
		Max_win = 'C';
	else
		Max_win = 'J';
}

int Gamejudge(char a, char b)
{
	if (((a == 'C') && (b == 'J'))
		|| ((a == 'J') && (b == 'B'))
		|| ((a == 'B') && (b == 'C')))
		return 1;
	else if (a == b)
		return 2;
	else 
		return 0;
}

int main()
{
	int N = 0;
	char a, b = '0';
	GameResult Jia, Yi;

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		Jia.update_result(Gamejudge(a, b), a);
		Yi.update_result(Gamejudge(b, a), b);
	}
	Jia.update_maxwin();
	Yi.update_maxwin();

	cout << Jia.T.win << " " << Jia.T.draw << " " << Jia.T.lose << endl;
	cout << Yi.T.win << " " << Yi.T.draw << " " << Yi.T.lose << endl;
	cout << Jia.Max_win << " " << Yi.Max_win << endl;

	return 0;
}