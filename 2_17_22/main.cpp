#include "linkedqueue.h"
#include "simulation.h"
//#include "book.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void setSimulationParameters(int& sTime, int& numOfServers,
                             int& transTime,
                             int& tBetweenCArrival);
void runSimulation();
int main()
{
	runSimulation();
	return 0;
}
void setSimulationParameters(int& sTime, int& numOfServers,
                             int& transTime,
                             int& tBetweenCArrival)
{
    cout << "Enter the simulation time: ";
    cin >> sTime;
    cout << endl;

    cout << "Enter the number of servers: ";
    cin >> numOfServers;
    cout << endl;

    cout << "Enter the transaction time: ";
    cin >> transTime; 
    cout << endl;

    cout << "Enter the time between customer arrivals: ";
    cin >> tBetweenCArrival;
    cout << endl;
}

void runSimulation()
{
	int clock;
	int simulationTime, numServers, transTime, betweenTime;
	setSimulationParameters(simulationTime, numServers, transTime, betweenTime);
	int numCustomers = 1;
	
	serverListType servers(numServers);
	waitingCustomerQueueType customers;
	customers.enqueue(customerType(numCustomers++, 0, 0, transTime));
	
	for(clock = 1; clock <= simulationTime; clock++)
	{
		servers.updateServers(cout);
		if(!customers.isEmptyQueue())
			customers.updateWaitingQueue();
		if(clock % betweenTime == 0)
			customers.enqueue(customerType(numCustomers++, clock, 0, transTime));
		if(servers.getNumberOfBusyServers() < numServers && !customers.isEmptyQueue())
		{
			servers.setServerBusy(servers.getFreeServerID(), customers.dequeue());
		}
	}
}