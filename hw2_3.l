%{ 
   unsigned word_count=0;
    unsigned equal_count=0;
    unsigned l_parentheses_count=0;
    unsigned r_parentheses_count=0;
    unsigned mark_count=0;
    unsigned number_count=0;
%}
F ({N}+\.{N}+)
N [0-9]
W [A-Za-z]
L "{" 
R "}" 
E "=" 
M "~"|"`"|"!"|"@"|"#"|"$"|"%"|"^"|"&"|"*"|"("|")"|"-"|"_"|"+"|"["|"]"|"\\"|"|"|":"|";"|["]|"'"|"<"|","|">"|"."|"?"|"/"
%%
    /*규칙절*/
[\n ]+  ;
[\t ]+  ;
[\r ]+  ;
{N}+ {number_count++;}
{F} {number_count++;}
{W}+ {word_count++;}
{L} {l_parentheses_count++;}
{R} {r_parentheses_count++;}
{E} {equal_count++;}
{M} {mark_count++;}

. {ECHO;} 
%%

/*서브루틴*/
int yywrap(){
    return 1;
}

int main(void){
    yylex();
    printf("word = %d\n", word_count);
    printf("'=' = %d\n",equal_count);
    printf("'{' = %d\n",l_parentheses_count);
    printf("'}' = %d\n", r_parentheses_count);
    printf("mark = %d\n", mark_count);
    printf("number = %d\n", number_count);

    return 0;
}
