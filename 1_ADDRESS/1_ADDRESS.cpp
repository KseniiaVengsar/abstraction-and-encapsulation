#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <stdio.h>

class address
{
public:
    std::string get_output_address(std::string city_name, std::string street_name, int house_number, int apartment_number);
    address(std::string city_name, std::string street_name, int house_number, int apartment_number);
    address() { int N, C, D; std::string A, B; }

private:
    std::string city_name;
    std::string street_name;
    int house_number;
    int apartment_number;
};

address::address(std::string city_name_, std::string street_name_, int house_number_, int apartment_number_)
{
    city_name = city_name_;
    street_name = street_name_;
    house_number = house_number_;
    apartment_number = apartment_number_;
}
//Создайте в вашем классе метод, который собирает строку для вывода в файл.

std::string address::get_output_address(std::string city_name, std::string street_name, int house_number, int apartment_number)
{
    //Формат вывода адреса: <название города>, <название улицы>, <номер дома>, <номер квартиры>.
    return city_name + "," + " " + street_name + "," + " " + std::to_string(house_number) + "," + " " + std::to_string(apartment_number);

}

int main() {
    setlocale(LC_ALL, "RU");
    address info;

    std::ifstream fin("in.txt");

    if (fin.fail())
    {
        std::cout << "Error" << std::endl;
    }
    else if (fin.is_open())
    {
        std::cout << "info from in.txt:" << std::endl;
        int N, Hnumber, Anum, Hnumber_1, Anum_1, Hnumber_2, Anum_2;
        std::string city, street, city_1, street_1, city_2, street_2;
        fin >> N;
        fin >> city;
        fin >> street;
        fin >> Hnumber;
        fin >> Anum;

        fin >> city_1;
        fin >> street_1;
        fin >> Hnumber_1;
        fin >> Anum_1;

        fin >> city_2;
        fin >> street_2;
        fin >> Hnumber_2;
        fin >> Anum_2;
        std::cout << N << std::endl;
        //Для хранения всех адресов, экземпляров вашего класса, заведите динамический массив типа address* 
        std::ofstream fout("out.txt", std::ios::trunc);
        address* mas = new address[N];
        fout << N << std::endl;
        /////////////////////////////////////////////////////////////////////////////////////      
        int i=0;

        mas[i] = address(city_2, street_2, Hnumber_2, Anum_2);
        fout << info.get_output_address(city_2, street_2, Hnumber_2, Anum_2) << std::endl;
        std::cout << info.get_output_address(city_2, street_2, Hnumber_2, Anum_2) << std::endl;
        ////////////////////////////////////////////////////////////////////////////////////////
        mas[i] = address(city_1, street_1, Hnumber_1, Anum_1);
        fout << info.get_output_address(city_1, street_1, Hnumber_1, Anum_1) << std::endl;
        std::cout << info.get_output_address(city_1, street_1, Hnumber_1, Anum_1) << std::endl;

        /////////////////////////////////////////////////////////////////////////////////////////    
        mas[i] = address(city, street, Hnumber, Anum);
        fout << info.get_output_address(city, street, Hnumber, Anum) << std::endl;
        std::cout << info.get_output_address(city, street, Hnumber, Anum) << std::endl;

        delete[]mas;
    }

    fin.close();


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

