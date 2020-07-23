#include <iostream>
using namespace std;

struct Question
{
	int Points;
	int Num_op;
	int Num_correct;
	int Num_false = 0;
	string Correct_Ans;
	void Write_Ans(char c);
};

void Question::Write_Ans(char c)
{
	Correct_Ans.push_back(c);
}

struct Student
{
	int Grades = 0;
	string Ans;
	int Num_Ans;
	void Wr_Ans(char c);
	void updateGrades(Question &Q);
	void Clear_Ans();
};

void Student::Wr_Ans(char c)
{
	Ans.push_back(c);
}

void Student::updateGrades(Question &Q)
{
	bool flag = 1;
	if (Q.Num_correct == Num_Ans)
	{
		for (int i = 0; i < Num_Ans; i++)
			if (Ans[i] != Q.Correct_Ans[i])
			{
				flag = 0; break;
			}	
	}
	else flag = 0;

	if (flag == 1) Grades += Q.Points;
	else Q.Num_false++;
}

void Student::Clear_Ans()
{
	Ans.clear();
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	int *Grade = new int[N];
	Question *Q = new Question[M];

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &Q[i].Points, &Q[i].Num_op, &Q[i].Num_correct);
		char c = '0';
		while (c != '\n')
		{
			c = getchar(); 
			if ((c !=' ') && (c!='\n'))
				Q[i].Write_Ans(c);
		}
	}

	Student *S = new Student[N];
	for (int i = 0; i < N; i++)
	{
		char c = '0'; int j = 0;
		while (c != '\n')
		{
			c = getchar();
			if (c == '(')
			{
				while (c != ')')
				{
					c = getchar();
					if (('0' <= c) && (c <= '9'))
						S[i].Num_Ans = c - '0';
					else if (('a' <= c) && (c <= 'e'))
						S[i].Wr_Ans(c);
				}
				S[i].updateGrades(Q[j++]);
				S[i].Clear_Ans();
			}
		}
		printf("%d\n", S[i].Grades);
	}

	int MAX_False = 0;
	for (int i = 0; i < M; i++)
	{
		if (Q[i].Num_false > MAX_False)
			MAX_False = Q[i].Num_false;
	}

	if (MAX_False == 0) printf("Too simple\n");
	else
	{
		printf("%d", MAX_False);
		for (int i = 0; i < M; i++)
		{
			if (Q[i].Num_false == MAX_False)
				printf(" %d", i + 1);
		}
		printf("\n");
	}

	delete[] S;
	delete[] Q;
	return 0;
}