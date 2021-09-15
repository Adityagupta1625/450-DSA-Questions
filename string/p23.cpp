// Robin krap Algorithm

#include <iostream>
#include <math.h>
using namespace std;

void search(char t[], char p[])
{
    int j = 0;
    int hashsum = 0;
    int m = 4, n = 4;
    while (t[j] != '\0')
    {
        int a = (t[j] - 'A' + 1) * pow(26, m - 1);
        a = a % 101;
        hashsum += a;
        m--;
        j++;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a = (p[i] - 'A' + 1) * pow(26, n - i - 1);
        a = a % 101;
        sum = sum + a;
    }
    int k = 0;

    if (sum == hashsum)
    {
        while (t[k] == p[k])
        {
            k++;
        }
    }
    if (k == n)
    {
        cout << 0 << endl;
    }
    int i = n;
    j = 0;
    while (p[i] != '\0')
    {
        int a = (p[j] - 'A' + 1) * pow(26, n - 1);
        a = (26 * a) % 101;
        sum = (sum * 26 - a) + (p[i] - 'A' + 1);
        j++;

        if (sum == hashsum)
        {
            k = 0;

            while (t[k] == p[j + k] && p[j + k] != '\0')
            {
                k++;
            }
            if (k == n)
            {
                cout << j << endl;
            }
        }
        i++;
    }
}
int main()
{
    char txt[] = "AABAACAADAABAABA";
    char pat[] = "AABA";
    // Function Call
    search(pat, txt);
    return 0;
}