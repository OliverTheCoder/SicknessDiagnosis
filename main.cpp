
/**
 * @author Oliver Boamah
 * SICKNESS DIAGNOSIS SYSTEM FOR DIAGNOSING THE 6 KILLER DISEASES IN GHANA
 *
 */

#include <iostream>
#include <algorithm>
using namespace std;
int getSymptomsCount(int n, string a[], int m, string b[]);
void displaySickness(string name, int maximIndex, int maxim);

int main()
{
    // header design
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "\t\t SICKNESS DIAGNOSIS " << endl;
    cout << "\t NB: FOR ACCURATE DIAGNOSIS ENTER AS MANY SYMPTOMS AS POSSIBLE" << endl;
    cout << "----------------------------------------------------------------------------" << endl;

    label:
    // accept name of patient
    string name;
    cout << "What's your name ?" << endl;
    getline(cin, name);

    // accept number of symptoms
    int n;
    cout << "How many symptoms do you want to enter ?" << endl;
    cin >> n;
    cin.ignore();

    // accept all symptoms
    string symptoms [n];
    for(int i = 0; i < n; i++)
    {
        cout << "Enter Symptom " << (i+1) << endl;
        getline(cin, symptoms[i]);
    }

    /**
      ******************** ARRAY OF KEYWORDS OF SYMPTOMS OF 6 KILLER DISEASES ********************************************
    */
    string malaria[] = {"shivering", "chills", "fever", "sweating", "headache", "nausea", "vomit", "abdominal pain",
    "loss of appetite", "lost appetite", "diarrhea", "anemia", "muscle pain", "convulsions", "coma", "bloody stools",
    "fast heart rate", "mental confusion"
    };

    string cholera[] = {"diarrhea", "vomit", "dehydrat", "low blood pressure", "thirst", "muscle cramp",
    "heart beat", "heart rate", "water stool"};

    string tuberclosis[] = {"pain in the chest", "pain breathing", "fatigue", "cant eat", "cannot eat", "can't eat",
    "loss of appetite", "lost appetite", "malaise", "night sweat", "sweating", "loss of     muscle", "phlegm", "lost weight", "weight loss",
    "shortness of breath", "short breath"};

    string measles[] = {"muscle pain", "fatigue", "fever", "malaise", "loss of appetite", "runny nose", "sneez",
    "skin rash", "dry cough", "pink eye", "diarrhea", "sensitive to light", "sensitivity to light", "sore throat",
    "swollen lymph node", "white spots", "swollen eyelid"};

    string hepatitis[] = {"abdomen", "fatigue", "appetite", "malaise", "nausea", "yellow skin", "yellow eyes",
     "dark urine", "itching", "jaundice", "colored poop", "stomach pain", "belly pain"};

    string aids[] = {"fever", "sore throat", "fatigue", "weight loss", "ulcer", "white tongue", "pneumonia",
    "red blotches", "rash", "tired", "muscle pain", "joint pain", "diarrhea"};


    // array to hold the count of occurences of symptoms
    int counter[6];
    counter[0] = getSymptomsCount(n, symptoms, sizeof(malaria)/sizeof(malaria[0]), malaria);
    counter[1] = getSymptomsCount(n, symptoms, sizeof(cholera)/sizeof(cholera[0]), cholera);
    counter[2] = getSymptomsCount(n, symptoms, sizeof(tuberclosis)/sizeof(tuberclosis[0]), tuberclosis);
    counter[3] = getSymptomsCount(n, symptoms, sizeof(measles)/sizeof(measles[0]), measles);
    counter[4] = getSymptomsCount(n, symptoms, sizeof(hepatitis)/sizeof(hepatitis[0]), hepatitis);
    counter[5] = getSymptomsCount(n, symptoms, sizeof(aids)/sizeof(aids[0]), aids);

    // Find the sickness with the highest number of symptoms
    int maxim = 0, maximIndex = 0;
    for(int i = 0; i < 6; i++)
    {

        if(maxim < counter[i])
        {
            maxim = counter[i];
            maximIndex = i;
        }
    }

    // display sickeness
    displaySickness(name, maximIndex, maxim);

    // do it again?
    int choice;
    cout << "1 - Diagnoze again \t Any key - Exit" << endl;
    cin >> choice;
    cin.ignore();
    if(choice == 1)
    {
        goto label;
    }


    return 0;
}

/* This function displays the diagnosis report */
void displaySickness(string name, int maximIndex, int maxim)
{
    string sickness;
    if(maximIndex == 0){
        sickness = "Malaria";
    }else if(maximIndex == 1){
        sickness = "Cholera";
    }else if(maximIndex == 2){
        sickness = "Tuberclosis";
    }else if(maximIndex == 3){
        sickness = "Measles";
    }else if(maximIndex == 4){
        sickness = "Hepatitis";
    }
    else{
        sickness = "HIV Aids";
    }

    cout << "------------------------------------------------------------" << endl;
    cout <<"\t\t DIAGNOSIS REPORT " << endl;

    if(maxim == 0){
        cout << name << ", your symptoms does not match any of our known diseases" << endl;
        cout << "Don't Worry, We'll run some Lab tests on you and see what's really wrong" << endl;
    }
    else{ cout << name << ", you may be suffering from " << sickness << "." << endl;
          cout << "You have " << maxim << " symptoms of " << sickness << "." << endl;
          cout << "We can confirm it by performing by performing some Lab Test on you."<< endl;
    }

    cout << "------------------------------------------------------------" << endl;
}


/* This function finds the number of matching symptoms */
int getSymptomsCount(int n, string a[], int m, string b[])
{
    int foundIndexes[n];
    bool isExist = false;
    int curr = 0;

    for(int i = 0; i < n; i++)
    {
       for(int j = 0; j < m; j++)
       {
         // convert all strings to lower case for correct comparisons
         std::transform(a[i].begin(), a[i].end(), a[i].begin(), ::toupper);
         std::transform(b[j].begin(), b[j].end(), b[j].begin(), ::toupper);

         if(a[i].find(b[j]) != string::npos)
         {
             for(int x = 0; x < n; x++)
             {
                 if(j == foundIndexes[x])
                 {
                    isExist = true;
                    break;
                 }
             }
             if(!isExist)
             {
                 foundIndexes[curr] = j;
                 curr ++;
             }
         }
       }
    }

    return curr;
}

