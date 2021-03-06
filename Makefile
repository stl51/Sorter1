default: Sorter_server.c handle_csv.c MergeSort.c
	gcc -g -Wall -pthread -c Sorter_server.c handle_csv.c MergeSort.c
	gcc -g -Wall -pthread Sorter_server.o handle_csv.o MergeSort.o -o sort_thread
	rm Sorter_server.o 
	rm handle_csv.o 
	rm MergeSort.o 

proc: Sorter.c handle_csv.c MergeSort.c
	gcc -g -Wall -c Sorter.c handle_csv.c MergeSort.c
	gcc -g -Wall Sorter.o handle_csv.o MergeSort.o -o sort_proc
	rm Sorter.o 
	rm handle_csv.o 
	rm MergeSort.o
clean:
	rm sort_thread
