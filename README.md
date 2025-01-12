# The `main` branch 
This branch was used at the start of the project and contains the initial version of the project. Currently, the branch is not being used for active development, and all new changes and developments are taking place in another branch.
For the current version of the project, please follow the link to the [GUI branch](https://github.com/Pigeon-Ignaty/survivalcraft-notes-translator).

# EN Survivalcraft Notes Translator
This program translates notes from the .musicxml format into a hexadecimal string with notes and octaves for the sound generator in Survivalcraft.
___
## Table of Contents
- [How Survivalcraft Notes Translator Works](#how-survivalcraft-notes-translator-works)
- [What's Implemented](#whats-implemented)
- [What's Not Implemented](#whats-not-implemented)
- [Changelog](#changelog)
- [Example](#example)
- [Project Team](#project-team)
___
# How Survivalcraft Notes Translator Works <a name="how-survivalcraft-notes-translator-works"></a>

**Survivalcraft Notes Translator** is a program that reads musicxml files, extracts the found parts and voices, and translates notes and octaves from the selected voice into the format of the sound generator in Survivalcraft.
___

# What's Implemented <a name="whats-implemented"></a>
- Opening and reading .musicxml files
- Output of part names and selection
- Output of all voices in a part and their selection
- Translation of basic single notes
- Automatic calculation of output notation for notes and octaves.
- Selection of the instrument and automatic transposition of notes to the required octave depending on the instrument's range. (For the bell, the first octave is trimmed as it sounds dissonant)
- Ligature detection and note duration extension
- Handling of all common time signatures
- Automatic line splitting at 256 characters with padding with 'F' characters if the line is less than 256 characters in length
- Translation of percussion instruments
- ___
# What's Not Implemented <a name="whats-not-implemented"></a>
- Opening and reading .xml and .midi files
- Splitting chords into separate parts and translating them
- Translation of duoles, trioles, quartoles, quintoles, etc.
- Translation of sound volume fluctuations
___
# Example <a name="example"></a>

For example:
```
Scatman_ski_ba_bop_dop_bop2.musicxml
```
The console will output the following parts:
```
Output of the following parts in the musical composition:
ID: P1  Part Name: Piano
ID: P2  Part Name: Piano
ID: P3  Part Name: Piano
ID: P4  Part Name: Piano
ID: P5  Part Name: Piano
ID: P6  Part Name: Sawtooth Synthesizer
ID: P7  Part Name: 5-string Electric Bass Guitar
ID: P8  Part Name: Drum Kit
ID: P9  Part Name: Clap
```
The user selects a part. Let it be P1.
Next, all voices from part P1 will be displayed:
```
Voices detected in the part
1
```
Then the user will be prompted to select the type of instrument.
  * *1 Bell*
  * *2 Organ*
  * *3 Whistle*
  * *4 String Instrument*
  * *5 Trumpet*
  * *6 Vocal Doo*
  * *7 Piano*
  * *8 Piano with Pedal*
<br>Next, the program will translate the selected piece and display 2 lines. If the line is longer than 256 characters, it will split them into 256-character parts. If there is a piece left that is smaller, it will pad it with 'F' characters.
```
Notes
FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F
3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F
3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F
5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F
5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F
3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F
3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3FFF
FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
Octaves
FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F
0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F
0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F
0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F
0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F
0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F
0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0FFF
FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
```

___
# Updates List <a name="changelog"></a>
In this section, all major changes, additions, and deletions in the code are recorded.
* 28th September 2023
    * Proper voice processing. Now, if a voice is missing in a measure, it will be automatically filled with a pause.
    * Correct calculation of the duration of a whole bar for basic time signatures.
    * For the Translation() method, it is now necessary to manually specify the minimum duration in duration units for the entire composition. Otherwise, the method will automatically reduce the duration using the minimum duration in the selected part. This will prevent incorrect encoding of output notes and octaves. In the future, a separate function will be developed to automatically determine the minimum duration.
* 4th October 2023
    * Added FindMinimalDuration() function, which reads and finds the minimum duration in the entire composition (except for percussion instruments, as it turned out). The obtained value is used by the Translation() method to correctly calculate the remaining durations.
* 26th October 2023
  	* Added support for percussion instruments. When a percussion sign is detected, notes in the selected part will be converted to the Survivalcraft percussion instrument format (numbers 0 to 9). Instead of note values, the percussion instrument number will be displayed, taking into account the duration. The octave line will be absent as it is not used. Support for 28 instruments has been added, and for some of them, a similar instrument had to be selected by ear. Here are the names of the percussion instruments and their ordinal numbers in the Survivalcraft sound generator or equivalent:
```
	{"Acoustic Bass Drum",1},
        {"Bass Drum 1",1},
        {"Side Stick",9}, //suitable 2,3
        {"Acoustic Snare",0},
        {"Electric Snare",0},
        {"Low Floor Tom",5},
        {"Closed Hi-Hat",2},
        {"High Floor Tom",5},
        {"Pedal Hi-Hat",3},
        {"Low Tom",5},
        {"Open Hi-Hat",8}, //it seems to be 4, but 8 is more suitable
        {"Low-Mid Tom",6},
        {"Hi-Mid Tom",6},
        {"Crash Cymbal 1",7},
        {"High Tom",6},
        {"Ride Cymbal 1",8},
        {"Chinese Cymbal",7},
        {"Ride Bell",8},
        {"Tambourine",3},
        {"Splash Cymbal",4}, //suitable 4 and 7
        {"Cowbell",3},
        {"Crash Cymbal 2",7},
        {"Ride Cymbal 2",8},
        {"Open Hi Conga",6},
        {"Low Conga",5},
        {"Cabasa",3},
        {"Castanets",2},
        {"Hand Clap",9},
```
___
# Ветка `main`
Эта ветка была использована для начальной версии проекта при его старте. На данный момент она не используется для активной разработки. Все новые изменения и разработки происходят в другой ветке.
Для получения актуальной версии проекта, пожалуйста, переходите по ссылке на ветку [GUI](https://github.com/Pigeon-Ignaty/survivalcraft-notes-translator).
# RU Survivalcraft Notes Translator
Эта программа переводит ноты из формата .musicxml в hex строку с нотами и октавами для генератора звука в Survivalcraft.
___
## Содержание
- [Как работает Survivalcraft Notes Translator](#Survivalcraft-Notes-Translator)
- [Что реализовано](#realized)
- [Что не реализовано](#unrealized)
- [Список обновлений](#updates)
- [Пример](#Пример)
- [Команда проекта](#команда-проекта)
___
# Как работает Survivalcraft Notes Translator <a name="Survivalcraft-Notes-Translator"></a>

**Survivalcraft Notes Translator** - программа, которая читает musicxml файл, выводит найденные партии и голоса, и из выбранного голоса переводит ноты и октавы в формат звукового генератора в Survivalcraft. 
___

# Что реализовано <a name="realized"></a>
- Открытие и чтение файлов .musicxml
- Вывод названий партий и их выбор
- Вывод всех голосов в партии и их выбор
- Перевод простейших одиночных нот
- Автоматический расчёт выходной записи для нот и октав.
- Выбор инструмента и автоматическое транспонирование нот на нужную октаву в зависимости от диапазона инструмента. (Для колокольчика обрезана первая октава, так как она звучит в диссонанс)
- Определение лиги и удлинение длительности ноты
- Работа со всеми основными размерами тактов
- Автоматическое разбиение на строки по 256 символов с заполнением символами 'F' в случае, если строка не достигает 256 символов в длину
- Перевод ударных инструментов
- ___
# Что не реализовано <a name="unrealized"></a>
- Открытие и чтение файлов .xml и .midi файлов
- Разбитие аккордов на отдельные партии и их перевод
- Перевод дуолей, триолей, квартолей, квинтолей и т. д.
- Перевод колебаний громкости звука
___
# Пример <a name="Пример"></a>

К примеру такой:
```
Scatman_ski_ba_bop_dop_bop2.musicxml
```
Консоль выведет следующие партии:
```
Вывод следующих партий в му	зыкальной композиции:
ID: P1  Название партии: Фортепиано
ID: P2  Название партии: Фортепиано
ID: P3  Название партии: Фортепиано
ID: P4  Название партии: Фортепиано
ID: P5  Название партии: Фортепиано
ID: P6  Название партии: Синтезатор пилообразной волны
ID: P7  Название партии: 5-стр. Электрическая бас-гитара
ID: P8  Название партии: Набор ударных
ID: P9  Название партии: Хлопок в ладоши
```
Пользователь выбирает партию. Пусть P1
Далее произойдёт вывод всех голосов из партии P1:
```
Голоса, обнаруженные в партии
1
```
Затем пользователю будет предложено выбрать тип инструмента. 
  * *1 Колокольчик*
  * *2 Орган*
  * *3 Свисток*
  * *4 Струнный инструмент*
  * *5 Труба*
  * *6 Вокальное ду*
  * *7 Фортепиано*
  * *8 Фортепиано c нажатой педалью*
<br>Далее программа переведёт выбранный кусок и выведет 2 строки. Если строка больше 256 символов, то она разделит их по 256. Если останется кусок меньше, то дополнит символами F
```
Ноты
FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F
3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F
3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F
5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F
5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F
3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F
3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3F3F3FF3FF3FF3FF3F5F1FF1FF1FF1FF1F1F5FF5FF5FF5FF5F5F3FF3FF3FF3FF3FFF
FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
Октавы
FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F
0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F
0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F
0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F
0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F
0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F
0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0F0F0FF0FF0FF0FF0FFF
FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
```

___
# Список обновлений <a name="updates"></a>
В этом разделе фиксируются все основные изменения, добавления и удаления в коде.
* 28.09.23
    * Правильная обработка голоса. Теперь, если в такте отсутствует необходимый голос, он будет автоматически заполнен паузой.
    * Для основных размеров тактов правильно рассчитывается длительность целого такта.
    * Для метода Translation() теперь необходимо вручную указывать минимальную длительность в единицах продолжительности во всём произведение. В противном случае метод будет автоматически сокращать длительность, используя минимальную длительность в выбранной партии. Это предотвратит неправильное кодирование выходных записей нот и октав. В будущем будет разработана отдельная функция, которая будет автоматически определять минимальную длительность.
* 4.10.23
	* Добавлена функция FindMinimalDuration(), которая считывает и находит минимальную длительность во всем произведении(как выяснилось кроме ударных инструментов). Полученное значение используется методом Translation() для правильного вычисления остальных длительностей.
* 26.10.23
  	* Добавлена поддержка ударных инструментов. При обнаружении знака перкуссии, ноты в выбранной партии будут преобразованы в формат ударных инструментов Survivalcraft (числа от 0 до 9). Вместо значений в виде нот будет выводиться номер ударного инструмента с учетом длительности. Строка с октавами будет отсутствовать, так как она не используется. Добавлена поддержка 28 инструментов, к некоторым из них приходилось подбирать похожий на слух инструмент. Вот название ударных и их порядковый номер в звуковом генераторе Survivalcraft или аналог:
```
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
```
