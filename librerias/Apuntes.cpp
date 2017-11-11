// Las librerias siempre iran con .h
//
// Compilar g++ -c aritmetica.cpp para el codigo objeto
//
//1.-Crear objeto g++ -c nombre.cpp (Se generan los .o) 
//2.-Creamos una paquete con las librerias cat * .h > mates.h ¡Cambiamos el ifndef y dejamos solo las llamadas de las funciones! 
//3.-ar cr nombreCrear.a objetos.o 
//4.-En Lib dejamos el .a 
//5.-En include los .h 
//6.-Compilas gcc -Iinclude -c uso.cpp gcc uso.o -o uso -Llib -lnombre.h sin .h  
//gcc uso.cpp -Iinclude -o uso -Llib -lmates

// ar cr libmates.a aritmetica.o logica.o  Creas la libreria libmates con los objetos de los dos archivos
// -Ilib en el gcc te busca en el directorio las librerias que te hacen faltia
// -I y hay que poner despues seguido donde estan los include
//
// gcc -Iinclude -c nombre.cpp
// gcc uso.o -o uso -Llib -lmates
//
// En una linea gcc uso.cpp -Iinclude -o uso -Llib -lmates
//
/*!!Cuando pases la libreria a otro proyecto!! 1.-compilas los .cpp 2.-gcc -shared -fPIC -o libmates.so aritmetica.o logica.o 3.-Movuemos el libmates.so a la carpeta lib 4.-gcc -c -Iinclude uso.cpp 5.-gcc -o uso uso.o -Llib -lmates

al ejecutar si se a cambiado la ruta no funciona. hay que cambiarla LD_LIBRARY_PATH='pwd'/lib export LD_LIBRARY_PATH

¡Cargar modulos! dlopen (.so) -> Cargalo en memoria. (.so, RTLD_LAZY) -> Cargalo en memoria cuando se genere la primera llamada.
*/
//
