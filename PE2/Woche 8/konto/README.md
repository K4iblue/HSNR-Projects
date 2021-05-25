# Aufgabe 8: Vererbung und Polymorphie in C++

Eine Bank verwaltet Konten, wobei jedes Konto einer Person zugeordnet ist. Leiten Sie von der Klasse `Konto` zwei Klassen `Girokonto` und `Sparkonto` ab. Folgende Funktionen haben alle Kontenarten gemeinsam:

```
void hebeAb(int betrag, Datum d);
void zahleEin(int betrag, Datum d);
int kontostand();
string kontoauszug();
```

Bei einem Sparkonto darf nur dann Geld abgehoben werden, wenn der Kontostand dadurch nicht negativ wird. Bei einem Girokonto darf der Kontostand zwar negativ werden, aber nur bis zum angegebenen `dispo`-Wert, dem Kreditlimit. Werden diese Regeln verletzt, soll eine Exception geworfen werden. 

Das Guthaben auf einem Sparkonto wird verzinst, beim Girokonto gibt es dagegen nur einen Sollzins, also einen Zinssatz für Überziehungen. Außerdem stellt das Girokonto eine weitere Methode bereit:

```
void ueberweise(int betrag, Datum d, string info)
```

Implementieren Sie obige Klassen. Überlegen Sie sich, welche Attribute die Klassen ha- ben und welche davon in der Basisklasse deklariert werden können. Welche der Methoden müssen als virtual deklariert und in einer Unterklasse überschrieben werden? Welche Methoden sind abstrakt? Wie werden Kontobewegungen vermerkt?

Die Klassen `Datum` und `Konto` stellen wir zur Verfügung, müssen aber eventuell noch etwas angepasst werden. Wie immer gehört das Erstellen von Testtreibern und Testfällen zur Aufgabe, um die Korrektheit Ihrer Implementierung nachzuweisen. Die von uns implementierten Testfälle sind nicht ausreichend.
