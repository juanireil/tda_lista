# Trabajo Practico Algoritmos y Programacion 2
# TDA Lista
## Explicacion del Trabajo:
### Implementacion:

La implementacion requerida, trataba de una lista simplemente enlazada y sus funciones primitivas. Además, se debían
implementar distintas funciones de pila y cola e iteradores interno y externo.

Con lo elaborado, se puede crear una lista y destruirla, ademas de insertar elementos en la posicion deseada y borrarlos
el elemento de una posición determinada. Tambien se puede saber el elemento de una posicion en especifica, la cantidad de elementos y si esta vacia o no.

Aprovechando estas funciones ya realizadas, se desarrollaron las demas con las que se puede apilar, desapilar y saber el tope, encolar, desencolar y saber el primer elemento. Tambien las funciones de los iteradores para crearlo, avanzarlo y saber el elemento actual.

### Compilación y ejecución:
Para simplificar la compilación y ejecución del programa opté por armar un makefile. En este, dividí en dos casos diferentes, uno en el que se quiera ejecutar usando las minipruebas y el otro en el que se desee ejecutar usando mis pruebas.

Para el caso de las minipruebas se debe ejecutar primero el comando:

- _make minipruebas_

Posteriormente se ejecutara el comando:

- _make valgrind_minipruebas_

Con estos dos comandos ya se habrá compilado y ejecutado mostrando asi lo esperado por pantalla. En el caso de querer ejecutar mis pruebas las lineas de comando son las mismas reemplazando minipruebas por pruebas. En este caso seria:

- _make pruebas_

- _make valgrind_pruebas_

Además, en el make esta la opcion de realizar un debugging usando gdb si se reemplaza valgrind por debug en la linea de comando. Por ultimo si se desea borrar todo lo generado en las compilaciones anteriores simplemente se ejecuta el comando

- _make clean_

En los casos en que se compila, la linea de compilacion es:

- _gcc pruebas.c lista.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0_

(Aclaración: Los nombres a poner son los de los archivos a compilar si se desean las minipruebas se pone en lugar de pruebas.c)

Para la ejecución con valgrind la linea de comando que se ejecuta es:

- _valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./lista_se_

### Consideraciones tomadas:

- En todas las funciones es tomado como un error que se reciba una lista NULL, en caso de recibirla se devuelve lo correspondiente para indicar un error.

- En las operaciones de borrado si la lista esta vacia se devuelve lo correspondiendte a un error.

- Es posible crear un iterador en una lista vacia, en este caso apunta a NULL sin tener siguiente ni poder avanzar.

- Lista iterador tiene siguiente devolvera true hasta llegar al NULL, es decir aún cuando este en nodo fin no se tomará a ese como al ultimo, sinó al siguiente de ese que siempre apuntará a NULL.

- Lista iterador avanzar, en caso de encontrarse en nodo fin avanzara ya que segun lo expuesto anteriormente tiene siguiente pero devolvera false ya que queda en un nodo NULL que no forma parte de la lista como tal.

## Explicacion de conceptos teoricos:
### Lista:

La lista es un tipo de dato abstracto en la cual se almacenan distintos datos y se posee informacion del primer y ultimo elemento. Además cada elemento posee la informacion de quien es su siguiente y/o anterior. Segun esto una lista puede ser simplemente o doblemente enlazada. En la simplemente enlazada cada elemento tiene referencia de su siguiente o anterior pero solo de uno de estos. En la doblemente enlazada por otro lado cada elemento tiene la informacion de quien es su anterior y siguiente. Una lista tiene la virtud de poder saber o modificar cualquier elemento sin importar su posicion. Lo mismo aplica para sacar o agregar algun elemento.

### Pila:
La pila, si bien la idea fundamental es la misma que la lista esta tiene la particularidad de tener un tope. Además te permite sacar o agregar unicamente en una posicion la ultima. Se puede ver como si fuera una pila de cajas, yo agrego en la última posicion y saco en esa misma.

### Cola:
La cola tambien parte de la misma idea fundamental con la diferencia de que busca asegurar de que el o lo primero en llegar sea lo primero en salir. Es decir yo inserto elementos por la ultima posicion pero saco por la primera. Esto se puede observar muy claramente en las filas de supermercado. Llega alguien nuevo y va a lo ultimo de la fila y cuando a alguien le toca salir sale el de la primera posicion.

### Iterador:
Un iterador es un tipo de dato abstracto o una estructura que permite recorrer de forma secuencial una lista sin necesidad de conocer la estrucutura de esta. Principalmente hay dos tipos, iterador interno y externo.

### Iterador externo:
El iterador externo como indica su nombre utiliza cosas externas para recorrer la lista. Este cuenta con una serie de primitivas propias que utiliza para recorrerla. En la aplicacion normalmente posee un campo en el cual tiene al elemento al que apunta y con sus primitivas puede saber si tiene o no siguiente, puede avanzar entre otras cosas.

### Iterador interno:
El iterador interno por otro lado no requiere de estas primitivas externas sino que utiliza normalmente otros elementos. Este no controla el ciclo si no que accede a las estructuras. En sus aplicaciones lo mas comun es que se utilice recibiendo la lista que se quiere iterar, un puntero a funcion y un puntero void extra.
