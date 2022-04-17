#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

struct Person {
    char* first_name;
    char* last_name;
    int age;
};

struct Cell {
    struct Person* person;
};

void free_cells(struct Cell*** cells) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            free( *(*( cells + i ) + j) );
        }
        free(*(cells + i));
    }
    free(cells);
}

int main() {

    struct Cell*** twoD_cells = malloc(sizeof(struct Cell**) * ROWS);

    // memory allocation for cells
    for (int i = 0; i < ROWS; i++) {
        *(twoD_cells + i) = malloc(sizeof(struct Cell*) * COLS);
        for (int j = 0; j < COLS; j++) {
            *(*(twoD_cells + i) + j) = malloc(sizeof(struct Cell));
            struct Cell* cell = *(*(twoD_cells + i) + j );
            cell->person = NULL;
        }
    }

    // index in the cells
    int i = 5;
    int j = 5;

    // adding a person inside the grid
    struct Cell* cell = *(*(twoD_cells + i) + j);
    cell->person = malloc(sizeof(struct Person));
    cell->person->first_name = "Gregory";
    cell->person->last_name  = "Maldonado";
    cell->person->age = 21;

    printf("Person's First Name:\t %s\n", cell->person->first_name);
    printf("Person's Last Name:\t\t %s\n", cell->person->last_name);
    printf("Person's Age:\t\t\t %d\n", cell->person->age);
    printf("Person's Memory Loc:\t %p\n", cell->person);

    free_cells(twoD_cells);
    return 0;
}


