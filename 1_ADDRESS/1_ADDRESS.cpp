#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <stdio.h>

class address
{
public:
    address(std::string city_name, std::string street_name, int house_number, int apartment_number);
    address();
    void mainFunc();
    void get_output_address(std::string city_name_, std::string street_name_, int house_number_, int apartment_number_);

private:
    std::string city_name;
    std::string street_name;
    int house_number;
    int apartment_number;
};

address::address() { }

address::address(std::string city_name_, std::string street_name_, int house_number_, int apartment_number_)
{
    city_name = city_name_;
    street_name = street_name_;
    house_number = house_number_;
    apartment_number = apartment_number_;

    get_output_address(city_name, street_name, house_number, apartment_number);
}

void address::mainFunc()
{
    std::string city_name_;
    std::string street_name_;
    int house_number_;
    int apartment_number_;

    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt", std::ios::trunc);
    std::cout << "info from in.txt:" << std::endl;

    int N;
    fin >> N;
    fout << N << std::endl;
    std::cout << N << std::endl;

    address* mas = new address[N];

    for (int i = 0; i < N; i++)
    {
        fin >> mas[i].city_name;
        fin >> mas[i].street_name;
        fin >> mas[i].house_number;
        fin >> mas[i].apartment_number;
        
    }

    for (int i = N-1; i >= 0; i--)
    {
        fout << mas[i].city_name + "," + " ";
        fout << mas[i].street_name + "," + " ";
        fout << std::to_string(mas[i].house_number) + "," + " ";
        fout << std::to_string(mas[i].apartment_number) << std::endl;

        city_name_ = mas[i].city_name;
        street_name_ = mas[i].street_name;
        house_number_ = mas[i].house_number;
        apartment_number_ = mas[i].apartment_number;

        address(city_name_, street_name_, house_number_, apartment_number_);
    }
}

void address::get_output_address(std::string city_name_, std::string street_name_, int house_number_, int apartment_number_)
{ 
    std::cout << city_name_ + "," + " " + street_name_ + "," + " " + std::to_string(house_number_) + "," + " " + std::to_string(apartment_number_) << std::endl;
}

int main()
{
    setlocale(LC_ALL, "RU");
    address info;

    std::ifstream fin("in.txt");

    if (fin.fail())
    {
        std::cout << "Error" << std::endl;
    }
    else if (fin.is_open())
    {
        info.mainFunc();
    }

    return 0;
}
