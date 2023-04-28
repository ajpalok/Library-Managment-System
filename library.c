// Library Management System: Create a program
// that allows users to manage a small library
// by adding, updating, or deleting books,
// authors, and borrowers. Use structures to
// store library data and a file to save and
// load the data.
//
//      gcc library.c -o 1 && .\1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/////////////////////
// Global variables
/////////////////////
char data[100]="";


////////////////////
// books structure
////////////////////
struct Book
{
    char title[100];
    char author[100];
    int quantity;
};
////////////////////////
// borrowers structure
////////////////////////

struct Borrower
{
    char name[100];
    char borrowedBookName[200];
    int borrowedBookCount;
};

struct Author
{
    char name[100];
    int bookCount;
};

// Function to clear console using ncurses library
void clearConsole() {
    if(system("cls")==0) system("cls");
    else system("clear");
}
///////////////////////
// functions prototype
///////////////////////

int checkFileExists(char *filename);
void MainMenuOptions();
void BookMenuOptions();
void BorrowerMenuOptions();
void AuthorMenuOptions();

//////////////////////////////
// books functions prototype
//////////////////////////////

void showBooks();
void addBook();
void updateBook();
void deleteBook();

///////////////////////////////
// borrower functions prototype
///////////////////////////////

void showBorrowers();
void addBorrower();
void updateBorrower();
void deleteBorrower();

////////////////
// Main Function
////////////////
int main()
{
    clearConsole();
    // loop for make user input to run until user input 0 to exit to main menu
    int mainChoice, bookMenuChoice, borrowerMenuChoice, authorMenuChoice;
    // int ;
    
    if (checkFileExists("books.txt") == 0 && checkFileExists("borrowers.txt") == 0 && checkFileExists("authors.txt") == 0){
        do{
            MainMenuOptions();
            scanf("%d", &mainChoice);
            getchar(); // consume the newline character left in the input buffer

            switch (mainChoice){
                // Exit
                case 0:
                    printf("Exiting...\n");
                    clearConsole();
                    break;
                // Book Menu
                case 1:
                    do{
                        BookMenuOptions();
                        scanf("%d", &bookMenuChoice);
                        getchar(); // consume the newline character left in the input buffer
                        switch (bookMenuChoice){
                            case 0:
                                puts("Going Back...");
                                clearConsole();
                                break;
                            case 1:
                                showBooks();
                                break;
                            case 2:
                                addBook();
                                break;
                            case 3:
                                updateBook();
                                break;
                            case 4:
                                deleteBook();
                                break;
                            default:
                                strcpy(data,"Invalid choice. Please try again.");
                                break;
                        }
                    } while (bookMenuChoice != 0);
                    break;
                case 2:
                    do{
                        BorrowerMenuOptions();
                        scanf("%d", &borrowerMenuChoice);
                        getchar(); // consume the newline character left in the input buffer
                        switch (borrowerMenuChoice){
                            case 0:
                                printf("Going Back...\n");
                                clearConsole();
                                break;
                            case 1:
                                showBorrowers();
                                break;
                            case 2:
                                addBorrower();
                                break;
                            case 3:
                                updateBorrower();
                                break;
                            case 4:
                                deleteBorrower();
                                break;
                            default:
                                strcpy(data,"Invalid choice. Please try again.");
                                break;
                        }
                    } while (borrowerMenuChoice != 0);
                    break;
                case 3:
                    do{
                        AuthorMenuOptions();
                        scanf("%d", &authorMenuChoice);
                        getchar(); // consume the newline character left in the input buffer
                        switch (authorMenuChoice){
                            case 0:
                                printf("Going Back...\n");
                                clearConsole();
                                break;
                            case 1:
                                // books(books, &bookCount);
                                break;
                            case 2:
                                // addBook(books, &bookCount);
                                break;
                            case 3:
                                // updateBook(books, bookCount);
                                break;
                            case 4:
                                // deleteBook(books, &bookCount);
                                break;
                            default:
                                strcpy(data,"Invalid choice. Please try again.");
                                break;
                        }
                    } while (authorMenuChoice != 0);
                    break;
                default:
                    strcpy(data,"Invalid choice. Please try again.");
                    break;
            }
        } while (mainChoice != 0);
    }
    return 0;
}

/////////////////////////////////////
// checks if file.txt exists or not
/////////////////////////////////////

int checkFileExists(char *filename)
{
    FILE *file;
    if ((file = fopen(filename, "r")))
    {
        fclose(file);
        return 0;
    }
    else
    {
        file = fopen(filename, "w");
        fclose(file);
        return 0;
    }
}

//////////////////////
// Main Menu Options
//////////////////////

void MainMenuOptions(){
    puts("=========================");
    puts("Library Management System");
    puts("=========================");
    puts("1. Books");
    puts("2. Borrowers");
    puts("3. Authors");
    puts("0. Exit");
    //  check if data not empty
    if (strcmp(data,"")!=0){
        puts(data);
        strcpy(data,"");
    }
    printf("Enter your choice: ");
}

//////////////////////
// Book Menu Options
//////////////////////

void BookMenuOptions(){
    clearConsole();
    printf("=============\n");
    printf("Books Section\n");
    printf("=============\n");
    printf("1. Show Books\n");
    printf("2. Add Book\n");
    printf("3. Update Book\n");
    printf("4. Delete Book\n");
    printf("0. Back\n");
    //  check if data not empty
    if (strcmp(data,"")!=0){
        puts(data);
        strcpy(data,"");
    }
    printf("Enter your choice: ");
}

//////////////////////////
// Borrower Menu Options
//////////////////////////

void BorrowerMenuOptions(){
    clearConsole();
    printf("=========\n");
    printf("Borrowers\n");
    printf("=========\n");
    printf("1. Show Borrowers\n");
    printf("2. Add Borrower\n");
    printf("3. Update Borrower\n");
    printf("4. Delete Borrower\n");
    printf("0. Back\n");
    //  check if data not empty
    if (strcmp(data,"")!=0){
        puts(data);
        strcpy(data,"");
    }
    printf("Enter your choice: ");
}

////////////////////////
// Author Menu Options
////////////////////////

void AuthorMenuOptions(){
    clearConsole();
    printf("=======\n");
    printf("Authors\n");
    printf("=======\n");
    printf("1. Show Authors\n");
    printf("2. Add Author\n");
    printf("3. Update Author\n");
    printf("4. Delete Author\n");
    printf("0. Back\n");
    //  check if data not empty
    if (strcmp(data,"")!=0){
        puts(data);
        strcpy(data,"");
    }
    printf("Enter your choice: ");
}

///////////////
// Show Books
///////////////

void showBooks(){
    clearConsole();
// add data from user input to struct of book and save it to books.txt
    int run = 1, count = 0;
    do{
        checkFileExists("books.txt");
        FILE *readfile;
        readfile = fopen("books.txt", "r");
        
        puts("======\nBooks:\n======");
        // puts("Title\t\tAuthor\t\tQuantity");
        char line[100];
        while (fgets(line, 100, readfile)){
            printf("%d.\n",++count);
            // printf("%s",line);
            char *info = strtok(line, ",");
            printf("\tTitle: %s\n", info);
            info = strtok(NULL, ",");
            printf("\tAuthor: %s\n", info);
            info = strtok(NULL, ",");
            printf("\tQuantity: %s\n\n", info);
        }
        fclose(readfile);
        count = 0;

        puts("\n\nEnter 0 to go back: ");
        scanf("%d", &run);
        getchar(); // consume the newline character left in the input buffer
        if (run != 0){
            clearConsole();
            puts("Invalid input. Please try again.\n");
        };
    } while (run != 0);
}

////////////
// Add Books
////////////

void addBook(){
    clearConsole();
    puts("==============\nAdd Book Data:\n==============");
    checkFileExists("books.txt");
    FILE *writefile;
    writefile = fopen("books.txt", "a");
    
    struct Book b1;

    printf("Title: ");
    fgets(b1.title, 100, stdin);
    b1.title[strcspn(b1.title, "\n")] = '\0'; // remove newline character from fgets

    printf("Author: ");
    fgets(b1.author, 100, stdin);
    b1.author[strcspn(b1.author, "\n")] = '\0'; // remove newline character from fgets

    printf("quantity: ");
    scanf("%d", &b1.quantity);
    getchar(); // consume the newline character left in the input buffer
    
    
    fprintf(writefile, "%s, %s, %d\n", b1.title, b1.author, b1.quantity);
    
    strcpy(data,"Book added successfully.");

    fclose(writefile);
}

///////////////
// Update Books
///////////////

void updateBook(){
    clearConsole();
    printf("=================\nUpdate Book Data:\n=================\n");
    checkFileExists("books.txt");
    checkFileExists("temp.txt");
    FILE *readfile, *writefile;
    readfile = fopen("books.txt", "r");
    writefile = fopen("temp.txt", "w");
    

    printf("Enter book name to update: ");
    char searchName[100];
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // remove the newline character from the search string

    char line[256], temp[256];
    char *pos;

    // search for the book name in the file
    int bookFound = 0;
    while(fgets(line, sizeof(line), readfile)){
        strcpy(temp, line);
        pos = strstr(line, searchName);
        if (pos != NULL && strtok(line, ",") != NULL && strcmp(strtok(line, ","), searchName) == 0){
            // update the book data
            struct Book b1;

            printf("Edit Book Title: ");
            fgets(b1.title, 100, stdin);
            b1.title[strcspn(b1.title, "\n")] = '\0'; // remove newline character from fgets

            printf("Edit Book Author: ");
            fgets(b1.author, 100, stdin);
            b1.author[strcspn(b1.author, "\n")] = '\0'; // remove newline character from fgets

            printf("Edit Book quantity: ");
            scanf("%d", &b1.quantity);
            getchar(); // consume the newline character left in the input buffer

            // write the updated book data to the temp file
            fprintf(writefile, "%s, %s, %d\n", b1.title, b1.author, b1.quantity);
            bookFound = 1;
        }
        else {
            // write the original book data to the temp file
            fprintf(writefile, "%s", temp);
        }
    }

    fclose(readfile);
    fclose(writefile);

    // replace the original file with the temp file
    if (bookFound) {
        remove("books.txt");
        rename("temp.txt", "books.txt");
        strcpy(data,"Book updated successfully.");
    }
    else {
        remove("temp.txt");
        strcpy(data,"Book not found.");
    }
}

//////////////
// Delete Book
//////////////

void deleteBook() {
    clearConsole();
    printf("=================\nDelete Book Data:\n=================\n");
    checkFileExists("books.txt");
    checkFileExists("temp.txt");
    FILE *readfile, *tempfile;
    readfile = fopen("books.txt", "r");
    tempfile = fopen("temp.txt", "w");


    printf("Enter book name to delete: ");
    char searchName[100];
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // remove the newline character from the search string

    char line[256], temp[256];
    char *pos;

    // copy all the lines except the one to delete to the temporary file
    while (fgets(line, sizeof(line), readfile)) {
        strcpy(temp, line);
        pos = strstr(line, searchName);
        if (pos == NULL && strtok(line, ",") != NULL || strcmp(strtok(line, ","), searchName) != 0){
            fprintf(tempfile, "%s", temp);
        }
    }

    fclose(readfile);
    fclose(tempfile);

    // delete the original file and rename the temporary file to the original file's name
    remove("books.txt");
    rename("temp.txt", "books.txt");

    strcpy(data,"Book deleted successfully.");
}


/////////////////
// Show Borrowers
/////////////////

void showBorrowers(){
    clearConsole();
// add data from user input to struct of Borrower and save it to borrowers.txt
    int run = 1, serial = 0;
    do{
        FILE *readfile;
        readfile = fopen("borrowers.txt", "r");
        if (readfile == NULL) {
        printf("Error opening file.\n");
        return;
    }
        puts("==========\nBorrowers:\n==========");
        // puts("Title\t\tAuthor\t\tQuantity");
        char line[100];
        while (fgets(line, 100, readfile)){
            printf("%d.\n",++serial);
            // printf("%s",line);
            char *info = strtok(line, ",");
            printf("\tName: %s\n", info);
            info = strtok(NULL, ",");
            printf("\tQuantity: %s\n\n", info);
        }
        fclose(readfile);
        serial = 0;

        puts("\n\nEnter 0 to go back: ");
        scanf("%d", &run);
        getchar(); // consume the newline character left in the input buffer
        if (run != 0){
            clearConsole();
            puts("Invalid input. Please try again.\n");
        };
    } while (run != 0);
}

////////////////
// Add Borrowers
////////////////
void addBorrower(){
    clearConsole();
    puts("==================\nAdd Borrower Data:\n==================");
    FILE *writefile;
    writefile = fopen("borrowers.txt", "a");
    
    struct Borrower b1;

    printf("Name: ");
    fgets(b1.name, 100, stdin);
    b1.name[strcspn(b1.name, "\n")] = '\0'; // remove newline character from fgets


    // printf("Author: ");
    // fgets(b1.author, 100, stdin);
    // b1.author[strcspn(b1.author, "\n")] = '\0'; // remove newline character from fgets

    printf("Total: ");
    scanf("%d", &b1.borrowedBookCount);
    getchar(); // consume the newline character left in the input buffer
    
    
    fprintf(writefile, "%s, %d\n", b1.name, b1.borrowedBookCount);
    
    strcpy(data,"Borrower added successfully.");

    fclose(writefile);
}

///////////////////
// Update Borrowers
///////////////////

void updateBorrower(){
    clearConsole();
    printf("=====================\nUpdate Borrower Data:\n=====================\n");
    FILE *readfile, *writefile;
    readfile = fopen("borrowers.txt", "r");
    writefile = fopen("temp.txt", "w");
    checkFileExists("borrowers.txt");
    checkFileExists("temp.txt");

    printf("Enter Borrower name to update: ");
    char searchName[100];
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // remove the newline character from the search string

    char line[256], temp[256];
    char *pos;

    // search for the Borrower name in the file
    int BorrowerFound = 0;
    while(fgets(line, sizeof(line), readfile)){
        strcpy(temp, line);
        pos = strstr(line, searchName);
        if (pos != NULL && strtok(line, ",") != NULL && strcmp(strtok(line, ","), searchName) == 0){
            // update the Borrower data
            struct Borrower b1;

            printf("Edit Borrower Title: ");
            fgets(b1.name, 100, stdin);
            b1.name[strcspn(b1.name, "\n")] = '\0'; // remove newline character from fgets

            // printf("Edit Borrower Author: ");
            // fgets(b1.author, 100, stdin);
            // b1.author[strcspn(b1.author, "\n")] = '\0'; // remove newline character from fgets

            printf("Edit Borrower quantity: ");
            scanf("%d", &b1.borrowedBookCount);
            getchar(); // consume the newline character left in the input buffer

            // write the updated Borrower data to the temp file
            fprintf(writefile, "%s, %d\n", b1.name, b1.borrowedBookCount);
            BorrowerFound = 1;
        }
        else {
            // write the original Borrower data to the temp file
            fprintf(writefile, "%s", temp);
        }
    }

    fclose(readfile);
    fclose(writefile);

    // replace the original file with the temp file
    if (BorrowerFound) {
        remove("borrowers.txt");
        rename("temp.txt", "borrowers.txt");
        strcpy(data,"Borrower updated successfully.");
    }
    else {
        remove("temp.txt");
        printf("Borrower not found.\n");
    }
    
    strcpy(data,"Borrower updated successfully.");
}

//////////////////
// Delete Borrower
//////////////////

void deleteBorrower() {
    clearConsole();
    printf("=================\nDelete Borrower Data:\n=================\n");
    FILE *readfile, *tempfile;
    readfile = fopen("borrowers.txt", "r");
    tempfile = fopen("temp.txt", "w");
    if (readfile == NULL || tempfile == NULL) {
        printf("Error opening file.\n");
        return;
    }


    printf("Enter Borrower name to delete: ");
    char searchName[100];
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // remove the newline character from the search string

    char line[256], temp[256];
    char *pos;

    // copy all the lines except the one to delete to the temporary file
    while (fgets(line, sizeof(line), readfile)) {
        strcpy(temp, line);
        pos = strstr(line, searchName);
        if (pos == NULL && strtok(line, ",") != NULL || strcmp(strtok(line, ","), searchName) != 0){
            fprintf(tempfile, "%s", temp);
        }
    }

    fclose(readfile);
    fclose(tempfile);

    // delete the original file and rename the temporary file to the original file's name
    remove("borrowers.txt");
    rename("temp.txt", "borrowers.txt");

    strcpy(data,"Borrower deleted successfully.");
}
/**/