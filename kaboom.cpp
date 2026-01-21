#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <string>

//Store names and date started
struct Person{
    
    std::string person;
    int startDay;
};

//Refresh the screen
void printRefresh(std::string clear) {
  std::cout << "\x1B[2J\x1B[1;1H";
  std::cout << clear;
}

//Generate random number
int randomNumberGenerate(){
    static std::random_device rd;
    static std::mt19937 eng(rd());
    std::uniform_int_distribution<int> distr(1, 10);
    
    return {distr(eng)};
}

//Explosion check
bool explode(int num){
    
    if(num > 3){
        return true;
    }
    
    return false;
}

int main()
{
    
    //Names to pick
    std::vector<Person> names = {
        {"Thalia Henderson", 0}, {"Beau Deleon", 0}, {"Gabrielle Jenkins", 0}, {"Declan Pham", 0}, {"Raelyn Stafford", 0},
        {"Alfredo Gillespie", 0}, {"Alianna Wyatt", 0}, {"Sam Banks", 0}, {"Cali Reynolds", 0}, {"Vincent Knapp", 0},
        {"Linda Young", 0}, {"Asher Bradford", 0}, {"Rhea Zhang", 0}, {"Isaias O’Connell", 0}, {"Jillian Lucas", 0},
        {"Chance Hart", 0}, {"Gemma Clay", 0}, {"Yosef Waters", 0}, {"Bristol Perry", 0}, {"Waylon Howe", 0},
        {"Persephone Casey", 0}, {"Armando Adkins", 0}, {"Emelia McLean", 0}, {"Zhouzen Li", 0}, {"Violeta Spears", 0},
        {"Ameer Whitehead", 0}, {"Sylvie Butler", 0}, {"Ryder Pace", 0}, {"Giana Baldwin", 0}, {"Jaiden Macias", 0},
        {"Adley Golden", 0}, {"Patrick Floirendo", 0}, {"Penny Rollins", 0}, {"Wes Price", 0}, {"Piper Reed", 0},
        {"Easton Acevedo", 0}, {"Ashlynn Wiley", 0}, {"Mathew Zimmerman", 0}, {"Ariyah Andrade", 0}, {"Abdiel Frederick", 0},
        {"Sariyah Allen", 0}, {"Carter Strickland", 0}, {"Nia Evans", 0}, {"Elias Stout", 0}, {"Chana Boyer", 0},
        {"Zeke Copeland", 0}, {"Dayana Pittman", 0}, {"Valentino Lloyd", 0}, {"Emely Ortega", 0}, {"Kobe Clarke", 0},
        {"Kaitlyn Enriquez", 0}, {"Elisha Johns", 0}, {"Giovanna Shepard", 0}, {"Damari Atkins", 0}, {"Mina Wang", 0},
        {"Adrian FernandezLopez", 0}, {"Leona Hunter", 0}, {"Archer Hester", 0}, {"Zendaya Hull", 0}, {"Salem Roberson", 0},
        {"Sasha Kim", 0}, {"Roman Newman", 0}, {"Oaklynn Phelps", 0}, {"Hamza Ruiz", 0}, {"Emery Miranda", 0},
        {"Rory Lester", 0}, {"Averi Sheppard", 0}, {"Trent Grimes", 0}, {"Braelyn Garrison", 0}, {"Noe Wall", 0},
        {"Jayda Boyer", 0}, {"Zeke Donovan", 0}, {"Azariah Price", 0}, {"Brooks Pham", 0}, {"Raelyn Lee", 0},
        {"Jack Walsh", 0}, {"Leia Rogers", 0}, {"Colton Klein", 0}, {"Elianna Garza", 0}, {"Judah Delgado", 0},
        {"Alani Moran", 0}, {"Tate Douglas", 0}, {"Aniyah Johnston", 0}, {"Felix Wolf", 0}, {"Jolene Kirby", 0},
        {"Tony Boyle", 0}, {"Aliya McKay", 0}, {"Joey Sparks", 0}, {"Aisha Blair", 0}, {"Troy Nguyen", 0},
        {"Esperanza Booth", 0}, {"Chaim Medina", 0}, {"Elliana Fields", 0}, {"Clayton Ware", 0}, {"Eileen Stevens", 0},
        {"Zachary Sims", 0}, {"Lena James", 0}, {"Jaxson Dougherty", 0}, {"Alisson Sharp", 0}, {"Shay Nicholas III Remington R5", 0}, {"Hadrian Lazic", 0}
    };
    
    //Initilize days
    std::vector<std::string> days {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int dayIndex {6};
    int totalDaysPassed {0};
    
    std::cout << "Today is Sunday\n\n";

    //Menu
    while(true){
        
        std::cout << "Advance day(y/n)?\n";
        char option {};
        std::cin >> option;
        
        
        if(option == 'Y' || option == 'y'){
            totalDaysPassed++;
            dayIndex = {(dayIndex + 1) % 7};//Cycle through the 7 days
            printRefresh({});
            std::cout << "\nIt is now " << days[dayIndex] << "\n\n";
            
            if(names.empty()){
                
                std::cout << "Everyone is gone... The world remains empty.\n\n";
            }
            else{
            
                int randomNumber = {randomNumberGenerate()};
                //std::cout << randomNumber; //debug, show number.
                
                //Check if explode is equal to random number
                if(explode(randomNumber)){
                    
                    printRefresh({});
                    std::cout << "BOOOM!!!\n";
                    
                    
                    std::random_device rd; 
                    std::mt19937 gen(rd());
                
                    std::shuffle(names.begin(), names.end(), gen);
                    
                    int participants = std::min((int)names.size(), 5);
                
                    if(participants > 0){    
                        
                        std::cout << "These people have tragically been taken out in the blast: \n";
                        for(int i {0}; i < participants; i++){
                            
                            Person candidate = names.back();
                            int survivalTime = totalDaysPassed - candidate.startDay;
                            
                            std::cout << "- " << candidate.person << ": (Survived " << survivalTime << " days)" << "\n";
                            names.pop_back(); //Permanently remove participants
                        }
                    }
                }
                else{
                    
                    std::cout << "Nothing interesting happened.\n\n";
                }
            }
        }
        else if(option == 'N' || option == 'n'){
            
            break;
        }
    }
}
