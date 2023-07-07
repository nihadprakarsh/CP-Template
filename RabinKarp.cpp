#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 9;
const int val = 31;
vector<int> rabinKarp(string &P, string &T)
{

    int sizeP = P.length(), sizeT = T.length();

    vector<long long> mfact(sizeT + 1);
    mfact[0] = 1;
    for (int i = 1; i < sizeT; i++)
        mfact[i] = (mfact[i - 1] * val) % mod;
    vector<long long> hashValue(sizeT + 1, 0);
    for (int i = 0; i < sizeT; i++)
        hashValue[i + 1] = (hashValue[i] + (T[i] - 'a' + 1) * mfact[i]) % mod;

    long long hashOfP = 0;
    for (int i = 0; i < sizeP; i++)
        hashOfP = (hashOfP + (P[i] - 'a' + 1) * mfact[i]) % mod;

    vector<int> indx;
    for (int i = 0; i <= sizeT - sizeP; i++)
    {

        long long currHash = (hashValue[i + sizeP] + mod - hashValue[i]) % mod;

        if (currHash == (hashOfP * mfact[i]) % mod)
            indx.push_back(i);
    }

    return indx;
}

int main()
{
    string P, T;
    cin >> P >> T;
    vector<int> indx = rabinKarp(P, T);
    if (indx.empty())
        cout << -1;
    else
    {
        for (int i = 0; i < indx.size(); i++)
            cout << indx[i] << " ";
    }
    return 0;
}
