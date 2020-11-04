/*
YOU HAVE TO WRITE THE REQUIRED  FUNCTIONS. YOU CAN ADD NEW FUNCTIONS IF YOU NEED.
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include <fstream>

#include "counter.h"

using namespace std;

	
int Counter::findindex(Token *arr,char elem[]){
	//THIS FUNCTION WILL BE CODED BY YOU
	return 0;
} 

bool Counter::contains(char *token, char target){
	//THIS FUNCTION WILL BE CODED BY YOU
	if (strstr(&target,token))
	{
	cout << "true";
	}
	
	return 0;
}

void Counter::read_and_count(){
	//THIS FUNCTION WILL BE CODED BY YOU
	Counter counter;
	FILE* piApprox = fopen("pi_approximate", "r+");
	fseek(piApprox, 0, SEEK_SET);
	int i=0;
	Token tempTokenArray[100];
	//int k=0;
	//char currentToken[2];
	//char tokens[198];
	while (!feof(piApprox)) {
		fread(tempTokenArray[i].token, 2, 1, piApprox);
		bool didCountIncrease = false;
		for (auto character : Counter::token_array)
		{
			if (strcmp(tempTokenArray[i].token, character.token) == 0)
			{
				character.count++;
				didCountIncrease = true;
			}
		}
		if (didCountIncrease)
		{
			cout<<"increased";
			continue;
		}
		
		if (atoi(tempTokenArray[i].token) >= 10  )
		{
			//cout << tempTokenArray[i].token <<endl;
			Counter::token_array[i] = tempTokenArray[i];
			Counter::token_count ++;
			Counter::token_array[i].count ++;
			cout << Counter::token_array[i].count <<endl;
			if (strcmp(Counter::token_array[i].token ,"14") == 0)
			{
				cout << Counter::token_array[i].token<<endl;
			}
			
		}
			i+=1;
		
	}
	fseek(piApprox, 3, SEEK_SET);
	while (!feof(piApprox)) {
		//fread(&tokens[i], 2, 1, piApprox);
		//fread(&counter.token_array[i], 2, 1, piApprox);
		fread(Counter::token_array[i].token, 2, 1, piApprox);
		//cout << Counter::token_array[100].token <<endl;
		//cout << counter.token_array->token<<endl;
		//cout << counter.token_array->token << endl;
		//cout << tokens[0] <<endl;
		i+=1;
	}
	
	contains(&counter.token_array->token[0],*counter.token_array->token);

	
	
}


Token *Counter::get_most_common_three(){
	//THIS FUNCTION WILL BE CODED BY YOU
	return 0;
}
