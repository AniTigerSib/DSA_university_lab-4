#include "generate_text.h"

void generateRandomText(char* data, int size) {
    srand(time(NULL)); // Инициализация генератора случайных чисел
    
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 26 + 97; // Генерация случайного символа от 'a' до 'z'
    }
}