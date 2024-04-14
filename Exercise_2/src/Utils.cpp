#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;

void rateRet(string nameFileI)
{
    string nameFileO = "result.txt";
    ifstream ifs(nameFileI);
    ofstream ofs(nameFileO);

    if (ifs.fail() || ofs.fail()) {
            cout << "Impossibile aprire il file di input o di output." << endl;
            return;
    }

    string header;
    getline(ifs,header);
    double S = 0;
    size_t pos = header.find(';');
    istringstream converter(header);

    if (pos != string::npos && pos + 1 < header.size()) {
        string numberStr = header.substr(pos + 1); // Estrae la sottostringa dopo il ';'
        converter.str(numberStr);
        converter >> S;}

    converter.clear();

    string line;
        getline(ifs, line);
        converter.str(line);
        int n = 0;
        pos = line.find(';'); // Ricalcola pos per la seconda riga
        if (pos != string::npos && pos + 1 < line.size()) { // Estrae la sottostringa dopo il ";"
            string numberStr2 = line.substr(pos + 1);
            converter.str(numberStr2);
            converter >> n;}


    double *w = new double[n];  // creazione vettori con memoria gestita manualmente
    double *r = new double[n];

    getline(ifs, line);  // salta una linea

    int riga = 0;
       while (getline(ifs, line)) {
           stringstream stringa(line);
           string token;

           getline(stringa, token, ';');
           double num1 = stod(token);  // coversione da stringa a double

           getline(stringa, token, ';');
           double num2 = stod(token);

           w[riga] = num1;
           r[riga] = num2;
           riga += 1;
    }


    double sumR = 0;
    for (int i = 0; i < n;i++){
        sumR += r[i]*w[i];
    }

    double V = 0;
    for (int i = 0; i < n;i++){
        V += (1+r[i])*(w[i]*1000);
    }

    ofs << "S = " << fixed << setprecision(2) << S << ", " << "n = " << n << endl;
    cout << "S = " << fixed << setprecision(2) << S << ", " << "n = " << n << endl;
    ofs << "w = [ ";
    cout << "w = [ ";
    for (int i = 0;i < n; i++){
        ofs << w[i] << " ";
        cout << w[i] << " ";
    }
    ofs << "]" << endl;
    cout << "]" << endl;

    ofs << "r = [ ";
    cout << "r = [ ";
    for (int i = 0;i < n; i++){
        ofs << r[i] << " ";
        cout << r[i] << " ";
    }
    ofs << "]" << endl;
    cout << "]" << endl;

    ofs << "Rate of return of the portfolio: " << fixed << setprecision(4) << sumR << endl;
    cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << sumR << endl;

    ofs << "V: " << fixed << setprecision(2) <<V << endl;
    cout << "V: " << fixed << setprecision(2) <<V << endl;

    ifs.close();
    ofs.close();
    delete [] w;
    delete [] r;


}
