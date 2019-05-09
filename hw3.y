%{
#include<stdio.h>
int yylex();
int func=0;
int mark = 0;
int int_number = 0;
int char_number = 0;
int pointer_number = 0;
int array_number = 0;
int selection_number = 0;
int iter_number = 0;
int return_number = 0;
int int_check=0;
int char_check=0;
int pointer_check=0;
int array_check=0;
int functioncheck=0;
int pointerfunctioncheck=0;
%}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF 
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%

primary_expression
	: IDENTIFIER
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')' {func++;}
	| postfix_expression '(' argument_expression_list ')' {func++;} 
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER {mark++;} 
	| postfix_expression INC_OP   {mark++;}
	| postfix_expression DEC_OP   {mark++;}
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression   {mark++;}
	| DEC_OP unary_expression   {mark++;}
	| unary_operator cast_expression
	| SIZEOF unary_expression 
	| SIZEOF '(' type_name ')' 
	;

unary_operator
	: '&' 
	| '*' 
	| '+' 
	| '-' 
	| '~' 
	| '!' 
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression {mark++;}    
	| multiplicative_expression '/' cast_expression   {mark++;}
	| multiplicative_expression '%' cast_expression   {mark++;}
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression   {mark++;}
	| additive_expression '-' multiplicative_expression   {mark++;}
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression   {mark++;}
	| shift_expression RIGHT_OP additive_expression   {mark++;}
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression   {mark++;}
	| relational_expression '>' shift_expression   {mark++;}
	| relational_expression LE_OP shift_expression   {mark++;}
	| relational_expression GE_OP shift_expression   {mark++;}
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression   {mark++;}
	| equality_expression NE_OP relational_expression   {mark++;}
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression   {mark++;}
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression  {mark++;}
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression {mark++;}  
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression  {mark++;}
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression  {mark++;}
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression 
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression  
	;

assignment_operator
	: '=' {mark++;}
	| MUL_ASSIGN {mark++;}
	| DIV_ASSIGN {mark++;}
	| MOD_ASSIGN {mark++;}
	| ADD_ASSIGN {mark++;}
	| SUB_ASSIGN {mark++;}
	| LEFT_ASSIGN {mark++;}
	| RIGHT_ASSIGN {mark++;}
	| AND_ASSIGN {mark++;}
	| XOR_ASSIGN {mark++;}
	| OR_ASSIGN {mark++;}
	;

expression
	: assignment_expression 
	| expression ',' assignment_expression    
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';' 
	| declaration_specifiers init_declarator_list ';'   
	{
		if(functioncheck==1){
			if(pointerfunctioncheck==1){
				func++; pointerfunctioncheck=0;
			}
			functioncheck=0; char_check=0; int_check=0;
		}
	}
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers 
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator  
	| init_declarator_list ',' init_declarator  
	;

init_declarator
	: declarator
	{
		if(char_check==1){
			char_number++;
		}
		if(int_check==1){
			int_number++;
		}
		if(pointer_check==1){
			pointer_check=0;
			if(functioncheck==0) pointer_number++;
		}
		
	}
	| declarator '=' initializer  {
		if(char_check==1)
			char_number++;
		if(int_check==1)
			int_number++;
		if(pointer_check==1){
			pointer_check=0;
			if(functioncheck==0) pointer_number++;
		}
		mark++;}
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID {int_check=0; char_check=0;}
	| CHAR {int_check=0; char_check=1; functioncheck=0;}
	| SHORT {int_check=0; char_check=0; functioncheck=0;}
	| INT {int_check=1; char_check=0; functioncheck=0;}
	| LONG {int_check=0; char_check=0; functioncheck=0;}
	| FLOAT {int_check=0; char_check=0; functioncheck=0;}
	| DOUBLE {int_check=0; char_check=0; functioncheck=0;}
	| SIGNED 
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression {mark++;} 
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
	: pointer direct_declarator {pointer_check=1; if(array_check==1) {array_number++;} array_check=0; }
	| direct_declarator {if(array_check==1) {array_number++;} array_check=0;} 
	;

direct_declarator
	: IDENTIFIER 
	| '(' declarator ')' {pointerfunctioncheck=1;}
	| direct_declarator '[' constant_expression ']' {array_check=1; } 
	| direct_declarator '[' ']' {array_check=1; }  
	| direct_declarator '(' parameter_type_list ')' {functioncheck=1; char_check=0; int_check=0;}
	| direct_declarator '(' identifier_list ')' 
	| direct_declarator '(' ')' {functioncheck=1; char_check=0; int_check=0;}
	;

pointer
	: '*' 
	| '*' type_qualifier_list 
	| '*' pointer 
	| '*' type_qualifier_list pointer 
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list {char_check=0; int_check=0;}
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration  
	| parameter_list ',' parameter_declaration  
	;

parameter_declaration
	: declaration_specifiers declarator {
		if(int_check==1) 
			int_number++;
		if(char_check==1)
			char_number++;
	} 
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator {if(array_check==1) {array_number++;} array_check=0;} 
	| pointer direct_abstract_declarator {if(array_check==1) {array_number++;} array_check=0; } 
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']' {array_check=1; }
	| '[' constant_expression ']' {array_check=1; }
	| direct_abstract_declarator '[' ']' { array_check=1; }
	| direct_abstract_declarator '[' constant_expression ']' {array_check=1; }
	| '(' ')' 
	| '(' parameter_type_list ')' 
	| direct_abstract_declarator '(' ')' 
	| direct_abstract_declarator '(' parameter_type_list ')' 
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration  
	| declaration_list declaration 
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement {selection_number++;}
	| SWITCH '(' expression ')' statement{selection_number++;}
	;

iteration_statement
	: WHILE '(' expression ')' statement {iter_number++;}
	| DO statement WHILE '(' expression ')' ';' {iter_number++;}
	| FOR '(' expression_statement expression_statement ')' statement	{iter_number++;}
	| FOR '(' expression_statement expression_statement expression ')' statement {iter_number++;}
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';' {return_number++;}
	| RETURN expression ';' {return_number++;}
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| '#' IDENTIFIER '<' IDENTIFIER '.' IDENTIFIER '>'
	| '#' IDENTIFIER IDENTIFIER CONSTANT
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {func++; functioncheck=0;}
	| declaration_specifiers declarator compound_statement {func++; functioncheck=0;}
	| declarator declaration_list compound_statement {func++; functioncheck=0;}
	| declarator compound_statement {func++; functioncheck=0;}
	;

%%
#include <stdio.h>

extern char yytext[];



int main(void){
yyparse();
printf("func = %d\n",func);
printf("mark = %d\n", mark );
printf("int_number = %d\n", int_number);
printf("char_number = %d\n", char_number );
printf("pointer_number = %d\n", pointer_number );
printf("array_number = %d\n", array_number );
printf("selection_number= %d\n", selection_number );
printf("iter_number = %d\n", iter_number );
printf("return_number = %d\n", return_number );
}

yyerror(s)
char *s;
{
	fflush(stdout);
	
}