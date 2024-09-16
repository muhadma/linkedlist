#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node *link;
};

//count how many nodes in the linked list
int count_of_nodes(struct node *head) {
    int count = 0;
    if (head == NULL) {
        cout << "Linked List is empty";
    }
    struct node *p = NULL;
    p = head;
    while (p != NULL) {
        count++;
        p = p->link;
    }

    return count;
}

//this will insert a node at the last of the list
void insert_node_atend(struct node *head) {
    struct node *p = NULL;
    p = head;

    int data = 0;
    cout << "Enter data to be inserted: ";
    cin >> data;

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while (p->link != NULL) {
        p = p->link;
    }
    p->link = temp;
}

//insert node at the beginning
struct node* insert_atbeg(struct node *head) {
    int data = 0;
    cout << "Enter data to be inserted at the front? ";
    cin >> data;

    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->link = NULL;

    p->link = head;
    head = p;

    return head;
}

//insert at the a certain postion
void insert_atpos(struct node *head, int pos) {
    int data = 0;

    cout << "Enter data to be inserted at position " << pos << ": ";
    cin >> data;

    if (head == NULL) {
        cout << "Linked List is empty";
    } else {
        //this will point at the first node of the list
        struct node *p = head;
        
        //create a node and assign the data but make the link NULL first and edit it afterwards
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->link = NULL;
        
        pos--;

        while (pos != 1) {
            p = p->link;
            pos--;
        }
        temp->link = p->link;
        p->link = temp;
    }
}

//this will print the data in each node
void print_data(struct node *head) {
    if (head == NULL) {
        cout << "Linked list is empty";
    }
    struct node *p = NULL;
    p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->link;
    }
    cout << endl;
}

//this will make the first node of the list to be deleted
struct node *del_first(struct node *head) {
    struct node *temp = NULL;
    temp = head;
    int count = 0;

    while (temp != NULL && count != 1) {
        count++;
        temp = temp->link;
    }
    if (count == 0) {
        cout << "Link list is empty";
    } else {
        head = temp;
        free(temp);
        temp = NULL;
    }
    
    return head;
}

//this will make the last node of the list to be deleted
struct node *del_last(struct node *head) {
    if (head == NULL) {
        cout << "Link is empty";
    } else if(head->link == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        struct node *temp2 = head;

        while (temp->link != NULL) {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}

//this will delete a node in a certain position
struct node *del_atpos(struct node *head) {
    int pos = 0;
    cout << "Enter node in the list to be deleted: ";
    cin >> pos;
    
    int count = 1;

    //you first gotta know how many nodes in the list
    int num = count_of_nodes(head);

    //if the posiiton is bigger than the num then return
    if (pos > num) {
        cout << "Position out of bound" << endl;
        return head;
    }

    //if the position is the beginning of the list
    if (pos == 1) {
        struct node *temp = head;
        head = head->link;
        delete temp;
        return head;
    }

    struct node *p = head;
    struct node *temp = NULL;

    //this will locate the position
    while (count != pos) {
        temp = p;
        p = p->link;
        count++;
    }

    //this will identify if the position entered
    //is the last node or not
    if(p->link != NULL) {
        head->link = p;
        p->link = NULL;
    } else {
        temp->link = NULL;
    }

    //then you will delete the p and return
    delete p;
    return head;
}


// single linked list
int main() {
    //first node of the list
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    //second node of the list
    struct node *n1 = (struct node*)malloc(sizeof(struct node));
    n1->data = 30;
    n1->link = NULL;
    head->link = n1; 
  
    //third node of the list
    n1 = (struct node*)malloc(sizeof(struct node));
    n1->data = 50;
    n1->link = NULL;

    //this will point the link of the second node to the
    //address of the third node
    head->link->link = n1;

    n1 = (struct node*) malloc(sizeof(struct node));
    n1->data = 60;
    n1->link = NULL;

    head->link->link->link = n1;

    //this will count on how many nodes in the pointer head
    int count = count_of_nodes(head);
    cout << count << endl;

    //this will print the data inside the nodes
    print_data(head);

    char ans;
    cout << "Do you want to continue? ";
    cin >> ans;

    int num = 0;
    int pos = 0;

    if (ans == 'Y' || ans == 'y') {
        cout << "1. Enter a node at the end" << endl;
        cout << "2. Enter a node at the beginning" << endl;
        cout << "3. Enter a node at a certain position" << endl;
        cout << "4. Delete the first node" << endl;
        cout << "5. Delete the last node" << endl;
        cout << "6. Delete a certain node in the list" << endl;
        cout << "7. Reverse the entire list" << endl;
        cout << "8. Delete the entire list" << endl;

        cout << "Enter a valid choice: ";
        cin >> num;

        switch (num){
        case 1:
            //this will insert a node at the end of the list
            insert_node_atend(head);

            break;
        case 2:
            //this will return a struct node to change the beginning
            head = insert_atbeg(head);

            //this will update the n1 so that it will also point at the head
            n1 = head;
            break;
        case 3:
            //this will insert a node at certain position in list;
            cout << endl << "Enter a position to be inserted: ";
            cin >> pos;

            insert_atpos(head, pos);
            break;
        case 4:
            //this will delete the first node of the list
            head = del_first(head);

            break;
        case 5:
            //this will delete the last node of the list
            head = del_last(head);

            break;
        case 6:
            head = del_atpos(head);

            break;
        default:
            break;
        }
    } 
    
    count = count_of_nodes(head);
    cout << count << endl;

    print_data(head);

    cout << endl << "Thank you come again..";

    return 0;
}