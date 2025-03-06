#include <iostream>
#include <fstream>

using namespace std;

double sumOfDoubles(double arry[], int choice);
double greaterThanTwenty(double chosen);


int main(){


  int choice= 0;
  double arry[choice];
  double chosen;
  double greg;
 
  cout << "how many numbers would you like to enter:" << endl;


  cin >> choice;

  chosen = sumOfDoubles(arry, choice);    

  cout << "the total sum is "<< chosen<<endl;


  greg = greaterThanTwenty(chosen);


  cout << ""<<greg<<endl;
  
  
}

double sumOfDoubles(double arry[], int choice){

  double sum = 0;

  for(int i=0; i< choice; i++){


    cout <<"enter a double:"<<endl;

    cin >> arry[i];

    sum+=arry[i];


  }

  return double (sum)/choice;
}

double greaterThanTwenty(double chosen){

  if(chosen >20){

    cout << "the total "<<chosen<<" is aslo greater then 20"<<endl;

  }else{
    cout << "the total "<<chosen<<" is aslo less then 20"<<endl;
  }

  return 0;
  
}
