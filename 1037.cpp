#include <iostream>
#include <string>
using namespace std;

void CalChange(int Gp, int Sp, int Kp, int Ga, int Sa, int Ka)
{
	int Gc = 0, Sc = 0, Kc = 0;

	if ((Ga < Gp) || ((Ga == Gp) && (Sa < Sp)) || ((Ga == Gp) && (Sa == Sp) && (Ka < Kp)))
	{
		printf("-");
		int tempg, temps, tempk;
		tempg = Ga; temps = Sa; tempk = Ka;
		Ga = Gp; Sa = Sp; Ka = Kp;
		Gp = tempg; Sp = temps; Kp = tempk;
	}
	do
	{
		if (Ka >= Kp) Kc = Ka - Kp;
		else
		{
			if (Sa > 0) { Sa--; Ka += 29; Kc = Ka - Kp; }
			else { Ga--;  Sa += 16; Ka += 29; Kc = Ka - Kp; }
		}
	} while (Ka < Kp);

	do
	{
		if (Sa >= Sp) Sc = Sa - Sp;
		else { Ga--; Sa += 17; Sc = Sa - Sp; }
	} while (Sa < Sp);
	
	Gc = Ga - Gp;
	printf("%d.%d.%d", Gc, Sc, Kc);

}

int main()
{
	string a, b;
	cin >> a >> b;

	int G_p, S_p, K_p, G_a, S_a, K_a;
	int len_gp = a.find('.');
	G_p = stoi(a.substr(0, len_gp));
	a.erase(0, len_gp + 1);
	int len_sp = a.find('.');
	S_p = stoi(a.substr(0, len_sp));
	int len_kp = a.size() - 1 - len_sp;
	K_p = stoi(a.substr(len_sp + 1, len_kp));

	int len_ga = b.find('.');
	G_a = stoi(b.substr(0, len_ga));
	b.erase(0, len_ga + 1);
	int len_sa = b.find('.');
	S_a = stoi(b.substr(0, len_sa));
	int len_ka = b.size() - 1 - len_sa;
	K_a = stoi(b.substr(len_sa + 1, len_ka));

	CalChange(G_p, S_p, K_p, G_a, S_a, K_a);


	return 0;
}