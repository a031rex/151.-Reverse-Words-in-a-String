/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"



char *trimwhitespace(char *str)
{
	char *end;

	// Trim leading space
	while(isspace(*str)) str++;

	if(*str == 0)  // All spaces?
	return str;

	// Trim trailing space
	end = str + strlen(str) - 1;
	while(end > str && isspace(*end)) end--;

	// Write new null terminator
	*(end+1) = 0;

	return str;
}

void strip_extra_spaces(char* str) {
  int i,x;
  for(i=x=1; str[i]; ++i)
    if(!isspace(str[i]) || (i>0 && !isspace(str[i-1])))
      str[x++] = str[i];
  str[x] = '\0';
}


void reverseWords(char *s) {

	int s_size = strlen(s);
	char result[s_size+1];
	int pos = 0;	//紀錄word的開頭
	int i = 0;

	memset(result,' ',s_size);
	
	//Create a array, copy word to right position directly
	for(i = 0; i < s_size ; i++)
	{
		if(isspace(s[i]))
		{
			strncpy(result + (s_size -i), s+pos, i-pos);//從前面複製到後面
			pos = i + 1;
		}
		
	}
	strncpy(result, s + pos, s_size-pos);
	result[s_size] = '\0';
	memcpy(s,trimwhitespace(result),s_size);
	strip_extra_spaces(s);
	
	printf("%s\n",s);
	
}

void main()
{
	char s[] ="   Rex      Amy";
	reverseWords(s);
}



