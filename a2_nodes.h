/********* nodes.h ********
    Student Name 	= David Mea Andjou
    Student Number	= 101297581
*/

/********** DON'T MODIFY **********/
// Structure to represent a linked list of users

#ifndef _A2_NODES_H
#define _A2_NODES_H

typedef struct user
{
    char username[30];
    char password[15];
    struct friend *friends;
    struct post *posts;
    struct user *next;
} user_t;

// Structure to represent a linked list of a user's friends
typedef struct friend
{
    char username[30]; 
    struct post **posts; 
    struct friend *next; 
}
friend_t;

// Structure to represent a linked list of a user's posts
typedef struct post
{
    char content[250];
    struct post *next;
} post_t;

#endif
