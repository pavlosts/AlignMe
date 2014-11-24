#include <stdio.h>

int main(){
	int count = 0;												//Counts curly braces
	int count2 = 0;												//Counts open parenthesis
	int flag = 0;												//True if ch is inside ''
	char ch;													//Character being read by getchar()
	int i;
	
	while((ch = getchar()) != EOF){
		if(ch == '{'){
			count++;
			printf("\n");
		}else if(ch == '}'){
			count--;
			//printf("\n");
		}
		if(ch == '\''){
			flag = !flag;
		}
		if( ch == '(' ){
			count2++;
		}else if( ch == ')'){
			count2--;
		}
		if( (ch == ';' || ch == '{') && ch != '}' ){
			printf("%c",ch);
			if(flag == 0 && count2 == 0){
				printf("\n");
				for(i = 1; i <= count; i++){
					printf("\t");
				}
			}
		}else{
			printf("%c",ch);
		}
	}
}
