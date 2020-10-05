#include <stdio.h>
#include <stdlib.h>

typedef struct Pets{
    int ID;
    char *animal;
    char *name;
    int age;
} Pet;

//initialize array of Pet
Pet *store;
size_t initArray = 0;

Pet addPet(int Id, char * type, char * nombre, int old){
  Pet newpet;
  newpet.ID = Id;
  newpet.animal = type;
  newpet.name = nombre;
  newpet.age = old;
  return newpet;
}

char * deletePet(int Id){
  size_t i = 0;
  char *message = " ";
  Pet *tmpS = calloc(initArray, sizeof(Pet));
  while(message = " "){
    Pet tmp = *(store + i);
    if(Id == tmp.ID){
      message = "Successfully deleted pet";
      return message;
    }
    else{
      *(tmpS + i) = tmp;
    }
    if (i == initArray-1) {
      message = "Error message, ID not found";
      return message;
    }
    i++;
  }
}

void printStore(){
  for (size_t i = 0; i < initArray; i++) {
    Pet tmp = *(store + i);
    printf("ID %d, name %s, animal %s, age %d\n", tmp.ID, &tmp.name, &tmp.animal, tmp.age);
  }
}

void main(){
store = calloc(initArray, sizeof(Pet));
int option = 0;
char *tmpAnimal;
char *tmpname;
int tmpAge;
int tmp; //ID
while (option != 4) {
  printf("Press 1 to add a new pet\nPress 2 to print the store catalogue\nPress 3 to delete a pet from the store\nPress 4 to finish\n");
  scanf("%d",&option);
  switch (option) {
    case 1:
      //change size of memnory block
      initArray += 1;
      //Reallocate memory
      store = realloc(store, initArray * sizeof(Pet));

      printf("What type of animal is the new pet?\n" );
      scanf("%s", &tmpAnimal);

      printf("What is the name of the pet?\n");
      scanf("%s", &tmpname );

      printf("What's the age of the pet?\n");
      scanf("%d", &tmpAge);

      //create new Pet
      *(store + initArray-1) = addPet(initArray-1, tmpAnimal, tmpname, tmpAge);
      break;
    case 2:
      printStore();
      break;
    case 3:
      printf("Type the ID of the animal you wish to delete: ");
      scanf("%d", &tmp);
      printf("%s\n", deletePet(tmp));
      break;
  }
}
free(store);

}
