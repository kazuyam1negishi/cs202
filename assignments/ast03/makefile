# Make file.

OBJS	= stocksMain.o stockInvestorImp.o investorTypeImp.o stocksPortfolioImp.o fileIOImp.o 
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g

DEPS	= stockInvestor.h investorType.h stocksPortfolio.h fileIO.h    

all: stocksMain

stocksMain: $(OBJS)
	$(CC) $(CCFLAGS) -o stocksMain $(OBJS)

stocksMain.o:	stocksMain.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c stocksMain.cpp

stockInvestorImp.o: stockInvestorImp.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c stockInvestorImp.cpp

investorTypeImp.o: investorTypeImp.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c investorTypeImp.cpp

stocksPortfolioImp.o: stocksPortfolioImp.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c stocksPortfolioImp.cpp

fileIOImp.o: fileIOImp.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c fileIOImp.cpp
	

# -----
# clean by removing object files.

clean:
	rm $(OBJS) stocksMain
