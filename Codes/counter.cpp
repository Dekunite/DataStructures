/*
YOU HAVE TO WRITE THE REQUIRED  FUNCTIONS. YOU CAN ADD NEW FUNCTIONS IF YOU NEED.
*/

/* @Author
Student Name: <Muhammet Derviş Kopuz>
Student ID : <504201531>
Date: <10.11.2020> */


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
	return -1;
} 

bool Counter::contains(char *token, char target){
	//THIS FUNCTION WILL BE CODED BY YOU
	if (*token == target)
		{
			return true;
		}
	
	return false;
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
	bool newToken = false;
	bool *newTokenPtr = &newToken;
	char isPresent;
	char prevChar;
	
	while (!feof(piApprox)) {
		fread(&char1, 1, 1, piApprox);
		if (inDecimal)
		{
			int j = 0;
			
			if (i != 0)
			{
				tempTokenArray[i-1].token[j] = prevChar;
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
			}
			i+=1;
			if (i == fileSize-2)
			{
				break;
			}
			prevChar = char1;
		}
		if (contains(&char1, '.'))
		{
			inDecimal = true;
		}
	}
}


Token *Counter::get_most_common_three(){
	//THIS FUNCTION WILL BE CODED BY YOU
	int COMMON_SIZE = 3;
	static Token mostCommon3Tokens[3];
	Token* ptr;

	for (int i = 0; i < Counter::token_count; i++)
	{
		for (int j = 0; j < COMMON_SIZE; j++)
			{
				if (Counter::token_array[i].count >= mostCommon3Tokens[j].count)
				{
					if (Counter::token_array[i].token[0] == mostCommon3Tokens[j].token[0]
					&& Counter::token_array[i].token[1] == mostCommon3Tokens[j].token[1])
					{
						break;
					}
					mostCommon3Tokens[j+2] = mostCommon3Tokens[j+1];
					mostCommon3Tokens[j+1] = mostCommon3Tokens[j];

					mostCommon3Tokens[j].token[0] = Counter::token_array[i].token[0];
					mostCommon3Tokens[j].token[1] = Counter::token_array[i].token[1];
					mostCommon3Tokens[j].token[2] = Counter::token_array[i].token[2];
					mostCommon3Tokens[j].count = Counter::token_array[i].count;
					break;
				} 
			}
	}

	ptr = &mostCommon3Tokens[0];

	return ptr;
}
