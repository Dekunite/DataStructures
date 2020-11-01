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
	fseek(piApprox, 2, SEEK_SET);
	int i=0;
	//int k=0;
	//char currentToken[2];
	//char tokens[198];
	while (!feof(piApprox)) {
		//fread(&tokens[i], 2, 1, piApprox);
		//fread(&currentToken, 2, 1, piApprox);
		fread(Counter::token_array[i].token, 2, 1, piApprox);
		//cout << Counter::token_array[49].token << endl;
		/*
		if (sizeof(currentToken) == 2)
		{
			for (int j = 0; j < 100; j++)
			{
				char* isPresent = NULL;
				isPresent = strstr(counter.token_array[j].token,currentToken);
				if (isPresent)
				{
					counter.token_array[j].count++;
				} else
				{
					&Counter::token_array->token = currentToken;
					counter.token_count++;
				}
				
				
			}
			
		}
		*/
		
		//cout << counter.token_array[i].token <<endl;
		//cout << counter.token_array->token<<endl;
		//cout << counter.token_array->token << endl;
		//cout << tokens[0] <<endl;
		i+=1;
	}
	fseek(piApprox, 3, SEEK_SET);
	while (!feof(piApprox)) {
		//fread(&tokens[i], 2, 1, piApprox);
		//fread(&counter.token_array[i], 2, 1, piApprox);
		fread(Counter::token_array[i].token, 2, 1, piApprox);
		cout << Counter::token_array[100].token <<endl;
		//cout << counter.token_array->token<<endl;
		//cout << counter.token_array->token << endl;
		//cout << tokens[0] <<endl;
		i+=1;
	}
	for ( i = 0; i <= 100; i++)
	{
		
		
	}
	
	contains(&counter.token_array->token[0],*counter.token_array->token);

	
	
}


Token *Counter::get_most_common_three(){
	//THIS FUNCTION WILL BE CODED BY YOU
	return 0;
}
