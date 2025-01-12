<p align="center">
  <img src="https://i.ibb.co/HhHRcy8/logo-project.png" alt="Project Logo" width="500"">
</p>

<p align="center">
<img src="https://img.shields.io/badge/Framework-Qt5%2FC%2B%2B-green?style=flat-square&logoColor=red"">
<a href="https://github.com/Pigeon-Ignaty/survivalcraft-notes-translator/releases"><img src="https://img.shields.io/badge/Stable%20Version%20-%20no-red?style=flat-square&logoColor=red"></a>
<a href="https://github.com/Pigeon-Ignaty/survivalcraft-notes-translator/blob/gui/LICENSE"><img src="https://img.shields.io/badge/License%20-GPL%20%20-blue?style=flat-square&logoColor=red"></a>
<img src="https://img.shields.io/badge/OS%20-%20Windows%20-%20%238932a8?style=flat-square">
</p>

# About 📔
Survivalcraft Notes Translator is a program that reads musicxml files, extracts the found parts and voices, and translates notes and octaves from the selected voice into the format of the sound generator in Survivalcraft.

## Installation
1. Download the current version [here](https://github.com/Pigeon-Ignaty/survivalcraft-notes-translator/releases)
2. Unpack the archive to any convenient location
3. Launch file.exe

## What's Implemented 🚀<a name="whats-implemented "></a>
- Open and read musicxml compressed and uncompressed files
- Output of party names and their selection
- Withdrawal of all votes in the party and their selection
- Translation of the simplest single notes
- Output hexadecimal notation for notes, octaves, instruments and volume
- Instrument selection and automatic transposition of notes to the desired octave depending on the range of the instrument (the first octave is cut off for the bell, as it sounds in dissonance)
- Determining the league and lengthening the note duration
- Work with all major clock sizes
- Automatic splitting into 256-character strings with 'F' characters in case the string does not reach this length.
- Translation of percussion instruments
  
## What's Not Implemented 🗿<a name="whats-not-implemented "></a>
- Opening and reading .midi files
- Splitting chords into separate parts and translating them
- Translation of duoles, trioles, quartoles, quintoles, etc.
- Translation of sound volume changes
- No music translation for the 2.4 version of the game with the updated sound generator operation

## User guide
For detailed information on how to use the application, open the [User's guide](path to the file.html), available in HTML format. It provides instructions on how to use the program.

## Acknowledgements
- This project uses the [tinyxml2](https://github.com/leethomason/tinyxml2) library for XML parsing.
- This project uses the [miniz](https://github.com/richgel999/miniz) library for compression and decompression.
  
## Author
This project was developed by [Pigeon Ignaty](https://github.com/Pigeon-Ignaty)

## Report a bug 🐛
If you find a bug or problem in the app, please create an [issue](https://github.com/Pigeon-Ignaty/survivalcraft-notes-translator/issues) by attaching a screenshot of the error and a music file.

## License
This project is licensed under the terms of the GNU General Public License v3.0. See the [LICENSE](./LICENSE) file for details.
___
## Updates List 💾<a name="changelog" ></a>
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
# RU Survivalcraft Notes Translator 
Survivalcraft Notes Translator - это программа, которая считывает файлы musicxml, извлекает найденные партии и голоса и переводит ноты и октавы из выбранного голоса в формат звукового генератора в Survivalcraft.

## Установка 🔧
1. Скачайте текущую версию [здесь](https://github.com/Pigeon-Ignaty/survivalcraft-notes-translator/releases)
2. Распакуйте архив в любое удобное для вас место
3. Запустите file.exe

## Что реализовано 🎹<a name="realized"></a>
- Открытие и чтение файлов сжатых и несжатых musicxml
- Вывод названий партий и их выбор
- Вывод всех голосов в партии и их выбор
- Перевод простейших одиночных нот
- Вывод шестнадцатеричной записи для нот, октав, инструментов и громкости
- Выбор инструмента и автоматическое транспонирование нот на нужную октаву в зависимости от диапазона инструмента (для колокольчика обрезана первая октава, так как она звучит в диссонанс)
- Определение лиги и удлинение длительности ноты
- Работа со всеми основными размерами тактов
- Автоматическое разбиение на строки по 256 символов с заполнением символами 'F' в случае, если строка не достигает этой длины
- Перевод ударных инструментов

## Что не реализовано <a name="unrealized"></a>
- Открытие и чтение .midi файлов
- Разбиение аккордов на отдельные партии и их перевод
- Перевод дуолей, триолей, квартолей, квинтолей и т. д.
- Перевод изменения громкости звука
- Отсутствие перевода музыки для версии игры 2.4 с обновлённой работой генератора звука
  
## Руководство пользователя 
Для получения подробной информации о том, как использовать приложение, откройте [руководство пользователя](путь_к_файлу.html), доступное в формате HTML. В нем представлены инструкции по использованию программы.

## Используемые библиотеки 📚
- [tinyxml2](https://github.com/leethomason/tinyxml2) — для парсинга XML.
- [miniz](https://github.com/richgel999/miniz) — для работы с архивами.
  
## Автор
Этот проект был разработан [Pigeon Ignaty](https://github.com/Pigeon-Ignaty)

## Сообщить о жуке (баге) ⚠️
Если вы нашли баг или проблему в приложении, пожалуйста, создайте [issue](https://github.com/Pigeon-Ignaty/survivalcraft-notes-translator/issues), прикрепив скриншот ошибки и музыкальный файл.

## Лицензия
Этот проект лицензирован на условиях GNU General Public License версии 3.0. Смотрите файл [ЛИЦЕНЗИЯ](./LICENSE) для получения дополнительной информации.
___
## Список обновлений 📋<a name="updates"></a>
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
