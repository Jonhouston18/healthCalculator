/* Health Calculator
 * Author: Jonathan Seibert
 * Version 1.0.0 */

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    // variables 
    int gender;
    int age;
    int activityLevel;
    double currentWeight;
    double goalWeight;
    double height;
    double neckCircum;
    double waistCircum;
     
    // Formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    //User Input
    cout << "\nEnter your gender. Type 0 for Male or 1 for Female: ";
    cin >> gender;
    while(gender >= 2 || gender <= -1) {
        cout << "Please only enter a 1 or 0: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> gender;
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
    double currentBodyFatFemale = (1.0324 - 0.19077 * log10(waistCircum-neckCircum) + 0.15456 * log10(height));
    double currentBodyFatFemaleTotal = pow(currentBodyFatFemale, -450.0);

    double bmrMale = 66 + (6.3 * currentWeight) + (12.9 * height) - (6.8 * age); 
    double bmrFemale = 655 + (4.3 * currentWeight) + (4.7 * height) - (4.7 * age);
    
    double sedentaryMale = 1.2 * bmrMale;
    double sedentaryFemale = 1.2 * bmrFemale;

    double lightActiveMale = 1.375 * bmrMale;
    double lightActiveFemale = 1.375 * bmrFemale;

    double moderatelyActiveMale = 1.55 * bmrMale;
    double moderatelyActiveFemale = 1.55 * bmrFemale;

    double veryActiveMale = 1.725 * bmrMale;
    double veryActiveFemale = 1.725 * bmrFemale;

    double extraActiveMale = 1.9 * bmrMale;
    double extraActiveFemale = 1.9 * bmrFemale;

    int timeFrame = currentWeight - goalWeight; 

    double buildMuscle = currentWeight * .8;
    
    // Output for body fat
    if (gender == 0) {
           cout << "Your current body fat percentage is " << currentBodyFatMale << "%" << endl;
    }
    if (gender == 1) {
           cout << "Your current body fat percentage is " << currentBodyFatFemaleTotal << " %" << endl;
    }

    // Output for daily calories needed to maintain
    if (gender == 0)
       if (activityLevel == 1) {
           cout << "You need " << sedentaryMale << " caloires a day to maintain your weight." << endl;
    }
    if (gender == 1)
       if (activityLevel == 1) {
           cout << "You need " << sedentaryFemale << " caloires a day to maintain your weight." << endl;
    }
    if (gender == 0)
       if (activityLevel == 2) {
           cout << "You need " << lightActiveMale << " caloires a day to maintain your weight." << endl;
    }
    if (gender == 1)
       if (activityLevel == 2) {
           cout << "You need " << lightActiveFemale << " caloires a day to maintain your weight." << endl;
    }
    if (gender == 0)
       if (activityLevel == 3) {
           cout << "You need " << moderatelyActiveMale << " caloires a day to maintain your weight." << endl;
    }
    if (gender == 1)
       if (activityLevel == 3) {
           cout << "You need " << moderatelyActiveFemale << " caloires a day to maintain your weight." << endl;
    }
    if (gender == 0)
       if (activityLevel == 4) {
           cout << "You need " << veryActiveMale << " caloires a day to maintain your weight." << endl;
    }
    if (gender == 1)
       if (activityLevel == 4) {
           cout << "You need " << veryActiveFemale << " caloires a day to maintain your weight." << endl;
    }
    if (gender == 0)
       if (activityLevel == 5) {
           cout << "You need " << extraActiveMale << " caloires a day to maintain your weight." << endl;
    }
    if (gender == 1)
       if (activityLevel == 5) {
           cout << "You need " << extraActiveFemale << " caloires a day to maintain your weight." << endl;
    }
    
    //Output for builidng muscle
    cout << "To build muscle, your body needs at least " << buildMuscle << " grams of protein intake per day." <<endl;
    
    // Output for calorie deficit
    if (gender == 0)
       if (activityLevel == 1) {
           cout << "You need " << sedentaryMale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
    }
    if (gender == 1)
       if (activityLevel == 1) {
           cout << "You need " << sedentaryFemale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
    }
    if (gender == 0)
       if (activityLevel == 2) {
           cout << "You need " << lightActiveMale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
    }
    if (gender == 1)
       if (activityLevel == 2) {
           cout << "You need " << lightActiveFemale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
    }
    if (gender == 0)
       if (activityLevel == 3) {
           cout << "You need " << moderatelyActiveMale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
    }
    if (gender == 1)
       if (activityLevel == 3) {
           cout << "You need " << moderatelyActiveFemale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
    }
    if (gender == 0)
       if (activityLevel == 4) {
           cout << "You need " << veryActiveMale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
    }
    if (gender == 1)
       if (activityLevel == 4) {
           cout << "You need " << veryActiveFemale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
    }
    if (gender == 0)
       if (activityLevel == 5) {
           cout << "You need " << extraActiveMale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
    }
    if (gender == 1)
       if (activityLevel == 5) {
           cout << "You need " << extraActiveFemale - 500 << " caloires a day to lose ~ 1lb per week." << endl;
       }
    
    // Output for weight loss time
    cout << "It should roughly take " << timeFrame << " weeks to get to your desired weight." << endl;

    // End program
    cout << "Keep on the grind!" << endl << endl;
    return 0;
}



