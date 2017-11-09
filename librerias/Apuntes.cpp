Las librerias siempre iran con .h

Compilar g++ -c aritmetica.cpp para el codigo objeto

ar cr libmates.a aritmetica.o logica.o  Creas la libreria libmates con los objetos de los dos archivos
-Ilib en el gcc te busca en el directorio las librerias que te hacen faltia
-I y hay que poner despues seguido donde estan los include

gcc -Iinclude -c nombre.cpp
gcc uso.o -o uso -Llib -lmates

 En una linea gcc uso.cpp -Iinclude -o uso -Llib -lmates


