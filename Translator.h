#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
//#include "MusicXMLReader.h"
using namespace std;

class Translator
{
	vector <int> converted_notes;
	vector <int> converted_notes_sequence;
	vector <int> converted_octaves;
	vector <int> converted_octaves_sequence;
	int type_instrument = 0;
public:
	//Translator( MusicXMLReader& reader);
	Translator(vector<char>& notes, vector<string>& octaves, vector<int>& semitone, vector<int>& duration, vector<int>& league, int fraction_numerator,int denominator_fraction,int bpm, int chromatic);
	int switch_hex_notes(char ch, int semitone);
	void notes_f( vector<char>& notes, vector<int>& semitone, int chromatic);
	void octaves_f( vector<int>& converted_notes, vector<string>& octaves);
	void convert_to_sequence(vector<int>& , vector<int>& , vector<int>&, int t);//вывод послед нот и октав
	void print_amount(int note, int duration, int league, vector <int>& notes_or_octaves);
	void show_information_about_composition(vector<int>& duration, int fraction_numerator, int denominator_fraction, int bpm);
	void show_notes(vector <int>&converted_notes);
	void show_octaves(vector <int>&converted_octaves);
};

