![Image alt](https://github.com/Pigeon-Ignaty/survivalcraft-notes-translator/image/qt_meme.jpg)

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

**Survivalcraft Notes Translator** is a program that reads musicxml files, displays the found parts and voices, and translates notes and octaves from the selected voice into the format of the sound generator in Survivalcraft, utilizing a clear and simple interface.

___

# What's Implemented <a name="whats-implemented"></a>
- Main window and console interface.
- Menu with options: file, settings, help.
- Opening, closing, and error checking in .musicxml files.
- Hiding and revealing the console.
- Redirecting all text to the console.

___

# What's Not Implemented <a name="whats-not-implemented"></a>
- Opening and reading .xml and .midi files.
- Separating chords into individual parts and their translation.
- Translation of duols, triols, quartoles, quintoles, and so on.
- Translation of changes in sound volume.

___

# Example <a name="example"></a>
*(Examples of the program's functionality can be added here)*

___

# Updates List <a name="changelog"></a>
This section displays major changes, additions, and deletions in the gui branch's code.

* 10.01.24
    * Loaded the basic QT project.
    * Created the initial prototype of the main window interface with a menu bar and functional options for opening, closing files, and exiting the program.
    * Established the console window, redirecting all text from the methods of the MainWindow class through the QTextEditStream class.
    * Implemented classes in the project: MainWindow - the class for the main window, Debug - the class for the console window, QTextEditStream - the class for text redirection to the console window, and the tinyxml2 library for reading musicxml files.
___
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

**Survivalcraft Notes Translator** - программа, которая читает musicxml файл, выводит найденные партии и голоса, и из выбранного голоса переводит ноты и октавы в формат звукового генератора в Survivalcraft, используя понятный и простой интерфейс
___

# Что реализовано <a name="realized"></a>
- Интерфейс главного окна и окна-консоли.
- Меню с пунктами: файл, настройки, справка.
- Открытие, закрытие и проверка ошибок в файлах .musicxml.
- Скрытие и открытие консоли.
- Перенаправление всего текста в консоль.

- ___
# Что не реализовано <a name="unrealized"></a>
- Открытие и чтение файлов .xml и .midi.
- Разбиение аккордов на отдельные партии и их перевод.
- Перевод дуолей, триолей, квартолей, квинтолей и так далее.
- Перевод изменений громкости звука.
___
# Пример <a name="Пример"></a>
*(Примеры функционала программы могут быть добавлены здесь)*


___
# Список обновлений <a name="updates"></a>
В этом разделе отображаются основные изменения, добавления и удаления в коде в ветке gui.

* 10.01.24
    * Загрузка базового проекта на QT.
    * Создание первого прототипа интерфейса главного окна с menu bar и рабочим функционалом открытия, закрытия файлов и выхода из программы.
    * Создание окна-консоли, в которое перенаправляется весь текст из методов класса MainWindow через класс QTextEditStream.
    * В проекте реализованы классы: MainWindow - класс первого окна, Debug - класс окна-консоли, QTextEditStream - класс перенаправления текста в окно-консоль, Библиотека tinyxml2 для чтения musicxml файлов
  