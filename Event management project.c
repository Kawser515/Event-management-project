
#include <stdio.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_LOCATION_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char date[11]; // Format: YYYY-MM-DD
    char location[MAX_LOCATION_LENGTH];
    int capacity;
} Event;

Event events[MAX_EVENTS];
int eventCount = 0;

void addEvent() {
    if (eventCount >= MAX_EVENTS) {
        printf("Event list is full!\n");
        return;
    }
    Event newEvent;
    newEvent.id = eventCount + 1; // Auto-generate ID
    printf("Enter event name: ");
    getchar(); // Clear newline character from buffer
    fgets(newEvent.name, MAX_NAME_LENGTH, stdin);
    newEvent.name[strcspn(newEvent.name, "\n")] = '\0'; // Remove newline

    printf("Enter event date (YYYY-MM-DD): ");
    scanf("%s", newEvent.date);

    printf("Enter event location: ");
    getchar(); // Clear newline character from buffer
    fgets(newEvent.location, MAX_LOCATION_LENGTH, stdin);
    newEvent.location[strcspn(newEvent.location, "\n")] = '\0'; // Remove newline

    printf("Enter event capacity: ");
    scanf("%d", &newEvent.capacity);

    events[eventCount++] = newEvent;
    printf("Event added successfully with ID %d!\n", newEvent.id);
}

void viewEvents() {
    if (eventCount == 0) {
        printf("No events to display.\n");
        return;
    }
    printf("\nList of Events:\n");
    for (int i = 0; i < eventCount; i++) {
        printf("ID: %d, Name: %s, Date: %s, Location: %s, Capacity: %d\n",
               events[i].id, events[i].name, events[i].date, events[i].location, events[i].capacity);
    }
}

void searchEvent() {
    int id;
    printf("Enter event ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < eventCount; i++) {
        if (events[i].id == id) {
            printf("Event Found: ID: %d, Name: %s, Date: %s, Location: %s, Capacity: %d\n",
                   events[i].id, events[i].name, events[i].date, events[i].location, events[i].capacity);
            return;
        }
    }
    printf("Event with ID %d not found.\n", id);
}

void updateEvent() {
    int id;
    printf("Enter event ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < eventCount; i++) {
        if (events[i].id == id) {
            printf("Enter new event name: ");
            getchar(); // Clear newline character from buffer
            fgets(events[i].name, MAX_NAME_LENGTH, stdin);
            events[i].name[strcspn(events[i].name, "\n")] = '\0'; // Remove newline

            printf("Enter new event date (YYYY-MM-DD): ");
            scanf("%s", events[i].date);

            printf("Enter new event location: ");
            getchar(); // Clear newline character from buffer
            fgets(events[i].location, MAX_LOCATION_LENGTH, stdin);
            events[i].location[strcspn(events[i].location, "\n")] = '\0'; // Remove newline

            printf("Enter new event capacity: ");
            scanf("%d", &events[i].capacity);

            printf("Event updated successfully!\n");
            return;
        }
    }
    printf("Event with ID %d not found.\n", id);
}

void deleteEvent() {
    int id;
    printf("Enter event ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < eventCount; i++) {
        if (events[i].id == id) {
            for (int j = i; j < eventCount - 1; j++) {
                events[j] = events[j + 1];
            }
            eventCount--;
            printf("Event with ID %d deleted successfully!\n", id);
            return;
        }
    }
    printf("Event with ID %d not found.\n", id);
}

void showMenu() {
    printf("\nEvent Management System\n");
    printf("1. Add Event\n");
    printf("2. View Events\n");
    printf("3. Search Event\n");
    printf("4. Update Event\n");
    printf("5. Delete Event\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEvent();
                break;
            case 2:
                viewEvents();
                break;
            case 3:
                searchEvent();
                break;
            case 4:
                updateEvent();
                break;
            case 5:
                deleteEvent();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
