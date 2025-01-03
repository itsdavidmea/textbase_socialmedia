/********* functions.h ********
   Student Name 	= David Mea Andjou
   Student Number	= 101297581
*/

#include "a2_nodes.h"
#include <ctype.h>
#ifndef _A2_FUNCTIONS_H
#define _A2_FUNCTIONS_H

/********** DON'T MODIFY **********/
/*
   Function that creates a new user and adds it to a sorted (ascending order) linked list at
   the proper sorted location. Return the head of the list.
*/
user_t *add_user(user_t *users, const char *username, const char *password);

/*
   Function that searches if the user is available in the database 
   Return a pointer to the user if found and NULL if not found. test
*/
user_t *find_user(user_t *users, const char *username);


/*
   Function that searches if the user's friend exist in the database 
   Return a pointer to the user's friend if found and NULL if not found.
*/
friend_t *find_friend(user_t *user, const char *friend_username);

/*
   Function that creates a new friend's node.
   Return the newly created node.
*/
friend_t *create_friend(const char *username);


/*
   Function that links a friend to a user. The friend's name should be added into
   a sorted (ascending order) linked list.
*/
void add_friend(user_t *user, const char *friend);

/*
   Function that removes a friend from a user's friend list.
   Return true if the friend was deleted and false otherwise.
*/
_Bool delete_friend(user_t *user, char *friend_name);

/*
   Function that removes all friends from a user's friend list.
   Return true if all friends were deleted and false otherwise.
*/
_Bool delete_all_friend(user_t *user);

/*
   Function that creates a new user's post.
   Return the newly created post.
*/
post_t *create_post(const char *text);

/*
   Function that adds a post to a user's timeline following a stack.
*/
void add_post(user_t *user, const char *text);

/*
   Function that removes a post from a user's list of posts.
   Return true if the post was deleted and false otherwise.
*/
_Bool delete_post(user_t *user);

/*
   Function that removes all posts from a user's list of posts.
   Return true if all posts were deleted and false otherwise.
*/
_Bool delete_all_post(user_t *user);

/*
   Function that  displays a specific user's posts (All posts)
*/
void display_all_user_posts(user_t *user);

/*
   Function that  displays the first three posts of the user (All posts)
*/
void display_first_free(user_t *user);

/*
   Function that displays a specific user's friends (All friends)
*/
void display_user_friends(user_t *user);

/*
   Function that displays "number" of posts for a given user.
   After displaying "number" posts, it prompts if you want to display
   more posts.
   If there are no more post or the user types “n” or “N”, the function returns. 
*/
void display_posts_by_n(user_t *users, int number);

/*
   Function that free all users from the database before quitting the application.
*/
void teardown(user_t *users);

/*
   Function that prints the main menu with a list of options for the user to choose from
*/
void print_menu();



/* 
   ******** DONT MODIFY THIS FUNCTION ********
   Function that reads users from the text file.
   IMPORTANT: This function shouldn't be modified and used as is
   ******** DONT MODIFY THIS FUNCTION ********
*/
user_t *read_CSV_and_create_users(FILE *file, int num_users);

/* 
   check if sorted properly
*/
void display_all_users(user_t *user);

/********** DON'T MODIFY **********/

// Extra functions' Prototypes/Declarations go here

/*
   Function that prints the menu of the User's dashboard with a list of options for the user to choose from
*/
void print_user_UI(user_t *user);

/*
   This function lower all the characters of a string 
*/

void lowercase(char *string);


/*
   This function upper all the characters of a string 
*/

void uppercase(char *string);

/*
   Function that links a friend to a user using the new structure. The friend's name should be added into
   a sorted (ascending order) linked list.
*/
void add_friends(user_t *users, user_t *user, const char *friend);


/*
   Function that  displays a specific user's friend posts (All posts)
*/
void display_all_friends_posts(user_t *user, const char *friend_name);


/*
   Function that  connects the user's friend's posts to the friend's stack
*/
void connect_friends_posts (user_t *users);


#endif
