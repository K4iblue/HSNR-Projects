# Zusatz 8: Vererbung und Polymorphie in C++

Implementieren Sie eine Basisklasse Dipol, die eine rein virtuelle Methode `impedance` bereitstellt. Leiten Sie von dieser Klasse drei Klassen `Resistor`, `Inductor` und `Capacitor` ab, die jeweils die Methode `impedance` implementieren.

Nutzen Sie unsere generische Klasse [Liste](https://git.ide3.de/pe2/beispiele/liste) aus der Vorlesung, um eine Klasse `Serial` und eine Klasse `Parallel` zu implementieren, die eine Serien- bzw. Parallelschaltung von Zweipolen realisieren und ebenfalls die Klasse `Dipol` implementieren.

Die obige Schaltung könnte wie folgt realisiert werden:

```
Resistor r(20);
Capacitor c(2e-6, 1e3);
Parallel par;
par.append(&r);
par.append(&c);
Inductor l(0.2, 1e3);
Serial ser;
ser.append(&l);
ser.append(&par);
cout << ser.impedance() << endl;
```

Wie ist das Programm circuit aus [Zusatz-Aufgabe 6](https://git.ide3.de/pe2/aufgaben/zusatz-6-komplexe-zahlen-aus-der-stl) zu ändern, um den dort realisierten Schaltkreis mittels der hier implementierten Klassen zu modellieren?

Wie immer gehoört das Erstellen von Testtreibern und Testfällen zur Aufgabe, um die Korrektheit Ihrer Implementierung nachzuweisen.
