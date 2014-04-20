#include <stdio.h>
#include <string.h>
#include <math.h>

#define OP_TYPE 0
#define NUM_TYPE 1
#define LEFT_BRACKET_TYPE 2
#define RIGHT_BRACKET_TYPE 3
#define VAR_TYPE 4
#define FUNC_TYPE 5

#define ADD 0
#define SUB 4
#define MUL 1
#define DIV 5

#define precedence(op) ((op) & 3)

#define is_operator(tok) ((tok).type == OP_TYPE)

double state[30];

typedef struct Token {
    int type;
    int contents;
    double num_contents;
} Token;

typedef struct Stack {
    Token tokens[10000];
    int fim;
} Stack;

void push(Stack* stack, Token token) {
    stack->tokens[stack->fim++] = token;
}

Token pop(Stack* stack) {
    return stack->tokens[--stack->fim];
}

int empty(Stack* stack) {
    return !stack->fim;
}

int parse (char* string, Stack *stack) {
    int i;
    char c;
    
    Stack op_stack = {0};
    
    for (i=0; string[i] != '\0'; i++) {
        c = string[i];
        
        Token token;
        
        switch (c) {
            case '*': token.type = OP_TYPE; 
                      token.contents = MUL;
                      break;
                      
            case '+': token.type = OP_TYPE;
                      token.contents = ADD;
                      break;
                      
            case '-': 
                token.type = OP_TYPE;
                token.contents = SUB;
                break;
                      
            case '/': token.type = OP_TYPE;
                      token.contents = DIV;
                      break;
                      
            case '(': token.type = LEFT_BRACKET_TYPE;
                      break;
            
            case ')': token.type = RIGHT_BRACKET_TYPE;
                      break;
            
            default:
                if ('0' <= c && c <= '9') {
                    token.type = NUM_TYPE;
                    token.num_contents = c - '0';
                    while ('0' <= string[i+1] && string[i+1] <= '9') {
                        token.num_contents = token.num_contents * 10 + string[i+1] - '0';
                        i++;
                    }
                }
                
                
               else if ('a' <= c && c <= 'z') {
                    token.type = VAR_TYPE;
                    token.contents = c-'a';
                }  
        }
        
        if (token.type == NUM_TYPE || 
            token.type == VAR_TYPE) 
            push(stack, token);
            
        else if (token.type == LEFT_BRACKET_TYPE) 
            push(&op_stack, token);
        
        else if (token.type == RIGHT_BRACKET_TYPE) {
            Token t;
            t = pop(&op_stack);
            
            while (t.type != LEFT_BRACKET_TYPE) {
                push(stack, t);
                t = pop(&op_stack);
            }
        } 
            
        else if (token.type == OP_TYPE) {
            int ops_restantes = 1;
            int op1 = token.contents;
            
            while (!empty(&op_stack) && op_stack.tokens[op_stack.fim-1].type == OP_TYPE && ops_restantes) { 
                int op2 = op_stack.tokens[op_stack.fim-1].contents;
                if (precedence(op1) <= precedence(op2)) {
                        push(stack, pop(&op_stack));
                }
                    
                else ops_restantes = 0;
            }
            
            push(&op_stack, token);
        }
    }
    
    while (!empty(&op_stack)) {
        push(stack, pop(&op_stack));
    }
    
    return 0;
}
            
double evaluate(Stack *stack) {
    Stack arg_stack = {0};
    
    int i;
    for (i = 0; i < stack->fim; i++) {
        Token cur_token = stack->tokens[i];
        
        if (cur_token.type == NUM_TYPE)
            push(&arg_stack, cur_token);
            
        else if (cur_token.type == VAR_TYPE) {
            Token t;
            t.type = NUM_TYPE;
            t.num_contents = state[cur_token.contents];
            
            push(&arg_stack, t);
        }
            
        else if (is_operator(cur_token)) {
            Token t1, t2;
            double arg1, arg2;
               
            t2 = pop(&arg_stack);
            t1 = pop(&arg_stack);
                
            arg1 = t1.num_contents;
            arg2 = t2.num_contents;
            
            Token result;
            result.type = NUM_TYPE;
            
            
            switch (cur_token.contents) {
                case ADD: result.num_contents = arg1 + arg2; break;
                case SUB: result.num_contents = arg1 - arg2; break;
                case MUL: result.num_contents = arg1 * arg2; break;
                case DIV: result.num_contents = arg1 / arg2; break;
            }
                
            push(&arg_stack, result);
        }
    }
    
    return arg_stack.tokens[0].num_contents;
}                               

char inp[100000];

int main() {    
    while(gets(inp) != NULL) {
        if (inp[0] == '\0') continue;
        
        Stack a = {0};
        
        if (inp[1]=='=') {
            parse(inp+2, &a);
            
            int var = inp[0]-'a';
            state[var] = evaluate(&a);
        }
        
        else {
            parse(inp, &a);
            printf("%.2lf\n",evaluate(&a));
        }
    }
}    
