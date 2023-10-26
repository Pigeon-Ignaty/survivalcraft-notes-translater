#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <numeric>
#include <set>
#include <locale>
#include <codecvt>
#include <map>

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
    vector<float> v_duration; // вектор с длительностями
    vector<string> v_instruments;// вектор с ударными инструментами

    vector<int> part_list; // номер дорожки, используется для выбора
    int divisions = 1; //переменная для правильного расчёта всех длительностей в партии
    //если она отсутствует, то по умолчанию равна 1

    map<string, int> PercussionSurvivalcraftMap{ // содержит название и тип инструмента в Survivalcraft
        {"Acoustic Bass Drum",1},
        {"Bass Drum 1",1},
        {"Side Stick",9}, //подходит 2,3
        {"Acoustic Snare",0},
        {"Electric Snare",0},
        {"Low Floor Tom",5},
        {"Closed Hi-Hat",2},
        {"High Floor Tom",5},
        {"Pedal Hi-Hat",3},
        {"Low Tom",5},
        {"Open Hi-Hat",8}, //вроде бы 4, но больше подходит 8
        {"Low-Mid Tom",6},
        {"Hi-Mid Tom",6},
        {"Crash Cymbal 1",7},
        {"High Tom",6},
        {"Ride Cymbal 1",8},
        {"Chinese Cymbal",7},
        {"Ride Bell",8},
        {"Tambourine",3},
        {"Splash Cymbal",4}, //подходит 4 и 7
        {"Cowbell",3},
        {"Crash Cymbal 2",7},
        {"Ride Cymbal 2",8},
        {"Open Hi Conga",6},
        {"Low Conga",5},
        {"Cabasa",3},
        {"Castanets",2},
        {"Hand Clap",9},
        {"F",15}
    };
    map<string, string> PercussionPartInstruments; //запись id инструмента и его названия из партии

    //массивы с конвертированными данными
    vector <int> converted_notes;
    vector <int> converted_notes_sequence;
    vector <int> converted_octaves;
    vector <int> converted_octaves_sequence;
    void type_instrument(int instrument); //фун-ция для определения верхней и нижней границы октав


    //буферные переменные для записи в массивы
    int fifths = 0; // знаки при ключе
    int beats = 0; // количество долей в числителе тактового размера
    int beat_type = 0; //количество долей в знаменателе тактового размера
    int line = 0; //Используется для ключей.2 для знака G (скрипичный ключ), 4 для знака F (басовый ключ) и 3 для знака C (альтовый ключ).
    int bpm = 0; // beat per minute
    int count_measure = 1; //счётчик тактов с 1
    int duration = 0; //счётчик тактов с 1
    //int voice = 0; //голоса
    int step = 0; // шаг для pitch
    int octave = 0; // октава
    int alter = 0; //показывает полутон на ноте, если он есть на ключе
    int chromatic = 0; // количество тонов для перехода от написанного к звучащему тону
    string sign; // символ ключа
    string bpm_unit; //обозначение bmp для величины
    string accidental; // знак на ноте: sharp - диез, natural - бекар,flat - бемоль  
    string rest; // пауза
    string tied; //лига start, stop
    int accidental_code(string s);
    int minimal_duration; //минимальная длительность во всём произведении

    int high_octave; //верхняя  октава
    int low_octave; //нижняя октава

    //методы, внутри Translation()
    void notes_f(vector<char>& notes, vector<int>& semitone, int chromatic);
    void octaves_f(vector<int>& converted_notes, vector<string>& octaves, int instrument);
    void convert_to_sequence(vector<int>&, vector<float>&, vector<int>&, int t);//вывод послед нот и октав
    void convert_to_sequence_percussion(vector <string>&, vector<float>&);
    void show_information_about_composition(vector<float>& duration, int fraction_numerator, int denominator_fraction, int bpm);
    void show_notes(vector <int>& converted_notes);
    void show_octaves(vector <int>& converted_octaves);
    int switch_hex_notes(char ch, int semitone);
    void print_amount(int note, int duration, int league, vector <int>& notes_or_octaves); //формирование последовательности нот или октав с учётом длительности и лиг
    void calculation_duration(int min_duration_note);
    void FindMinimalDuration(const char* );
    void WriteScoreInstrument(); //метод записывающий название ударных инструментов
public:
    MusicXMLReader(const char*); //конструктор открывающий musicxml и считывающий партии
    void ReadVoice(const char*); //метод, считывающий количество голосов в партии для последующего выбора
    void MusicPartWriter(const char*, const char*); //метод, который записывает всю информацию из патрии и голоса в массивы
    void OutputToConsole(); //вывод массивов в консоль
    int Translation(int instrument); // функция, которая вызывает другие функции для перевода
};
