#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h> // Added for whitespace handling

// Config
#define MAX_PRODUCTS 100
#define INVENTORY_FILE "warehouse_inventory.txt"
#define SALES_FILE "sales_report.txt"

// Data Structure
typedef struct {
    int id;
    char name[50];
    char category[30];
    float price;
    int quantity;
    int reorder_level;
    char date_added[30];
} Product;

// Global Variables
extern Product products[MAX_PRODUCTS];
extern int p_count;

// Function Prototypes
void load_inventory();
void save_inventory_rewrite();
void append_sales_log(int id, char *name, int qty_sold, float revenue);
void add_product();
void record_sale();
void search_category_recursive(int index, const char *search_cat);
void generate_analytics();

#endif