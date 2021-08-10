/* Health Calculator
 * Author: Jonathan Seibert
 * Version 1.2.0 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    // global variables 
    string userGender, bfRange;
    int age, activityLevel;
    double currentWeight, goalWeight, height, neckCircum, waistCircum, hipCircum;
     
    // Formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    //User Input
    cout << "\nWhat is your gender? Enter Male or Female: ";
    cin >> userGender;
    while(userGender.at(0) != 'M' && userGender.at(0) != 'm' && userGender.at(0) != 'f' && userGender.at(0) != 'F') {
        cout << "Please enter either \"male\" or \"female\" to get the most accurate bodyweight calculations: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> userGender;
    }
    cout << "\nWhat's your age: ";
    cin >> age;
    while(age <= 0) {
        cout << "Please only enter a postive numerical value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> age;
    }
    cout << "\nEnter current body weight in lbs: ";
    cin >> currentWeight;
    while(currentWeight <= 0) {
        cout << "Please only enter a postive numerical value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> currentWeight;
    }
    cout << "\nEnter your height in inches: ";
    cin >> height;
    while(height <= 0) {
            cout << "Please only enter a non-negative numerical value: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> height;
    }
    cout << "\nWhat is your activity level?: ";
    cout << "\nType 1 for little or no exercise: ";
    cout << "\nType 2 for lightly active (light exercise/sports 1-3 days/week): ";
    cout << "\nType 3 for moderately active (moderate exercise/sports 3-5 days/week): ";
    cout << "\nType 4 for very active (hard exercise/sports 6-7 days a week): ";
    cout << "\nType 5 for extra active (very hard exercise/sports & physical job or 2x training): ";
    cin >> activityLevel;
    while(activityLevel >= 6 || activityLevel <= 0 ) {
        cout << "Please only enter a value between 1-5: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> activityLevel;
       }
       cout << "\nEnter current neck circumfance in inches: ";
       cin >> neckCircum;
       while(neckCircum <= 0) {
              cout << "Please only enter a non-negative numerical value: ";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              cin >> neckCircum;
       }
       if(userGender.at(0) == 'f' || userGender.at(0) == 'F') {
       cout << "\nEnter current hip circumfance in inches: ";
       cin >> hipCircum;
       while(hipCircum <= 0) {
              cout << "Please only enter a non-negative numerical value: ";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              cin >> hipCircum;
            }
       }
       cout << "\nEnter current waist circumfance in inches: ";
       cin >> waistCircum;
       while(waistCircum <= 0) {
              cout << "Please only enter a non-negative numerical value: ";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              cin >> waistCircum;
       }
       cout << "\nEnter your desired goal weight in lbs: ";
       cin >> goalWeight;
       while(goalWeight <= 0) {
              cout << "Please only enter a non-negative numerical value: ";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              cin >> goalWeight;
       }
    cout << endl;

    // Calculations
    double currentBodyFatMale = (86.010 * log10(waistCircum - neckCircum) - 70.041 * log10(height) + 36.76);
    double currentBodyFatFemale = (163.205 * log10((waistCircum + hipCircum) - neckCircum) - 97.684 * log10(height) - 78.387);

    double bmrMale = 66 + (6.3 * currentWeight) + (12.9 * height) - (6.8 * age); 
    double bmrFemale = 655 + (4.3 * currentWeight) + (4.7 * height) - (4.7 * age);
    
    double sedentaryMale = 1.2 * bmrMale;
    double sedentaryFemale = 1.2 * bmrFemale;

    double lightlyActiveMale = 1.375 * bmrMale;
    double lightlyActiveFemale = 1.375 * bmrFemale;

    double moderatelyActiveMale = 1.55 * bmrMale;
    double moderatelyActiveFemale = 1.55 * bmrFemale;

    double veryActiveMale = 1.725 * bmrMale;
    double veryActiveFemale = 1.725 * bmrFemale;

    double peakActivityMale = 1.9 * bmrMale;
    double peakActivityFemale = 1.9 * bmrFemale;

    int timeFrame = currentWeight - goalWeight; 

    double buildMuscle = currentWeight * .8; 
    
    // Calculate user's category of body fat if man
    if((userGender.at(0) == 'm' || userGender.at(0) == 'M') && currentBodyFatMale <= 6.0) {
         bfRange = "esssiential";
    }
    else if ((userGender.at(0) == 'm' || userGender.at(0) == 'M') && (currentBodyFatMale >= 6.0 && currentBodyFatMale <= 13.0)) {
         bfRange = "athletic";
    }
    else if ((userGender.at(0) == 'm' || userGender.at(0) == 'M') && (currentBodyFatMale >= 13.0 && currentBodyFatMale <= 17.0)) {
         bfRange = "fitness";
    }
    else if ((userGender.at(0) == 'm' || userGender.at(0) == 'M') && (currentBodyFatMale >= 17.0 && currentBodyFatMale <= 24.0)) {
         bfRange = "average";
    }
    else if ((userGender.at(0) == 'm' || userGender.at(0) == 'M') && (currentBodyFatMale >= 24.0)) {
         bfRange = "obese";
    }

    // Calculate user's category of body fat if woman
    if((userGender.at(0) == 'f' || userGender.at(0) == 'F') && currentBodyFatMale <= 13.0) {
         bfRange = "esssiential";
    }
    else if ((userGender.at(0) == 'f' || userGender.at(0) == 'F') && (currentBodyFatMale >= 14.0 && currentBodyFatMale <= 20.0)) {
         bfRange = "athletic";
    }
    else if ((userGender.at(0) == 'f' || userGender.at(0) == 'F') && (currentBodyFatMale >= 20.0 && currentBodyFatMale <= 24.0)) {
         bfRange = "fitness";
    }
    else if ((userGender.at(0) == 'f' || userGender.at(0) == 'F') && (currentBodyFatMale >= 25.0 && currentBodyFatMale <= 31.0)) {
         bfRange = "average";
    }
    else if ((userGender.at(0) == 'f' || userGender.at(0) == 'F') && (currentBodyFatMale >= 31.0)) {
         bfRange = "obese";
    }

    // Output for body fat
    if(userGender.at(0) == 'm' || userGender.at(0) == 'M') {
        cout << "Your current body fat percentage is " << currentBodyFatMale << "%" << 
            " which puts you in the " << bfRange << " range." << endl;
    }
    else if (userGender.at(0) == 'f' || userGender.at(0) == 'F'){
        cout << "Your current body fat percentage is " << currentBodyFatFemale << " %" <<
            " which puts you in the " << bfRange << " range." << endl;
    }

    // Output for daily calories needed to maintain for men
    if (userGender.at(0) == 'm' || userGender.at(0) == 'M') {
            switch (activityLevel) {
            case 1: 
                cout << "You need " << sedentaryMale << " caloires a day to maintain your weight." << endl;
                break;
            case 2: 
                cout << "You need " << lightlyActiveMale << " caloires a day to maintain your weight." << endl;
                break;
           case 3: 
                cout << "You need " << moderatelyActiveMale << " caloires a day to maintain your weight." << endl;
                break;
           case 4: 
                cout << "You need " << veryActiveMale << " caloires a day to maintain your weight." << endl;
                break;
           case 5: 
                cout << "You need " << peakActivityMale << " caloires a day to maintain your weight." << endl;
                break;
        }
    }

    // Output for daily calories needed to maintain for women
    if (userGender.at(0) == 'f' || userGender.at(0) == 'F') {
            switch (activityLevel) {
            case 1: 
                cout << "You need " << sedentaryFemale << " caloires a day to maintain your weight." << endl;
                break;
            case 2: 
                cout << "You need " << lightlyActiveFemale << " caloires a day to maintain your weight." << endl;
                break;
           case 3: 
                cout << "You need " << moderatelyActiveFemale << " caloires a day to maintain your weight." << endl;
                break;
           case 4: 
                cout << "You need " << veryActiveFemale << " caloires a day to maintain your weight." << endl;
                break;
           case 5: 
                cout << "You need " << peakActivityFemale << " caloires a day to maintain your weight." << endl;
                break;
        }
    }

    //Output for builidng muscle
    cout << "To build muscle, your body needs at least " << buildMuscle << " grams of protein intake per day." <<endl;
    
    // Output for calorie deficit for men
    if (userGender.at(0) == 'm' || userGender.at(0) == 'M') {
            switch (activityLevel) {
            case 1: 
                cout << "You need " << sedentaryMale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
                break;
            case 2: 
                cout << "You need " << lightlyActiveMale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
                break;
           case 3: 
                cout << "You need " << moderatelyActiveMale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
                break;
           case 4: 
                cout << "You need " << veryActiveMale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
                break;
           case 5: 
                cout << "You need " << peakActivityMale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
                break;
        }
    }

    // Output for calorie deficit for women
    if (userGender.at(0) == 'f' || userGender.at(0) == 'F') {
            switch (activityLevel) {
            case 1: 
                cout << "You need " << sedentaryFemale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
                break;
            case 2: 
                cout << "You need " << lightlyActiveFemale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
                break;
           case 3: 
                cout << "You need " << moderatelyActiveFemale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
                break;
           case 4: 
                cout << "You need " << veryActiveFemale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
                break;
           case 5: 
                cout << "You need " << peakActivityFemale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
                break;
        }
    }
    
    // Output for weight loss time
    cout << "It should roughly take " << timeFrame << " weeks to get to your desired weight." << endl;

    // End program
    cout << "Keep on the grind!" << endl << endl;
    return 0;
}
