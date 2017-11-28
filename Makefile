default: Sorter_thread.c handle_csv.c MergeSort.c
	gcc -g -Wall -pthread -c Sorter_thread.c handle_csv.c MergeSort.c
	gcc -g -Wall Sorter_thread.o handle_csv.o MergeSort.o -o sort_thread
	rm Sorter_thread.o 
	rm handle_csv.o 
	rm MergeSort.o 
clean:
	rm sort_thread
