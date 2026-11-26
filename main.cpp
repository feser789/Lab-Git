#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double calc(double x,int n) {
    double y = 0;
    if (x < 0) {
        for (int i = 0; i <= n; i++) {
            double p = 1;
            for (int j = i; j <= n-1; j++) {
                p *= (i - j);
            }
            y += p;
        }
    }else {
        for (int i = 1; i <= n-2; i++) {
            y += (i - x) * (i - x);
        }
    }
    return y;
}

void checkValidInput(std::istream &in) {
    if (in.fail()) {
        throw "incorrect input";
    }
}
bool isValid(double a, double b,double h,int n) {
    return a <= b && n >= 0 && h> 0 ;
}

void checkValidParams(double a,double b,double h,int n) {
    if (!isValid(a,b,h,n)) {
        throw "input correct data";
    }
}

int countSteps(double a,double b,double h) {
    return (int)floor((b-a)/h + 1e-9);
}

bool readFromFile(const string &fileName,double &a,double &b,double &h,int &n) {
    ifstream fin(fileName);
    if (!fin) return false;

    fin >> a >> b >> h >> n;

    return !fin.fail();
}

int main() {
    double a,b,h;
    int n;
    int inputchoise;

    try {
        cout << "select input: (1 - console, 2 - file input)\n";
        cin >> inputchoise;

        if (inputchoise == 2) {
            if (!readFromFile("input.txt",a,b,h,n)) {
                throw "cannot read file";
            }
        }else {
            cout << "Input Start(a), End(b), Step size(h), n (separated by space): \n";
            cin >> a >> b >> h >> n;
            checkValidInput(cin);
        }
        checkValidParams(a,b,h,n);

        char choise;
        cout << "Save result to file?(y/n): \n";
        cin >> choise;

        ofstream fout;
        bool save = (choise == 'y' || choise == 'Y');
        if (save) {
            fout.open("file.txt");
            if (!fout) {
                cout << "Error: failed to open file!\n";
                save = false;
            }
        }

        int steps = countSteps(a,b,h);
        for (int k = 0; k <= steps; k++) {
            double x = a + k * h;
            double y = calc(x,n);
            cout <<"x = "<< x << " y = "<< y << '\n';
            if (save) fout << "x = "<< x << " y = "<< y << '\n';
        }

        if (save) {
            fout.close();
            cout << "Result saved to file.txt\n";
        }
    }catch (const char *ex) {
        cout << "Error: " << ex;
        return -1;
    }
    catch (...) {
        cout << "Error: unknown error\n";
        return -2;
    }
    return 0;
}