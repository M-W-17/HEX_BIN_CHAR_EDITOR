# HEX_BIN_CHAR_EDITOR

**C++17 HEX/BIN/CHAR Datei-Editor – IU Portfolio Aufgabe 1**

## 1. Projektbeschreibung

Der HEX_BIN_CHAR_EDITOR ist ein in C++ entwickeltes Programm zur binären Bearbeitung von Dateien.

Das Programm ermöglicht es, Dateien byteweise einzulesen, deren Inhalte in verschiedenen Darstellungsformen anzuzeigen und einzelne Bytes gezielt zu verändern.

Ein Byte kann dabei als Hexadezimalwert (HEX), Binärwert (BIN) oder Zeichen (CHAR) dargestellt und bearbeitet werden.

## 2. Funktionen

- Dateien im Binärmodus laden und speichern
- Speicherung der Dateiinhalte in einem `std::vector<uint8_t>`
- Anzeige der Dateiinhalte in HEX-, BIN- und CHAR-Darstellung
- Bearbeitung einzelner Bytes
- Umwandlung zwischen den verschiedenen Darstellungsformen
- Eingabeprüfung und Fehlerbehandlung
- Tabellarische Darstellung mit Offset
- Navigation durch größere Dateien
- Speicherung der vorgenommenen Änderungen

Nicht druckbare Zeichen werden in der Zeichenansicht durch einen Punkt (`.`) dargestellt.

## 3. Softwarearchitektur

Das Programm ist modular aufgebaut und besteht aus vier zentralen Komponenten:

| Modul | Aufgabe |
|---|---|
| FileManager | Laden, Speichern und Verwalten der Bytes |
| DataConverter | Umwandlung und Validierung der Eingaben |
| UserInterface | Anzeige und Benutzerinteraktion |
| Controller | Steuerung des Programmablaufs |

### Dateistruktur

```text
HEX_BIN_CHAR_EDITOR/
│
├── main.cpp
├── Controller.cpp
├── Controller.h
├── FileManager.cpp
├── FileManager.h
├── DataConverter.cpp
├── DataConverter.h
├── UserInterface.cpp
├── UserInterface.h
├── CMakeLists.txt
├── .gitignore
└── README.md
```

## 4. Technische Grundlagen

- Programmiersprache: C++
- Sprachstandard: C++17
- Entwicklungsumgebung: CLion
- Build-System: CMake
- Versionsverwaltung: Git
- Repository: GitHub (privat)

## 5. Kompilierung

Das Projekt kann über CLion und die zugehörige CMake-Konfiguration erstellt werden.

Alternativ kann es mit einem C++17-kompatiblen Compiler kompiliert werden.

Beispiel mit GCC:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic \
main.cpp Controller.cpp FileManager.cpp \
DataConverter.cpp UserInterface.cpp \
-o HEX_BIN_CHAR_EDITOR
```

## 6. Programmstart

Das Programm kann mit einem Dateipfad als Kommandozeilenargument gestartet werden.

Beispiel:

```bash
HEX_BIN_CHAR_EDITOR.exe testdata.txt
```

Alternativ kann der Dateipfad über die Benutzeroberfläche eingegeben werden.

## 7. Ziel des Projekts

Ziel ist die Entwicklung eines modularen Datei-Editors, der den Umgang mit binären Daten und deren unterschiedlichen Darstellungsformen ermöglicht.

Das Projekt dient gleichzeitig der praktischen Anwendung von Grundlagen der objektorientierten und modularen C++-Programmierung.

## 8. Versionsverwaltung

Das Projekt wird über ein privates GitHub-Repository verwaltet:

[HEX_BIN_CHAR_EDITOR – GitHub](https://github.com/M-W-17/HEX_BIN_CHAR_EDITOR)

---

**Projektstatus:** Entwicklungsstand gemäß IU Portfolio Aufgabe 1.