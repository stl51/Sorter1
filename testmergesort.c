#include <stdio.h>
#include <stdlib.h>
#include "Sorter.h"

int main(){
	film* test_array = (film*) malloc(sizeof(film)*3);
	test_array[0].color = "Color";
	test_array[0].director_name = "James Cameron";
	test_array[0].num_critic_for_reviews = 723;
	test_array[0].duration = 178;
	test_array[0].director_facebook_likes = 0;
	test_array[0].actor_3_facebook_likes = 855;
	test_array[0].actor_2_name = "Joel David Moore";
	test_array[0].actor_1_facebook_likes = 1000;
	test_array[0].gross = 760505847;
	test_array[0].genres = "Action|Adventure|Fantasy|Sci-Fi";
	test_array[0].actor_1_name = "CCH Pounder";
	test_array[0].movie_title = "Avatar";
	test_array[0].num_voted_users = 886204;
	test_array[0].cast_total_facebook_likes = 4834;
	test_array[0].actor_3_name = "Wes Studi";
	test_array[0].facenumber_in_poster = 0;
	test_array[0].plot_keywords = "avatar|future|marine|native|paraplegic";
	test_array[0].movie_imdb_link = "http://www.imdb.com/title/tt0499549/?ref_=fn_tt_tt_1";
	test_array[0].num_user_for_reviews = 3054;
	test_array[0].language = "English";
	test_array[0].country = "USA";
	test_array[0].content_rating = "PG-13";
	test_array[0].budget = 237000000;
	test_array[0].title_year = 2009;
	test_array[0].actor_2_facebook_likes = 936;
	test_array[0].imdb_score = 7.9;
	test_array[0].aspect_ratio = 1.78;
	test_array[0].movie_facebook_likes = 33000;
	
	test_array[1].color = "Color";
	test_array[1].director_name = "Gore Verbinski";
	test_array[1].num_critic_for_reviews = 302;
	test_array[1].duration = 169;
	test_array[1].director_facebook_likes = 563;
	test_array[1].actor_3_facebook_likes = 1000;
	test_array[1].actor_2_name = "Orlando Bloom";
	test_array[1].actor_1_facebook_likes = 40000;
	test_array[1].gross = 309404152;//
	test_array[1].genres = "Action|Adventure|Fantasy";
	test_array[1].actor_1_name = "Johnny Depp";
	test_array[1].movie_title = "Pirates of the Caribbean: At World's End ";
	test_array[1].num_voted_users = 471220;
	test_array[1].cast_total_facebook_likes = 48350;
	test_array[1].actor_3_name = "Jack Davenport";
	test_array[1].facenumber_in_poster = 0;
	test_array[1].plot_keywords = "goddess|marriage ceremony|marriage proposal|pirate|singapore";
	test_array[1].movie_imdb_link = "http://www.imdb.com/title/tt0449088/?ref_=fn_tt_tt_1";
	test_array[1].num_user_for_reviews = 1238;
	test_array[1].language = "English";
	test_array[1].country = "USA";
	test_array[1].content_rating = "PG-13";
	test_array[1].budget = 300000000;
	test_array[1].title_year = 2007;
	test_array[1].actor_2_facebook_likes = 5000;
	test_array[1].imdb_score = 7.1;
	test_array[1].aspect_ratio = 2.35;
	test_array[1].movie_facebook_likes = 0;
	
	test_array[2].color = NULL;
	test_array[2].director_name = NULL;
	test_array[2].num_critic_for_reviews = 302;
	test_array[2].duration = 169;
	test_array[2].director_facebook_likes = 563;
	test_array[2].actor_3_facebook_likes = 1000;
	test_array[2].actor_2_name = NULL;
	test_array[2].actor_1_facebook_likes = 40000;
	test_array[2].gross = 309404152;//
	test_array[2].genres = "Action|Adventure|Fantasy";
	test_array[2].actor_1_name = "Johnny Depp";
	test_array[2].movie_title = "Pirates of the Caribbean: At World's End ";
	test_array[2].num_voted_users = 471220;
	test_array[2].cast_total_facebook_likes = 48350;
	test_array[2].actor_3_name = "Jack Davenport";
	test_array[2].facenumber_in_poster = 0;
	test_array[2].plot_keywords = "goddess|marriage ceremony|marriage proposal|pirate|singapore";
	test_array[2].movie_imdb_link = "http://www.imdb.com/title/tt0449088/?ref_=fn_tt_tt_1";
	test_array[2].num_user_for_reviews = 1238;
	test_array[2].language = "English";
	test_array[2].country = "USA";
	test_array[2].content_rating = "PG-13";
	test_array[2].budget = 300000000;
	test_array[2].title_year = 2007;
	test_array[2].actor_2_facebook_likes = 5000;
	test_array[2].imdb_score = 7.1;
	test_array[2].aspect_ratio = 2.35;
	test_array[2].movie_facebook_likes = 0;
	
	
	
	test_array = mergesort(test_array, 3, 2);
	
	printf("done!\n");
	
	return 0;
}
