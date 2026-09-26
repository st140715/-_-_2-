#include <iostream>
#include "Mi_Lib.h"


int main() {

    std::cout << one() << std::endl; // Пробный Вывод пробной функции

    sort_Up_And_Print_Int_Numbers("45 1 67 88 3 26 8 100");  // Вызыв функции, сортирующей числа в порядке возрастания.

    sort_Down_And_Print_Int_Numbers("45 1 67 88 3 26 8 100"); // В порядке убывания

    sort_Up_And_Print_Words("abracababra bums, tili mili tram"); // Сортируем строки в порядке возрастания.

    sort_Down_And_Print_Words("abracababra bums, tili mili tram"); // В порядке убывания

    sort_Characters_And_Print("abracababra bums, tili mili tram, 45 1 67 88 3 26 8 100"); // Сортируем символы

    return 0;
}