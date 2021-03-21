typedef struct {
	char *first_N;
	char *last_N;

} student_t;
typedef struct node_t {
	student_t *info;
	struct node_t *new;
} node_t;
// TODO: add typedef for a Student struct
// TODO: add typedef for a Node struct

void addToEnd(node_t **head, student_t *student);

void addToStart(node_t **head, student_t *student);

void printList(node_t *head);


void removeByIndex(node_t **head, int n);


void removeLast(node_t **head);


void removeFromStart(node_t **head);



