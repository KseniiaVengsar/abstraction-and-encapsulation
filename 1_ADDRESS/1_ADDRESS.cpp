// ADDRESS_KV_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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


   /* void set_city_name(std::string k) {
        city_name = k;
    }
    void set_street_name(std::string j) {
        street_name = j;
    }
    void set_house_number(int u) {
        house_number = u;
    }
    void set_apart_number(int x) {
        apartment_number = x;
    }*/

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
    address info;
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
            mas[i].setINFO(a, b, c, d);
            mas[i].setINFO(a, b, c, d);
            mas[i].setINFO(a, b, c, d);

            //fout << mas[i].outAddress() << std::endl;
            //std::cout << mas[i].outAddress() << std::endl;
        }



      for (int i = N - 1; i >= 0; i--)
        {
          mas[i].setINFO(a, b, c, d);
          mas[i].setINFO(a, b, c, d);
          mas[i].setINFO(a, b, c, d);
          mas[i].setINFO(a, b, c, d);

             fout << mas[i].outAddress() << std::endl;
             std::cout << mas[i].outAddress() << std::endl;
        }

        
    }
    return 0;
    
}






/*For getter it is simply to do. You declare parameter that will specify element's index of array.

For example

int get_element( size_t index ) { return ( a[index] ); }

For setter you can specify two parameters: element's index and a new value

void set_element( size_t index, int value ) { a[index] = value; }

Also you can overload operator [] if your array is a part of a class definition.
void setINFO(int i, std::string k, std::string j, int u, int x) {

            mas[i] = k;
            mas[i] = j;
            mas[i] = u;
            mas[i] = x;
        }*/
