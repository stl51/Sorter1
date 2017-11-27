/*****
*
*	Define structures and function prototypes for your sorter
*
*
*
******/

//Suggestion: define a struct that mirrors a record (row) of the data set
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

struct film{
		char* color;
		char* director_name;
		int num_critic_for_reviews;
		int duration;
		int director_facebook_likes;
		int actor_3_facebook_likes;
		char* actor_2_name;
		int actor_1_facebook_likes;
		int gross;
		char* genres;
		char* actor_1_name;
		char* movie_title;		
		int num_voted_users;
		int cast_total_facebook_likes;
		char* actor_3_name;		
		int facenumber_in_poster;
		char* plot_keywords;
		char* movie_imdb_link;
		int num_user_for_reviews;
		char* language;
		char* country;
		char* content_rating;
		int budget;
		int title_year;
		int actor_2_facebook_likes;	
		double imdb_score;
		double aspect_ratio;
		int movie_facebook_likes;
};
typedef struct film film;

struct thread_arg{
	//&(tids[spawns - 1]), 0, run_thru, dir_check, sortby, dest_dir, pathway
	DIR* dir_check;
	int sortby;
	char* dest_dir;
	char* pathway;
	
};
typedef struct thread_arg thread_arg;

struct sortcsv_arg{
	//ofile, sortby, dir_path
	FILE* ofile;
	int sortby;
	char* dir_path;
	
};
typedef struct sortcsv_arg sortcsv_arg;

//Suggestion: prototype a mergesort function
film** mergesort(film** array, int size, int col);//pointer to unsorted array, size of array, column to sort by

void free_strings(film** array, int len);//free string pointers for each struct when freeing an array
film* filmcpy(film* filmA, film* filmB);//copy a film struct function
film* replace_NULL_w_empty(film* f);//self explanitory
char* strtok_fix (char* str, char const * delim);//a fix to strtok to include nulls
film** sort_csv(FILE* file, int sortby, char* curr_dir);
film** run_thru(DIR* folder, int sortby, char* dest_dir, char* pathway);
