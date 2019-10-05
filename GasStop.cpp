/*
Author: Sergio Hernandez Castillo, A01025210
Date: 02/10/2019
Description: This program calculates the minimum amount of times a trucker would need to stop for gas while on his way to Acapulco from CDMX
Complexity: This program/algorithm has a O(n) complexity due to having only one while loop.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void scramble(int stations, int distances[], int distance)
{
  srand(time(NULL));

	for(int i = 0; i < stations; i++)
  {
    distances[i] = rand() % distance;
	}//Close for
}//Close scramble

void printDistances(int stations, int distances[])
{
  cout << "The distances to the gas stations are: " << endl;

  for (int i = 0; i < stations; i++)
  {
    cout << "\nGas Station " << i + 1 << ": " << distances[i];
  }//Close for

  cout << "\n" << endl;
}//Close printDistances

int forceStop(int distance, int distances[], int stations)
{
  int i = 0, kmRun = 0, check = 0;

  while (i != stations)
  {
    kmRun += distances[i];

    if (kmRun > distance)
    {
      i--;
      check++;
      cout << "Fill up the tank in station: " << i + 1 << endl;
      kmRun = 0;
    }//Close if

    i++;
  }//Close while

  if (check = 0)
  {
    cout << "You don't need to fill up gas along the whole route." << endl;
  }//Close if
}//Close forceStop

int main()
{
  int distance = 150, stations, stationDist;

  //The non-stop distance is also the full amount of gas in the truck
  cout << "\nThe distance that the truck can go non-stop is: " << distance << endl;

  cout << "\nEnter the amount of gas stations on the way: " << endl;
  cin >> stations;
  cout << "\n";

  int distances[stations];

  scramble(stations, distances, distance);
  sort(distances, distances + stations);
  printDistances(stations, distances);
  forceStop(distance, distances, stations);

  return 0;
}//Close main
