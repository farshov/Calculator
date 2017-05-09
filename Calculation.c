#include <stdio.h>
#include <assert.h>

char BUF[100] = {};
int POS = 0;

void Read_file(FILE * input);
int GetG();
int GetE();
int GetT();
int GetP();
int GetN();

int main()
{
    int res = 0;
    FILE * input = fopen("input", "r + w");
    Read_file(input);
    fclose(input);
    res = GetG();
    printf("Resault = %d\n", res);
    return 0;
}

int GetG()
{
    printf("getG\n");
    int val = GetE();
    printf("BUF[POS] = %c\n", BUF[POS]);
    assert(BUF[POS] == '\0');
    printf(" VAL = %d\n", val);
    return val;
}

int GetN()
{
    printf("getN\n");
    int val = 0;
    int p = POS;
    while('0' <= BUF[POS] && BUF[POS] <= '9')
    {
        val = val * 10 + BUF[POS] - '0';
        POS++;
    }
    assert(p != POS);
    printf(" VAL = %d\n", val);
    return val;
}

int GetE()
{
    printf("getE ");
    int val = GetT();
    int val2 = 0;
    int cur = 0;
    while(BUF[POS] == '+' || BUF[POS] == '-')
    {
        cur = BUF[POS++];
        val2 = GetT();
        if(cur == '+')
        {
            val += val2;
        }
        else
        {
            val -= val2;
        }
    }
    printf(" VAL = %d\n", val);
    return val;
}

int GetT()
{
    printf("getT\n");
    int val = GetP();
    int val2 = 0;
    int cur = 0;
    while(BUF[POS] == '*' || BUF[POS] == '/')
    {
        cur = BUF[POS++];
        val2 = GetP();
        if(cur == '*')
        {
            val = val * val2;
        }
        else
        {
            val = val / val2;
        }
    }
    printf(" VAL = %d\n", val);
    return val;
}

int GetP()
{
    printf("getP\n");
    int val = 0;
    if(BUF[POS] == '(')
    {
        POS++;
        val = GetE();
        assert(BUF[POS] == ')');
        POS++;
    }
    else
    {
        val = GetN();
    }
    printf(" VAL = %d\n", val);
    return val;
}

void Read_file(FILE * input)
{
    int length = 0;
    fseek(input, 0, SEEK_END);
    length = ftell(input);
    fseek(input, 0, SEEK_SET);
    fread(BUF, sizeof(char), 10, input);
    BUF[9] = '\0';
}