#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- FILENAMES ---
#define FILE_ENTRY "parked.txt"
#define FILE_EXIT "unparked.txt"

typedef struct {
    int id;
    int is_occupied;
    char plate[20];
    int age;
} Slot;

Slot *parking_lot = NULL;
int total_capacity = 0;
int current_count = 0;

// Helper to get current time
void get_time_string(char *buffer) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 30, "%Y-%m-%d %H:%M:%S", timeinfo);
}

void create_parking_lot(int size) {
    if (parking_lot != NULL) free(parking_lot);
    
    total_capacity = size;
    current_count = 0;
    parking_lot = (Slot *)malloc(sizeof(Slot) * size);

    for (int i = 0; i < size; i++) {
        parking_lot[i].id = i + 1;
        parking_lot[i].is_occupied = 0;
        parking_lot[i].age = 0;
        strcpy(parking_lot[i].plate, "");
    }
    printf(">> Created lot with %d slots.\n", size);
}

// --- NEW FUNCTION: Park in a specific slot ---
void park_vehicle_manual(char *plate, int age, int target_slot) {
    if (total_capacity == 0) {
        printf(">> Error: Create lot first!\n");
        return;
    }
    
    // Check if the slot number is valid (e.g. not 0 or 100)
    if (target_slot < 1 || target_slot > total_capacity) {
        printf(">> Error: Slot %d does not exist (Max is %d).\n", target_slot, total_capacity);
        return;
    }

    int idx = target_slot - 1; // Array index is slot - 1

    // Check if someone is already there
    if (parking_lot[idx].is_occupied == 1) {
        printf(">> Error: Slot %d is ALREADY OCCUPIED by %s.\n", target_slot, parking_lot[idx].plate);
        return;
    }

    // If we get here, the slot is free. Park the car!
    parking_lot[idx].is_occupied = 1;
    strcpy(parking_lot[idx].plate, plate);
    parking_lot[idx].age = age;
    current_count++;
    
    // Get Time
    char time_str[30];
    get_time_string(time_str);

    // WRITE TO FILE
    FILE *f = fopen(FILE_ENTRY, "a"); 
    if (f) {
        fprintf(f, "[%s] Parked: Slot %d | Plate: %s | Age: %d\n", 
                time_str, target_slot, plate, age);
        fclose(f);
    }
    
    printf(">> Success: Parked at Slot %d (Saved to %s)\n", target_slot, FILE_ENTRY);
}

void leave_slot(int slot_id) {
    int idx = slot_id - 1;
    if (idx < 0 || idx >= total_capacity || parking_lot[idx].is_occupied == 0) {
        printf(">> Error: Slot is invalid or empty.\n");
        return;
    }

    char time_str[30];
    get_time_string(time_str);

    // WRITE TO FILE
    FILE *f = fopen(FILE_EXIT, "a"); 
    if (f) {
        fprintf(f, "[%s] Left: Slot %d | Plate: %s | Age: %d\n", 
                time_str, slot_id, parking_lot[idx].plate, parking_lot[idx].age);
        fclose(f);
    }

    // Clear Memory
    parking_lot[idx].is_occupied = 0;
    strcpy(parking_lot[idx].plate, "");
    parking_lot[idx].age = 0;
    current_count--;
    
    printf(">> Success: Slot %d is free (Saved to %s)\n", slot_id, FILE_EXIT);
}

void status() {
    printf("\n--- LIVE STATUS ---\n");
    for (int i = 0; i < total_capacity; i++) {
        if (parking_lot[i].is_occupied) {
            printf("Slot %d: %s (Age: %d)\n", parking_lot[i].id, parking_lot[i].plate, parking_lot[i].age);
        } else {
            printf("Slot %d: [Available]\n", parking_lot[i].id);
        }
    }
    printf("-------------------\n");
}

int main() {
    char command[50];
    char plate[20];
    int val, age, slot;

    printf("\n=== MANUAL SLOT PARKING MANAGER ===\n");
    printf("Commands:\n");
    printf("  create <size>\n");
    printf("  park <plate> <age> <slot_id>\n");
    printf("  leave <slot_id>\n");
    printf("  status\n");
    printf("  exit\n");

    while (1) {
        printf("\nEnter command: ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            scanf("%d", &val);
            create_parking_lot(val);
        }
        else if (strcmp(command, "park") == 0) {
            // NOW WE SCAN 3 THINGS: Plate, Age, and Slot ID
            scanf("%s %d %d", plate, &age, &slot);
            park_vehicle_manual(plate, age, slot);
        }
        else if (strcmp(command, "leave") == 0) {
            scanf("%d", &val);
            leave_slot(val);
        }
        else if (strcmp(command, "status") == 0) {
            status();
        }
        else if (strcmp(command, "exit") == 0) {
            break; 
        }
    }
    return 0;
}