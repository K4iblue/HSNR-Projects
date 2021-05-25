# Aufgabe 4: Heap als Klasse

Die in der Vorlesung behandelten Klassen `string`, `iostream`, `iomanip` und `fstream` aus
der Standard-Bibliothek sollen vertieft und angewendet werden.

Implementieren Sie den Heap aus [Aufgabe 2](https://git.ide3.de/pe2/aufgaben/woche-2-modularer-heap) als Klasse in C++.

1. Ersetzen Sie die Funktion `createHeap` durch einen Konstruktor und die Funktion `destroyHeap` durch einen Destruktor.
2. Realisieren Sie die Speicherverwaltung mit `new` und `delete`.
3. Ergä̈nzen Sie die Klasse Heap
    - um eine Methode `readFile(std::string filename)`, die die angegebene Datei öffnet, die darin enthaltenen Werte einliest und in den Heap übernimmt.
    - um eine Methode `writeFile(std::string filename)`, die die angegebene Datei öffnet und alle Werte des Heaps darin speichert.

Wie immer, gehört das Erstellen von Testtreibern und Testfällen zur Aufgabe, um die Korrektheit Ihrer Implementierung nachzuweisen.
