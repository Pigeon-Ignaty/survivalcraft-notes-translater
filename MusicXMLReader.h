#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Z:\VS\MidiApp\MidiAPP\tiny\tinyxml2.h"

using namespace std;
using namespace tinyxml2;

class MusicXMLReader
{
    vector <string> musical_parts; // id всех музыкальных партий в произведении
    XMLDocument doc; // файл musicxml 


    vector<char> v_notes; // вектор с нотами      | r - rest пауза|
    vector<string> v_octaves;//вектор с октавами    | n - null при rest в notes|
    vector<int> v_semitone; // вектор с полутонами
    vector<string> v_voices;// вектор с голосами
    vector<int> v_league; // вектор с координатами лиг
    vector<int> v_duration; // вектор с координатами лиг
    vector<int> part_list; // номер дорожки
    int fifths = 0; // знаки при ключе
    int beats = 0; // количество долей в числителе тактового размера
    int beat_type = 0; //количество долей в знаменателе тактового размера
    string sign; // символ ключа
    int line = 0; //Используется для ключей.2 для знака G (скрипичный ключ), 4 для знака F (басовый ключ) и 3 для знака C (альтовый ключ).
    int bpm = 0; // beat per minute
    string bpm_unit; //обозначение bmp для величины
    int count_meaure = 1; //счётчик тактов с 1
    int duration = 0; //счётчик тактов с 1
    int voice = 0; //голоса
    int step = 0;
    int octave = 0;
    int alter = 0; //показывает полутон на ноте, если он есть на ключе
    int chromatic = 0;
    string accidental; // знак на ноте: sharp - диез, natural - бекар,flat - бемоль  
    string rest; // пауза
    string tied; //лига start, stop
    int accidental_code(string s);

    friend class Translator;
public:
    MusicXMLReader(const char*); //конструктор открывающий musicxml и считывающий партии
    void MusicPartReader(const char*); //метод, который выводит всю информацию из патрии в массивы
};
