/*

?. ./pipex nombres.txt "grep ^M" "wc -l" salida.txt
   * - Filtra los nombres que empiezan con 'M' y cuenta cuántos son.

?. ./pipex nombres.txt "cat" "sort" salida.txt
   * Muestra todos los nombres y los ordena alfabéticamente.

?. ./pipex nombres.txt "grep a" "tr a-z A-Z" salida.txt
	* Filtra los nombres que contienen la letra 'a' y convierte esos nombres a mayúsculas.

?. ./pipex nombres.txt "awk '{print \$1}'" "rev" salida.txt
   * Extrae los nombres (primera columna) y los invierte (al revés).

?. ./pipex nombres.txt "tail -n 5" "sort" salida.txt
   * Muestra los últimos 5 nombres y los ordena alfabéticamente.

?. ./pipex nombres.txt "cat" "cut -c1-3" salida.txt
   * Muestra los primeros tres caracteres de cada nombre.

?. ./pipex nombres.txt "grep i" "wc -c" salida.txt
	* Filtra los nombres que contienen la letra 'i' y cuenta el número total de caracteres de esos nombres.

?. ./pipex nombres.txt "sort -r" "head -n 2" salida.txt
	* Ordena los nombres en orden inverso (descendente) y muestra los primeros dos.

?. ./pipex nombres.txt "sed 's/a/@/g'" "cat" salida.txt
   * Reemplaza todas las letras 'a' con '@' en cada nombre y los muestra.

?. ./pipex nombres.txt "grep ^C" "cut -d 'a' -f 1" salida.txt
	* Filtra los nombres que empiezan con 'C' y corta todo el texto desde la primera aparición de la letra 'a'.

?                                 LEAKS DE MEMORIA

!     valgrind --leak-check=full ./pipex nombres.txt "comando1" "comando2" salida.txt

*/