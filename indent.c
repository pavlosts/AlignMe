#include <stdio.h>

int main(){
	int i;
	int count = 0;												//Counts curly braces
	int count2 = 0;												//Counts open parenthesis
	int flag = 0;												//True if ch is inside ''
	char ch;													//Character being read by getchar()
	int flag2 = 0;												//True if previous character was space
	int flag3 = 0;												//True if previous character was tab
	int flag4 = 0;												//True if ch is inside " "
	int flag5 = 0;												//True if ch is \	
	
	while((ch = getchar()) != EOF){
		
		if( ch == '\n'){
			continue;
		}
		
		if( ch == '\t'){
			flag3++;
			if(flag3 == 1){
				printf("\t");
			}
		}else{
			flag3=0;
		}
		
		if( ch == '\\'){
			flag5 = !flag5;
		}
		
		if( ch == '\"' ){
			if( flag5 != 0){
				flag4 = !flag4;
			}
		}
		
		if( ch == ' '){
			flag2++;
			if(flag2 == 1){
				printf(" ");
			}
		}else{
			flag2 = 0;
		}
		
		if(ch == '\''){
			if(flag5 != 0){
				flag = !flag;
			}
		}
		
		if(ch == '{'){
			count++;
			if(flag == 0 && flag4 == 0){
				printf("\n");
			}
		}else if(ch == '}'){
			count--;
			//printf("\n");
		}
		
		if( ch == '(' ){
			count2++;
		}else if( ch == ')'){
			count2--;
		}
		
		if( ch == ';' || ch == '{' || ch == '}' ){
			printf("%c",ch);
			
			if(flag == 0 && count2 == 0 && flag4 == 0){
				printf("\n");
				
				for(i = 1; i <= count; i++){
					printf("\t");
				}
			}
		}else{
			
			if(flag2 == 0){
				printf("%c",ch);
			}
		}
	}
}
