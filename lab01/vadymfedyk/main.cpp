#include <iostream>
#include<iomanip>
using namespace std;


int main() {
  int n;
  cout << "Len of array(5-20): ";
  cin >> n;
  if(n >= 5 && n <= 20){
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
    cout << "Input element [" << i << "]: " ;
    cin >> arr[i];
  }

  double sm = 0; //sum
  for(int s = 0; s < n; s++){
    sm += arr[s];
  }
  
  double avarage = sm/n;
  cout << fixed << setprecision(2);
  cout << "Your array: ";
  for(int a = 0; a < n; a++){
    cout << arr[a] << " ";
  }
  cout << endl;
  cout << "Sum: " << sm << endl;
  cout << "Average: " << avarage << endl;

  cout << "Elements that are bigger than " << avarage << ": ";
  for(int mx = 0; mx < n; mx++){
    if(arr[mx] > avarage){
      cout << arr[mx] << " ";
    }
  }
  cout << endl;

  cout << "Elements that are less than: " << avarage << ": ";
  for(int mn = 0; mn < n; mn++){
    if(arr[mn] < avarage){
      cout << arr[mn] << " ";
    }
  }

  }else{
    cout << "Try again";
  }
  
  return 0;

}

 
