/*****************
    Student Name 	= David Mea Andjou
    Student Number	= 101297581
*/

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include "a2_nodes.h"
#include "a2_functions.h"

// Your solution goes here

/*
   ******** DONT MODIFY THIS FUNCTION ********
   Function that reads users from the text file.
   IMPORTANT: This function shouldn't be modified and used as is
   ******** DONT MODIFY THIS FUNCTION ********
*/
user_t *read_CSV_and_create_users(FILE *file, int num_users)
{
    srand(time(NULL));
    user_t *users = NULL;
    char buffer[500];
    fgets(buffer, sizeof(buffer), file); // Read and discard the header line
    int count = 0;
    for (int i = 0; i < num_users; i++)
    {
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\r\n")] = 0; // Remove newline characters

        char *token = strtok(buffer, ",");
        char *token2 = strtok(NULL, ",");
        users = add_user(users, token, token2);
        char *username = token;

        token = strtok(NULL, ",");

        user_t *current_user = users;
        for (; current_user != NULL && strcmp(current_user->username, username) != 0; current_user = current_user->next)
            ;

        while (token != NULL && strcmp(token, ",") != 0 && count < 3)
        {
            if (strcmp(token, " ") != 0)
            {
                add_friend(current_user, token);
            }
            token = strtok(NULL, ",");
            count++;
        }
        count = 0;

        // token = strtok(NULL, ",");
        while (token != NULL && strcmp(token, ",") != 0)
        {
            add_post(current_user, token);
            token = strtok(NULL, ",");
        }
    }
    return users;
}

user_t *add_user(user_t *users, const char *username, const char *password)
{

    user_t *new_user = malloc(sizeof(user_t));
    assert(new_user != NULL);
    strcpy(new_user->username, username);
    strcpy(new_user->password, password);
    new_user->friends = NULL;
    new_user->posts = NULL;
    new_user->next = NULL;

    user_t *current_user, *previous_user;
    for (previous_user = NULL, current_user = users; current_user != NULL && strcmp(new_user->username, current_user->username) > 0; previous_user = current_user, current_user = current_user->next)
    {
    }

    new_user->next = current_user;
    if (previous_user == NULL)
    {
        users = new_user;
    }
    else
    {
        previous_user->next = new_user;
    }

    return users;
}

user_t *find_user(user_t *users, const char *username)
{

    user_t *current;
    for (current = users; current != NULL; current = current->next)
    {

        if (strcmp(current->username, username) == 0)
        {
            return current;
        }
    }
    return NULL;
}



/*
   Function that creates a new friend's node.
   Return the newly created node.
*/
friend_t *create_friend(const char *username)
{

    friend_t *new_friend = malloc(sizeof(friend_t));
    assert(new_friend != NULL);
    strcpy(new_friend->username, username);
    new_friend->next = NULL;
    return new_friend;
}

/*
   Function that links a friend to a user. The friend's name should be added into
   a sorted (ascending order) linked list.
*/
void add_friend(user_t *user, const char *friend)
{

    friend_t *friend_node = create_friend(friend);
   

    friend_t *current_friend, *previous;
    for (previous = NULL, current_friend = user->friends; current_friend != NULL && strcmp(friend_node->username, current_friend->username) > 0; previous = current_friend, current_friend = current_friend->next)
    {
    }

    friend_node->next = current_friend;
    if (previous == NULL)
    {
        user->friends = friend_node;
        
    }
    else
    {

        previous->next = friend_node;
    }
}

/*
   Function that removes a friend from a user's friend list.
   Return true of the friend was deleted and false otherwise.
*/
_Bool delete_friend(user_t *user, char *friend_name)
{

    if (user->friends == NULL)
    {
        return false;
    }
    else if (strcmp(user->friends->username, friend_name) == 0)
    {
        friend_t *delete = user->friends;
        user->friends = user->friends->next;
        free(delete);
        delete = NULL;
        return true;
    }

    friend_t *current, *previous;
    for (previous = NULL, current = user->friends; current != NULL && strcmp(current->username, friend_name) != 0; previous = current, current = current->next)
    {
        /* code */
    }

    friend_t *node_del = current;
    previous->next = current->next;
    current = current->next;
    free(node_del);
    node_del = NULL;
    return true;
}

/*
   Function that creates a new user's post.
   Return the newly created post.
*/
post_t *create_post(const char *text)
{

    post_t *new_post = malloc(sizeof(post_t));
    assert(new_post != NULL);
    strcpy(new_post->content, text);
    new_post->next = NULL;
    return new_post;
}

/*
   Function that adds a post to a user's timeline following a stack.
*/
void add_post(user_t *user, const char *text)
{

    assert(user != NULL);
    post_t *post_node = create_post(text);
    if (user->posts == NULL)
    {
        user->posts = post_node;
    }
    else if (user->posts != NULL)
    {
        post_node->next = user->posts;
        user->posts = post_node;
    }
}

/*
   Function that removes a post from a user's list of posts.
   Return true if the post was deleted and false otherwise.
*/
_Bool delete_post(user_t *user)
{

    if (user->posts == NULL)
    {
        printf("\n There is nothing to delete");
        return false;
    }

    post_t *post_to_delete = user->posts;
    user->posts = user->posts->next;
    free(post_to_delete);
    post_to_delete = NULL;
    return true;
}

/*
   Function that  displays a specific user's posts (All posts)
*/
void display_all_user_posts(user_t *user)
{

    int count = 0;
    post_t *current_post;
    for (current_post = user->posts; current_post != NULL; current_post = current_post->next)
    {
        count += 1;

        printf("\n %d - % s ", count, current_post->content);
    }

    if (count == 0)
    {
        printf("\n Note: No post available for %s", user->username);
    }
}


/*
   Function that  displays a specific user's posts (All posts)
*/
void display_first_three(user_t *user)
{

    int count = 0;
    post_t *current_post;
    for (current_post = user->posts; current_post != NULL && count < 4; current_post = current_post->next)
    {
        count += 1;

        printf("\n %d - % s ", count, current_post->content);
    }

    if (count == 0)
    {
        printf("\n Note: No post available for %s", user->username);
    }
}

/*
   Function that displays a specific user's friends (All friends)
*/
void display_user_friends(user_t *user)
{
    int count = 0;
    friend_t *current_friend;
    for (current_friend = user->friends; current_friend != NULL; current_friend = current_friend->next)
    {
        count += 1;

        printf("\n %d - % s ", count, current_friend->username);
    }

    if (count == 0)
    {
        printf("\n No friends for %s", user->username);
    }
}

/*
   Function that displays "number" of posts for a given user.
   After displaying "number" posts, it prompts if you want to display
   more posts.
   If there are no more post or the user types “n” or “N”, the function returns.
*/
void display_posts_by_n(user_t *user, int number)
{
    int count = 0;
    post_t *current_post;
    for (current_post = user->posts; current_post != NULL && count < number; current_post = current_post->next)
    {
        count += 1;

        printf("\n %d - % s ", count, current_post->content);
    }

    char user_display[2];
    bool run = true;
    while (current_post != NULL && run == true)
    {
        if (count % number == 0)
        {
            printf("\n would you like to display more post: ");
            scanf("%s", user_display);
            if (strcmp(user_display, "Y") == 0 || strcmp(user_display, "y") == 0)
            {
                run = true;
            }
            else if (strcmp(user_display, "N") == 0 || strcmp(user_display, "n") == 0)
            {
                run = false;
            }
        }

        count += 1;
        printf("\n %d - % s ", count, current_post->content);
        current_post = current_post->next;
    }

    if (current_post == NULL)
    {
        printf("\n \n All posts have been displayed");
    }
}

/*
   Function that free all users from the database before quitting the application.
*/
void teardown(user_t *users)
{
    user_t *current_user;
    for (current_user = users; current_user != NULL; current_user = current_user->next)
    {

        delete_all_friend(current_user);
        delete_all_post(current_user);
    }

    while (users != NULL)
    {
        user_t *delete_user = users;
        users = users->next;
        free(delete_user);
        delete_user = NULL;
    }
}

/*
   Function that prints the main menu with a list of options for the user to choose from
*/
void print_menu()
{

    printf("\n\n*********************************************** \n");
    printf("                 MAIN MENU                      \n");
    printf("*********************************************** \n");
    printf("1. Register a new user \n");
    printf("2. Login with existing user's information \n");
    printf("3. Exit \n");
   
}

void print_user_UI(user_t *user) {
    printf("\n\n*********************************************** \n");
    printf("                Welcome %s:                     \n", user->username);
    printf("*********************************************** \n");
    printf("1. Manage profile (change password) \n");
    printf("2. Manage posts (add/remove) \n");
    printf("3. Manage friends (add/remove) \n");
    printf("4. Display a friend's posts \n");
    printf("5. Exit \n");
}

// void display_all_users(user_t *users){

//     user_t *current_user;
//     for (current_user = users; current_user != NULL; current_user = current_user->next)
//     {

//         printf("%s ", current_user->username);

//     }

//      if (current_user == NULL)
//     {
//         printf("No users yet");
//     }

// }

friend_t *find_friend(user_t *user, const char *friend_username)
{
    friend_t *current;
    for (current = user->friends; current != NULL; current = current->next)
    {

        if (strcmp(current->username, friend_username) == 0)
        {
            return current;
        }
    }
    return NULL;
}

_Bool delete_all_post(user_t *user)
{

    if (user->posts == NULL)
    {
        return false;
    }

    while (user->posts != NULL)
    {

        post_t *post_to_delete = user->posts;
        user->posts = user->posts->next;
        free(post_to_delete);
        post_to_delete = NULL;
    }
    return true;
}

_Bool delete_all_friend(user_t *user)
{

    if (user->friends == NULL)
    {
        return false;
    }
    else
    {
        while (user->friends != NULL)
        {

            friend_t *delete = user->friends;
            user->friends = user->friends->next;
            free(delete);
            delete = NULL;
        }
        return true;
    }
}

/*
   This function lower all the characters of a string 
*/

void lowercase(char *string){

   
    for (int i = 0; i < strlen(string); i++)
    {
        string[i] = tolower(string[i]);
    }
    
    
}


/*
   This function upper all the characters of a string 
*/

void uppercase(char *string){

   
    for (int i = 0; i < strlen(string); i++)
    {
        string[i] = toupper(string[i]);
    }
    
    
}


void add_friends(user_t *users, user_t *user, const char *friend)
{

    friend_t *friend_node = create_friend(friend);
    user_t *friend_stack = find_user(users, friend); 
  
    
   

    friend_t *current_friend, *previous;
    for (previous = NULL, current_friend = user->friends; current_friend != NULL && strcmp(friend_node->username, current_friend->username) > 0; previous = current_friend, current_friend = current_friend->next)
    {
    }

    friend_node->next = current_friend;
    if (previous == NULL)
    {
        user->friends = friend_node;
        friend_node->posts = &(friend_stack->posts);
        
        
    }
    else
    {

        previous->next = friend_node;
        friend_node->posts = &(friend_stack->posts);
    }    
}

void display_all_friends_posts(user_t *user, const char *friend_name)
{
    
    friend_t *user_friend = find_friend(user, friend_name);
    int count = 0;
    post_t *current_friend = *((*user_friend).posts);

    printf("\n--------------------------------------\n");
    printf("             Displaying %s's posts            ", friend_name);
    printf("\n--------------------------------------\n\n");
    for (current_friend = *((*user_friend).posts); current_friend != NULL; current_friend = current_friend->next)
    {
        count += 1;

        printf("\n %d - % s ", count, current_friend->content);
    }

    if (count == 0)
    {
        printf("\n Note: No pots for %s", user->friends);
    }
}

void connect_friends_posts (user_t *users) {

    user_t *current_user;
    friend_t *current_friend;
    for (current_user = users; current_user != NULL; current_user = current_user->next)
    {
        for (current_friend = current_user->friends; current_friend != NULL;  current_friend = current_friend->next)
        {
            user_t* friends_stack = find_user(users, current_friend->username);
            current_friend->posts = &(friends_stack->posts);
        }
        
    }
    

}