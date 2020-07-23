#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

class LinkedList
{
public:
	int Data;
	int Next;
};

int main()
{
	int Head, N, K;
	cin >> Head >> N >> K;

	map<int,LinkedList> map_LinkedList;
	LinkedList temp;
	int add, data, next;

	for (int i = 0; i < N; i++)
	{
		cin >> add >> data >> next;
		temp.Data = data; temp.Next = next;
		map_LinkedList[add] = temp;
	}

	int *addptr = new int[N];
	int Num_Valid = 1;
	addptr[0] = Head;
	for (int i = 1; i < N; i++)
	{
		if (map_LinkedList[addptr[i - 1]].Next != -1)
		{
			addptr[i] = map_LinkedList[addptr[i - 1]].Next;
			Num_Valid++;
		}
		else
			break;
	}
	
	int pos = 0;
	if (K > 1)
	{
		while (pos + K <= Num_Valid)
		{
			reverse(addptr + pos, addptr + pos + K);
			pos += K;
		}
	}

	for (int i = 0; i < Num_Valid; i++)
	{
		if (i != Num_Valid - 1)
			map_LinkedList[addptr[i]].Next = addptr[i + 1];
		else
			map_LinkedList[addptr[i]].Next = -1;
	}
	
	for (int i = 0; i < Num_Valid; i++)
	{
		if (map_LinkedList[addptr[i]].Next != -1)
			printf("%05d %d %05d\n", addptr[i], map_LinkedList[addptr[i]].Data, map_LinkedList[addptr[i]].Next);
		else
			printf("%05d %d %d\n", addptr[i], map_LinkedList[addptr[i]].Data, map_LinkedList[addptr[i]].Next);
	}

	delete[] addptr;
	return 0;
}
