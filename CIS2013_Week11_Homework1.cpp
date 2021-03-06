#include <iostream>
#include <cstring>

using namespace std;

class Car{
    //Privately accessed variables
    private:
        string color;
        string make;
        string model;
        string year;
        int currentSpeed;
        bool isRunning;
    //Publicly accessed functions/methods
    public:
        //Getters
        string GetColor(){
            return color;
        }
        string GetMake(){
            return make;
        }
        string GetModel(){
            return model;
        }
        string GetYear(){
            return year;
        }
        int GetCurrentSpeed(){
            return currentSpeed;
        }
        bool GetIsRunning(){
            return isRunning;
        }
        //Setters
        void SetColor(string inputColor){
            color = inputColor;
        }
        void SetMake(string inputMake){
            make = inputMake;
        }
        void SetModel(string inputModel){
            model = inputModel;
        }
        void SetYear(string inputYear){
            year = inputYear;
        }
        void IncreaseSpeed(){
            currentSpeed += 10;
        }
        void DecreaseSpeed(){
            currentSpeed -= 10;
        }
        void SetIsRunning(bool inputIsRunning){
            isRunning = inputIsRunning;
        }
        void SetCurrentSpeed(int speed){
            currentSpeed = speed;
        }
        bool CheckIsPrintable(){
            if(make != "" && model != "" && year != "" && color != ""){
                return true;
            }
            else{
                return false;
            }
        }
        void TurnLeft(){
            cout << "\n\nYou turn left.\n\n";
        }

        void TurnRight(){
            cout << "\n\nYou turn right.\n\n";
        }

        void DeploySpikeTraps(){
            cout <<"\n\nNananana batman.\n\n";
        }
};

string DisplayMenu(string);
void PrintDetails(Car);
void ClearConsole();

int main(){
    ClearConsole();
    //Create a car object
    Car myCar;
    myCar.SetIsRunning(false);
    myCar.SetCurrentSpeed(0);
    
    string action;
    bool exit = false;

    cout << "You must get home in time for dinner!!\n\n  Build a car fast!\n\n   GOOD LUCK!\n\n";

    while(!exit){
        action = DisplayMenu(action);

        if(action == "c"){
            string inputColor;
            cout << "\nPlease enter the color of the car.\nColor: ", cin >> inputColor;
            myCar.SetColor(inputColor);
            ClearConsole();
        }
        if(action == "m"){
            string inputMake;
            cout << "\nPlease enter the make of the car.\nMake: ", cin >> inputMake;
            myCar.SetMake(inputMake);
            ClearConsole();
        }
        if(action == "o"){
            string inputModel;
            cout << "\nPlease enter the model of the car.\nModel: ", cin >> inputModel;
            myCar.SetModel(inputModel);
            ClearConsole();
        }
        if(action == "y"){
            string inputYear;
            cout << "\nPlease enter the year of the car.\nYear: ", cin >> inputYear;
            myCar.SetYear(inputYear);
            ClearConsole();
        }
        if(action == "s"){
            if(myCar.CheckIsPrintable()){
                //start
                if(!myCar.GetIsRunning()){
                    myCar.SetIsRunning(true);
                    ClearConsole();
                    cout << "You start your car.\n\n";
                }
                else{
                    ClearConsole();
                    cout << "Your car is already turned on. . .\n\n";
                }
            }
            else{
                ClearConsole();
                cout << "\n\n\nYou are still missing some information about your car!\n\n";
                cout << "Current information" << endl ;
                cout << " -Color: " << myCar.GetColor() << endl;
                cout << " -Make : " << myCar.GetMake() << endl;
                cout << " -Model: " << myCar.GetModel() << endl;
                cout << " -Year : " << myCar.GetYear() << endl << endl;                
            }
        }
        if(action == "S"){
            if(myCar.GetIsRunning()){
                //Stop the car / turn off
                myCar.SetIsRunning(false);
                ClearConsole();
                cout << "Your car is now off.\n\n";
            }
            else{
                ClearConsole();
                cout << "You car is already turned off. . .\n\n";
            }
        }
        if(action == "p"){
            if(myCar.CheckIsPrintable()){
                ClearConsole();
                PrintDetails(myCar);    
            }
            else{
                ClearConsole();
                cout << "\n\n\nYou are still missing some information about your car!\n\n";
                cout << "Current information" << endl ;
                cout << " -Color: " << myCar.GetColor() << endl;
                cout << " -Make : " << myCar.GetMake() << endl;
                cout << " -Model: " << myCar.GetModel() << endl;
                cout << " -Year : " << myCar.GetYear() << endl << endl;
            }            
        }
        if(action == "d"){
            if(myCar.GetIsRunning()){
                bool driving = true;
                ClearConsole();
                cout << "You grab the steering wheel.\n\n";
                while(driving){
                    string drivingAction;
                    cout <<     "_________________________________\n"
                         <<     "   Select an action: \n"
                         <<     "       - increase speed       (+)\n"
                         <<     "       - decrease speed       (-)\n"
                         <<     "       - turn left            (l)\n"
                         <<     "       - turn right           (r)\n"
                         <<     "       - deploy spike traps   (t)\n"
                         <<     "       - stop                 (x)\n"
                         <<     "_________________________________\n" << endl;
                    cout << "\nWhat would you like to do?\n";
                    cout << "\nAction: ", cin >> drivingAction;

                    if(drivingAction == "+"){
                        ClearConsole();
                        myCar.IncreaseSpeed();
                        cout << "\nYou speed up, and are now driving " << myCar.GetCurrentSpeed() << " MPH.\n\n";
                        if(myCar.GetCurrentSpeed() > 80){
                            cout << "You were pulled over by the police. \n\nYour quest to make it home in time for dinner has failed. \n\nGame over!\n" << endl;
                            driving = false;
                            exit = true;
                        }
                    }
                    if(drivingAction == "-"){
                        ClearConsole();
                        myCar.DecreaseSpeed();
                        cout << "\nYou slow down, and are now driving " << myCar.GetCurrentSpeed() << " MPH.\n\n";
                        if(myCar.GetCurrentSpeed() < 0){
                            cout << "You went back in time and fall into an erupting prehistoric volcano. \n\nYour quest to make it home in time for dinner has failed. \n\nGame Over!\n" << endl;
                            driving = false;
                            exit = true;
                        }
                    }
                    if(drivingAction == "l"){
                        ClearConsole();                    
                        myCar.TurnLeft();
                    }
                    if(drivingAction == "r"){
                        ClearConsole();                    
                        myCar.TurnRight();
                    }
                    if(drivingAction == "t"){
                        ClearConsole();                    
                        myCar.DeploySpikeTraps();
                    }
                    if(drivingAction == "x"){
                        if(myCar.GetCurrentSpeed() != 0){
                            ClearConsole();
                            cout << "You must decrease speed before stopping.\n\n";
                        }
                        else{
                            ClearConsole();
                            cout << "You stopped your car.\n\n";
                            driving = false;    
                        }           
                    }
                    if(drivingAction != "+" && drivingAction != "-" && drivingAction != "l" && drivingAction != "r" && drivingAction != "t" && drivingAction != "x"){
                        ClearConsole();
                        cout << "Invalid action.\n\n";
                    }
                }//End of Driving loop
            }
            else{
                ClearConsole();
                cout << "You must start your car before you drive. . . \n\n";
            }
        }
        if(action == "x"){
            ClearConsole();
            exit = true;
        }
        if(action != "c" && action != "m" && action != "o" && action != "y" && action != "s" && action != "S" && action != "p" && action != "d" && action != "x"){
            ClearConsole();
            cout << "Invalid action.\n\n";
        }
    }//End of game loop
    return 0;
}

string DisplayMenu(string action){
        cout <<     "______________________\n"
             <<     "   Select an action:  \n"
             <<     "       - set color (c)\n"
             <<     "       - set make  (m)\n"
             <<     "       - set model (o)\n"
             <<     "       - set year  (y)\n"
             <<     "       - start car (s)\n"
             <<     "       - stop car  (S)\n"
             <<     "       - print     (p)\n"
             <<     "       - drive     (d)\n"
             <<     "       - exit      (x)\n"
             <<     "______________________\n" << endl;

        cout << "\nWhat would you like to do?\n";
        cout << "\nAction: ", cin >> action;
        return action;
}
void PrintDetails(Car c){
    cout << "\n\n\nYou\'re driving a "<< c.GetColor() << ", " << c.GetYear() << " " << c.GetMake() << " " << c.GetModel() << ".";

    if(c.GetIsRunning()){
        cout << "\nThe car is currently turned ON.\n";
    }
    if(!c.GetIsRunning()){
        cout << "\nThe car is currently turned OFF.\n";
    }
    cout << endl << endl;

}
void ClearConsole(){
        for(int i = 0; i < 50; i++){
            cout << "\n";
        }
}
