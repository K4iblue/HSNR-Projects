# Aufgabe 5: Liste mit Operatoren

In dieser Aufgabe soll das Thema {\em Operatorüberladung} vertieft und angewendet werden. Überladen Sie daher die folgenden Operatoren für die aus der Vorlesung bekannte Klasse `Liste`.

- `Liste Liste::operator+(Liste& lst)` soll die Inhalte
  der Listen `*this` und `lst` hintereinander hängen.
  
- `int Liste::operator[](int pos)` soll, wie bei einem Array,
  das Element liefern, das auf der Position `pos` steht. Wird dabei
  auf einen ungültigen Bereich der Liste zugegriffen, soll eine Ausnahme *geworfen* werden.
  
- Überladen Sie den Ausgabeoperator `<<` sowie den Eingabeoperator `>>` um Listen einfach auf dem Bildschirm ausgeben und von der Tastatur einlesen zu können.
  
- Überladen Sie den Vergleichsoperator `==` um zwei Listen auf Gleichheit testen zu können.
  
- Der Zuweisungsoperator, der durch den Compiler zur Verfügung gestellt wird, kopiert lediglich die Attributwerte der Liste. Daher soll der Zuweisungsoperator überladen werden: `Liste& Liste::operator=(const Liste& l)`

Wie immer gehört das Erstellen von Testtreibern und Testfällen zur Aufgabe,
um die Korrektheit Ihrer Implementierung nachzuweisen.
