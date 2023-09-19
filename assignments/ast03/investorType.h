#ifndef INVESTORTYPE_H
#define INVESTORTYPE_H
#include<string>
#include<fstream>
#include"stockInvestor.h"
using namespace std;

class investorType:public stockInvestor
{
public:
  

  investorType(); //Default constructor
  investorType(string id, string fName, string lName,
    string tyName, string stName, int stCount, double stPrice, 
    ostream &output);

  void setInvestorInfo(string id, string fName, string lName,
    string tyName, string stName, int stCount, double stPrice);

  void setType(string tyName);
  void setStockName(string stName);
  void setStockCount(int stCount);
  void setStockPrice(double stPrice);

  string getID() const; //Function overriding
  string getFirstName() const;
  string getLastName() const;
  string getType() const;
  string getStockName() const;
  double getStockPrice() const;
  double getStockCount() const;

  void print(ostream &outFile) const;
  void writeDataToFile(ofstream &outFile, investorType tempObj);
private:
  string typeName;
  string stockName;
  int stockCount;
  double stockPrice;
};


#endif
