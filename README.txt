Cerinta 1:
	-pentru a afla daca un graf este aciclic, am implementat o functie ce parcurge fiecare din copiii unui nod pe rand, apoi pe rand copiii copiilor
nodului resppectiv pe rand samd pana cand nu mai exista, apoi se intoarce la un nivel mai sus samd(daca x are copiii a b c, iar a are compii q p r, il marchez pe x ca vizitat, 
apoi trec la a, il marchez ca vizitat, apoi trec la q, il marchez ca vizitat, ma intorc la copiii lui a, il "demarchez" pe q, si il marchez pe p samd). 
Astfel daca trebuie sa marchez ca vizitat un nod ce era deja marcat ca vizitat, graful este ciclic

Cerinta 2:
	-am implementat o functie de tip dfs, numita dfshelp, care primeste
ca parametri graful in care se face parcurgerea, nodul din care se porneste
parcurgerea, dar si un vector initializat cu 0, in care modific in 1 componenta
specifica indicelor nodurilor parcurse, iar dupa apleare afisez nodurile
specifice componentelor cu valoare 1 si astfel afisez nodurile pentru past(node)
	
	-am implementat alta functie, numita dfs, ce primeste ca parametru graful in care se face cautarea, p
entru care va fi apelata functia dfshelper, nodul primit ca parametru, dar si un vector initializat cu 0, 
dar care la finalul functiei va avea valoarea 1 pe fiecare componenta specifica unui nod din care se poate 
ajunge in nodul cautat. In urma apelului functiei dfshelper, voi avea un vector ale carui componente sunt 
explicate anterior. In continuare, in cadrul functiei dfs, verific daca vectorul rezultat are 1 pe pozitia specifica
nodului primit ca parametru in linia de comanda. In caz afirmativ, nodul pentru care a fost apelata functia dfshelper face parte
din future(node)

	-pentru a afla anticone(node) am adunat fiecare membru al vectorilor obtinuti in cadrul aflarii componentelor past(node) 
si future(node), iar daca suma dintre 2 componente de pe aceeasi pozitie este 0, inseamnra ca nodul respectiv nu face parte nici
din future(node) nici din past(node), asa ca face parte din anticone(node)

	-pentru a afla tips(G) vac un vecotr in care retin numarul de aparitii ale nodului in lista de adiacenta din fisierul de intrare, iar
daca nodul nu apare niciodata, inseamna ca face parte din tips(G)