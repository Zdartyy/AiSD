
# Quaternion Library in C++

## Opis
Ten projekt implementuje klase i operatory umożliwiające pracę z **kwaternionami** w języku C++. Kwaterniony to rozszerzenie liczb zespolonych, które są powszechnie używane w grafice komputerowej, mechanice obrotowej i innych dziedzinach nauki i techniki. Klasa `Quaternion` zapewnia podstawowe działania arytmetyczne, takie jak dodawanie, odejmowanie, mnożenie, sprzężenie i obliczanie modułu.


---

## Funkcje obsługiwane przez klasę `Quaternion`
- **Dodawanie**: `operator+`
- **Odejmowanie**: `operator-`
- **Mnożenie**: `operator*`
- **Sprzężenie**: `conjugate()`
- **Moduł**: `modulus()`
- **Porównywanie**: `operator==`, `operator!=`
- **Wyświetlanie**: `operator<<`

---

## Struktura projektu
```
.
├── main.cpp          # Program testujący funkcjonalność klasy Quaternion
├── Quaternion.h       # Nagłówek definiujący klasę Quaternion
├── Quaternion.cpp     # Implementacja metod klasy Quaternion
├── Makefile           # Skrypt do kompilacji projektu
└── README.md          # Ten plik
```

---

## Jak skompilować projekt
Aby skompilować projekt, wykonaj następujące kroki:

1. Upewnij się, że masz zainstalowany kompilator C++ (`g++`) i narzędzie `make`.
2. Otwórz terminal i przejdź do katalogu projektu.
3. Uruchom polecenie:
   ```bash
   make
   ```
   To skompiluje projekt z flagami `-Wall` (włącza ostrzeżenia) i `-std=c++11` (ustawia standard C++11).

4. Po pomyślnej kompilacji wygenerowany będzie plik wykonywalny o nazwie `quaternion_test`.

5. Aby uruchomić program, wpisz:
   ```bash
   ./quaternion_test
   ```

6. Aby usunąć pliki tymczasowe i wykonywalne, użyj polecenia:
   ```bash
   make clean
   ```

---

## Przykład działania
Program testowy (`main.cpp`) demonstruje podstawowe operacje na kwaternionach. Oto przykład wyniku działania programu:

```
q1 = 1 + 2i + 3j + 4k
q2 = 5 + 6i + 7j + 8k
q1 + q2 = 6 + 8i + 10j + 12k
q1 - q2 = -4 - 4i - 4j - 4k
q1 * q2 = -60 + 12i + 30j + 24k
Conjugate of q1 = 1 - 2i - 3j - 4k
Modulus of q1 = 5.47723
q1 is not equal to q2
```
