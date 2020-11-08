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
	char* order;
	for (int i = 0; i < Counter::token_count ; i++)
	{
		order = strstr(arr[i].token, elem);
		if (order != NULL)
		{
			return i;
		}
		
	}
	
	//int index = strchr(arr->token, elem[0]) - arr->token;

	return -1;
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
	fseek(piApprox, 0, SEEK_END);
	long fileSize = ftell(piApprox);
	fseek(piApprox, 0, SEEK_SET);
	char char1;
	int i=0;
	int k = 0;
	bool inDecimal = false;
	Token tempTokenArray[100];
	Counter::token_count = 0;
	bool newToken = false;
	bool *newTokenPtr = &newToken;
	char isPresent;
	//int k=0;
	//char currentToken[2];
	//char tokens[198];
	while (!feof(piApprox)) {
		fread(&char1, 1, 1, piApprox);
		if (inDecimal)
		{
			int j = 0;
			
			tempTokenArray[i].token[j] = char1;
			if (i != 0)
			{
			tempTokenArray[i-1].token[j+1] = char1;
			//saçma karakterler gelmesin diye
			tempTokenArray[i-1].token[j+2] = 0;

			*newTokenPtr = false;
			for (int l = 0; l <= Counter::token_count; l++)
			{
			char* isPresentPtr = &isPresent;
			isPresentPtr = strstr(Counter::token_array[l].token,tempTokenArray[i-1].token);
			if (isPresentPtr == NULL)
			{
				*newTokenPtr = true;
			} else
			{
				*newTokenPtr = false;
				Counter::token_array[l].count++;
				break;
			}
			}

			if (newToken)
			{
			Counter::token_array[k].token[0] = tempTokenArray[i-1].token[0];
			Counter::token_array[k].token[1] = tempTokenArray[i-1].token[1];
			Counter::token_array[k].count++;
			Counter::token_count++;
			k++;
			}
			std::cout << k-1 << ": " << Counter::token_array[k-1].token << endl;

			
			if (strcmp(tempTokenArray[i-1].token,"35")== 0)
			{
				std::cout <<"found 35 yay" <<endl;
			}
			if (strcmp(tempTokenArray[i-1].token,"9 ")== 0)
			{
				std::cout <<"found 9  yay" <<endl;
			}
			
			}
			i+=1;
			if (i == fileSize-3)
			{
				break;
			}
			
		}
		if (strcmp(&char1,".") == 0)
		{
			inDecimal = true;
		}
		//fclose(piApprox);
	}
	//findindex(Counter::token_array, "14");
	
	//contains(&counter.token_array->token[0],*counter.token_array->token);

	
	
}


Token *Counter::get_most_common_three(){
	//THIS FUNCTION WILL BE CODED BY YOU
	int COMMON_SIZE = 3;
	Token mostCommon3Tokens[COMMON_SIZE];
	Token* ptr;
	int currentMax = 0;

	for (int i = 0; i < Counter::token_count; i++)
	{
		if (Counter::token_array[i].count > currentMax)
		{
			currentMax = Counter::token_array[i].count;
			for (int j = 0; j < COMMON_SIZE; j++)
			{
				if (currentMax >= mostCommon3Tokens[j].count)
				{
					mostCommon3Tokens[j+2] = mostCommon3Tokens[j+1];
					mostCommon3Tokens[j+1] = mostCommon3Tokens[j];

					mostCommon3Tokens[j].token[0] = Counter::token_array[i].token[0];
					mostCommon3Tokens[j].token[1] = Counter::token_array[i].token[1];
					mostCommon3Tokens[j].token[2] = Counter::token_array[i].token[2];
					mostCommon3Tokens[j].count = currentMax;
					break;
				}
				
			}
			
		}
		
		
	}
	
	for (int k = 0; k < COMMON_SIZE; k++)
	{
	cout << mostCommon3Tokens[k].token << " " << mostCommon3Tokens[k].count <<endl;
	}

	
	
	return ptr;
}
