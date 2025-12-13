#include "warehouse.h"

int main() {
    load_inventory(); // Load data on startup

    int choice;
    while(1) {
        printf("\n=== WAREHOUSE SYSTEM ===\n");
        printf("1. Add Product\n");
        printf("2. Record Sale\n");
        printf("3. View Inventory\n");
        printf("4. Search Category\n");
        printf("5. Analytics\n");
        printf("6. Exit\n");
        printf("Select: ");
        
        // Validate integer input to prevent infinite loops on bad input
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch(choice) {
            case 1: add_product(); break;
            case 2: record_sale(); break;
            case 3: 
                printf("\n%-5s | %-15s | %-5s\n", "ID", "Name", "Qty");
                printf("-------------------------------\n");
                for(int i=0; i<p_count; i++)
                    printf("%-5d | %-15s | %-5d\n", products[i].id, products[i].name, products[i].quantity);
                break;
            case 4: {
                char cat[30];
                printf("Category: "); scanf("%29s", cat);
                search_category_recursive(0, cat);
                break;
            }
            case 5: generate_analytics(); break;
            case 6: printf("Bye!\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}