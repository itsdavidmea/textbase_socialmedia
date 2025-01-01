/********* main.c ********
    Student Name 	= David Mea Andjou
    Student Number	= 101297581
*/

// Includes go here
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "a2_nodes.h"
#include "a2_functions.h"

int main()
{
    FILE *csv_file = fopen("user_details.csv", "r");
    if (csv_file == NULL)
    {
        perror("Error opening the CSV file");
        return 1;
    }
    // Parse CSV data and create users
    user_t *users = read_CSV_and_create_users(csv_file, 50);

    fclose(csv_file);

    // Check user_choice
    bool run_app = true;
    connect_friends_posts(users);
    printf("\n\n*********************************************** \n");
    printf("           Welcome to Text-Based Facebook           \n");
    printf("*********************************************** \n");
    do
    {

        print_menu();
        printf("\n \nEnter a Choice:");
        int user_choice;
        scanf("%d", &user_choice);

        if (user_choice > 3 || user_choice < 1)
        {
            do
            {
                printf("Invalid Choice. Please try again");
                printf("\nEnter your choice again:");
                scanf("%d", &user_choice);
            } while (user_choice > 3 || user_choice < 1);
        }
        switch (user_choice)
        {
            const char username[30];
        case 1:

            const char password[15];
            printf("Enter a Username:");
            scanf("%s", username);

            char to_lowercase[15];
            strcpy(to_lowercase, username);
            lowercase(to_lowercase);

            char to_uppercase[15];
            strcpy(to_uppercase, username);
            uppercase(to_uppercase);

            user_t *check_lowercase = find_user(users, to_lowercase);
            user_t *check_uppercase = find_user(users, to_uppercase);

            if (check_lowercase != NULL || check_uppercase != NULL)
            {

                printf("\nUser already exist !");
                break;
            }
            else if (check_lowercase == NULL && check_uppercase == NULL)
            {
                printf("Enter an up to 15 characters password:");
                scanf("%s", password);
                if (strlen(password) > 15 || strlen(password) < 8)
                {
                    do
                    {
                        printf("Enter a password between 8 to 15 characters:");
                        scanf("%s", password);
                    } while (strlen(password) > 15 || strlen(password) < 8);
                }

                users = add_user(users, username, password);

                printf("\n**** User Added! ****");
                break;
            }

        case 2:
            printf("Enter your username:");
            scanf("%s", username);
            user_t *user = find_user(users, username);
            if (user == NULL)
            {
                printf("\n****User Not found****\n");
                break;
            }
            else if (strcmp(user->username, username) == 0)
            {
                printf("Enter your password: ");
                scanf("%s", password);
                if (strcmp(user->password, password) == 0)
                {
                    bool run_user_UI = true;
                
            
                    do
                    {
                        print_user_UI(user);
                        int user_choice2;
                        printf("\n \nEnter a Choice:");
                        scanf("%d", &user_choice2);

                        if (user_choice2 > 5 || user_choice2 < 1)
                        {
                            do
                            {
                                printf("Invalid Choice. Please try again");
                                printf("\nEnter your choice again:");
                                scanf("%d", &user_choice2);
                            } while (user_choice2 > 5 || user_choice2 < 1);
                        }

                        switch (user_choice2)
                        {
                        case 1:

                            char old_password[15];
                            char new_password[15];

                            printf("Enter your old password:");
                            scanf("%s", old_password);

                            if (strcmp(old_password, user->password) == 0)
                            {
                                printf("Enter a new password: ");
                                scanf("%s", new_password);

                                if ((strcmp(new_password, old_password) == 0) || (strlen(new_password) > 15 || strlen(new_password) < 8))
                                {
                                    do
                                    {
                                        if ((strcmp(new_password, old_password) == 0))
                                        {
                                            do
                                            {
                                                printf("Enter a different password than the previous one:");
                                                scanf("%s", new_password);
                                            } while (strcmp(new_password, old_password) == 0);
                                        }

                                        if (strlen(new_password) > 15 || strlen(new_password) < 8)
                                        {
                                            do
                                            {
                                                printf("Enter a password between 8 to 15 characters:");
                                                scanf("%s", new_password);
                                            } while (strlen(new_password) > 15 || strlen(new_password) < 8);
                                        }

                                    } while ((strcmp(new_password, old_password) == 0) || (strlen(new_password) > 15 || strlen(new_password) < 8));
                                }

                                strcpy(user->password, new_password);

                                printf("\n\nPassword changed sucessfully !! :)");
                                break;
                            }
                            else if (strcmp(old_password, user->password) != 0)
                            {
                                printf("\nWrong password !");
                                break;
                            }

                        case 2:

                            int user_choice_post;
                            bool run_post_menu = true;
                            printf("\n--------------------------------------\n");
                            printf("             Managing %s's posts            ", user->username);
                            printf("\n--------------------------------------\n");
                            display_all_user_posts(user);
                            printf("\n \n1. Add a new post\n");
                            printf("2. Remove a post\n");
                            printf("3. Return to main menu\n");
                            printf("Your choice:");
                            scanf("%d", &user_choice_post);

                            switch (user_choice_post)
                            {
                            case 1:
                                char post[250];
                                printf("Enter your post content:");
                                scanf(" %[^\n]s", post);
                                add_post(user, post);

                                break;

                            case 2:
                                delete_post(user);

                                break;

                            case 3:
                                
                                break;
                            }

                            // other display
                            if (user_choice_post == 3)
                            {
                                run_post_menu = false;
                                break;
                            }
                            
                            do
                            {
                                printf("\n--------------------------------------\n");
                                printf("                 %s's posts            \n", user->username);
                                // Diplaying newly created post
                                display_all_user_posts(user);
                                printf("\n--------------------------------------\n");

                                printf("\n1. Add a new post\n");
                                printf("2. Remove a post\n");
                                printf("3. Return to main menu\n");
                                printf("Your choice:");
                                scanf("%d", &user_choice_post);

                                switch (user_choice_post)
                                {
                                case 1:
                                    char post[250];
                                    printf("Enter your post content:");
                                    scanf(" %[^\n]s", post);
                                    add_post(user, post);

                                    // add the post to the user

                                    break;

                                case 2:

                                    delete_post(user);

                                    break;

                                case 3:
                                    run_post_menu = false;
                                    break;
                                }
                                
                            } while (run_post_menu);
                            break;
                        case 3:
                            int user_choice_friend;

                            bool run_friend_menu = true;
                            do
                            {
                                printf("\n--------------------------------------\n");
                                printf("             Managing %s's friends            ", user->username);
                                printf("\n--------------------------------------\n");
                                printf("\n \n1. Add a new friend\n");
                                printf("2. Remove a friend\n");
                                printf("3. Return to main menu\n");
                                printf("Your choice:");
                                scanf("%d", &user_choice_friend);

                                switch (user_choice_friend)
                                {
                                case 1:
                                    const char friend[30];
                                    printf("Enter your friend's name:");
                                    scanf("%s", friend);
                                    user_t *check_friend = find_user(users, friend);
                                    if (check_friend == NULL)
                                    {

                                        printf("\n****This User does not exist !****\n");
                                        break;
                                    }
                                    else
                                    {

                                        add_friends(users, user, friend);
                                        printf("\n****Friend Added !****\n");
                                        break;
                                    }
                                    break;
                                case 2:
                                    printf("\nList of %s's friends", user->username);
                                    display_user_friends(user);
                                    char friend_to_delete[30];
                                    printf("\nEnter a friend's name to delete:");
                                    scanf("%s", friend_to_delete);
                                    if (find_friend(user, friend_to_delete) == NULL)
                                    {
                                        printf("\n Invalid friend's name");
                                        run_friend_menu = false;
                                        break;
                                    }
                                    else
                                    {
                                        delete_friend(user, friend_to_delete);
                                        printf("\nUpdated list of %s's friends", user->username);
                                        display_user_friends(user);
                                        break;
                                    }
                                    break;
                                case 3:
                                    run_friend_menu = false;
                                    break;
                                }

                            } while (run_friend_menu);
                            break;
                        case 4:
                            
                            
                            char friend_name[30];
                            printf("Enter your friend's name: ");
                            scanf("%s", friend_name);
                            display_all_friends_posts(user, friend_name);
                            break;

                        case 5:
                            run_app = true;
                            run_user_UI = false;
                            break;
                            
                            
                        }

                    } while (run_user_UI);
                }
                else
                {
                    printf("Invalid password");
                    break;
                }
            }
            break;

        case 3:

            teardown(users);
            printf("\n \n Goodbye :)\n \n \n \n");

            run_app = false;
            break;
        }
    } while (run_app);
}
