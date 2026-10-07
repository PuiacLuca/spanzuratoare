#include <iostream>
#include <cstring>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());

    char cuv[25], l;
    char gasit[25] = {};
    int c, hp,m,n;

    cin.getline(cuv, 25);

    c = strlen(cuv);
    hp = 6;
n=c;
uniform_int_distribution<>distrib(1, c-1);
    cout << "\033[1A";
    cout << "\033[2K";
    cout << "Total: "<<c<< endl;
    l=' ';
    while(l==' '){
l=cuv[distrib(gen)];
    }
    while (hp > 0&&n>0)
    {
    m=1;
        for (int i = 0; i < c; i++)
        {
            if (cuv[i] == l||cuv[i] == l-32||cuv[i]-32 == l||cuv[i]==' ')
            {
                gasit[i] = true;
                m=0;
                n--;
            }
        }
if(m==1){
    hp--;
}
        for (int i = 0; i < c; i++)
        {
            if (gasit[i])
                cout << "\033[32m" << cuv[i] << "\033[0m";
            else
                cout << "\033[31m_\033[0m";
        }
        cout<<endl;
        if(hp<=0||n<=0)break;
        cin >> l;
        cout << "\033[3A";

        cout << "hp:"<<hp<<"      "<<endl;
    }
    cout<<endl;
    if(n > 0){
        cout<<"\033[31mLooser\033[0m"<<endl<<cuv;
    }
    if(hp > 0){
        cout<<"\033[32mWinner\033[0m";
    }

    return 0;
}
