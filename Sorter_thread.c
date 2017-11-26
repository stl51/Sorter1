#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sorter_thread.h"
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

int main(int argc, char** argv) {

	int sortby;

	if (strcmp("-c", argv[1]) != 0) {
		printf("ERROR: Invalid Value Type\n");
		return 0;
	}
	sortby = 0;
	if (strcmp("color", argv[2]) == 0) {
		sortby = 1;
	}
	else if (strcmp("director_name", argv[2]) == 0) {
		sortby = 2;
	}
	else if (strcmp("num_critic_for_reviews", argv[2]) == 0) {
		sortby = 3;
	}
	else if (strcmp("duration", argv[2]) == 0) {
		sortby = 4;
	}
	else if (strcmp("director_facebook_likes", argv[2]) == 0) {
		sortby = 5;
	}
	else if (strcmp("actor_3_facebook_likes", argv[2]) == 0) {
		sortby = 6;
	}
	else if (strcmp("actor_2_name", argv[2]) == 0) {
		sortby = 7;
	}
	else if (strcmp("actor_1_facebook_likes", argv[2]) == 0) {
		sortby = 8;
	}
	else if (strcmp("gross", argv[2]) == 0) {
		sortby = 9;
	}
	else if (strcmp("genres", argv[2]) == 0) {
		sortby = 10;
	}
	else if (strcmp("actor_1_name", argv[2]) == 0) {
		sortby = 11;
	}
	else if (strcmp("movie_title", argv[2]) == 0) {
		sortby = 12;
	}
	else if (strcmp("num_voted_users", argv[2]) == 0) {
		sortby = 13;
	}
	else if (strcmp("cast_total_facebook_likes", argv[2]) == 0) {
		sortby = 14;
	}
	else if (strcmp("actor_3_name", argv[2]) == 0) {
		sortby = 15;
	}
	else if (strcmp("facenumber_in_poster", argv[2]) == 0) {
		sortby = 16;
	}
	else if (strcmp("plot_keywords", argv[2]) == 0) {
		sortby = 17;
	}
	else if (strcmp("movie_imdb_link", argv[2]) == 0) {
		sortby = 18;
	}
	else if (strcmp("num_user_for_reviews", argv[2]) == 0) {
		sortby = 19;
	}
	else if (strcmp("language", argv[2]) == 0) {
		sortby = 20;
	}
	else if (strcmp("country", argv[2]) == 0) {
		sortby = 21;
	}
	else if (strcmp("content_rating", argv[2]) == 0) {
		sortby = 22;
	}
	else if (strcmp("budget", argv[2]) == 0) {
		sortby = 23;
	}
	else if (strcmp("title_year", argv[2]) == 0) {
		sortby = 24;
	}
	else if (strcmp("actor_2_facebook_likes", argv[2]) == 0) {
		sortby = 25;
	}
	else if (strcmp("imdb_score", argv[2]) == 0) {
		sortby = 26;
	}
	else if (strcmp("aspect_ratio", argv[2]) == 0) {
		sortby = 27;
	}
	else if (strcmp("movie_facebook_likes", argv[2]) == 0) {
		sortby = 28;
	}
	if (sortby == 0) {
		printf("ERROR: Invalid Category For Sorting\n");
		return 1;
	}
	//vvv  set these to the default of current directory  vvv
	char src_dir[4096];	//source directory
	char dest_dir[4096];	//destination directory
	char orig_dir[4096]; //starting directory
	/*src_dir = (char*)malloc(sizeof(char) * 4096);
	dest_dir = (char*)malloc(sizeof(char) * 4096);
	orig_dir = (char*)malloc(sizeof(char) * 4096);*/
	getcwd(src_dir, sizeof(src_dir));
	getcwd(dest_dir, sizeof(dest_dir));
	getcwd(orig_dir, sizeof(orig_dir));
	if((argc==6)||(argc==8)){
			printf("ERROR: Incorrect number of arguments\n");
			return 1;
	}
	if(argc==5){
	
			if (strcmp("-d", argv[3]) == 0) {
				if (argv[4] != NULL) {
					strcpy(src_dir, argv[4]);
				}
				else {
					printf("ERROR: Missing input directory name\n");
					return 1;
				}
			}
			else if (strcmp("-o", argv[3]) == 0) {
				if (argv[4] != NULL) {
					strcat(dest_dir, argv[4]);
				}
				else {
					printf("ERROR: Missing output directory name\n");
					return 1;
				}
			}
	}
	if(argc==7)	{
		if (strcmp("-o", argv[5]) == 0) {
			if (argv[6] != NULL) {
				strcpy(dest_dir, argv[6]);
			}
			else {
				printf("ERROR: Missing output directory name\n");
				return 1;
			}
		}
	}
	//check if directories are valid:
	DIR* src_folder = opendir(src_dir);
	if (src_folder) {
		//closedir(src_folder);
	}
	else {
		printf("ERROR: Invalid input directory\n");
		return 1;
	}

	DIR* dest_folder = opendir(dest_dir);
	if (dest_folder) {
		//closedir(dest_folder);
	}
	else {
		printf("ERROR: Invalid output directory\n");
		return 1;
	}

	int total;
	printf("Initial PID: %d\n", getpid());
	
	char pathway[4096];
	getcwd(pathway,sizeof(pathway));
	strcat(pathway,"/");
	strcat(pathway,src_dir);
	
	
	total = run_thru(src_folder, sortby, dest_dir,pathway);
	printf("\ntotal number of child processes: %d\n", total);


	////Convert all lines from here to closedir into function (adding a return total)
	////Ashy's variables are declared here
	//int spawns = 0; int total = 0;
	//pid_t * pids = (pid_t*)malloc(sizeof(pid_t) * 1);//array of all pids this process creates
	//int array_size = 1;
	//int status;
	////REMEMBER TO ZERO OUT ALL VARIABLES YOU WANT TO START AT 0 FOR EACH PROCESS AFTER FORKING
	//struct dirent* protag;	//protag is the file/directory in focus
	//while ((protag = readdir(src_folder)) != NULL) {
	//	DIR* dir_check = opendir(protag->d_name);
	//	if (dir_check != NULL) {//dirfork(parameters); //protag is a folder, fork and handle
	//		char* deuterag;
	//		deuterag = (char*)malloc(sizeof(char) * 512);
	//		deuterag = protag->d_name;
	//		//do the metadata computations done for file portion
	//		//recursively call self
	//		//total = spawns + "return value of self"
	//		//return total;
	//	}
	//	else if (errno == ENOTDIR) {//filefork(parameters); //protag is a file, fork and handle
	//		errno = 0;
	//		spawns++;
	//		if (spawns > array_size) {
	//			array_size = array_size * 2;
	//			pids = (pid_t*)realloc(pids, sizeof(pid_t)*array_size);
	//		}
	//		pids[spawns - 1] = fork();
	//		if (pids[spawns - 1] == 0) {//if child
	//			spawns = 0;
	//			total = 0;
	//			memset(pids, 0, sizeof(pid_t)*array_size);
	//			//create a string var for the filename
	//			char* antag;
	//			antag = (char*)malloc(sizeof(char) * 512);
	//			antag = protag->d_name;
	//			//create file ptr for the file to be processed
	//			FILE* ofile = fopen(antag, "r");
	//			curr_dir = (char*)malloc(sizeof(char) * 1024);
	//			getcwd(curr_dir, sizeof(curr_dir);
	//			FILE* nfile = sort_csv(ofile, antag, sortby, curr_dir, dest_dir);
	//			//place file in the proper location
	//			return spawns;
	//		}
	//	}
	//}
	//while (i < spawns) {//wait for each child, adding up the total number of processes underneath them as they return
	//	wait(&status);
	//	total = total + status;
	//	i++;
	//}
	//total = total + spawns;
	//closedir(src_folder);
	////return total;
	return 0;
}


int run_thru(DIR* folder, int sortby, char* dest_dir, char* pathway) {
	
	//printf("PIDS of all child processes: ");

	int spawns = 0; int total = 0;
	pid_t * pids = (pid_t*)malloc(sizeof(pid_t) * 1);//array of all pids this process creates
	int array_size = 1;
	int status; int res; int i;
	DIR* procdir; char* deuterag;


	struct dirent* protag;	//protag is the file/directory in focus
	protag = readdir(folder);
	while (protag != NULL) {
		char swing[1024];
		strcpy(swing, protag->d_name);
		DIR* dir_check = opendir(swing);
		if(dir_check==NULL){
			if(pathway[strlen(pathway)-1] != '/'){
				strcat(pathway,"/");
			}
			strcat(pathway,swing);
			dir_check=opendir(pathway);
		}
		if (dir_check != NULL) {//dirfork(parameters); 
			//protag is a folder, fork and handle
			if (!strcmp(swing, ".") || !strcmp(swing,"..")) {
				protag = readdir(folder);
				continue;
			}
			//do the metadata computations done for file portion
			errno = 0;
			spawns++;
			if (spawns > array_size) {
				array_size = array_size * 2;
				pids = (pid_t*)realloc(pids, sizeof(pid_t)*array_size);
			}
			pids[spawns - 1] = fork();
			//recursively call self
			if (pids[spawns - 1] == 0) {//if child
				//printf("Initial PID: %d\n", getpid());
				spawns = 0;
				total = 0;
				memset(pids, 0, sizeof(pid_t)*array_size);
				
				res = run_thru(dir_check, sortby, dest_dir,pathway);
				total = spawns + res;
				exit(total);
			}
			printf("%d,", pids[spawns - 1]);
			wait(&status);
			total = WEXITSTATUS(status) + total;
		}
		else /* if (errno == ENOTDIR)*/ {//filefork(parameters); //protag is a file, fork and handle
			errno = 0;
			spawns++;
			if (spawns > array_size) {
				array_size = array_size * 2;
				pids = (pid_t*)realloc(pids, sizeof(pid_t)*array_size);
			}
			pids[spawns - 1] = fork();
			if (pids[spawns - 1] == 0) {//if child
				errno = 0;
				printf("Initial PID: %d\n", getpid());
				spawns = 0;
				total = 0;
				memset(pids, 0, sizeof(pid_t)*array_size);
				
				FILE* ofile = fopen(pathway, "r");
				
				char* dir_path = (char*) malloc(sizeof(char)*4096);
                dir_path = (char*) memcpy(dir_path, pathway, sizeof(char)*(strlen(pathway)-strlen(swing)));
                dir_path[strlen(pathway)-strlen(swing)] = '\0';

				sort_csv(ofile, swing, sortby, dir_path, dest_dir);
				
				exit(spawns);
			}
			printf("%d,", pids[spawns - 1]);
			wait(&status);
			total = WEXITSTATUS(status) + total;
		}
        pathway[strlen(pathway)-strlen(swing)] = '\0';
	
	protag = readdir(folder);
	}

	//while (i < spawns) {//wait for each child, adding up the total number of processes underneath them as they return
	//	wait(&status);
	//	total = total + status;
	//	i++;
	//}
	total = total + spawns;
	printf("\ntotal number of child processes: %d\n", total);

	closedir(folder);
	return total;
}