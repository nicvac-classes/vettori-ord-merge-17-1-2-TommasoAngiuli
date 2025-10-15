#include <iostream>
using namespace std;
int main() 
{
    int i, j, t, n, idx, x, p, inizio, fine, medio, m, k;
    cout << "inserire il numero di celle di v1" << endl;
    cin >> n;
    bool scambio;
    int v1[n];
    cout << "inserire il numero di celle di v2" << endl;
    cin >> m;
    int v3[n + m];
    int v2[m];
    i = 0;
    while (i <= n - 1) 
    {
        v1[i] = rand() % (n * 10 + 1);
        i = i + 1;
    }
    i = 0;
    while (i <= m - 1) 
    {
        v2[i] = rand() % (m * 10 + 1);
        i = i + 1;
    }
    i = 0;
    scambio = true;
    while (i <= n - 1 && scambio) 
    {
        scambio = false;
        j = 0;
        while (j <= n - 2 - i) 
        {
            if (v1[j] > v1[j + 1]) 
            {
                t = v1[j];
                v1[j] = v1[j + 1];
                v1[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    scambio = true;
    while (i <= m - 1 && scambio) 
    {
        scambio = false;
        j = 0;
        while (j <= m - 2 - i) 
        {
            if (v2[j] > v2[j + 1]) 
            {
                t = v2[j];
                v2[j] = v2[j + 1];
                v2[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    cout << "vettore 1" << endl;
    while (i <= n - 1) 
    {
        cout << v1[i] << endl;
        i = i + 1;
    }
    i = 0;
    cout << "vettore 2" << endl;
    while (i <= m - 1) 
    {
        cout << v2[i] << endl;
        i = i + 1;
    }
    i = 0;
    j = 0;
    k = 0;
    while (i <= n - 1 && j <= m - 1) 
    {
        if (v1[i] <= v2[j]) 
        {
            v3[k] = v1[i];
            i = i + 1;
        } 
        else 
        {
            v3[k] = v2[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i <= n - 1) 
    {
        v3[k] = v1[i];
        k = k + 1;
        i = i + 1;
    }
    while (j <= m - 1) 
    {
        v3[k] = v2[j];
        k = k + 1;
        j = j + 1;
    }
    cout << "vettore 3" << endl;
    i = 0;
    while (i <= n + m - 1) 
    {
        cout << v3[i] << endl;
        i = i + 1;
    }
    cout << "inserisci il valore da cercare" << endl;
    cin >> x;
    p = 0;
    idx = (int) (-1);
    inizio = 0;
    fine = n + m - 1;
    while (inizio <= fine && idx == -1) 
    {
        medio = (int) (inizio + (double) (fine - inizio) / 2);
        p = p + 1;
        if (x == v3[medio]) 
        {
            idx = medio;
        } 
        else 
        {
            p = p + 1;
            if (x > v3[medio]) 
            {
                inizio = medio + 1;
            } 
            else 
            {
                fine = medio - 1;
            }
        }
    }
    cout << "il valore si trova nella cella " << idx << " e sono stati effettuati " << p << " passaggi con la ricerca binaria" << endl;
    return 0;
}