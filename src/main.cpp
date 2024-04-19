#include <chrono>
#include <iostream>

#include "generate_text.h"
#include "search.h"

#define TEST_CASES_NUM 20
#define SIZE_OF_PATTERN 100
#define SIZE_OF_TEXT 10000000
#define SITUATIONS_OF_SEARCH_AMOUNT 4

float  TimeTest(char *txt, char *search);

int g_func_num_to_test = 0;
// 0 - KMP
// 1 - std::strstr

int g_size_of_txt = 0;

void SizeTests();
void TextSizeTests();

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Not correct amount of command line params\n";
    } else {
        g_func_num_to_test = std::atoi(argv[1]);
        g_size_of_txt = std::atoi(argv[2]);

        // SizeTests();
        TextSizeTests();
    }
    return 0;
}

void SizeTests() {
    int step = g_size_of_txt;
    for (int i = 0; i < TEST_CASES_NUM; i++) {
        char *txt = new char[g_size_of_txt];
        generateRandomText(txt, g_size_of_txt);
        std::cout << g_size_of_txt << '\t';
        for (int j = 0; j < SITUATIONS_OF_SEARCH_AMOUNT; j++) {
            char *search = (char*)calloc(g_size_of_txt, sizeof(char));
            switch (j) {
            case 0:
                // generateRandomText(search, SIZE_OF_PATTERN);
                strncpy(search, txt + g_size_of_txt - SIZE_OF_PATTERN, SIZE_OF_PATTERN);
                for (int k = 0; k < SIZE_OF_PATTERN; k++) {
                    search[k]++;
                }
                break;
            case 1:
                strncpy(search, txt, SIZE_OF_PATTERN);
                break;
            case 2:
                strncpy(search, txt + g_size_of_txt / 2, SIZE_OF_PATTERN);
                break;
            case 3:
                strncpy(search, txt + g_size_of_txt - SIZE_OF_PATTERN, SIZE_OF_PATTERN);
                break;
            default:
                break;
            }
            std::cout << TimeTest(txt, search) << "\t";
            std::cout.flush();
            free(search);
        }
        std::cout << "\n";
        delete[] txt;
        g_size_of_txt += step;
    }
}

void TextSizeTests() {
    int step = g_size_of_txt;
    for (int i = 0; i < TEST_CASES_NUM; i++) {
        char *txt = new char[SIZE_OF_TEXT];
        generateRandomText(txt, SIZE_OF_TEXT);
        std::cout << g_size_of_txt << '\t';
        for (int j = 0; j < SITUATIONS_OF_SEARCH_AMOUNT; j++) {
            char *search = (char*)calloc(g_size_of_txt + 1, sizeof(char));
            strncpy(search, txt + SIZE_OF_TEXT - g_size_of_txt, g_size_of_txt);
            switch (j) {
            case 0:
                // generateRandomText(search, SIZE_OF_PATTERN);
                for (int k = 0; k < g_size_of_txt; k++) {
                    search[k]++;
                }
                break;
            case 1:
                strncpy(search, txt, g_size_of_txt);
                break;
            case 2:
                strncpy(search, txt + SIZE_OF_TEXT / 2, g_size_of_txt);
                break;
            case 3:
                break;
            default:
                break;
            }
            std::cout << TimeTest(txt, search) << "\t";
            free(search);
        }
        std::cout << "\n";
        std::cout.flush();
        delete[] txt;
        g_size_of_txt += step;
    }
}

float TimeTest(char *txt, char *search) {
    auto start = std::chrono::steady_clock::now( );
    if (g_func_num_to_test == 0) {
        // char* to_return = nullptr;
        KMP(txt, search);
        // if (to_return == nullptr) printf("%p\n", to_return);
    } else {
        char* to_return = nullptr;
        to_return = std::strstr(txt, search);
        if (to_return == (char*)0xFFFFF) printf("%p\t", to_return);
    }
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::steady_clock::now( ) - start );
    return elapsed.count() / 1e3;
}