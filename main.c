#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int roll;
    int prn;
    char name[20];
    struct node *next;
};

// Add president (head)
struct node* create() {
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    printf("ENTER PRN NO, ROLL NO & NAME of PRESIDENT:\n");
    scanf("%d %d %s", &head->prn, &head->roll, head->name);
    head->next = NULL;
    return head;
}

// Add members after president
void add_member(struct node *head) {
    int count;
    struct node *temp, *q = head;

    printf("HOW MANY MEMBERS YOU WANT TO ADD?\n");
    scanf("%d", &count);

    // Move to last member or president
    while (q->next != NULL) {
        q = q->next;
    }

    for (int i = 0; i < count; i++) {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("ENTER PRN NO, ROLL NO & NAME of MEMBER %d:\n", i + 1);
        scanf("%d %d %s", &temp->prn, &temp->roll, temp->name);
        temp->next = NULL;
        q->next = temp;
        q = temp;
    }
}

// Add secretary at end
void add_secratary(struct node *head) {
    struct node *s = (struct node *)malloc(sizeof(struct node));
    printf("ENTER PRN NO, ROLL NO & NAME of SECRETARY:\n");
    scanf("%d %d %s", &s->prn, &s->roll, s->name);
    s->next = NULL;

    while (head->next != NULL) {
        head = head->next;
    }
    head->next = s;
}

// Delete president and return new head
struct node* delete_president(struct node *head) {
    if (head == NULL) return NULL;

    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("President deleted.\n");
    return head;
}

// Delete secretary (last node)
void delete_secratary(struct node *head) {
    if (head == NULL || head->next == NULL) {
        printf("Cannot delete secretary. List is empty or only president exists.\n");
        return;
    }

    struct node *prev = NULL;

    while (head->next != NULL) {
        prev = head;
        head = head->next;
    }

    free(head);
    prev->next = NULL;
    printf("Secretary deleted.\n");
}

// Delete member by PRN
void delete_member(struct node *head) {
    if (head == NULL || head->next == NULL) {
        printf("No members to delete.\n");
        return;
    }

    int target;
    printf("ENTER PRN NO OF MEMBER TO DELETE:\n");
    scanf("%d", &target);

    struct node *prev = head;
    struct node *curr = head->next;

    while (curr != NULL) {
        if (curr->prn == target) {
            prev->next = curr->next;
            free(curr);
            printf("Member with PRN %d deleted.\n", target);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Member with PRN %d not found.\n", target);
}

// Display club
void display(struct node *head) {
    if (head == NULL) {
        printf("\nClub is empty.\n");
        return;
    }

    printf("\n---- CLUB MEMBERS ----\n");
    struct node *temp = head;
    int count = 1;

    while (temp != NULL) {
        printf("\nMember %d:\n", count++);
        printf("ROLE    : ");
        if (temp == head)
            printf("President\n");
        else if (temp->next == NULL)
            printf("Secretary\n");
        else
            printf("Member\n");

        printf("PRN NO  : %d\n", temp->prn);
        printf("ROLL NO : %d\n", temp->roll);
        printf("NAME    : %s\n", temp->name);

        temp = temp->next;
    }
    printf("-----------------------\n");
}

int main() {
    int choice;
    struct node *head = NULL;

    do {
        printf("\n1) ADD PRESIDENT\n2) ADD MEMBERS\n3) ADD SECRETARY\n");
        printf("4) DELETE PRESIDENT\n5) DELETE SECRETARY\n6) DELETE MEMBER\n");
        printf("7) DISPLAY CLUB\n8) EXIT\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = create();  // HEAD IS PRESIDENT
                break;
            case 2:
                if (head == NULL)
                    printf("Please add president first.\n");
                else
                    add_member(head);
                break;
            case 3:
                if (head == NULL)
                    printf("Please add president first.\n");
                else
                    add_secratary(head);
                break;
            case 4:
                head = delete_president(head);
                break;
            case 5:
                delete_secratary(head);
                break;
            case 6:
                delete_member(head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}
