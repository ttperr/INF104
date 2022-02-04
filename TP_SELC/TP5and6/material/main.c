#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
  char lastname[30];
  char firstname[20];
  int group;
} Student_t;

typedef struct link
{
  Student_t student;
  struct link *next;
} Link_t;

Link_t *new_link(Student_t student);
Link_t *chain(Link_t *beginning, Link_t *new_link);
void display_linked_list(Link_t *list);
void free_list(Link_t *list);
Link_t *sort(Link_t *beginning);
Link_t *search(Link_t *beginning, char *name_to_search);
Link_t *insert(Link_t *beginning, Link_t *new_link);
void read_file_content(Student_t *array, FILE *file);

/*************   global variables   ****************/

Link_t *first_link = NULL;
int number_of_students = 0;

/********************   main   ********************/
int main(int argc, char *argv[])
{
  // First, we read the content of the file with the list of students
  // check that the user gave a correct number of parameters
  // Usage: ./sum_fscanf file_name
  if (argc != 2)
  {
    printf("Wrong usage: expected ./linked_list file_name");
    return -1;
  }

  // check for the occurence of errors when using fopen and fscanf,
  // display an error message and quit in case of errors.
  FILE *f = fopen(argv[1], "r");
  if (f == NULL)
  {
    printf("Error: could not open file %s, make sure it exists\n", argv[1]);
    return -2;
  }

  Student_t students_array[160];
  read_file_content(students_array, f);

  // visualize the content of students_array using printf
  for (int i = 0; i < number_of_students; i++)
  {
    printf("\nStudent n°%d : %s %s is in group %d\n", i, students_array[i].firstname,
           students_array[i].lastname, students_array[i].group);
  }

  // create a linked list from the array of students
  int i;
  for (i = 0; i < number_of_students; i++)
  {
    first_link = chain(first_link, new_link(students_array[i]));
  }

  printf("\n-------------- Initial content of the list -------------- \n");
  display_linked_list(first_link);

  /********************   test search function  ********************/
  printf("\n\n**************************************************\n");
  printf("Test of the \"search\" function ...\n");
  char name_to_search[80];
  do
  {
    printf("Enter a name to search (write END when finished testing): ");
    scanf("%s", name_to_search);
    Link_t *found_link = search(first_link, name_to_search);
    if (found_link != NULL)
    {
      printf("Found %s ! :  last name: %s first name: %s group: %d\n", name_to_search,
             found_link->student.lastname, found_link->student.firstname,
             found_link->student.group);
    }
    else
      printf("%s was not found  !\n", name_to_search);

  } while (strcmp(name_to_search, "END") != 0);
  printf("Test of the \"search\" function finished: evaluate the result.\n");
  printf("**************************************************\n\n");

  /********************   test insertion  ********************/
  printf("\n\n**************************************************\n");
  printf("Test of the \"insert\" function ...\n");
  Student_t student_z = {"ZZZ", "should_be_last", 42};
  Student_t student_a = {"AAA", "should_be_first", 42};
  Student_t student_o = {"OOO", "should_be_middle", 42};

  Link_t *link_z = new_link(student_z);
  Link_t *link_a = new_link(student_a);
  Link_t *link_o = new_link(student_o);

  first_link = insert(first_link, link_z);
  first_link = insert(first_link, link_a);
  first_link = insert(first_link, link_o);

  printf("-------------- Content of the list after insertion -------------- \n");
  display_linked_list(first_link);
  printf("Test of the \"insert\" function finished: evaluate the result.\n");
  printf("**************************************************\n\n");

  /********************   test  sort    ********************/
  printf("\n\n**************************************************\n");
  printf("Test of the \"sort\" function ...\n");
  Link_t *sorted_list = sort(first_link);
  printf("-------------- Content of the list after sort -------------- \n");
  display_linked_list(sorted_list);
  printf("Test of the \"sort\" function finished: evaluate the result.\n");
  printf("**************************************************\n\n");

  /*****  test free ********/
  printf("\n\n**************************************************\n");
  printf("Test of the \"free_list\" function ...\n");
  free_list(first_link);
  printf("Test of the \"free_list\" function finished.\n");
  printf("**************************************************\n\n");

  printf("\n\n**************************************************\n");
  printf("Tests passed?\n\t NO --> continue ! \n\t YES --> This is the end ... Hold your breath and count to ten ... Next: Makefiles and OS ... \n");
  printf("**************************************************\n\n");

  return 0;
}

/********************   read_file_content   ********************
* read file and extract information to store it in array
**************************************************************/

void read_file_content(Student_t *array, FILE *file)
{

  /* TODO: implement this function */
  /* printf("read_file_content: Not Implemented Yet\n");
  exit(-1);
  */
  int ret_lec;
  int i = 0;
  while (1)
  {
    ret_lec = fscanf(file, "%s %s %d", array[i].lastname, array[i].firstname, &array[i].group);
    if (ret_lec != EOF || ret_lec == 3)
    {
      number_of_students++;
      i++;
    }
    else
      break;
  }
}

/********************    new_link   *******************
* Create a new link of type Link_t: the field next is initialized to NULL
* Returns the adress of the new link.
********************************************************/
Link_t *new_link(Student_t student)
{
  Link_t *link;

  /* TODO: implement this function */
  /*printf("new_link: Not Implemented Yet\n");
  exit(-1);
  */

  link = (Link_t *)malloc(sizeof(Link_t));
  link->student = student;
  (*link).next = NULL;
  return link;
}

/********************    chain   *******************
* Add a new link (new_link) at the beginning of an existing
* linked list (beginning).
* Returns the address of the first element of the list.
********************************************************/
Link_t *chain(Link_t *beginning, Link_t *new_link)
{
  /* TODO: implement this function */
  /* printf("chain: Not Implemented Yet\n");
  exit(-1);
  */

  new_link->next = beginning;
  return new_link;
}

/********************   display_linked_list   *******************
* Display (using printf) the information contained in the
* linked list.
********************************************************/
void display_linked_list(Link_t *list)
{

  /* TODO: implement this function */
  /*printf("display_linked_list: Not Implemented Yet\n");
  exit(-1);
  */
  Link_t *currentElement = list;
  int i = 1;
  while (currentElement != NULL)
  {
    printf("\nStudent n°%d : %s %s is in group %d\n", i, currentElement->student.firstname,
           currentElement->student.lastname, currentElement->student.group);
    i++;
    currentElement = currentElement->next;
  }
}

/********************   search   *******************
* Search for a link corresponding to a student last
* name
* beginning: first link of the list used for searching
* name_to_search: last name of the student to search
* returns the firts link for which the name equals
* name_to_search
********************************************************/
Link_t *search(Link_t *beginning, char *name_to_search)
{
  Link_t *found_link;

  /* TODO: implement this function */
  /*printf("search: Not Implemented Yet\n");
  exit(-1);
  */

  Link_t *currentElement = beginning;
  while (currentElement->next != NULL)
  {
    if (!strcmp(currentElement->student.lastname, name_to_search))
    {
      return currentElement;
    }
    else
    {
      currentElement = currentElement->next;
    }
  }
  return NULL;
}

/********************   insert   *******************
* Insert a link in a linked list
* beginning: first link of the original list
* new_link: link to insert
* returns the firts link of the list after insertion
********************************************************/
Link_t *insert(Link_t *beginning, Link_t *new_link)
{
  /* TODO: implement this function */
  /*printf("insert: Not Implemented Yet\n");
  exit(-1);
  */
  if (beginning == NULL)
  {
    return chain(beginning, new_link);
  }
  if (strcmp(beginning->student.lastname, new_link->student.lastname) >= 0)
  {
    new_link->next = beginning->next;
    return chain(beginning, new_link);
  }
  return chain(insert(beginning->next, new_link), beginning);
}

/********************   sort   *******************
* Sort the content of the linked list.
********************************************************/
Link_t *sort(Link_t *beginning)
{
  /* TODO: implement this function */
  /*printf("sort: Not Implemented Yet\n");
  exit(-1);
  */
  Link_t *sorted_list = NULL;
  Link_t *link = beginning;
  while (link != NULL)
  {
    Link_t *next = link->next;
    sorted_list = insert(sorted_list, link);
    link = next;
  }
  return sorted_list;
}

/********************   free_list   *******************
* Free the memory used by the linked list.
********************************************************/
void free_list(Link_t *list)
{

  /* TODO: implement this function */
  /*printf("free_list: Not Implemented Yet\n");
  exit(-1);
  */
  Link_t *link = list;
  while (link != NULL)
  {
    Link_t *next = link->next;
    free(link);
    link = next;
  }
}
