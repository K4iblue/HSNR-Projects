# Zusatzaufgabe 4: Mandelbrot

Komplexe Zahlen eignen sich nicht nur für die komplexe Wechselstromrechnung, wir nutzen sie auch zur Darstellung der [Mandelbrot-Menge](https://de.wikipedia.org/wiki/Mandelbrot-Menge), die im allgemeinen Sprachgebrauch oft auch Apfelmä̈nnchen genannt wird.

Die Mandelbrot-Menge *M* ist die Menge aller komplexen Zahlen *c*, fü̈r welche die rekursiv definierte Folge komplexer Zahlen *z<sub>0</sub>, z<sub>1</sub>, z<sub>2</sub>, ...* mit dem Bildungsgesetz

*z<sub>n + 1</sub> = z<sub>n</sub><sup>2</sup> + c*

und dem Anfangsglied *z<sub>0</sub> = 0* beschrä̈nkt bleibt, das heißt,
der Betrag der Folgenglieder wä̈chst nicht ü̈ber alle Grenzen.

![](mandelbrot.jpg)

Die grafische Darstellung dieser Menge erfolgt in der komplexen Ebene. Die Punkte der Menge *M* werden dabei in der Regel schwarz dargestellt und der Rest farbig, wobei die Farbe eines Punktes den Grad der Divergenz der zugehö̈rigen Folge widerspiegelt. Man berechnet also den Wert *n*, fü̈r den der Betrag *|z<sub>n</sub>|* z.B. grö̈ßer als zwei ist, und diesem Wert *n* ordnet man eine Farbe zu.

Schreiben Sie ein Programm, dass die Farbwerte in eine Datei schreibt, sodass man die Ap- felmä̈nnchen mittels eines Bildbetrachtungsprogramms ansehen kann. Zur einfachen Speicherung von Rastergrafiken eignen sich das [Protable-Pixmap-(PPM)](https://de.wikipedia.org/wiki/Portable_Anymap) und das [Windows-Bitmap-Format (BMP)](https://de.wikipedia.org/wiki/Windows_Bitmap).

Sinnvoll ist es, dem Programm fü̈nf Parameter zu ü̈bergeben:

- Die maximale Anzahl von Iterationsschritten. Wird dieser Wert ü̈berschritten, so wird das entsprechende Pixel der Menge *M* zugeordnet. Der Wert sollte mindestens 100 betragen. Bei stä̈rkerer Vergrö̈ßerung sind zur korrekten Darstellung der Struk- turen teilweise erheblich grö̈ßere Werte erforderlich und es ergeben sich dann deutlich lä̈ngere Rechenzeiten.

- Die beiden Werte *re<sub>min</sub>* und *im<sub>min</sub>* beschreiben den unteren, linken Bildpunkt, die beiden Werte *re<sub>max</sub>* und *im<sub>max</sub>* beschreiben den oberen, rechten Bildpunkt des Ap- felmä̈nnchens. Die Berechnung des dem Pixel zugeordneten komplexen Zahlenwerts *c = (c<sub>re</sub> + i · c<sub>im</sub>)* mit dem Realteil *re<sub>min</sub> ≤ c<sub>re</sub> ≤ re<sub>max</sub>* und dem Imaginä̈rteil *im<sub>min</sub> ≤ c<sub>im</sub> ≤ im<sub>max</sub>* erfolgt durch lineare Interpolation zwischen den beiden Punkten.

Geeignete Programm-Parameter sind:

```
| iter | 128  | 256  | 384   | 512    | 640     | 768      | 
| rmin | -2.0 | -1.0 | -0.78 | -0.751 | -0.7446 | -0.74401 |
| imin | -1.2 | 0.0  | 0.10  | 0.118  | 0.1303  | 0.13151  |
| rmax | 0.8  | -0.5 | -0.74 | -0.735 | -0.7424 | -0.74327 |
| imax | 1.2  | 0.5  | 0.14  | 0.134  | 0.1325  | 0.13225  |
```
