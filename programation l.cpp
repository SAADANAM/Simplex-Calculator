#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;
int M;
double l[50][50];
int getNumberOfProducts() {
    int numberOfProducts;
    do{
        cout << "How many products do you have: ";
        cin >> numberOfProducts;}while(numberOfProducts<1);
    return numberOfProducts;
}


int getNumberOfConstraints() {
    int numberOfConstraints;
    do{
    cout << "How many constraints do you have: ";
    cin >> numberOfConstraints;}while(numberOfConstraints<1);
    return numberOfConstraints;
}

void calculerMax(int numberOfProducts, int numberOfConstraints) {
    double x,y;
    M=numberOfProducts+2+numberOfConstraints;
    vector<double> T(M, 0);
    T[0]=1;
    for(int i=1;i<=numberOfProducts;i++){
    cout << "Enter the value of X"<<i<<" in the Z equation: ";
    cin >> x;
    T[i]=-x;
    }
       for (int j = 0; j < M; ++j) {
           l[0][j] = T[j];
    }

    for(int i=1;i<=numberOfConstraints;i++){
    for(int j=1;j<=numberOfProducts;j++){
    cout << "Enter the value of X"<<j<<" in the Constraint "<<i<<" : "<<endl;
    cin >> x;
    l[i][j] = x;
    l[i][i+numberOfProducts] = 1;
    }
    cout << "equate to:"<<endl;
    cin >> y;
    l[i][M-1] = y;

    T[i+numberOfProducts]=0;
   }
system("clear");

    for (int j = 0; j < M/2+1; ++j) {
    	cout << "+-----------+" ;
       
	}
		 cout <<endl;

    
    for (int i = 0; i < numberOfConstraints + 1; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << l[i][j] << "   |   ";
        }
        cout <<endl;
    for (int j = 0; j < M/2+1; ++j) {
    	cout << "+-----------+" ;
       
	}
	 cout <<endl;

    }

start:
   double minNegative = 0;
    int minColumnIndex = -1;

    for (int j = 0; j < M; ++j) {
        if (l[0][j] < minNegative) {
            minNegative = l[0][j];
            minColumnIndex = j;
            
        }
    }

    double minimum = l[1][M-1]/l[1][minColumnIndex];
   int minColumnIndex1 = 1;
   for (int i = 2; i < numberOfConstraints+1 ; ++i) {
        if (l[i][M-1]/l[i][minColumnIndex] < minimum) {
            minimum=l[i][M-1]/l[i][minColumnIndex];
            minColumnIndex1=i;

            }
   }
	cout <<"le ligne pivot  est :"<<endl;
	    for (int j = 0; j < M/2+1; ++j) {
    	cout << "+-----------+" ;
       
	}
		 cout <<endl;

    
	    for (int j = 0; j < M; ++j) {
            cout << l[minColumnIndex1][j] << "   |   ";
        }
                cout <<endl;
    for (int j = 0; j < M/2+1; ++j) {
    	cout << "+-----------+" ;
       
	}
	 cout <<endl;
	 cout << "car "<<l[minColumnIndex1][M-1]<<"/"<<l[minColumnIndex1][minColumnIndex]<<"le minimum positif"<<endl;
    double  pivot=  l[minColumnIndex1][minColumnIndex];
    cout<<"le pivot est :"<<pivot<<endl;
    cout <<"Etape 1 : "<<"L"<< minColumnIndex1<<" / "<< pivot<<endl;
        
		
		for (int j = 0; j < M/2+1; ++j) {
    	cout << "+-----------+" ;
       
	}
	cout <<endl;
for (int j = 0; j < M; ++j) {

       l[minColumnIndex1][j]=l[minColumnIndex1][j]/pivot;
  }
  
      for (int i = 0; i < numberOfConstraints + 1; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << l[i][j] << "   |   ";
        }
        cout <<endl;
    for (int j = 0; j < M/2+1; ++j) {
    	cout << "+-----------+" ;
       
	}
	 cout <<endl;

    }

double o[numberOfConstraints+1];
for (int i = 0; i < numberOfConstraints+1 ; ++i) {
        o[i]=l[i][minColumnIndex];
        }

    for (int i = 0; i < numberOfConstraints+1 ; ++i) {
    	        	cout<<"Etape 2 L"<<i<<"= L"<<i<<"-("<<minNegative<<")L"<<minColumnIndex1<<endl;
        for (int j = 0; j < M; ++j) {

            if(i==minColumnIndex1){
                continue;
            }
            l[i][j]=l[i][j]-(o[i]*l[minColumnIndex1][j]);

        }
      }
      
          for (int j = 0; j < M/2+1; ++j) {
    	cout << "+-----------+" ;
       
	}
	cout <<endl;

  
      for (int i = 0; i < numberOfConstraints + 1; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << l[i][j] << "   |   ";
        }
        cout <<endl;
    for (int j = 0; j < M/2+1; ++j) {
    	cout << "+-----------+" ;
       
	}
	 cout <<endl;

    }
        for (int j = 0; j < M; ++j) {
            if(l[0][j]<0){
                goto start;
            }
        }

cout<<"conclusion";
   cout<< "Z*= "<<l[0][M-1]<<endl;
   for (int j = 1;  j<= numberOfProducts ; ++j){
   for (int i = 0; i < numberOfConstraints+1 ; ++i) {
        if(l[i][j]==1){
            cout<< "X"<<j<<"*="<<l[i][M-1]<<endl;
            }
   }
   }
   }

int main(){
            cout << " maximization problem." << endl;
                int numberOfProducts = getNumberOfProducts();
                int numberOfConstraints = getNumberOfConstraints();
                calculerMax(numberOfProducts,numberOfConstraints);
    return 0;
}
