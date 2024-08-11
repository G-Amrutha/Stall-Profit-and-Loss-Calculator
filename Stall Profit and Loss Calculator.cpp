//816117625
//Amrutha Ginkala

#include <iostream>
#include <fstream>

using namespace std;

struct Stall {
    string name;
    double income;
    double expenses;
    double net;
};

int main()
{

    double tprofit_loss = 0, most_profit;
    Stall tmp;
    int n = 0;
    Stall Stalls[100];
    bool loop = true;

    ifstream f ("C:\\comp1602asg1\\asg1\\stalls.txt");
    
    ofstream of ("C:\\comp1602asg1\\asg1\\stalls_output.txt");

    if (!f.is_open()) {
		cout << "Error opening input file. Aborting ...";
		return 0;
	}

    if (!of.is_open()) {
		cout << "Error opening output file. Aborting ...";
		return 0;
	}
	
    while (loop) {
        f >> tmp.name;

        if (tmp.name == "XXXXXX" || tmp.name == "xxxxxx") {
            loop = false;
            continue;
        }

        f >> tmp.income; 
        f >> tmp.expenses; 

        tmp.net = tmp.income - tmp.expenses;
        tprofit_loss += tmp.net;

        Stalls[n] = tmp;

        n++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (Stalls[i].net < Stalls[j].net) {
                Stall tmp = Stalls[i];
                Stalls[i] = Stalls[j];
                Stalls[j] = tmp;
            }
        }
    }

    of << "Stall name\t| " 
       << "Net Income" << endl;
       
    of << "---------------\t"
       << "|-----------" << endl;
	   

    for (int i = 0; i < n; i++)
        of << Stalls[i].name << "\t\t" << "|" << Stalls[i].net << endl;
        
    of << endl;

    of << "The number of stalls in the bazaar were " << n << endl;
    
    of << endl;
    
    if (tprofit_loss < 0)
        of << "Total loss of bazaar is " << tprofit_loss << endl;
    else
        of << "Total profit of bazaar is " << tprofit_loss << endl;
        
    of << endl;
    
    of << "Stalls Which Made Profits: "<<endl;
   for (int i = 0; i < n; i++)
   {
       if ((Stalls[i].net) > 0)
           of << Stalls[i].name << endl;
   }
   of << endl;

    of << "The stall with most profit is ";
    
for (int k = 0; k < n; k++) 
    for (int i = 0; i < n; i++){
        if (Stalls[i].net < 0)
        {
            for (int j = i + 1; j < n; ++j){
                Stalls[j - 1] = Stalls[j];
				}
				n--;
        }
    }
    for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
            if (Stalls[i].net > Stalls[j].net) {
                Stall tmp = Stalls[i];
                Stalls[i] = Stalls[j];
                Stalls[j] = tmp;
            }
        }
    }
    for (int i = 0; i < 1; i++)
        of << Stalls[i].name << endl;
        of <<endl;
        

    of << "Stalls Which Made Profit In Increasing Order Of Profit:"<<endl;
    

    for (int i = 0; i < n; i++)
        of << Stalls[i].name << endl;

    of << endl;
    return 0;
}
