#include "Mi_Lib.h"
#include <iostream>
#include <string>     // Обязательно добавляем для работы со std::string
#include <sstream> // Для std::stringstream
#include <vector>  // Для std::vector
#include <algorithm> // Для std::sort


int one() {
    return 1; // Реализация пробной функции
}

void sort_Up_And_Print_Int_Numbers(const std::string& input) {
    std::stringstream ss(input);
    std::vector<int> numbers;
    int number;

    while (ss >> number) {           // Считываем числа из строкового потока одно за другим
        numbers.push_back(number);
    }

    std::sort(numbers.begin(), numbers.end());  // Сортируем вектор по возрастанию

    for (int num : numbers) {                 // Выводим отсортированные числа через пробелЫ
        std::cout << num << " ";
    }

    std::cout << std::endl; // Перевод строки в конце
}

void sort_Down_And_Print_Int_Numbers(const std::string& input) {
    std::stringstream ss(input);
    std::vector<int> numbers;
    int number;
   
    while (ss >> number) {             // Считываем числа из строки
        numbers.push_back(number);
    }

    // Сортируем вектор по УБЫВАНИЮ
    // Третий аргумент std::greater<int>() указывает компилятору сортировать от большего к меньшему
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    for (int num : numbers) {        // Выводим отсортированные числа через пробел
        std::cout << num << " ";
    }
    std::cout << std::endl; 
}

void sort_Up_And_Print_Words(const std::string& input) {
    std::stringstream ss(input);
    std::vector<std::string> words; // Вектор теперь хранит std::string, а не int
    std::string word;

    // Считываем слова из строкового потока одно за другим
    while (ss >> word) {
        words.push_back(word);
    }

    // Сортируем вектор слов по алфавиту (по возрастанию)
    std::sort(words.begin(), words.end());

    // Выводим отсортированные слова через пробел
    for (const std::string& w : words) {
        std::cout << w << " ";
    }
    std::cout << std::endl; 
}

void sort_Down_And_Print_Words(const std::string& input) {
    std::stringstream ss(input);
    std::vector<std::string> words; 
    std::string word;

    // Считываем слова из строки
    while (ss >> word) {
        words.push_back(word);
    }

    // Сортируем вектор слов по убыванию
    // Указываем std::greater для строк, чтобы сортировка шла от Я к А
    std::sort(words.begin(), words.end(), std::greater<std::string>());

    // Выводим отсортированные слова через пробел
    for (const std::string& w : words) {
        std::cout << w << " ";
    }
    std::cout << std::endl; 
}

void sort_Characters_And_Print(std::string input) {
    // Сортируем символы прямо внутри строки от начала (begin) до конца (end)
    std::sort(input.begin(), input.end());

    // Выводим получившуюся строку
    std::cout << input << std::endl;
}