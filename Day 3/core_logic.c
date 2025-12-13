#include "warehouse.h"

// Define storage here
Product products[MAX_PRODUCTS];
int p_count = 0;

void add_product() {
    if (p_count >= MAX_PRODUCTS) { printf("Error: Warehouse Full!\n"); return; }

    Product p;
    p.id = p_count + 101; 
    
    printf("\n--- Add Product ---\n");
    // Using %49s prevents buffer overflow
    printf("Name (No Spaces): "); scanf("%49s", p.name);
    printf("Category: "); scanf("%29s", p.category);
    printf("Price: "); scanf("%f", &p.price);
    printf("Quantity: "); scanf("%d", &p.quantity);
    printf("Reorder Level: "); scanf("%d", &p.reorder_level);

    // Get time from helper
    time_t now; time(&now);
    struct tm *local = localtime(&now);
    strftime(p.date_added, 30, "%Y-%m-%d %H:%M:%S", local);

    products[p_count++] = p;
    save_inventory_rewrite();
    printf(">> Added ID %d successfully.\n", p.id);
}

void record_sale() {
    int id, qty;
    printf("\n--- Record Sale ---\n");
    printf("Enter Product ID: "); 
    if(scanf("%d", &id) != 1) { printf("Invalid Input\n"); return; } // Input check

    int idx = -1;
    for(int i=0; i<p_count; i++) {
        if(products[i].id == id) { idx = i; break; }
    }

    if(idx == -1) { printf("Product Not Found!\n"); return; }

    printf("Product: %s | Current Stock: %d\n", products[idx].name, products[idx].quantity);
    printf("Qty to Sell: "); 
    scanf("%d", &qty);

    if (products[idx].quantity >= qty) {
        products[idx].quantity -= qty;
        float revenue = qty * products[idx].price;

        save_inventory_rewrite();
        append_sales_log(id, products[idx].name, qty, revenue);

        printf(">> Sale Recorded. Revenue: $%.2f\n", revenue);
        
        if(products[idx].quantity < products[idx].reorder_level) {
            printf("[ALERT] Low Stock! Please Reorder.\n");
        }
    } else {
        printf("Error: Insufficient Stock.\n");
    }
}

void search_category_recursive(int index, const char *search_cat) {
    if (index >= p_count) return;

    if (strcmp(products[index].category, search_cat) == 0) {
        printf("MATCH: ID %d | %s | Stock: %d\n", 
               products[index].id, products[index].name, products[index].quantity);
    }
    search_category_recursive(index + 1, search_cat);
}

void generate_analytics() {
    float total = 0;
    printf("\n--- Warehouse Value ---\n");
    for(int i=0; i<p_count; i++) {
        float val = products[i].quantity * products[i].price;
        total += val;
        printf("%-15s: $%.2f\n", products[i].name, val);
    }
    printf("---------------------\n");
    printf("Total Value    : $%.2f\n", total);
}