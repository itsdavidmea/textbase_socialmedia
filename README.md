# Text-Based Social Media Platform

This project is a text-based implementation of a social media platform inspired by Facebook, created as part of the **SYSC 2006: Foundations of Imperative Programming** course. The project emphasizes the use of **C programming** concepts, including structures, memory allocation, linked lists, and stacks.

## Features

### Core Functionalities:
1. **User Registration**:
   - Register new users with unique usernames (case-insensitive).
   - Password validation ensures a minimum length of 8 characters.

2. **Profile Management**:
   - Update user passwords by verifying old credentials.

3. **Friends Management**:
   - Add or remove friends for a user profile.
   - Maintain friends as a sorted linked list in ascending order.

4. **Post Management**:
   - Add or remove posts for a user.
   - Posts are managed as a stack, with the most recent post displayed first.

5. **View Posts**:
   - Display posts from a specific user or a user's friends.

6. **Login System** (Enhanced in Bonus Assignment):
   - Validate username and password combinations.
   - Show personalized menus after login.

### Bonus Features:
- **Database Search for Friends**:
  - Users can only add registered users as friends.
  - Invalid friend additions display appropriate error messages.

- **Improved Menu System**:
  - Enhanced user experience with a more intuitive menu flow.

- **Pointer-to-Pointer Structures**:
  - Friend structures link directly to their posts for better data connectivity.

## Project Structure

- **`main.c`**: Contains the main application logic and menu systems.
- **`a2_functions.c`**: Includes all core functions for user, post, and friend management.
- **`a2_functions.h`**: Header file declaring all the functions used in the project.
- **`a2_nodes.h`**: Defines data structures for users, friends, and posts.

## How to Run

### Compilation
Ensure you have GCC installed. Use the following commands to compile the project:

```bash
gcc -g *.c -o SocialMediaApp
./SocialMediaApp
```

### Navigation
1. Launch the program.
2. Use the menu to register users, manage profiles, and interact with posts and friends.

## Concepts Covered

- **Data Structures**: Linked lists, stacks, and pointer-to-pointer operations.
- **Memory Management**: Dynamic memory allocation using `malloc` and `free`.
- **String Manipulation**: Username and password handling, including case sensitivity and validation.
- **Modular Programming**: Separation of concerns across multiple files.

## Future Enhancements

- Implement a file-based database for persistent data storage.
- Add functionality for exporting posts and user details to a file.
- Enhance UI for better user experience.

## Author

- **David Mea Andjou**  
  - Email: mea.david29@outlook.com  
  - GitHub: [itsdavidmea](https://github.com/itsdavidmea)

## License

This project is for educational purposes and adheres to academic integrity policies. Plagiarism or unauthorized sharing of code will result in disciplinary action.

---
