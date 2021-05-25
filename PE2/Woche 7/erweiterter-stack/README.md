# Aufgabe 7: Erweiterter Stack

Hier soll das Thema Vererbung vertieft und angewendet werden.

Erweitern Sie in einer Klasse `ExtStack` die Funktionalität der Klasse Stack aus [Aufgabe 3](https://git.ide3.de/pe2/aufgaben/woche-3-stack-als-klasse), indem Sie die folgenden Methoden implementieren:

- Die Methode `size t ExtStack::size()` liefert die Anzahl der aktuell im Stack gespeicherten Werte

- Die Methode `void ExtStack::swap(ExtStack& s)` tauscht die Elemente des Stacks mit den Elementen des Stacks `s` aus.

- Der zusätzliche Konstruktor `ExtStack::ExtStack(const float *arr, size_t len)` soll die Elemente des als Parameter übergebenen Arrays `arr` in den Stack übernehmen.

Ändern Sie Ihren Testtreiber und erweitern Sie ggf. die Testfälle, um die Korrektheit Ihrer Implementierung nachzuweisen.
