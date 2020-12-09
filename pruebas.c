#include  "lista.h"
#include "pa2mm.h"

static const int NO_SE_PUDO_INSERTAR = -1, SE_PUDO_INSERTAR = 0;
static const int SE_PUDO_BORRAR = 0, NO_SE_PUDO_BORRAR = -1;
static const bool TIENE_SIGUIENTE = true, NO_TIENE_SIGUIENTE = false;
const bool ESTA_VACIA = true, NO_ESTA_VACIA = false;
const int LISTA_VACIA = 0;
//static const int LISTA_VACIA = 0;

typedef struct elemento_prueba{
    int valor;
}elemento_prueba_t;

void probar_creacion_lista(){
    lista_t* lista = NULL;

    pa2m_afirmar((lista=lista_crear()) != NULL, "Puedo crear una lista");
    pa2m_afirmar((*lista).cantidad == 0, "Una lista se crea vacia");
    pa2m_afirmar((*lista).nodo_inicio == NULL, "Una lista se crea con primer elemento nulo");
    pa2m_afirmar((*lista).nodo_fin == NULL, "Una lista se crea con ultimo elemento nulo");

    lista_destruir(lista);
}

void probar_lista_insertar(){
    lista_t* lista;
    elemento_prueba_t* elemento = NULL;

    elemento = malloc(sizeof(elemento_prueba_t));
    (*elemento).valor = 3;

    lista = lista_crear();
    pa2m_afirmar(lista_insertar(NULL, elemento) == NO_SE_PUDO_INSERTAR, "Lista invalida, no puede insertar");

    pa2m_afirmar(lista_insertar(lista, elemento) == SE_PUDO_INSERTAR, "Lista vacia, se puede insertar, inserto en la ultima posicion");
    pa2m_afirmar((*lista).cantidad == 1, "Lista vacia ahora tiene 1 elemento");
    pa2m_afirmar((*(*lista).nodo_inicio).elemento == elemento, "Lista con un elemento apunto al primero");
    pa2m_afirmar((*(*lista).nodo_fin).elemento == elemento, "Lista con un elemento apunta al ultimo");
    pa2m_afirmar((*(*lista).nodo_fin).siguiente == NULL, "Ultimo elemento apunta a NULL");

    pa2m_afirmar(lista_insertar(lista, elemento) == SE_PUDO_INSERTAR, "Lista con un elemento, se puede insertar, inserto en la ultima posicion");
    pa2m_afirmar((*lista).cantidad == 2, "Lista con un elemento ahora tiene 2 elementos");
    pa2m_afirmar((*(*lista).nodo_fin).elemento == elemento, "Lista con dos elementos apunta al ultimo");
    pa2m_afirmar((*(*lista).nodo_fin).siguiente == NULL, "Ultimo elemento apunta a NULL");

    lista_destruir(lista);
    free(elemento);
}

void probar_lista_insertar_en_posicion(){
    lista_t* lista;
    lista_t* lista_2;
    elemento_prueba_t* elemento = NULL;

    elemento = malloc(sizeof(elemento_prueba_t));
    (*elemento).valor = 3;

    lista = lista_crear();
    lista_2 = lista_crear();
    pa2m_afirmar(lista_insertar_en_posicion(NULL, elemento,0) == NO_SE_PUDO_INSERTAR, "Lista invalida, no puede insertar");

    pa2m_afirmar(lista_insertar_en_posicion(lista, elemento,1) == SE_PUDO_INSERTAR, "Lista vacia, posicion invalida, inserto");
    pa2m_afirmar((*lista).cantidad == 1, "Lista vacia ahora tiene 1 elemento");
    pa2m_afirmar((*(*lista).nodo_fin).siguiente == NULL, "Ultimo elemento apunta a NULL");

    pa2m_afirmar(lista_insertar_en_posicion(lista_2, elemento,0) == SE_PUDO_INSERTAR, "Lista vacia, posicion valida, inserto");
    pa2m_afirmar((*lista_2).cantidad == 1, "Lista vacia ahora tiene 1 elemento");
    pa2m_afirmar((*(*lista_2).nodo_fin).siguiente == NULL, "Ultimo elemento apunta a NULL");

    lista_insertar(lista, elemento);
    lista_insertar(lista, elemento);
    pa2m_afirmar(lista_insertar_en_posicion(lista, elemento,1) == SE_PUDO_INSERTAR, "Lista con 3 elementos, posicion valida, inserto");
    pa2m_afirmar((*lista).cantidad == 4, "Lista con 3 elementos ahora tiene 4 elementos");
    pa2m_afirmar((*(*lista).nodo_fin).siguiente == NULL, "Ultimo elemento apunta a NULL");
    lista_destruir(lista);
    lista_destruir(lista_2);
    free(elemento);
}

void probar_lista_borrar(){
    lista_t* lista;
    elemento_prueba_t* elemento = NULL;

    elemento = malloc(sizeof(elemento_prueba_t));
    (*elemento).valor = 3;

    lista = lista_crear();
    pa2m_afirmar(lista_borrar(NULL) == NO_SE_PUDO_BORRAR, "Lista invalida, no puede borrar");
    pa2m_afirmar(lista_borrar(lista) == NO_SE_PUDO_BORRAR, "Lista vacia, no se puede borrar");
    lista_insertar(lista, elemento);

    pa2m_afirmar(lista_borrar(lista) == SE_PUDO_BORRAR, "Lista con 1 elemento, se puede borrar");
    pa2m_afirmar((*lista).cantidad == 0, "Lista con 1 elemento ahora esta vacia");
    pa2m_afirmar((*lista).nodo_inicio == NULL, "Lista primer elemento nulo");
    pa2m_afirmar((*lista).nodo_fin == NULL, "Lista ultimo elemento nulo");

    lista_insertar(lista, elemento);
    lista_insertar(lista, elemento);
    pa2m_afirmar(lista_borrar(lista) == SE_PUDO_BORRAR, "Lista con 2 elementos, se puede borrar");
    pa2m_afirmar((*lista).cantidad == 1, "Lista con 2 elementos ahora tiene 1 elemento");
    pa2m_afirmar((*(*lista).nodo_fin).siguiente == NULL, "Ultimo elemento apunta a NULL");

    lista_destruir(lista);
    free(elemento);
}

void probar_lista_borrar_de_posicion(){
    lista_t* lista;
    elemento_prueba_t* elemento = NULL;

    elemento = malloc(sizeof(elemento_prueba_t));
    (*elemento).valor = 3;

    lista = lista_crear();
    pa2m_afirmar(lista_borrar_de_posicion(NULL, 2) == NO_SE_PUDO_BORRAR, "Lista invalida, no puede borrar");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 2) == NO_SE_PUDO_BORRAR, "Lista vacia, no se puede borrar");
    lista_insertar(lista, elemento);

    pa2m_afirmar(lista_borrar_de_posicion(lista, 4) == SE_PUDO_BORRAR, "Lista con 1 elemento, posicion invalida, se puede borrar el ultimo");
    pa2m_afirmar((*lista).cantidad == 0, "Lista con 1 elemento ahora esta vacia");
    pa2m_afirmar((*lista).nodo_inicio == NULL, "Lista primer elemento nulo");
    pa2m_afirmar((*lista).nodo_fin == NULL, "Lista ultimo elemento nulo");

    lista_insertar(lista, elemento);
    lista_insertar(lista, elemento);
    pa2m_afirmar(lista_borrar_de_posicion(lista,0) == SE_PUDO_BORRAR, "Lista con 2 elementos, primera posicion, se puede borrar");
    pa2m_afirmar((*lista).cantidad == 1, "Lista con 2 elementos ahora tiene 1 elemento");
    pa2m_afirmar((*(*lista).nodo_fin).siguiente == NULL, "Ultimo elemento apunta a NULL");

    lista_insertar(lista, elemento);
    lista_insertar(lista, elemento);
    lista_insertar(lista, elemento);
    pa2m_afirmar(lista_borrar_de_posicion(lista,1) == SE_PUDO_BORRAR, "Lista con 4 elementos, segunda posicion, se puede borrar");
    pa2m_afirmar((*lista).cantidad == 3, "Lista con 4 elementos ahora tiene 3 elementos");
    pa2m_afirmar((*(*lista).nodo_fin).siguiente == NULL, "Ultimo elemento apunta a NULL");

    lista_destruir(lista);
    free(elemento);
}
void probar_lista_elemento_en_posicion(){
    char a = 'a';
    lista_t* lista;

    lista = lista_crear();
    lista_insertar(lista, &a);
    pa2m_afirmar(lista_elemento_en_posicion(NULL, 2) == NULL, "Lista invalida, no se puede saber el elemento");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 7) == NULL, "Posicion de elemento invalida");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &a, "Posicion de elemento valida, lista valida devuelve elemento");

    lista_destruir(lista);
}

void probar_lista_ultimo(){
    char a = 'a';
    lista_t* lista;

    lista = lista_crear();
    lista_insertar(lista, &a);
    pa2m_afirmar(lista_ultimo(NULL) == NULL, "Lista invalida, no se puede saber el elemento");
    pa2m_afirmar(lista_ultimo(lista) == &a, "Lista valida devuelve el ultimo elemento");

    lista_destruir(lista);
}

void probar_lista_vacia(){
    char a = 'a';
    lista_t* lista;

    lista = lista_crear();
    
    pa2m_afirmar(lista_vacia(NULL) == ESTA_VACIA, "Lista invalida, esta vacia o no");
    pa2m_afirmar(lista_vacia(lista) == ESTA_VACIA, "Lista vacia");

    lista_insertar(lista, &a);
    pa2m_afirmar(lista_vacia(lista) == NO_ESTA_VACIA, "Lista contiene elementos");

    lista_destruir(lista);
} 

void probar_lista_elementos(){
    char a = 'a';
    lista_t* lista;

    lista = lista_crear();
    
    pa2m_afirmar(lista_elementos(NULL) == LISTA_VACIA, "Lista invalida, no tiene elementos");
    pa2m_afirmar(lista_elementos(lista) == LISTA_VACIA, "Lista vacia");

    lista_insertar(lista, &a);
    pa2m_afirmar(lista_elementos(lista) == (*lista).cantidad, "Lista contiene 1 elemento");
    
    lista_destruir(lista);
}

void probar_funcionamiento_lista(){
    lista_t* lista;
    char a = 'a';
    lista = lista_crear();
    for(size_t i = 0; i < 10; i++){
        lista_insertar(lista, &i);
    }
    pa2m_afirmar(lista_elementos(lista) == 10, "Lista con 10 elementos");
    for(size_t i = 0; i < 10; i++){
        pa2m_afirmar(lista_elemento_en_posicion(lista, i) == &i, "Posicion de elemento valida, lista valida devuelve el elemento es correcto");
    }
    pa2m_afirmar(lista_insertar_en_posicion(lista, &a,9) == SE_PUDO_INSERTAR, "Lista con 3 elementos, posicion valida, inserto");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 9) == &a, "Posicion de elemento valida, lista valida devuelve elemento correcto");
    pa2m_afirmar(lista_elementos(lista) == 11, "Lista con 11 elementos");
    pa2m_afirmar(lista_borrar(lista) == SE_PUDO_BORRAR, "Se puedo borrar el ultimo elemento");
    pa2m_afirmar(lista_ultimo(lista) == &a, "Lista devuelve el ultimo elemento correctamente");
    pa2m_afirmar(lista_borrar_de_posicion(lista,3) == SE_PUDO_BORRAR, "Se puedo borrar");
    pa2m_afirmar(lista_elementos(lista) == 9, "Lista con 10 elementos");
    while (!lista_vacia(lista)){
        lista_borrar(lista);
    }
    pa2m_afirmar(lista_vacia(lista) == ESTA_VACIA, "Lista vacia");
    
    lista_destruir(lista);
}

void probar_lista_apilar(){
    lista_t* lista;
    char a = 'a';

    lista = lista_crear();
    pa2m_afirmar(lista_apilar(NULL, &a) == NO_SE_PUDO_INSERTAR, "Lista invalida, no puede apilar");

    pa2m_afirmar(lista_apilar(lista, &a) == SE_PUDO_INSERTAR, "Lista vacia, se puede apilar, inserto en la ultima posicion");
    pa2m_afirmar((*lista).cantidad == 1, "Lista vacia ahora tiene 1 elemento");
    pa2m_afirmar((*(*lista).nodo_inicio).elemento == &a, "Lista con un elemento apunto al primero");
    pa2m_afirmar((*(*lista).nodo_fin).elemento == &a, "Lista con un elemento apunta al ultimo");
    pa2m_afirmar((*(*lista).nodo_fin).siguiente == NULL, "Ultimo elemento apunta a NULL");

    lista_destruir(lista);
}

void probar_lista_desapilar(){
    lista_t* lista;
    char a = 'a';

    lista = lista_crear();
    pa2m_afirmar(lista_desapilar(NULL) == NO_SE_PUDO_BORRAR, "Lista invalida, no puede desapilar");
    pa2m_afirmar(lista_desapilar(lista) == NO_SE_PUDO_BORRAR, "Lista vacia, no se puede desapilar");
    lista_insertar(lista, &a);

    pa2m_afirmar(lista_desapilar(lista) == SE_PUDO_BORRAR, "Lista con 1 elemento, se puede desapilar");
    pa2m_afirmar((*lista).cantidad == 0, "Lista con 1 elemento ahora esta vacia");
    pa2m_afirmar((*lista).nodo_inicio == NULL, "Lista primer elemento nulo");
    pa2m_afirmar((*lista).nodo_fin == NULL, "Lista ultimo elemento nulo");

    lista_destruir(lista);
}

void probar_lista_tope(){
    char a = 'a';
    lista_t* lista;

    lista = lista_crear();
    lista_insertar(lista, &a);
    pa2m_afirmar(lista_tope(NULL) == NULL, "Lista invalida, no se puede saber el elemento");
    pa2m_afirmar(lista_tope(lista) == &a, "Lista valida devuelve el ultimo elemento");

    lista_destruir(lista);
}

void probar_funcionamiento_pila(){
    lista_t* lista;

    lista = lista_crear();
    for(size_t i = 0; i < 10; i ++){
        pa2m_afirmar(lista_apilar(lista, &i) == SE_PUDO_INSERTAR, "Se apilo correctamente");
        pa2m_afirmar(lista_tope(lista) == &i, "Ultimo elemento correcto");
    }
    for(size_t i = 9; i != 0; i --){
        pa2m_afirmar(lista_desapilar(lista) == SE_PUDO_BORRAR, "Se desapilo correctamente");
        pa2m_afirmar(lista_tope(lista) == &i, "Ultimo elemento correcto");
    }
    lista_destruir(lista);
}

void probar_lista_encolar(){
    lista_t* lista;
    char a = 'a';

    lista = lista_crear();
    pa2m_afirmar(lista_encolar(NULL, &a) == NO_SE_PUDO_INSERTAR, "Lista invalida, no puede encolar");

    

    pa2m_afirmar(lista_encolar(lista, &a) == SE_PUDO_INSERTAR, "Lista vacia, se puede encolar, inserto en la ultima posicion");
    pa2m_afirmar((*lista).cantidad == 1, "Lista vacia ahora tiene 1 elemento");
    pa2m_afirmar((*(*lista).nodo_inicio).elemento == &a, "Lista con un elemento apunto al primero");
    pa2m_afirmar((*(*lista).nodo_fin).elemento == &a, "Lista con un elemento apunta al ultimo");
    pa2m_afirmar((*(*lista).nodo_fin).siguiente == NULL, "Ultimo elemento apunta a NULL");

    lista_destruir(lista);
}

void probar_lista_desencolar(){
    lista_t* lista;
    char a = 'a' , b = 'b';

    lista = lista_crear();
    pa2m_afirmar(lista_desencolar(NULL) == NO_SE_PUDO_BORRAR, "Lista invalida, no puede desencolar");
    pa2m_afirmar(lista_desencolar(lista) == NO_SE_PUDO_BORRAR, "Lista vacia, no se puede desencolar");

    lista_insertar(lista, &a);
    lista_insertar(lista, &b);

    pa2m_afirmar(lista_desencolar(lista) == SE_PUDO_BORRAR, "Lista con 2 elementos, se puede desencolar");
    pa2m_afirmar((*lista).cantidad == 1, "Lista con 2 elementos ahora tiene 1");
    pa2m_afirmar((*(*lista).nodo_inicio).elemento == &b, "Lista primer elemento correcto");
    pa2m_afirmar((*(*lista).nodo_fin).elemento == &b, "Lista ultimo elemento correcto");

    pa2m_afirmar(lista_desencolar(lista) == SE_PUDO_BORRAR, "Lista con 1 elemento, se puede desencolar");
    pa2m_afirmar((*lista).cantidad == 0, "Lista con 1 elemento ahora esta vacia");
    pa2m_afirmar((*lista).nodo_inicio == NULL, "Lista primer elemento nulo");
    pa2m_afirmar((*lista).nodo_fin == NULL, "Lista ultimo elemento nulo");

    lista_destruir(lista);
}

void probar_lista_primero(){
    char a = 'a';
    lista_t* lista;

    lista = lista_crear();
    lista_insertar(lista, &a);
    pa2m_afirmar(lista_primero(NULL) == NULL, "Lista invalida, no se puede saber el elemento");
    pa2m_afirmar(lista_primero(lista) == &a, "Lista valida devuelve el primer elemento");

    lista_destruir(lista);
}

void probar_funcionamiento_cola(){
    lista_t* lista;

    lista = lista_crear();

    for(size_t i = 0; i < 10; i ++){
        pa2m_afirmar(lista_encolar(lista, &i) == SE_PUDO_INSERTAR, "Se encolo correctamente");
    }
    for(size_t i = 0; i < 10; i ++){
        pa2m_afirmar(lista_primero(lista) == &i, "Primer elemento correcto");
        pa2m_afirmar(lista_desencolar(lista) == SE_PUDO_BORRAR, "Se desencolo correctamente");
    }

    lista_destruir(lista);
}

void probar_lista_iterador_crear(){
    lista_t* lista;
    lista_iterador_t* iterador;
    
    pa2m_afirmar(lista_iterador_crear(NULL) == NULL, "Lista invalida, no se puede crear el iterador");

    lista = lista_crear();
    pa2m_afirmar((iterador = lista_iterador_crear(lista)) != NULL, "Lista valida, se puede crear el iterador");
    pa2m_afirmar((*iterador).corriente == NULL, "Lista vacia, se puede crear el iterador,  iterador apunta a NULL");

    lista_destruir(lista);
    lista_iterador_destruir(iterador);
}

void probar_lista_iterador_tiene_siguiente_y_avanzar(){
    char a = 'a';
    lista_t* lista;
    lista_iterador_t* iterador;

    pa2m_afirmar(lista_iterador_tiene_siguiente(NULL) == NO_TIENE_SIGUIENTE, "Iterador invalido no tiene siguiente");
    pa2m_afirmar(lista_iterador_avanzar(NULL) == NO_TIENE_SIGUIENTE, "Iterador invalido no puede avanzar");

    lista = lista_crear();
    iterador = lista_iterador_crear(lista);

    pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == NO_TIENE_SIGUIENTE, "Lista vacia, iterador no tiene siguiente");
    pa2m_afirmar(lista_iterador_avanzar(iterador) == NO_TIENE_SIGUIENTE, "Lista vacia, iterador no puede avanzar");
    lista_iterador_destruir(iterador);
    for (int i = 0; i< 5; i++){
        lista_insertar(lista, &a);
    }
    iterador = lista_iterador_crear(lista);

    pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == TIENE_SIGUIENTE, "Lista con 5 elementos, iterador tiene siguiente");
    for (int i = 0; i< 5; i++){
        if(i < 4){
            pa2m_afirmar(lista_iterador_avanzar(iterador) == TIENE_SIGUIENTE, "Lista con 5 elementos, iterador puede avanzar");
            pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == TIENE_SIGUIENTE, "Lista con 5 elementos, avanzo una posicion, tiene siguiente");
        }
        else{
            pa2m_afirmar(lista_iterador_avanzar(iterador) == NO_TIENE_SIGUIENTE, "Lista con 5 elementos, iterador puede avanzar, pero queda en el ultimo elemento");
            pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == NO_TIENE_SIGUIENTE, "Lista con 5 elementos, avanzo una posicion, no tiene siguiente");
        }
    }
    pa2m_afirmar(lista_iterador_avanzar(iterador) == NO_TIENE_SIGUIENTE, "Lista con 5 elementos, iterador en la ultima posicion no puede avanzar");

    lista_destruir(lista);
    lista_iterador_destruir(iterador);
}

void probar_lista_iterador_elemento_actual(){
    lista_t* lista;
    lista_iterador_t* iterador;

    pa2m_afirmar(lista_iterador_elemento_actual(NULL) == NULL, "Iterador invalido no tiene elemento actual");

    lista = lista_crear();
    iterador = lista_iterador_crear(lista);

    pa2m_afirmar(lista_iterador_elemento_actual(iterador) == NULL, "Lista vacia no tiene elemento actual");

    lista_iterador_destruir(iterador);
    for (int i = 0; i< 5; i++){
        lista_insertar(lista, &i);
    }
    iterador = lista_iterador_crear(lista);

    for (int i = 0; i< 5; i++){
        pa2m_afirmar(lista_iterador_elemento_actual(iterador) == &i, "Iterador devuelve el elemento correcto");
        lista_iterador_avanzar(iterador);
    }
    pa2m_afirmar(lista_iterador_elemento_actual(iterador) == NULL, "Iterador en ultimo elemento, elemento NULL");
    lista_destruir(lista);
    lista_iterador_destruir(iterador);
}

void probar_funcionamiento_iterador(){
    char a = 'a';
    lista_t* lista;
    lista_iterador_t* iterador;

    lista = lista_crear();

    for (int i = 0; i< 5; i++){
        lista_insertar(lista, &a);
    }
    iterador = lista_iterador_crear(lista);
    pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == TIENE_SIGUIENTE, "Lista con 5 elementos, iterador tiene siguiente");
    for (int i = 0; i< 5; i++){
        if(i < 4){
            pa2m_afirmar(lista_iterador_elemento_actual(iterador) == &a, "Elemento actual correcto");
            pa2m_afirmar(lista_iterador_avanzar(iterador) == TIENE_SIGUIENTE, "Lista con 5 elementos, iterador puede avanzar");
            pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == TIENE_SIGUIENTE, "Lista con 5 elementos, avanzo una posicion, tiene siguiente");

        }
        else{
            pa2m_afirmar(lista_iterador_elemento_actual(iterador) == &a, "Elemento actual correcto");
            pa2m_afirmar(lista_iterador_avanzar(iterador) == NO_TIENE_SIGUIENTE, "Lista con 5 elementos, iterador puede avanzar, pero queda en el ultimo elemento");
            pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == NO_TIENE_SIGUIENTE, "Lista con 5 elementos, avanzo una posicion, no tiene siguiente");
        }
    }
    pa2m_afirmar(lista_iterador_avanzar(iterador) == NO_TIENE_SIGUIENTE, "Lista con 5 elementos, iterador en la ultima posicion no puede avanzar");

    lista_iterador_destruir(iterador);
    lista_destruir(lista);
}

bool quedan_elementos(void* elemento, void* contador){   
    if(elemento && contador){
        (*(int*)contador)+=1;
    }
    return true;
}

void probar_lista_con_cada_elemento(){
    lista_t* lista;
    int contador = 0;
    bool (*funcion)(void*, void*) = quedan_elementos;

    pa2m_afirmar(lista_con_cada_elemento(NULL, funcion, (void*)&contador) == 0, "Lista invalido no se la puede recorrer");
    
    lista = lista_crear();
    pa2m_afirmar(lista_con_cada_elemento(lista, funcion, NULL) == 0, "Contexto invalido no se puede recorrer la lista");
    pa2m_afirmar(lista_con_cada_elemento(lista, NULL, &contador) == 0, "Funcion invalida no se puede recorrer la lista");    
    pa2m_afirmar(lista_con_cada_elemento(lista, funcion, &contador) == 0, "Lista vacia recorre 0 elementos");
    
    for(int i = 0; i < 10; i++){
        lista_insertar(lista, &i);
    }
    pa2m_afirmar(lista_con_cada_elemento(lista, funcion, &contador) == 10, "Lista con 10 elementos los recorre todos");
    contador = 0;

    lista_destruir(lista);
}

int main(){

    pa2m_nuevo_grupo("PRUEBAS OPERACIONES DE LISTA");
    printf("Pruebas creacion lista\n");
    probar_creacion_lista();
    printf("Pruebas insertar\n");
    probar_lista_insertar();
    printf("Pruebas insertar en posicion\n");
    probar_lista_insertar_en_posicion();
    printf("Pruebas de lista borrar\n");
    probar_lista_borrar();
    printf("Pruebas lista borrar en posicion\n");
    probar_lista_borrar_de_posicion();
    printf("Pruebas lista elemento en posicion\n");
    probar_lista_elemento_en_posicion();
    printf("Pruebas lista ultimo\n");
    probar_lista_ultimo();
    printf("Pruebas de lista vacia\n");
    probar_lista_vacia();
    printf("Pruebas lista elementos\n");
    probar_lista_elementos();
    printf("Pruebas funcionamiento general de la lista\n");
    probar_funcionamiento_lista();

    pa2m_nuevo_grupo("PRUEBAS OPERACIONES PILA");
    printf("Pruebas lista apilar\n");
    probar_lista_apilar();
    printf("Pruebas lista desapilar\n");
    probar_lista_desapilar();
    printf("Pruebas lista tope\n");
    probar_lista_tope();
    printf("Pruebas funcionamiento general de la pila\n");
    probar_funcionamiento_pila();

    pa2m_nuevo_grupo("PRUEBAS OPERACIONES COLA");
    printf("Pruebas lista encolar\n");
    probar_lista_encolar();
    printf("Pruebas lista desencolar\n");
    probar_lista_desencolar();
    printf("Pruebas lista primer elemento\n");
    probar_lista_primero();
    printf("Pruebas funcionamiento general de la cola\n");
    probar_funcionamiento_cola();

    pa2m_nuevo_grupo("PRUEBAS ITERADOR EXTERNO");
    printf("Pruebas lista iterador crear\n");
    probar_lista_iterador_crear();
    printf("Pruebas lista iterador tiene siguiente y avanzar\n");
    probar_lista_iterador_tiene_siguiente_y_avanzar();
    printf("Pruebas lista iterador elemento actual\n");
    probar_lista_iterador_elemento_actual();
    printf("Pruebas funcionamiento general del iterador\n");
    probar_funcionamiento_iterador();

    pa2m_nuevo_grupo("PRUEBAS ITERADOR INTERNO");
    printf("Pruebas lista con cada elemento\n");
    probar_lista_con_cada_elemento();

    pa2m_mostrar_reporte();

    printf("aaaaaa\n");
    return 0;
}
