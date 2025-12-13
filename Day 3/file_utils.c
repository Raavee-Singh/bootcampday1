#include "warehouse.h"

// Helper: Remove extra spaces from the table format
void trim_whitespace(char *str) {
    if(!str) return;
    // Trim trailing
    int len = strlen(str);
    while(len > 0 && isspace(str[len-1])) str[--len] = '\0';
    // Trim leading (by moving memory)
    char *start = str;
    while(*start && isspace(*start)) start++;
    if(start != str) memmove(str, start, strlen(start) + 1);
}

void get_current_time_str(char *buffer) {
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    strftime(buffer, 30, "%Y-%m-%d %H:%M:%S", local);
}

void save_inventory_rewrite() {
    FILE *fp = fopen(INVENTORY_FILE, "w");
    if(!fp) { printf("Error: Cannot write to file.\n"); return; }
    
    // Header
    fprintf(fp, "%-5s | %-20s | %-15s | %-10s | %-8s | %-8s | %-25s\n", 
            "ID", "Name", "Category", "Price", "Qty", "Reorder", "Date Added");
    fprintf(fp, "----------------------------------------------------------------------------------------------------------------\n");

    for(int i=0; i<p_count; i++) {
        fprintf(fp, "%-5d | %-20s | %-15s | %-10.2f | %-8d | %-8d | %-25s\n", 
            products[i].id, products[i].name, products[i].category,
            products[i].price, products[i].quantity,
            products[i].reorder_level, products[i].date_added);
    }
    fclose(fp);
}

void append_sales_log(int id, char *name, int qty_sold, float revenue) {
    FILE *fp = fopen(SALES_FILE, "a");
    if(!fp) return;
    
    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0) {
        fprintf(fp, "%-25s | %-5s | %-20s | %-5s | %-10s\n", 
                "Sale Time", "ID", "Name", "Qty", "Revenue");
        fprintf(fp, "--------------------------------------------------------------------------\n");
    }

    char time_str[30];
    get_current_time_str(time_str);

    fprintf(fp, "%-25s | %-5d | %-20s | %-5d | %-10.2f\n", 
            time_str, id, name, qty_sold, revenue);
    fclose(fp);
}

// * FIXED LOAD FUNCTION using strtok *
void load_inventory() {
    FILE *fp = fopen(INVENTORY_FILE, "r");
    if (!fp) return;

    char line[256];
    p_count = 0;
    
    // Skip Header and Line
    fgets(line, sizeof(line), fp); 
    fgets(line, sizeof(line), fp); 

    while (fgets(line, sizeof(line), fp)) {
        if(p_count >= MAX_PRODUCTS) break;
        
        // Use strtok to split by pipe symbol '|'
        char *token;
        Product p;
        
        // 1. ID
        token = strtok(line, "|"); if(!token) continue;
        p.id = atoi(token);
        
        // 2. Name
        token = strtok(NULL, "|"); if(!token) continue;
        trim_whitespace(token);
        strcpy(p.name, token);

        // 3. Category
        token = strtok(NULL, "|"); if(!token) continue;
        trim_whitespace(token);
        strcpy(p.category, token);

        // 4. Price
        token = strtok(NULL, "|"); if(!token) continue;
        p.price = atof(token);

        // 5. Qty
        token = strtok(NULL, "|"); if(!token) continue;
        p.quantity = atoi(token);

        // 6. Reorder
        token = strtok(NULL, "|"); if(!token) continue;
        p.reorder_level = atoi(token);

        // 7. Date
        token = strtok(NULL, "|\n"); if(!token) continue;
        trim_whitespace(token);
        strcpy(p.date_added, token);

        products[p_count++] = p;
    }
    fclose(fp);
}