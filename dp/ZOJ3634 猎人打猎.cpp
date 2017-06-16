#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
#define MAX 100100
double charge[MAX],cost[MAX];
double ratio_money[MAX],ratio_energy[MAX];
int main()
{
    int N;
    double money,energy;
    while(cin >> N >> money >> energy)
    {
        for(int i = 0;i < N;i++)cin >> cost[i] >> charge[i];
        for(int i = N - 1;i >= 0;i--)
        {
            if(i == N - 1)
            {
                ratio_money[i] = max((double)1,charge[i] / cost[i]);
                //energy is useless more the money have,more good
                ratio_energy[i] = charge[i];//each energy can transform ...money
            }
            else
            {
                ratio_energy[i] = charge[i] * ratio_money[i + 1] + ratio_energy[i + 1];
                /*
                each energy can transform this step's money then this step money go on
                transform to next step's money and next step's one energy
                */
                ratio_money[i] = max(ratio_money[i + 1],ratio_energy[i] / cost[i]);
                //each money can transform next step's one money or this step's energy
            }
        }
        cout << fixed << setprecision(2) << ratio_energy[0] * energy + ratio_money[0] * money << endl;
    }
    return 0;
}
