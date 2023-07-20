#include "Translator.h"
//Translator::Translator( MusicXMLReader& reader) {
//	type_instrument = 2;
//	notes_f(reader.v_notes, reader.v_semitone, reader.chromatic);
//	octaves_f(converted_notes, reader.v_octaves);
//}
Translator::Translator(vector<char>& notes, vector<string>& octaves, vector<int>& semitone, vector<int>& duration, vector<int>& league, int fraction_numerator, int denominator_fraction, int bpm, int chromatic) {
	type_instrument = 2;
	notes_f(notes, semitone, chromatic);
	octaves_f(converted_notes,octaves);
	convert_to_sequence(converted_notes, duration, league,0);//ноты
	convert_to_sequence(converted_octaves, duration, league,1);//октавы
	show_information_about_composition(duration, fraction_numerator, denominator_fraction, bpm);
	show_notes(converted_notes_sequence);
	show_octaves(converted_octaves_sequence);

}
void Translator::notes_f( vector<char>& notes, vector<int>& semitone, int chromatic) {
	if (notes.size() != semitone.size()) {
		cout << "Error: vectors have different sizes" << endl;
	}
	cout << "Ноты в notes_f:" << endl;
	for (int i = 0; i < semitone.size(); i++) {
		semitone[i] = semitone[i] + chromatic;
		if (switch_hex_notes(notes[i], semitone[i]) < 0) { //??
			converted_notes.push_back(12 + switch_hex_notes(notes[i], semitone[i]));
		}
		else {
			converted_notes.push_back(switch_hex_notes(notes[i], semitone[i]));

		}
		cout << hex << uppercase << switch_hex_notes(notes[i], semitone[i]);
	}
	cout << endl;
}
void Translator::octaves_f( vector<int>& converted_notes, vector<string>& octaves) {
	//cout << "Октавы в octaves_f:" << endl;

	for (int i = 0; i < octaves.size(); i++) {
		int number = 0;
		if (octaves[i] == "n") {
			converted_octaves.push_back(15);
			//cout << hex << uppercase << 15;
		}
		else {
			try {
				number = stoi(octaves[i])-2;
				if (number > 3 && converted_notes[i] == 0) {
					number = 4;
				}
				else{
					number = stoi(octaves[i]) - 2;
					if (number < 0) {
						number = 0;
					}
					else if (number > 3) {
						number = 3;
					}
				}
				converted_octaves.push_back(number);

				//cout << hex << uppercase << number;
			}
			catch(const exception& ex) {
				cout << ex.what() << endl;
			}
		} 

		
	}
}

void Translator::convert_to_sequence(vector<int>& converted, vector<int>& duration, vector<int>& league, int t) {
	/*int min_duration = *min_element(duration.begin(), duration.end());
	int max_duration = *max_element(duration.begin(), duration.end());
	cout << dec << "max" << max_duration << endl;
	cout << dec << "min" << min_duration << endl;*/

	/*for (int i = 0; i < duration.size(); i++) {
		duration[i] = duration[i] / min_duration;
	}*/
	/*cout << endl <<"Длительности" << endl;
	for (int i = 0; i < duration.size(); i++) {
		cout << dec << duration[i] << " ";
	}*/
	/*cout << min_duration << "\t" << max_duration << endl;*/
	if (converted.size() != duration.size()) {
		cout << "Error: vectors have different sizes" << endl;
	}
	//cout << endl << "Последовательности" << endl;
	try {
		if (!t) {
			for (int i = 0; i < duration.size(); i++) {
				//if (i == 0) cout << converted_notes[i];
				//cout << "F";
				(print_amount(converted[i], duration[i], league[i], converted_notes_sequence));
				//cout << i;
			}
		}
		else{
			for (int i = 0; i < duration.size(); i++) {
				//if (i == 0) cout << converted_notes[i];
				//cout << "F";
				(print_amount(converted[i], duration[i], league[i], converted_octaves_sequence));
				//cout << i;
			}
		}
		
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
}
void Translator::print_amount(int object, int duration, int league, vector <int>& converted_notes_sequence) {
	for (int i = 0; i < duration; i++) {
		if (league) {
			if (league == 2) converted_notes_sequence.push_back(object);//cout <<hex<< object;
			else if (league == 1 || league == 3)  converted_notes_sequence.push_back(15);//cout << hex << "F";
			league = 0;
		}
		else {
			if (i == 0) converted_notes_sequence.push_back(object);//cout << hex << object;
			else converted_notes_sequence.push_back(15);//cout << hex << "F";
		}
		
	}
		

}
int Translator::switch_hex_notes( char ch, int semitone) {
	switch (ch){
	case 'C': return 0 + semitone; //до
	case 'D': return 2 + semitone; //ре
	case 'E': return 4 + semitone; //ми
	case 'F': return 5 + semitone; //фа
	case 'G': return 7 + semitone; //соль
	case 'A': return 9 + semitone; //ля
	case 'B': return 11 + semitone;//си
	default: return 15;
	}
}
void Translator::show_notes(vector <int>& converted_notes_sequence) {
	cout << "Ноты" << endl;
	int count = 0;
	for (int& i : converted_notes_sequence) {
		if (count == 256) {
			cout << endl;
			count = 0;
		}
		cout << hex << uppercase << i;
		count++;
	} 
	while (count != 256) {
		cout << "F";
		count++;
	}
	cout << endl;
}
void Translator::show_octaves(vector <int>& converted_octaves_sequence) {
	cout << "Октавы" << endl;
	int count = 0;
	for (int& i : converted_octaves_sequence) {
		if (count == 256) {
			cout << endl;
			count = 0;
		}
		cout << hex << uppercase << i;
		count++;
	}
	while (count != 256) {
		cout << "F";
		count++;
	}
	cout << endl;
}

void Translator::show_information_about_composition(vector<int>& duration, int fraction_numerator, int denominator_fraction, int bpm) {
	float min_duration = *min_element(duration.begin(), duration.end());
	float max_duration = *max_element(duration.begin(), duration.end());
	float relationship_bpm;
	float quarter_time;
	float time_min_duration;
	try {
		relationship_bpm = float(60) / float(bpm); //отношение
		quarter_time = relationship_bpm * float(fraction_numerator); //длительность такта
		time_min_duration = quarter_time / max_duration;
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
	cout << "Длина минимальной длительности/время для генератора " << round(time_min_duration*100)/ 100 << endl;
	cout << "Минимальная длительность " << max_duration << endl;

}
