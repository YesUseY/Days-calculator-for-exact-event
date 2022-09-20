#include <iostream>
#include <fstream>

using namespace std;

int konvertavimas (int m, int d) {
    cout << m << " " << d << endl;
    if (m==6) {
        return d;
    }
    else if (m==7) {
        return d + 30;
    }
    else {
       return d + 61;
    }
}

int main()
{
    ifstream fin("data.txt");
    ofstream fout("data1.txt");
    int a;
    fin >> a;
    int did = 0;
    int ipm, ipd;
    int ibm, ibd;
    int didpr;
    int didpb;
    int VasarosDienos[93] = {};
    int prd, pbd;
    int zpm, zpd, zpam, zpad;
    for (int i=0; i<a; i++) {
        fin >> zpm >> zpd >> zpam >> zpad;
        prd = konvertavimas (zpm, zpd);
        pbd = konvertavimas (zpam, zpad);
        for (int j=prd; j<=pbd; j++) {
            VasarosDienos[j]++;
        }
    }
    for (int i=0; i<93; i++) {
        if (VasarosDienos[i]>did) {
            did = VasarosDienos[i];
            didpr = i;
        }
    }
    for (int i=didpr; i<93; i++) {
        if (VasarosDienos[i]<did) {
            didpb = i-1;
            break;
        }
    }
    if (didpr<31) {
           ipm = 6;
           ipd = didpr;
    }
    else if (didpr<62) {
        ipm = 7;
        ipd = didpr - 30;
    }
    else {
        ipm = 8;
        ipd = didpr - 61;
    }
    if (didpb<31) {
        ibm = 6;
        ibd = didpb;
    }
    else if (didpb<62) {
        ibm = 7;
        ibd = didpb - 30;
    }
    else {
        ibm = 8;
        ibd = didpb - 61;
    }
    fout << did << endl;
    fout << ipm << " " << ipd << endl;
    fout << ibm << " " << ibd << endl;


    return 0;
}
