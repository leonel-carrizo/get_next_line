estoy en el primer nodo = '\n.\nThi'

## LEAKS DE MEMORIA
EL problema que estoy teniendo de momento es como liberar
los estrings y lineas alojadas y retornadas. Por ejemplo, en
la funcion `new_line`, que extrae la nueva linea y la guarda 
en una variable que retornara a `get_next_line` en la variable line
la que sera retornada.

## BORRADO DE NODOS.
Ademas, los nodos a los que he eliminado la linea,
estan quedando vacios, pero todavia existen. al recorrer en busca
del ultimo nodo para anadir el nuevo nodo despues del string anterior 
todavia estna alli.


# Entendiendo el **heap** y **stack**
los datos almacenadoa automaticamente al crear una variable
se almacenan en el **stak** y los datos almacenados cuando usamos **malloc**
para reservar memoria para una variable se almacenan en el **heap**
y esto es algo que debemos manejar para liberar este espacio de memoria
para usarlo posteriormente

