#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <stdio.h>

class address
{
public:
  

   void setINFO(std::string k, std::string j, int u, int x) {
        city_name = k;
        street_name = j;
        house_number = u;
        apartment_number = x;
    }

    std::string outAddress();

private:

    std::string city_name;
    std::string street_name;
    int house_number;
    int apartment_number;
};

std::string address::outAddress()
{
    return city_name + ", " + street_name + ", " + std::to_string(house_number) + ", " + std::to_string(apartment_number);
}

int main()
{
    setlocale(LC_ALL, "RU");
    
    std::string a, b;
    int c = 0; int d = 0;

    std::ifstream fin("in.txt");
   

    if (fin.fail())
    {
        std::cout << "Error" << std::endl;
    }
    else if (fin.is_open())
    {
        std::ofstream fout("out.txt", std::ios::trunc);
        std::cout << "info from in.txt:" << std::endl;
        int N;
        fin >> N;

        std::cout << N << std::endl;
        fout << N << std::endl;

        address* mas = new address[N];

        for (int i = 0; i < N; i++)
        {
            fin >> a;
            fin >> b;
            fin >> c;
            fin >> d;

            mas[i].setINFO(a, b, c, d);
        }

        for (int i = N - 1; i >= 0; i--)
        {
            fout << mas[i].outAddress() << std::endl;
            std::cout << mas[i].outAddress() << std::endl;
        }
        delete[]mas;
    }
    fin.close();
    return 0;
    
}
