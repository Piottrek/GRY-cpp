#include <iostream>
#include <vector>
using namespace std;

vector<string> listaSlow = { "KLUCZ","TEST","POLSKA","OAZA"};

void ryujWisielca(int blad)
{
    vector<string> wisielec = {
        "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
    };
    cout << wisielec[blad] << endl;
}

void czyscEkran()
{
    system("cls");
}

int main()
{
    setlocale(LC_ALL, "");
    srand(time(0));
    char ponownaGra;
    do
    {     
        int indeks = rand() % listaSlow.size();
        string slowo = listaSlow[indeks];
        listaSlow.erase(listaSlow.begin() + indeks);
        
        string zgadniete(slowo.length(), '_');
        string uzyteLitery = "";
        int bledy = 0;
        constexpr int maksymalneBledy = 6;

        while (bledy < maksymalneBledy && zgadniete != slowo)
        {
            czyscEkran();
            ryujWisielca(bledy);

            cout << "SŁOWO: " << zgadniete << endl;
            cout << "UŻYTE LITERY: " << uzyteLitery << endl;
            cout << "POZOSTAŁE PRÓBY: " << maksymalneBledy - bledy << endl;
        
            cout << "Podaj litere: ";
            char litera;
            cin >> litera;
            litera = toupper(litera);

            if (uzyteLitery.find(litera) != string::npos)
            {
                cout << "Ta litera jes juz podana" << endl; 
                continue;
            }
            
            uzyteLitery += litera;

            if (slowo.find(litera) != string::npos)
            {
                for (int i = 0; i < slowo.length(); i++)
                {
                    if (slowo[i] == litera)
                    {
                        zgadniete[i] = litera;
                    }
                }
            }
            else
            {
                bledy++;
            }
        }

        czyscEkran();
        ryujWisielca(bledy);
        if (zgadniete == slowo)
        {
            cout << "GRATULUJE! TWOJE SLOWO TO: " << slowo << endl;
        }
        else
        {
            cout << "PRZEGRALES! PRAWIDLOWE SLOWO TO: " << slowo << endl;
        }

        cout << "CZY CHESZ ZAGRAC PONOWNIE? (T/N)";
        cin >> ponownaGra;
        ponownaGra = toupper(ponownaGra);

    } while (ponownaGra == 'T');
     return 0;
}