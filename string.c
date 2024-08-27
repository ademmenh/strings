
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>





typedef struct charDNode
{
    char Value;
    struct charDNode *Previous;
    struct charDNode *Next;
} charDNode;

typedef struct string
{
    struct charDNode *H;
    struct charDNode *T;
    int length;
} string;



void funccharDNodeInit (charDNode *pDNode)
{
    pDNode->Value = 0;
    pDNode->Next = NULL;
    pDNode->Previous = NULL;
}

charDNode* funccharDNodeCreate (char value)
{

    charDNode *vpNew = (charDNode *) malloc(sizeof(charDNode));
    if ( vpNew==NULL )
    {
        printf ("\nThe Allocation has failled !!!");
        exit (1);
    }

    funccharDNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}

charDNode* funccharDNodePointer (string DList, int index)
{
    charDNode *vpCn;
    int viCn;


    if ( 0<=index )
    {
        if ( DList.length-1<index )
        {
            printf ("The index is out the range of the String !!!");
            exit (1);
        }

        vpCn = DList.H;
        for ( viCn=0; viCn<index; viCn++ )
        {
            vpCn = vpCn->Next;
        }

        return vpCn;
    }
    else
    {
        if ( DList.length<-index )
        {
            printf ("The index is out the range of the String !!!");
            exit (1);
        }

        vpCn = DList.T;
        for ( viCn=-1; index<viCn; viCn-- )
        {
            vpCn = vpCn->Previous;
        }

        return vpCn;
    }
}

void funccharDNodeFree (charDNode *pDNode)
{
    pDNode->Next = NULL;
    pDNode->Previous = NULL;
    pDNode->Value = 0;
    free (pDNode);
}



void funcstringInit (string *pString)
{
    pString->H = NULL;
    pString->T = NULL;
    pString->length = 0;
}

bool funcstringEmpty (string String)
{
    if ( String.length==0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}


// do not have a dependency
void funcstringInsert (string *pString, int index, char value)
{

    charDNode *vpNew;
    charDNode *vpTemp;
    charDNode *vpCn;
    int viCn;


    
    if ( 0<=index )
    {
        
        if ( (*pString).length<index )
        {
            printf ("The index is out the range of the String !!!");
            exit (1);
        }

        vpNew = funccharDNodeCreate (value);

        if ( (*pString).length==0 )
        {
            (*pString).H = vpNew;
            (*pString).T = vpNew;
        }
        else
        {
            if ( index==0 )
            {
                vpTemp = (*pString).H;
                (*pString).H = vpNew;

                (*pString).H->Next = vpTemp;
                vpTemp->Previous = (*pString).H;
            }
            else if ( index==(*pString).length )
            {
                vpTemp = (*pString).T;
                (*pString).T = vpNew;

                (*pString).T->Previous = vpTemp;
                vpTemp->Next = (*pString).T;
            }
            else
            {

                vpCn = (*pString).H;
                for ( viCn=0; viCn<index; viCn++ )
                {
                    vpCn = vpCn->Next;
                }
                vpTemp = vpCn;


                vpNew->Next = vpTemp;
                vpNew->Previous = vpTemp->Previous;

                vpTemp->Previous->Next = vpNew;
                vpTemp->Previous = vpNew;
            }
        }
    }
    else
    {
        if ( (*pString).length+1<-index )
        {
            printf ("The index is out the range of the String !!!");
            exit (1);
        }


        vpNew = funccharDNodeCreate (value);

        if ( (*pString).length==0 )
        {
            (*pString).H = vpNew;
            (*pString).T = vpNew;
        }
        else
        {
            if ( index==-1 )
            {
                vpTemp = (*pString).T;
                (*pString).T = vpNew;

                (*pString).T->Previous = vpTemp;
                vpTemp->Next = (*pString).T;
            }
            else if ( index==-((*pString).length)-1 )
            {
                vpTemp = (*pString).H;
                (*pString).H = vpNew;

                (*pString).H->Next = vpTemp;
                vpTemp->Previous = (*pString).H;
            }
            else
            {
                vpCn = (*pString).T;
                for ( viCn=-1; index<viCn; viCn-- )
                {
                    vpCn = vpCn->Previous;
                }
                vpTemp = vpCn;

                vpNew->Previous = vpTemp;
                vpNew->Next = vpTemp->Next;

                vpTemp->Next->Previous = vpNew;
                vpTemp->Next = vpNew;
            }
        }
    }
        



    (*pString).length++;
}

void funcstringInsertBegin (string *pString, char value)
{
    funcstringInsert (pString, 0, value);   //&(*pString)
}

void funcstringInsertEnd (string *pString, char value)
{
    funcstringInsert (pString, pString->length, value);     // &(*pString), (*pString).length
}

/*
void funcstringInsertBegin (string *pString, char value)
{

    charDNode *vp;
    charDNode *vpTemp;

    vp = funccharDNodeCreate (value);
    if ( (*pString).length==0 )
    {
        (*pString).H = vp;
        (*pString).T = vp;
    }
    else
    {
        vpTemp = (*pString).H;
        (*pString).H = vp;

        (*pString).H->Next = vpTemp;
        vpTemp->Previous = (*pString).H;
    }



    (*pString).length++;
}
*/

/*
void funcstringInsertEnd (string *pString, char value)
{

    charDNode *vpNew;
    charDNode *vpTemp;

    vpNew = funccharDNodeCreate(value);
    if ( (*pString).length==0 )
    {
        (*pString).H = vpNew;
        (*pString).T = vpNew;
    }
    else
    {
        vpTemp = (*pString).T;
        (*pString).T = vpNew;

        (*pString).T->Previous = vpTemp;
        vpTemp->Next = (*pString).T;
    }



    (*pString).length++;
}
*/


char funcstringat (string pString, int index)
{

    charDNode *vpCn;
    charDNode *vp;
    int viCn = 0;



    vp = funccharDNodePointer (pString, index);

    return vp->Value;
}

int funcstringIndex (string pString, char value)
{

    charDNode *vpCn;
    int viCn;

    vpCn = pString.H;
    for ( viCn=0; viCn<pString.length; viCn++ )
    {
        if ( vpCn->Value == value )
        {
            return viCn;
        }
        
        vpCn = vpCn->Next;
    }

    printf ("The Number %c do not exist in the String !!!", value);
    exit(1);
}

int funcstringCount (string pString, char value)
{
    
    charDNode *vpCn = pString.H;
    int viFound = 0;



    while ( vpCn!=NULL )
    {
        if ( value==vpCn->Value )
        {
            viFound ++;
        }

        vpCn = vpCn->Next;
    }

    return viFound;
}

void funcstringModify (string *pString, int index, char value)
{

    charDNode *vpNew = funccharDNodePointer (*pString, index);

    vpNew->Value = value;
}


void funcstringRemove (string *pString, int index)
{

    charDNode *vp;
    charDNode *vpTemp;



    vp = funccharDNodePointer (*pString, index);



    if ( (*pString).length==1 )
    {
        vpTemp = vp;
        (*pString).H = NULL;
        (*pString).T = NULL;

        funccharDNodeFree (vpTemp);
    }
    else
    {
        if ( vp==(*pString).H )
        {
            vpTemp = (*pString).H;
            (*pString).H = (*pString).H->Next;

            (*pString).H->Previous = NULL;
            funccharDNodeFree (vpTemp);
        }
        else if ( vp==(*pString).T )
        {
            vpTemp = (*pString).T;
            (*pString).T = (*pString).T->Previous;

            (*pString).T->Next = NULL;
            funccharDNodeFree (vpTemp);
        }
        else
        {
            vpTemp = vp;

            vpTemp->Previous->Next = vpTemp->Next;
            vpTemp->Next->Previous = vpTemp->Previous;
            funccharDNodeFree (vpTemp);
        }
    }





    (*pString).length--;
}

void funcstringRemoveBegin (string *pString)
{
    funcstringRemove (pString, 0);  // &(*pString)
}

void funcstringRemoveEnd (string *pString)
{
    funcstringRemove (pString, pString->length-1);  // &(*pString), (*pString).length-1
}

/*
void funcstringRemoveBegin (string *pString)
{

    charDNode *vpTemp;

    if ( (*pString).length==0 )
    {
        printf ("The String is already empty !!!");
        return;
    }


    if ( (*pString).length==1 )
    {
        vpTemp = (*pString).H;
        (*pString).H = NULL;
        (*pString).T = NULL;

        funccharDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pString).H;
        (*pString).H = (*pString).H->Next;

        (*pString).H->Previous = NULL;
        funccharDNodeFree (vpTemp);    
    }



    (*pString).length--;
}
*/

/*
void funcstringRemoveEnd (string *pString)
{
    
    charDNode *vpTemp;
    

    if ( (*pString).length==0 )
    {
        printf ("The String is already empty !!!");
        return;
    }

    if ( (*pString.length==1) )
    {
        vpTemp = (*pString).H;
        (*pString).H = NULL;
        (*pString).T = NULL;

        funccharDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pString).T;
        (*pString).T = (*pString).T->Previous;

        (*pString).T->Next = NULL;
        funccharDNodeFree (vpTemp);
    }
    



    (*pString).length--;
}
*/


void funccharDListClear (string *pString)
{

    while ( (*pString).length>0 )
    {
        funcstringRemove (pString, 0);  // &(*pString)
    }
}

/*
void funcstringClear (string *pString)
{


    charDNode *vpCn;
    charDNode *vpTemp;


    vpCn = (*pString).H;
    while ( vpCn!=NULL )
    {
        vpTemp = vpCn;
        vpCn = vpCn->Next;

        funccharDNodeFree (vpTemp);
    }


    (*pString).H = NULL;
    (*pString).T = NULL;
    (*pString).length = 0;
}
*/


const int string_max_length = 1001;

void funcstringInput (string *pString)
{

    char vsString [string_max_length];
    int viCn;
    int ClearBuffer;


    printf ("Enter the String: ");
    fgets (vsString, string_max_length, stdin);


    while ((ClearBuffer=getchar()) != '\n' )
    {}

    for ( viCn=0; viCn<string_max_length-1; viCn++ )
    {
        if ( vsString [viCn]=='\0' )
        {
            break;
        }
        funcstringInsertEnd (pString, vsString[viCn]);
    }

}

void funcstringDisplay (string String)
{

    charDNode *vpCn;
    
    if ( String.length==0 )
    {
        printf ("The String is Empty !!!\n");
        return;
    }
    
    vpCn = String.H;
    while (vpCn!=NULL)
    {
        printf ("%c", vpCn->Value);
        vpCn = vpCn->Next;
    }
    
}

void funcstringDisplayReversed (string String)
{

    charDNode *vpCn;

    if ( String.length==0 )
    {
        printf ("The String is empty !!!\n");
        return;
    }
    
    
    vpCn = String.T;
    while ( vpCn!=NULL )
    {
        printf ("%c", vpCn->Value);
        vpCn = vpCn->Previous;
    }
}



int main ()
{
    string vsString1;
    string vsString2;

    funcstringInit (&vsString1);
    funcstringInit (&vsString2);

    funcstringInput (&vsString1);
    funcstringDisplay (vsString1);
    printf ("\n");
    funcstringInput (&vsString2);
    funcstringDisplay (vsString2);

    return 0;
}