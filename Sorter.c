#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sorter.h"
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

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
	total = run_thru(src_folder, sortby, dest_dir);


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


int run_thru(DIR* folder, int sortby, char* dest_dir) {
	//Convert all lines from here to closedir into function (adding a return total)
	//Ashy's variables are declared here
	int spawns = 0; int total = 0;
	pid_t * pids = (pid_t*)malloc(sizeof(pid_t) * 1);//array of all pids this process creates
	int array_size = 1;
	int status; int res; int i;
	DIR* procdir; char* deuterag;
	//REMEMBER TO ZERO OUT ALL VARIABLES YOU WANT TO START AT 0 FOR EACH PROCESS AFTER FORKING


	struct dirent* protag;	//protag is the file/directory in focus
	while ((protag = readdir(folder)) != NULL) {
		char swing[1024];
		swing = strcpy(swing, protag->d_name);
		DIR* dir_check = opendir(protag->d_name);
		if (dir_check != NULL) {//dirfork(parameters); //protag is a folder, fork and handle
			deuterag = (char*)malloc(sizeof(char) * 512);
			deuterag = strcpy(deuterag, protag->d_name);
			if (!strcmp(deuterag, ".") || !strcmp(deuterag,"..")) {
				free(deuterag);
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
				spawns = 0;
				total = 0;
				memset(pids, 0, sizeof(pid_t)*array_size);
				procdir = opendir(deuterag);
				res = run_thru(procdir, sortby, dest_dir);
				total = spawns + res;
				return total;
			}
			wait(&status);
			total = status + total;
		}
		else if (errno == ENOTDIR) {//filefork(parameters); //protag is a file, fork and handle
			errno = 0;
			spawns++;
			if (spawns > array_size) {
				array_size = array_size * 2;
				pids = (pid_t*)realloc(pids, sizeof(pid_t)*array_size);
			}
			pids[spawns - 1] = fork();
			if (pids[spawns - 1] == 0) {//if child
				spawns = 0;
				total = 0;
				memset(pids, 0, sizeof(pid_t)*array_size);
				//create a string var for the filename
				char* antag;
				antag = (char*)malloc(sizeof(char) * 512);
				antag = strcpy(antag, protag->d_name);
				//create file ptr for the file to be processed
				FILE* ofile = fopen(antag, "r");
				char curr_dir[4096];
				getcwd(curr_dir, sizeof(curr_dir));
				FILE* nfile = sort_csv(ofile, antag, sortby, curr_dir, dest_dir);
				//place file in the proper location
				return spawns;
			}
			wait(&status);
			total = status + total;
		}


	}

	//while (i < spawns) {//wait for each child, adding up the total number of processes underneath them as they return
	//	wait(&status);
	//	total = total + status;
	//	i++;
	//}
	total = total + spawns;


	closedir(folder);
	return total;
}


/*	for new sorter:
	DIR * dirp; //directory pointer
	set dirp to given char* dir_name
	dirp=opendir(dir_name);
	if(dirp==NULL){
	return error invalid directory name
	}
	chdir(dir_name);	//change current directory to given directory
	struct dirent* duwang;	//requires dirent.h library
	duwang=readdir(dirp);
	while((duwang!=NULL){
	* 
	* 
	* 
	kinda iffy what goes here besides forking stuff
	
	char* file_name=  whatever the current file is
	int bodega=strlen(file_name)-1;
	if(file_name[bodega-4]=='.'){
	* 
	* if(file_name[bodega-4]=='c')){
	* 
		* 
			* if(file_name[bodega-4]=='s')){
				* if(file_name[bodega-4]=='v')){
				* 
				* 	FILE* fp=fopen(file_name,"r");
				* 
				* perhaps fork here and run sort?
				* 
				* 
				* 
				* 
				* fclose(fp);
				* create an output file
				* char* dest_file;
				* FILE* dfp=fopen(dest_file,"wb");
				* //write stuff to here for output 
				* fclose(dfp);
				* return;
				* 
				* 
				* }
			* }
			* 
		* }
	* 
	* 
	* 
	* }
	
	}
	
*/
	
	
//	int loop=0;
//	FILE* file=stdin;	/*CHANGE THIS STUFF so that it accepts .csv files in the directory*/
//	char line [5000];
//	int a_size = 50;
//	film** array=(film**)malloc(sizeof(film*)*a_size);
//	int arrayloc = 0;
//	while(fgets(line,sizeof(line),file)!=NULL){
//		loop++;
//		//printf("%d\n", loop-1);
//		if(loop==1){		//skip first line containing categories
//				continue;
//		}
//		
//		film* x=NULL;
//		x=(struct film*)malloc(sizeof(film));	//current film record being made
//		
//		
//		int assignto=0;	//determines where value will be stored
//		char* val=strtok_fix(line,",");
//
//		while (val!=NULL){
//			assignto++;
//			//printf("current val is %s\n",val);
//			if(assignto == 1 || assignto == 2 || assignto == 7 || assignto == 10 || assignto == 11 || assignto == 12 || assignto == 15 || assignto == 17 || assignto == 18 || assignto == 20 || assignto == 21 || assignto == 22){
//				while(val[0] == ' '){
//					val++;
//				}
//			}
//
//			//if(assignto==1){
//				//if(strcmp(val,"Color")!=0 && strcmp(val,"color")!=0 && strcmp(val, "Black and White")!=0){
//					//x->color="";
//					//continue;
//				//}
//			//}
//			
//			if(strcmp(val,"")==0){	//empty value
//				if(assignto==1){
//					x->color="";
//				}else if(assignto==2){
//					x->director_name="";
//				}else if(assignto==3){
//					x->num_critic_for_reviews=0;
//				}else if(assignto==4){
//					x->duration=0;
//				}else if(assignto==5){
//					x->director_facebook_likes=0;
//				}else if(assignto==6){
//					x->actor_3_facebook_likes=0;
//				}else if(assignto==7){
//					x->actor_2_name="";
//				}else if(assignto==8){
//					x->actor_1_facebook_likes=0;
//				}else if(assignto==9){
//					x->gross=0;
//				}else if(assignto==10){
//					x->genres="";
//				}else if(assignto==11){
//					x->actor_1_name="";
//				}else if(assignto==12){
//					x->movie_title="";
//				}else if(assignto==13){
//					x->num_voted_users=0;
//				}else if(assignto==14){
//					x->cast_total_facebook_likes=0;
//				}else if(assignto==15){
//					x->actor_3_name="";
//				}else if(assignto==16){
//					x->facenumber_in_poster=0;
//				}else if(assignto==17){
//					x->plot_keywords="";
//				}else if(assignto==18){
//					x->movie_imdb_link="";
//				}else if(assignto==19){
//					x->num_user_for_reviews=0;
//				}else if(assignto==20){
//					x->language="";
//				}else if(assignto==21){
//					x->country="";
//				}else if(assignto==22){
//					x->content_rating="";
//				}else if(assignto==23){
//					x->budget=0;
//				}else if(assignto==24){
//					x->title_year=0;
//				}else if(assignto==25){
//					x->actor_2_facebook_likes=0;
//				}else if(assignto==26){
//					x->imdb_score=0;
//				}else if(assignto==27){
//					x->aspect_ratio=0;
//				}else if(assignto==28){
//					x->movie_facebook_likes=0;
//				}
//				//val=strtok(NULL,",");	//move on to next token
//				//continue;		//jump to next token
//			}else if((assignto==3)|(assignto==4)|(assignto==5)|(assignto==6)|(assignto==8)|(assignto==9)|(assignto==13)|(assignto==14)|(assignto==16)|(assignto==19)|(assignto==23)|(assignto==24)|(assignto==25)|(assignto==28)){	//convert to int
//				int numval=atoi(val);
//				if(assignto==3){
//					x->num_critic_for_reviews=numval;
//				}else if(assignto==4){
//					x->duration=numval;
//				}else if(assignto==5){
//					x->director_facebook_likes=numval;
//				}else if(assignto==6){
//					x->actor_3_facebook_likes=numval;
//				}else if(assignto==8){
//					x->actor_1_facebook_likes=numval;
//				}else if(assignto==9){
//					x->gross=numval;
//				}else if(assignto==13){
//					x->num_voted_users=numval;
//				}else if(assignto==14){	
//					x->cast_total_facebook_likes=numval;
//				}else if(assignto==16){
//					x->facenumber_in_poster=numval;
//				}else if(assignto==19){	
//					x->num_user_for_reviews=numval;
//				}else if(assignto==23){
//					x->budget=numval;
//				}else if(assignto==24){
//					x->title_year=numval;
//				}else if(assignto==25){
//					x->actor_2_facebook_likes=numval;
//				}else{
//					x->movie_facebook_likes=numval;
//				}	
//				//val=strtok(NULL,",");	//move on to next token
//				//continue;	//jump to next token
//										
//			}else if((assignto==26)|(assignto==27)){		//convert to double
//				if(assignto==26){
//					x->imdb_score=atof(val);
//				}else{
//					x->aspect_ratio=atof(val);
//				}
//				//val=strtok(NULL,",");	//move on to next token
//				//continue;	//jump to next token
//			}
//			
//			if(val[0]=='"'){	//opening quotation, check for closing quote
//				while(val[strlen(val)-1]!='"'){	//lacks a closing quote
//					char* temp = strtok_fix(NULL,",");
//					char* teststr = (char*) malloc(strlen(temp)+1);
//					teststr = strcpy(teststr, temp);
//					strcat(val,teststr);	//concatenates next token to current token
//				}
//			}
//				//enter values if token is a string
//				if(assignto==1){
//					x->color=val;
//				}else if(assignto==2){
//					x->director_name=val;
//				}else if(assignto==7){
//					x->actor_2_name=val;
//				}else if(assignto==10){
//					x->genres=val;
//				}else if(assignto==11){
//					x->actor_1_name=val;
//				}else if(assignto==12){
//					x->movie_title=val;
//				}else if(assignto==15){
//					x->actor_3_name=val;
//				}else if(assignto==17){
//					x->plot_keywords=val;
//				}else if(assignto==18){
//					x->movie_imdb_link=val;
//				}else if(assignto==20){
//					x->language=val;
//				}else if(assignto==21){
//					x->country=val;
//				}else if(assignto==22){
//					x->content_rating=val;
//				}	
//			
//			if(assignto==28){		//x is a complete film to add to the array
//				if((loop-1) == a_size){
//					a_size = a_size*2;
//					array = (film**)realloc(array, sizeof(film*)*a_size);
//				}
//				array[arrayloc] = (film*) malloc(sizeof(film));
//				array[arrayloc] = filmcpy(x, array[arrayloc]);
//				free(x);
//				arrayloc++;
//				assignto=0;
//			}
//			
//			
//			val=strtok_fix(NULL,",");	//move on to next token
//
//		
//		}
//	
//	
//	}//done reading file
//	array = mergesort(array, arrayloc, sortby);
//	//printf("done!\n");
//	int b;
//	for(b=0; b<arrayloc; b++){
//		printf("%s,%s,%d,%d,%d,%d,%s,%d,%d,%s,%s,%s,%d,%d,%s,%d,%s,%s,%d,%s,%s,%s,%d,%d,%d,%f,%f,%d\n",array[b]->color,array[b]->director_name,array[b]->num_critic_for_reviews,array[b]->duration,array[b]->director_facebook_likes,array[b]->actor_3_facebook_likes,array[b]->actor_2_name,array[b]->actor_1_facebook_likes,array[b]->gross,array[b]->genres,array[b]->actor_1_name,array[b]->movie_title,array[b]->num_voted_users,array[b]->cast_total_facebook_likes,array[b]->actor_3_name,array[b]->facenumber_in_poster,array[b]->plot_keywords,array[b]->movie_imdb_link,array[b]->num_user_for_reviews,array[b]->language,array[b]->country,array[b]->content_rating,array[b]->budget,array[b]->title_year,array[b]->actor_2_facebook_likes,array[b]->imdb_score,array[b]->aspect_ratio,array[b]->movie_facebook_likes);
//	}
//	//print the sorted stuff
//	
//	return 0;
//}
//
//
//char* strtok_fix (char* str, char const * delim){
//	static char * src=NULL;
//	char*p=0;
//	char*ret=0;
//	
//	if(str!=NULL){
//			src=str;
//	}
//	
//	if(src==NULL){
//			return NULL;
//	}
//	
//	if((p=strpbrk(src,delim))!=NULL){
//			*p=0;
//			ret=src;
//			src=++p;
//	}else if (*src){
//			ret=src;
//			src=NULL;
//	}
//	
//	return ret;

