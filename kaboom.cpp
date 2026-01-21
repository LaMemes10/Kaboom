#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <string>

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
    
    if(num == 5){
        return true;
    }
    
    return false;
}

int main()
{
    
    //Names to pick
    std::vector<std::string> names = {
        "Thalia Henderson", "Beau Deleon", "Gabrielle Jenkins", "Declan Pham", "Raelyn Stafford",
        "Alfredo Gillespie", "Alianna Wyatt", "Sam Banks", "Cali Reynolds", "Vincent Knapp",
        "Linda Young", "Asher Bradford", "Rhea Zhang", "Isaias O’Connell", "Jillian Lucas",
        "Chance Hart", "Gemma Clay", "Yosef Waters", "Bristol Perry", "Waylon Howe",
        "Persephone Casey", "Armando Adkins", "Emelia McLean", "Zhouzen Li", "Violeta Spears",
        "Ameer Whitehead", "Sylvie Butler", "Ryder Pace", "Giana Baldwin", "Jaiden Macias",
        "Adley Golden", "Patrick Floirendo", "Penny Rollins", "Wes Price", "Piper Reed",
        "Easton Acevedo", "Ashlynn Wiley", "Mathew Zimmerman", "Ariyah Andrade", "Abdiel Frederick",
        "Sariyah Allen", "Carter Strickland", "Nia Evans", "Elias Stout", "Chana Boyer",
        "Zeke Copeland", "Dayana Pittman", "Valentino Lloyd", "Emely Ortega", "Kobe Clarke",
        "Kaitlyn Enriquez", "Elisha Johns", "Giovanna Shepard", "Damari Atkins", "Mina Wang",
        "Adrian FernandezLopez", "Leona Hunter", "Archer Hester", "Zendaya Hull", "Salem Roberson",
        "Sasha Kim", "Roman Newman", "Oaklynn Phelps", "Hamza Ruiz", "Emery Miranda",
        "Rory Lester", "Averi Sheppard", "Trent Grimes", "Braelyn Garrison", "Noe Wall",
        "Jayda Boyer", "Zeke Donovan", "Azariah Price", "Brooks Pham", "Raelyn Lee",
        "Jack Walsh", "Leia Rogers", "Colton Klein", "Elianna Garza", "Judah Delgado",
        "Alani Moran", "Tate Douglas", "Aniyah Johnston", "Felix Wolf", "Jolene Kirby",
        "Tony Boyle", "Aliya McKay", "Joey Sparks", "Aisha Blair", "Troy Nguyen",
        "Esperanza Booth", "Chaim Medina", "Elliana Fields", "Clayton Ware", "Eileen Stevens",
        "Zachary Sims", "Lena James", "Jaxson Dougherty", "Alisson Sharp", "Michi Heike", "Hadrian Lazic"
    };
    
    //Initilize days
    std::vector<std::string> days {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int dayIndex {6};
    
    std::cout << "Today is Sunday\n\n";

    //Menu
    while(!names.empty()){
        
        std::cout << "Advance day(y/n)?\n";
        char option {};
        std::cin >> option;
        
        
        if(option == 'Y' || option == 'y'){
            dayIndex = {(dayIndex + 1) % 7};//Cycle through the 7 days
            printRefresh({});
            std::cout << "\nIt is now " << days[dayIndex] << "\n\n";
            
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
                        
                        std::cout << "- " << names.back() << "\n";
                        names.pop_back(); //Permanently remove participants
                    }
                }
                else{
                    
                    std::cout << "Everybody is gone...\n\n";
                    
                }
                
            }
            else{
                
                std::cout << "Nothing interesting happened.\n\n";
            }
            
        }
        else if(option == 'N' || option == 'n'){
            
            break;
        }

    }

}
