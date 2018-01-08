Z badań jednoznacznie wynika, że `deque` jest zdecydowanie wydajniejszym kontenerem
implementującym interfejs kolejki. Zarówno dopisywanie na koniec kolejki, jak i odczyt
oraz usuwanie pierwszego elementu są około 10 krotnie szybsze. Jedyną zaletą kontenera
`list` jest bardzo krótki czas tworzenia, ok 1 ns w porównaniu z 42 ns potrzebnymi na
utworzenie `deque`.

Prawdopodobną przyczyną tej różnicy w dostępach jest dużo gorszy wzorzec dostępów
do pamięci kontenera `list`. Dla trybu pracy w którym najpierw dostawiane jest n elementów,
a następnie są one sekwencyjnie odcinane od przodu, kontener `deque` wywołał ok 6 razy
mniej cache-miss.

Wyniki można uzyskać kompilując kod źródłowy poleceniem `make`, następnie wywołując program
`test` aby zobaczyć czasy wykonania operacji `push` oraz `pop/front`.
Poleceniem `run-tests` można zapisać przebiegi programów `p-list` oraz `p-deque`
realizujących powyższy scenariusz dostępów do pamięci.
Wynik można obejrzeć poleceniami:

 1. `sudo perf report -G -i list.perf`
 2. `sudo perf report -G -i deque.perf`

