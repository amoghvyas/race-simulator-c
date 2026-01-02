#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> //experimental

// Structures section
typedef struct Race {
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
  } Race;
typedef struct RaceCar {
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
} RaceCar;


// Print functions section
void printIntro(){
  printf("Welcome to our main event digital race fans!\nI hope everybody has their snacks because we are about to begin!\n");
	Sleep(2000);
}
//experimental (using windows header file for first time)
void printCountDown(){
  printf("\nRacers Ready! In...\n");
	Sleep(1000); // Pauses for 1000 milliseconds (1 second)
  	system("cls"); //clear console
	printf("5\n");
  	Sleep(1000);
	system("cls");
  	printf("4\n");
  	Sleep(1000);
	system("cls");
  	printf("3\n");
  	Sleep(1000);
	system("cls");
  	printf("2\n");
  	Sleep(1000);
	system("cls");
  	printf("1\n");
  	Sleep(1000);
	system("cls");
  	printf("Race!\n");
}
//conventional code
void printFirstPlaceAfterLap(struct Race* race){
  printf("\nAfter lap number %d\nFirst Place Is: %s in the %s race car!\n", race->currentLap, race->firstPlaceDriverName, race->firstPlaceRaceCarColor);
}
void printCongratulation(struct Race* race){
  printf("\nLet's all congratulate %s in the %s race car for an amazing performance.\nIt truly was a great race and everybody have a goodnight!\n", race->firstPlaceDriverName, race->firstPlaceRaceCarColor);
}


// Logic functions section
int calculateTimeToCompleteLap(){
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;
  return speed + acceleration + nerves;
}
void updateRaceCar(struct RaceCar* raceCar){
  raceCar-> totalLapTime = raceCar -> totalLapTime + calculateTimeToCompleteLap();
}
void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2){
  if(raceCar1->totalLapTime <= raceCar2->totalLapTime){
    race->firstPlaceDriverName = raceCar1->driverName;
    race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
  } else {
    race->firstPlaceDriverName = raceCar2->driverName;
    race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
  }
}
void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2){
  struct Race race = {5, 1, NULL, NULL};
  for (int i = 0; i < race.numberOfLaps; i++){
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    race.currentLap = i+1;
    printFirstPlaceAfterLap(&race);
  }
  printCongratulation(&race);
}


// Main function
int main() {
	srand(time(0));
  	printIntro();
  	printCountDown();
  	struct RaceCar racer1 = {"Racer 1", "Blue", 0};
  	struct RaceCar racer2 = {"Racer 2", "Red", 0};
  	startRace(&racer1, &racer2);
	return 0;
}
