#ifndef LAB7FINAL_FUNCTIONS_H
#define LAB7FINAL_FUNCTIONS_H

const std::string ERROR_INVALID_NAME = "Error: invalid name!";
const std::string ERROR_INVALID_SURNAME = "Error: invalid surname!";
const std::string ERROR_INVALID_BIRTH_YEAR = "Error: invalid birth year!";

template<typename T2>
void splitWords(std::ifstream &fileIn, T2 &surname,T2 &name,T2 &birthYear){

    std::string str;
    size_t countSurname = 0;
    size_t countName = 0;
    size_t countBirthYear = 0;
    size_t flag = 1;

    getline(fileIn,str);
    for(size_t i = 0; 1; i++){
        if(str[i] != ' ' && flag == 1){
            countSurname++;
            if(str[i+1] == ' '){
                flag++;
            }
            continue;
        }

        if(str[i] != ' ' && flag == 2){
            countName++;
            if(str[i+1] == ' '){
                flag++;
            }
            continue;
        }

        if(str[i] != ' '  && flag == 3){
            countBirthYear++;
            if(str[i+1] == ' ' || str[i+ 1] == '\0'){
                flag++;
            }
            else{
                continue;
            }
        }

        if(str[i] == '\n' || str[i] == '\0') {
            flag = 1;
            break;
        }
    }

    char cleanName [50];
    char cleanSurname [50];
    char cleanBirthYear [50];
    cleanName[countName] = '\0';
    cleanSurname[countSurname] = '\0';
    cleanBirthYear[countBirthYear] = '\0';

    for(size_t i = 0, y = 0; 1; i++){
        if(str[i] == '\n') {
            break;
        }

        if(str[i] != ' ' && flag == 1){
            cleanSurname[y] = str[i];
            y++;
            if(str[i + 1] == ' '){
                flag++;
                y = 0;
            }
            continue;
        }

        if(str[i] != ' ' && flag == 2){
            cleanName[y] = str[i];
            y++;
            if(str[i + 1] == ' '){
                flag++;
                y = 0;
            }
            continue;
        }

        if(str[i] != ' ' && flag == 3){
            cleanBirthYear[y] = str[i];
            y++;
            if(str[i+1] == ' ' || str[i+ 1] == '\0'){
                flag++;
            }
            else{
                continue;
            }
        }

        if(flag == 4){
            break;
        }

    }
    name = cleanName;
    surname = cleanSurname;
    birthYear = cleanBirthYear;
}

template<typename T2>
void findErrors(const size_t num, T2 str){

    switch(num)
    {
        case 1:
            if(str.length() < 3 || str.length() > 20){
                throw ERROR_INVALID_SURNAME;
            }
            break;
        case 2:
            if(str.length() < 2 || str.length() > 10){
                throw ERROR_INVALID_NAME;
            }
            break;
        case 3:
            if(str.length() != 4){
                throw ERROR_INVALID_BIRTH_YEAR;
            }
            else if (str < "1920" || str > "2020") {
                throw ERROR_INVALID_BIRTH_YEAR;
            }
            break;
    }
}

template<typename T1>
void doSort(std::vector <T1> &array,const size_t num){
    size_t counter = 0;
    for(size_t i = 1;i < num;i++){
        for(size_t j = i; j > 0 && array[j-1] < array[j];j--){
            counter++;
            T1 tmp = array[j-1];
            array[j-1] = array[j];
            array[j] = tmp;
        }
    }
}

template<typename T2>
bool doComparison(const T2 str1, const T2 str2){
    size_t len1 = str1.length();
    size_t len2 = str2.length();
    size_t counter = 0;
    size_t num = 0;

    if(len1 < len2){
        num = len1;
    }
    else{
        num = len2;
    }
    for(size_t i = 0; i < num; i++){
        if(str1[i] == str2[i]){
            counter++;
        }
        if(str1[i] != str2[i]){
            break;
        }
    }


    if(len1 - counter == 3 && len2 - counter == 2 || len2 - counter == 3 && len1 - counter == 2){
        return true;
    }
    else if(len1 - counter == 0 && len2 - counter == 1 || len2 - counter == 0 && len1 - counter == 1){
        return true;
    }
    else if(len1 - counter == 0 && len2 - counter == 0){
        return true;
    }
    else{
        return false;
    }

}

template<typename T1>
size_t findDifNames(std::vector<T1>& array,const size_t num){
    std::vector<size_t> name(num);
    for(size_t i = 0;i < num ;i++){
        for(size_t y = i; y < num ; y++){
            if(doComparison(array[i].getName(),array[y].getName())){
                name[i]++;
            }
        }
    }

    size_t counter = 0;

    for(size_t i = 0; i < num; i++){
        if(name[i] == 1){
            counter++;
        }
    }

    return counter;
}

template<typename T1, typename T2>
T2 findYear(std::vector<T1>& array,const size_t num){
    std::vector <T2> year(num);
    size_t flag = 0;
    size_t o = 0;
    size_t border = 0;
    for(size_t i = 0;i < num; i++){
        for(size_t y = 0; y < border ;y++)
        {
            if(doComparison(year[y],array[i].getBirthYear())){
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            year[o] = array[i].getBirthYear();
            border++;
            o++;
        }
        flag = 0;
    }

    std::vector <size_t> counter(o);
    year.resize(o);

    for(size_t i = 0; i < num; i++){
        for(size_t y = i ; y < num ;y++){
            if(doComparison(array[i].getBirthYear(),array[y].getBirthYear()) &&
               doComparison(array[i].getName(),array[y].getName()) &&
               doComparison(array[i].getSurname(),array[y].getSurname())){
                for(size_t j = 0; j < o; j++){
                    if(doComparison(array[i].getBirthYear(), year[j])){
                        counter[j]++;
                    }
                }
            }
        }
    }
    size_t max = counter[0];
    size_t index = 0;
    for(size_t i = 0; i < o; i++){
        if(max < counter[i]){
            max = counter[i];
            index = i;
        }
    }

    if(max == 1){
        return "0";
    }
    else {
        return year[index];
    }
}

template<typename T1, typename T2>
void output(std::ofstream &fileOut, std::vector<T1>& array, const int num ,size_t difNames, T2 year){
    for(int i = num - 1; i >= 0;i--){
        fileOut << array[i].getSurname();
        fileOut << ' ';
        fileOut << array[i].getName();
        fileOut << ' ';
        fileOut << array[i].getBirthYear();
        fileOut << '\n';
    }

    if(difNames == 1) {
        fileOut << "\nAll names are the same\n";
    }
    else {
        fileOut << "\nThere are " << difNames << " different names in file.\n\n";
    }

    if(year == "0"){
        fileOut << "There is no such year\n";
    }
    else {
        fileOut << year << " is the year in which the most people with the same first and last names were born.\n";
    }
}

#endif //LAB7FINAL_FUNCTIONS_H
