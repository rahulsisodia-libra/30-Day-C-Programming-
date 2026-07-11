// Write a program to Create inventory management system.


#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LEN  50

typedef struct {
    int    id;
    char   name[NAME_LEN];
    int    quantity;
    double price;
} Item;

/* ── storage ── */
static Item  inventory[MAX_ITEMS];
static int   item_count = 0;

/* ── helpers ── */
static int find_by_id(int id) {
    for (int i = 0; i < item_count; i++)
        if (inventory[i].id == id) return i;
    return -1;
}

static int next_id(void) {
    int max = 0;
    for (int i = 0; i < item_count; i++)
        if (inventory[i].id > max) max = inventory[i].id;
    return max + 1;
}

/* ── CRUD operations ── */
static void add_item(void) {
    if (item_count >= MAX_ITEMS) {
        printf("Inventory full.\n");
        return;
    }
    Item it;
    it.id = next_id();

    printf("Enter item name    : ");
    scanf(" %49[^\n]", it.name);
    printf("Enter quantity     : ");
    scanf("%d", &it.quantity);
    printf("Enter price        : ");
    scanf("%lf", &it.price);

    if (it.quantity < 0 || it.price < 0) {
        printf("Quantity and price must be non-negative.\n");
        return;
    }

    inventory[item_count++] = it;
    printf("Item added with ID %d.\n", it.id);
}

static void view_items(void) {
    if (item_count == 0) {
        printf("No items in inventory.\n");
        return;
    }
    printf("\n%-6s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("%-6s %-30s %-10s %-10s\n", "------", "------------------------------",
           "----------", "----------");
    for (int i = 0; i < item_count; i++) {
        printf("%-6d %-30s %-10d $%-9.2f\n",
               inventory[i].id,
               inventory[i].name,
               inventory[i].quantity,
               inventory[i].price);
    }
    printf("\n");
}

static void update_item(void) {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    int idx = find_by_id(id);
    if (idx == -1) {
        printf("Item with ID %d not found.\n", id);
        return;
    }

    printf("New name (current: %s): ", inventory[idx].name);
    scanf(" %49[^\n]", inventory[idx].name);

    printf("New quantity (current: %d): ", inventory[idx].quantity);
    scanf("%d", &inventory[idx].quantity);

    printf("New price (current: %.2f): ", inventory[idx].price);
    scanf("%lf", &inventory[idx].price);

    if (inventory[idx].quantity < 0 || inventory[idx].price < 0) {
        printf("Quantity and price must be non-negative.\n");
        return;
    }

    printf("Item ID %d updated.\n", id);
}

static void delete_item(void) {
    int id;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);

    int idx = find_by_id(id);
    if (idx == -1) {
        printf("Item with ID %d not found.\n", id);
        return;
    }

    /* Shift remaining items left */
    for (int i = idx; i < item_count - 1; i++)
        inventory[i] = inventory[i + 1];
    item_count--;

    printf("Item ID %d deleted.\n", id);
}

static void search_item(void) {
    char query[NAME_LEN];
    printf("Enter name to search: ");
    scanf(" %49[^\n]", query);

    int found = 0;
    printf("\n%-6s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("%-6s %-30s %-10s %-10s\n", "------", "------------------------------",
           "----------", "----------");
    for (int i = 0; i < item_count; i++) {
        if (strstr(inventory[i].name, query) != NULL) {
            printf("%-6d %-30s %-10d $%-9.2f\n",
                   inventory[i].id,
                   inventory[i].name,
                   inventory[i].quantity,
                   inventory[i].price);
            found++;
        }
    }
    if (!found) printf("No items matched '%s'.\n", query);
    printf("\n");
}

static void show_low_stock(void) {
    int threshold;
    printf("Enter low-stock threshold: ");
    scanf("%d", &threshold);

    int found = 0;
    printf("\nLow-stock items (quantity <= %d):\n", threshold);
    for (int i = 0; i < item_count; i++) {
        if (inventory[i].quantity <= threshold) {
            printf("  ID %-4d | %-30s | qty: %d\n",
                   inventory[i].id, inventory[i].name, inventory[i].quantity);
            found++;
        }
    }
    if (!found) printf("No items below threshold.\n");
    printf("\n");
}

/* ── persistence ── */
#define DATA_FILE "inventory.dat"

static void save_to_file(void) {
    FILE *fp = fopen(DATA_FILE, "wb");
    if (!fp) { perror("Cannot open file for writing"); return; }
    fwrite(&item_count, sizeof(int),  1,          fp);
    fwrite(inventory,   sizeof(Item), item_count, fp);
    fclose(fp);
    printf("Inventory saved to %s.\n", DATA_FILE);
}

static void load_from_file(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) { printf("No saved inventory found.\n"); return; }
    fread(&item_count, sizeof(int),  1,          fp);
    if (item_count > MAX_ITEMS) item_count = MAX_ITEMS;
    fread(inventory,   sizeof(Item), item_count, fp);
    fclose(fp);
    printf("Loaded %d item(s) from %s.\n", item_count, DATA_FILE);
}

/* ── menu ── */
static void print_menu(void) {
    printf("========== Inventory Management ==========\n");
    printf("  1. Add item\n");
    printf("  2. View all items\n");
    printf("  3. Update item\n");
    printf("  4. Delete item\n");
    printf("  5. Search item by name\n");
    printf("  6. Show low-stock items\n");
    printf("  7. Save inventory\n");
    printf("  8. Load inventory\n");
    printf("  0. Exit\n");
    printf("==========================================\n");
    printf("Choice: ");
}

int main(void) {
    load_from_file();   /* auto-load on start */

    int choice;
    do {
        print_menu();
        if (scanf("%d", &choice) != 1) { choice = -1; }

        switch (choice) {
            case 1: add_item();       break;
            case 2: view_items();     break;
            case 3: update_item();    break;
            case 4: delete_item();    break;
            case 5: search_item();    break;
            case 6: show_low_stock(); break;
            case 7: save_to_file();   break;
            case 8: load_from_file(); break;
            case 0: save_to_file(); printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
