#include <stdio.h>

int main(){
	int count3 = 0;
	int i;
	int count = 0;												//Counts curly braces
	int count2 = 0;												//Counts open parenthesis
	int flag = 0;												//True if ch is inside ''
	char ch;													//Character being read by getchar()
	int flag2 = 0;												//True if previous character was space
	int flag3 = 0;												//True if previous character was tab
	int flag4 = 0;												//True if ch is inside " "
	int flag5 = 0;												//True if ch is \	
	int flag7 = 0;												//True if ch is \n
	
	while((ch = getchar()) != EOF){
		if( count3 == 1){
			count3 = 2;
		}else if( count3 == 2){
			count3 = 0;
			flag5 = 0;
		}
		
		if( ch == '#' ){
			do{
				printf("%c",ch);
			}while((ch = getchar()) != '\n');
		}
		
		if( ch == '\n' || ch == '\t'){
			flag3 = 1;
		}else{
			flag3 = 0;
		}
		
		if( ch == '\\'){
			flag5 = !flag5;
			count3 = 1;
		}
		
		if( ch == '\"' ){
			if( flag5 == 0){
				flag4 = !flag4;
			}
		}
		
		if(ch == '\''){
			if(flag5 == 0){
				flag = !flag;
				//printf("%d",flag);
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
		
		if(ch == '{'){
			if(flag == 0 && flag4 == 0){
				printf("\n");
				for(i = 1; i <= count; i++){
					printf("\t");
				}
				count++;
			}else if( flag != 0 || flag4 != 0){
				putchar(ch);
				continue;
			}
		}else if(ch == '}'){
			if( flag == 0 && flag4 == 0 ){
				count--;
			}
		}
		
		if( ch == '(' ){
			if( flag == 0 && flag4 == 0){
				count2++;
							//printf("%d",count2);
			}
		}else if( ch == ')'){
			if( flag == 0 && flag4 == 0){
				count2--;
							//printf("%d",count2);
			}
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
			
			if(flag2 == 0 && flag3 == 0){
				printf("%c",ch);
			}
		}
	}
}
