# CS 210 Project Three: Corner Grocer

## Project Summary

The Corner Grocer project is a C++ program designed to help a grocery store analyze how often items were purchased. The program reads item names from an input file, counts the frequency of each item, and allows the user to view the data in different ways through a menu. The user can search for a specific item, print all item frequencies, display a histogram using asterisks, or exit the program.

The problem this project solved was helping Corner Grocer better understand purchasing patterns. Instead of manually counting items from a file, the program automates the process and presents the results in a simple format.

## What I Did Well

One thing I did well was organizing the program into a class called `InventoryTracker`. This helped keep the code cleaner because the file reading, frequency counting, backup file creation, menu display, and user choices were separated into different functions. I also used a `map` to store each grocery item with its frequency, which made the program more efficient and easier to manage.

I also think I did well with readability. The program uses clear function names, comments, and a menu that is easy for the user to understand.

## Where I Could Enhance My Code

One area where I could improve the program is by making the item search more flexible. Right now, the user has to type the item name in the same format as the input file. In the future, I could improve this by allowing searches that are not case-sensitive.

I could also improve error handling. For example, if the input file is missing or empty, the program currently displays an error message, but I could add more detailed feedback or prevent the menu from continuing without valid data. These changes would make the program more secure, reliable, and user-friendly.

## Most Challenging Part

The most challenging part of this project was organizing the file input and frequency counting in a way that worked smoothly with the menu. I had to make sure the program read the input file correctly, stored each item count, and then reused that data for different menu options.

I overcame this by breaking the program into smaller functions and testing each feature step by step. Using class functions helped me focus on one part of the program at a time instead of trying to manage everything in `main()`.

## Transferable Skills

The skills from this project that will transfer to other projects include reading from files, writing to files, using maps to store data, validating user input, and organizing code into classes and functions. These are useful skills because many programs need to process outside data, store information efficiently, and present results clearly to the user.

This project also helped me practice writing code that is easier to maintain, which is important for future coursework and professional software development.

## Maintainability, Readability, and Adaptability

I made this program maintainable by separating the code into smaller functions with specific responsibilities. For example, one function loads the input file, another creates the backup file, and other functions handle menu options and output. This makes the code easier to update later because changes can be made to one section without affecting the entire program.

I made the code readable by using clear names such as `LoadInputFile`, `CreateBackupFile`, `PrintHistogram`, and `GetItemFrequency`. I also included comments to explain the purpose of important sections.

The program is adaptable because the input file can be changed, and the program will still count whatever items are listed in the file. The menu structure also makes it possible to add more features in the future, such as sorting items by frequency or exporting a more detailed report.


