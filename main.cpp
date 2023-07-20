#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Translator.h"
#include "MusicXMLReader.h" // открытие и чтение MusicXML

using namespace std;


int main() {
    //system("chcp 1251");
    setlocale(LC_ALL, "RU");
    MusicXMLReader xml("123.xml");
    //Translator music(xml);

    return 0;
}
