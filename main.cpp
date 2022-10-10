#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "String.h"
#include "Person.h"
#include "functions.h"

const std::string OUT_FILE_NAME = "result.txt";
const std::string ERROR_FILE_NOT_OPEN = "Error: incorrect file name";
const std::string ERROR_NOT_INTEGER_NUMBER = "Error: invalid integer number!";

const std::string inputFileName() {
    std::string fileName;
    std::cout << "Enter a name of input file: " << std::endl;
    std::cin >> fileName;
    return fileName;
}

std::basic_ifstream<char> openFile(const std::string &fileName, size_t &num) {
    std::ifstream fileIn(fileName, std::istream::in);

    if (!fileIn.is_open()) {
        throw ERROR_FILE_NOT_OPEN + fileName;
    }

    std::string tmp;
    size_t flag=0;
    getline(fileIn,tmp);

    for (size_t i = 0; i < 100; ++i) {
        if (tmp == std::to_string(i)) {
            flag = 1;
            break;
        }
    }

    num = std::stoi(tmp);

    if (!flag) {
        throw ERROR_NOT_INTEGER_NUMBER + fileName;
    }

    return fileIn;
}

std::basic_ofstream<char> closeFile(const std::string &fileName) {
    std::ofstream fileOut(fileName, std::ifstream::out);

    if (!fileOut.is_open()) {
        throw ERROR_FILE_NOT_OPEN + fileName;
    }
    return fileOut;
}

template<typename T1, typename T2>
void input(std::ifstream &fileIn, std::vector<T1>& array, const size_t num){

    T2 name;
    T2 surname;
    T2 birthYear;

    for (size_t i = 0; i < num; i++) {
        splitWords<T2>(fileIn,surname,name,birthYear);
        findErrors<T2>(1,surname);
        findErrors<T2>(2,name);
        findErrors<T2>(3,birthYear);
        array[i].setSurname(surname);
        array[i].setName(name);
        array[i].setBirthYear(birthYear);
    }
}

template<typename T1, typename T2>
void taskString(){
    size_t num = 0;
    std::basic_ifstream<char> fileIn = openFile(inputFileName(), num);
    std::basic_ofstream<char> fileOut = closeFile(OUT_FILE_NAME);
    std::vector<T1> data(num);

    input<T1, T2>(fileIn, data, num);
    doSort<T1>(data, num);
    output(fileOut, data, num , findDifNames<T1>(data, num),findYear<T1,T2>(data, num));
}

int main() {
    char flag = 0;
    size_t choise = 0;

    try {
        std::cout << "Select the library you want to use:\n";
        std::cout << "1 - std::string\n";
        std::cout << "2 - String\n";
        std::cin >> choise;

        switch(choise){
            case 1:
                taskString<Person,std::string>();
                break;

            case 2:
                taskString<StringPerson,String>();
                break;
            default:
                std::cerr << "Such a command does not exist!\n";
                break;
        }
    }
    catch (std::string error)
    {
        std::cerr << error << std::endl;
        flag = -1;
    }

    return flag;
}