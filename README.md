# kruskal-algorithm-C

## Estructuras:

	arista: 
		Una arista consiste de dos vertices y un costo. Los 3 valores son dados por enteros.

	rama:
		Una rama es una estructura preparada para crear una lista enlazada de aristas, que contiene
	una arista, y un puntero hacia un tipo rama, que va a ser la arista siguiente.

	
	
	Conjunto_CE:
		El conjunto_ce consiste de dos estructuras, que son encabezado y nombre.
	La estructura "nombre" está también preparada para ser una lista enlazada, conteniendo un nombre, que va a ser la indexación
	para el "encabezado" que la contiene, y un entero que va a ser el siguiente elemento de la lista.
	
	La estructura "encabezado" va a contener un entero con la cantidad de elementos en la lista, y otro entero que va a ser el primer elemento de la misma.


## Funciones:
	
	void inicial(tipo_nombre, tipo_elemento, conjunto_ce*): toma un nombre, un elemento, y un puntero al conjunto_ce, y genera las dos "tablas" de la estructura de dato conjunto_ce para
	todos los vertices del grafo. (Lo que sería gráficamente dibujar el grafo sin las aristas).

	void combina(tipo_nombre, tipo_nombre, conjunto_ce*): Recibe dos nombres de conjuntos (que sirven para indexar los elementos pertenecientes a cada conjunto)
	e inserta el menor de ellos por el frente del mayor. Haciendo que el elemento inicial del mayor, sea el inicial del menor, y que cada elemento del menor este
	relacionado al conjunto mayor.

	tipo_nombre encuentra(tipo_elemento, conjunto_ce*): dado un elemento, y la estructura ce, devuelve el nombre del conjunto al que pertenece ese elemento.

	arista * sacar_min(rama**): Dada una lista enlazada de aristas, devuelve el primer elemento de la misma.

	void inserta(int, int, int, rama**): dados dos vertices y un costo, inserta la misma en una lista enlazada de aristas de forma ordenada de menor a mayor.

	void lista(rama*): listar toda una lista enlazada de aristas dada.
	
	void kruskal(rama*): Llama a la funcion "inicial", luego recorre toda la lisa de prioridad del grafo ingresado inicialmente, analizando cada vertice de las 
	aristas dadas, uniendo en un mismo conjunto las que pertenecen a conjuntos diferentes y no conforman un ciclo, luego los inserta en el arbol resultante 
	a partir del único conjunto que queda con elementos, y lo imprime.

	
