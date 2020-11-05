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
	fseek(piApprox, 0, SEEK_END);
	long fileSize = ftell(piApprox);
	fseek(piApprox, 0, SEEK_SET);
	char char1;
	int i=0;
	int k = 0;
	bool inDecimal = false;
	Token tempTokenArray[100];
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

			for (int l = 0; l < 100; l++)
			{
			string counterArray(Counter::token_array[l].token);
			string token(tempTokenArray[i-1].token);
			cout << strstr(tempTokenArray[i-1].token,Counter::token_array[l].token) <<endl;
			if (counterArray.find(token))
			{
			Counter::token_array[k].token[0] = tempTokenArray[i-1].token[0];
			Counter::token_array[k].token[1] = tempTokenArray[i-1].token[1];
			}}
			
			cout << tempTokenArray[i-1].token<<endl;
			if (strcmp(tempTokenArray[i-1].token,"35")== 0)
			{
				cout<<"found 35 yay" <<endl;
			}
			if (strcmp(tempTokenArray[i-1].token,"9 ")== 0)
			{
				cout<<"found 9  yay" <<endl;
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
		
		
	}
	
	contains(&counter.token_array->token[0],*counter.token_array->token);

	
	
}


Token *Counter::get_most_common_three(){
	//THIS FUNCTION WILL BE CODED BY YOU
	return 0;
}
