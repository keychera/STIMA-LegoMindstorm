#include <stdlib.h>
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define Nil 0
#define MaxS 100
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl
#define boolean unsigned char
#define true 1
#define false 0

typedef char infostack;
typedef int address;
typedef struct {
	infostack T[MaxS+1];
	address TOP;
} Stack;
typedef int infotype;
typedef int address;
typedef struct { infotype * T;
                 address HEAD;
                 address TAIL;
                 int MaxEl;
               } Queue;

void CreateEmptyS (Stack *S)
{
Top(*S) = Nil;
}

boolean IsEmptyS (Stack S)
{
	return(Top(S) == Nil);
}

boolean IsFullS (Stack S)
{
	return(Top(S) == MaxS);
}

void Push (Stack * S, infostack X)
{
    Top(*S)++;
    InfoTop(*S) = X;
}

void Pop (Stack * S, infostack* X)
{
	*X = InfoTop(*S);
    Top(*S)--;
}

boolean IsEmpty (Queue Q)
{
    return((Head(Q) == Nil) && (Tail(Q) == Nil));
}

boolean IsFull (Queue Q)
{
   return((Head(Q) == 1) && (Tail(Q)==MaxEl(Q)));
}

int NBElmt (Queue Q)
{
	int n;

	if (IsEmpty(Q)) n = 0;
	else if (Head(Q) <= Tail(Q)) n = Tail(Q) - Head(Q) + 1;
	else n = Q.MaxEl - Tail(Q) + Head(Q) + 1;
	return n;
}
void CreateEmpty (Queue * Q, int Max)
{
   (*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));
   if ((*Q).T != NULL) {
          MaxEl(*Q) = Max;
          Head(*Q) = Nil;
          Tail(*Q) = Nil;
          }
          else
            {
                MaxEl(*Q) = Nil;
          }
}
void DeAlokasi(Queue * Q)
{
    MaxEl(*Q) = Nil;
    free((*Q).T);
}

void Add (Queue * Q, infotype X)
{
	if (IsEmpty(*Q))
	{
		Tail(*Q) = 1;
		Head(*Q) = 1;
	}
	else
	{
		Tail(*Q) += 1;
		if (Tail(*Q) == (*Q).MaxEl + 1) Tail(*Q) = 1;
	}
	InfoTail(*Q) = X;
}

void Del (Queue * Q, infotype * X)
{
		(*X) = InfoHead(*Q);
		if (Head(*Q) == Tail(*Q))	{
			Head(*Q) = Nil;
			Tail(*Q) = Nil;
		}
		else {
			Head(*Q)++;
			if (Head(*Q) == MaxEl(*Q) + 1) Head(*Q) = 1;
		}
}
